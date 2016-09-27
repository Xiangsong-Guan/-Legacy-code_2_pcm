#include <enums.h>
#include <interpret_cmd.h>
#include <stdio.h>

/*optional parameters*/
extern enum opt_channels opt_ch;
extern enum opt_sample_ps opt_sps;
extern enum opt_bits_per_sample opt_bps;

/*file*/
extern FILE *i_file;
extern FILE *o_file;

int main(int argc, char **argv)
{
	if(interpret_parameter(argc, (const char **)argv) != 0)
	{
		return 1;
	}



	fclose(i_file);
	fclose(o_file);

	return 0;
}