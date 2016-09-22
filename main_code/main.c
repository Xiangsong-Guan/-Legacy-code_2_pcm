#include "data_format.h"
#include "interpret_cmd.h"
#include <stdio.h>
#include <assert.h>

extern int interpret_parameter(const int parameters_cnt, const char **parameters);

/*optional parameters*/
extern enum opt_channels opt_ch;
extern enum opt_sample_ps opt_sps;
extern enum opt_bits_per_sample opt_bps;

/*necessary parameters*/
extern char *i_path;
extern char *o_path;

/*file*/
extern FILE *i_file;
extern FILE *o_file;

int main(int argc, char **argv)
{
	/*to do...*/

	/*debug, the file is already close?*/
	assert(i_file == NULL && o_file == NULL);

	return 0;
}