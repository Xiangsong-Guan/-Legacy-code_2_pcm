#include <defines.h>
#include <data_format.h>
#include <stdio.h>

/*set the options according to cmd parameters, return 0 if no problems. self print.*/
extern int interpret_parameter(const int parameters_cnt, const char **parameters);
/*format the target file's header*/
extern int format_header(struct wave_file *pwf);

/*file*/
extern FILE *i_file;
extern FILE *o_file;

int main(int argc, char **argv)
{
	struct wave_file trgt_file;

	if(interpret_parameter(argc, (const char **)argv) != 0)
	{
		return 1;
	}

	format_header(&trgt_file);



	fclose(i_file);
	fclose(o_file);

	return 0;
}