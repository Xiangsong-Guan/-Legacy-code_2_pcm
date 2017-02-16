#include "code_2_pcm.h"

/*set the options according to cmd parameters, return 0 if no problems. self print.*/
extern int interpret_parameter(const int parameters_cnt, const char **parameters);

/*file*/
extern FILE *i_file;
extern FILE *o_file;

/*optional parameters*/
extern enum opt_channels opt_ch;
extern enum opt_sample_ps opt_sps;
extern enum opt_bits_per_sample opt_bps;