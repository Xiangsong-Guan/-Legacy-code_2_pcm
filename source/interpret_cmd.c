#include <stdio.h>
#include <string.h>
#include <include/macro_defines.h>
#include <include/wav_options_value.h>

/*optional parameters*/
enum opt_channels opt_ch;
enum opt_sample_ps opt_sps;
enum opt_bits_per_sample opt_bps;

/*file*/
FILE *i_file;
FILE *o_file;

static void usage(const char *msg)
{
	puts(msg);
	puts("---------------- Usage for " INFO_VERSION " ver. | writen by " INFO_AUTHOR " ----------------");
	puts("Encode your source code file to a pcm codec wave file, just for fun.");
	puts(INFO_TILTE " [options] <input_file_path | -h | -v>");
	puts("options:");
	puts("  -h  print this usage.");
	puts("  -v  print version infomation.");
	puts("  -o  output file (wave file)'s path.");
	puts("      [default]when miss this option, the default value 'o.wav' will be applied.");
	puts("  -c  decide the number of Sound Channel.");
	puts("      m(ono)      -> single sound channel.");
	puts("      s(tereo)    -> output file will contain left & right sound channel.");
	puts("      [default]when miss this option, the default value 'mono' will be applied.");
	puts("  -s  decide the sample per second.");
	puts("      t(elephone) -> 8000Hz which is used by Telecommunication.");
	puts("      r(adio)     -> 22050Hz which is used by Radio broadcasting.");
	puts("      c(d)        -> 44100Hz which is used by CD quality.");
	puts("      d(vd)       -> 48000Hz which is used by High quality DVD and Digital TV.");
	puts("      [default]when miss this option, the default value 'telephone' will be applied.");
	puts("  -b  decide the bits per sample.");
	puts("      l(ow)       -> 8bits which make low Fidelity.");
	puts("      n(omal)     -> 16bits which is widly used in music & video.");
	puts("      h(igh)      -> 24bits which is used to make high Fidelity.");
	puts("      [default]when miss this option, the default value 'low' will be applied.");
	puts(INFO_TIME);
	return;
}

/*return 0 if no problems. self print.*/
static int assgin_options(const int parameters_cnt, const char **parameters, const char *o_path)
{
	char opt;
	int i;
	const char *pc;

	opt = 0x00;

	for(i = 1; i <= (parameters_cnt - 2); i++)
	{
		pc = parameters[i];

		if(opt == 0x00)
		{
			if(pc[0] == '-')
			{
				switch(pc[1])
				{
					case CHANNELS:
					case BITS_PER_SAMPLE:
					case SAMPLE_PS:
					case OUTPUT_PATH:
						FUNC_ASS_AND_BREAK(opt, pc[1]);
					default:
						FUNC_USAGE_AND_RETURN("ERROR! Invalid option.");
				}
			}
			else
			{
				FUNC_USAGE_AND_RETURN("ERROR! Invalid parameters!");
			}
		}
		else
		{
			switch(opt)
			{
				case CHANNELS:
					switch(pc[0])
					{
						case OPT_STEREO:
							FUNC_ASS_AND_BREAK(opt_ch, stereo);
						case OPT_MONO:
							FUNC_ASS_AND_BREAK(opt_ch, mono);
						default:
							FUNC_USAGE_AND_RETURN("Wrong channels option!");
					}
					break;
				case SAMPLE_PS:
					switch(pc[0])
					{
						case OPT_TELEPHONE:
							FUNC_ASS_AND_BREAK(opt_sps, telephone);
						case OPT_RADIO:
							FUNC_ASS_AND_BREAK(opt_sps, radio);
						case OPT_CD:
							FUNC_ASS_AND_BREAK(opt_sps, cd);
						case OPT_DVD:
							FUNC_ASS_AND_BREAK(opt_sps, dvd);
						default:
							FUNC_USAGE_AND_RETURN("Wrong sample per second option!");
					}
					break;
				case BITS_PER_SAMPLE:
					switch(pc[0])
					{
						case OPT_LOW:
							FUNC_ASS_AND_BREAK(opt_bps, low);
						case OPT_NOMAL:
							FUNC_ASS_AND_BREAK(opt_bps, nomal);
						case OPT_HIGH:
							FUNC_ASS_AND_BREAK(opt_bps, high);
						default:
							FUNC_USAGE_AND_RETURN("Wrong bits per sample option!");
					}
					break;
				case OUTPUT_PATH:
					FUNC_ASS_AND_BREAK(o_path, pc);
				default:
					FUNC_USAGE_AND_RETURN("Wrong option!");
			}
			opt = 0x00;
		}
	}

	if(opt != 0x00)
	{
		FUNC_USAGE_AND_RETURN("ERROR! Lack of some parameters!");
	}
	else
	{
		return SUCCESS;
	}
}

/*set the options according to cmd parameters, return 0 if no problems. self print.*/
int interpret_parameter(const int parameters_cnt, const char **parameters)
{
	const char *o_path, *i_path;

	opt_ch = mono;
	opt_sps = telephone;
	opt_bps = low;
	o_path = DEFAULT_OUTPUT_PATH;

	/*check the cmd is valid or not*/
	if(parameters_cnt == 1)
	{
		FUNC_USAGE_AND_RETURN("");
	}

	i_path = parameters[parameters_cnt - 1];
	if(i_path[0] == '-')
	{
		if(i_path[1] == 'h')
		{
			usage("");
			return SKIP_TO_END;
		}
		else if(i_path[1] == 'v')
		{
			puts(INFO_VERSION);
			return SKIP_TO_END;
		}
	}

	/*input file is readable?*/
	i_file = fopen(i_path, "rb");
	if(i_file == NULL)
	{
		perror("Input file: ");
		return ERROR;
	}

	if(assgin_options(parameters_cnt, parameters, o_path) == ERROR)
	{
		return ERROR;
	}

	/*output file is already existed? writable?*/
	o_file = fopen(o_path, "rb");
	if (o_file != NULL)
	{
	  fclose(o_file);
	  puts("Output file is already existed! Overwrite? [y/n]");
	  if (getchar() != 'y')
	  {
	    fclose(i_file);
	    puts("Abort.");
	    return ERROR;
	  }
	}
	o_file = fopen(o_path, "wb");
	if (o_file == NULL)
	{
	  perror("Output file: ");
	  fclose(i_file);
	  return ERROR;
	}
	return SUCCESS;
}