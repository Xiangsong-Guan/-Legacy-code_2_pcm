#include "data_format.h"
#include <stdio.h>
#include <errno.h>
#include <assert.h>

/*optional parameters*/
enum opt_channels opt_ch;
enum opt_sample_ps opt_sps;
enum opt_bits_per_sample opt_bps;

/*necessary parameters*/
char *i_path;
char *o_path;

/*file*/
FILE *i_file;
FILE *o_file;

static void usage()
{
	puts("Usage");
	puts("Encode your source code file to a pcm codec wave file, just for fun.");
	puts("code_2_pcm [options] input_file_path output_file_path");
	puts("options:");
	puts("  -h  print this usage.");
	puts("  -c  decide the number of Sound Channel.");
	puts("      mono      -> single sound channel.");
	puts("      stereo    -> output file will contain left & right sound channel.");
	puts("      [default]when miss this option, the default value 'stereo' will be applied.");
	puts("  -s  decide the sample per second.");
	puts("      telephone -> 8000Hz which is used by Telecommunication.");
	puts("      radio     -> 22050Hz which is used by Radio broadcasting.");
	puts("      cd        -> 44100Hz which is used by CD quality.");
	puts("      dvd       -> 48000Hz which is used by High quality DVD and Digital TV.");
	puts("      [default]when miss this option, the default value 'cd' will be applied.");
	puts("  -b  decide the bits per sample.");
	puts("      low       -> 8bits which make low Fidelity.");
	puts("      nomal     -> 16bits which is widly used in music & video.");
	puts("      high      -> 24bits which is used to make high Fidelity.");
	puts("      [default]when miss this option, the default value 'nomal' will be applied.");
	return;
}

int interpret_parameter(const int parameters_cnt, const char **parameters)
{
	char *pc;
	char opt[2];
	int i;

	opt_ch = default_channels;
	opt_sps = default_sample_ps;
	opt_bps = default_bits_per_sample;

	pc = parameters[1];
	opt[1] = 0;
	opt[0] = 0;

	/*verify cmd via number of parameters*/
	if(parameters_cnt < 3)
	{
		puts("Incorrect parameters!");
		usage();
		return 1;
	}

	i_path = parameters[parameters_cnt - 2];
	o_path = parameters[parameters_cnt - 1];

	/*input file is readble?*/
	i_file = fopen(i_path, "rt");
	if(i_file == NULL)
	{
		perror();
		return 1;
	}

	/*output file is already existed? writable?*/
	o_file = fopen(o_path, "rb");
	if(o_file != NULL)
	{
		fclose(o_file);
		puts("Output file is already existed! Overwrite? [y/n]");
		if(getchar() != 'y')
		{
			fclose(i_file);
			puts("Abort.");
			return 1;
		}
	}
	o_file = fopen(o_path, "wb");
	if(o_file == NULL)
	{
		perror();
		fclose(i_file);
		return 1;
	}

	/*debug, all files is open?*/
	assert(i_file != NULL && o_file != NULL);

	/*interpret parameters*/
	for(i = 1; i < (parameters_cnt - 3); i++)
	{
		/*to do...*/
	}

	return 0;
}
