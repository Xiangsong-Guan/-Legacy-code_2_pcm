#include <data_format.h>
#include <stdio.h>

/*set the options according to cmd parameters, return 0 if no problems. self print.*/
extern int interpret_parameter(const int parameters_cnt, const char **parameters);
/*format the target file's header*/
extern int format_header(struct wave_file *pwf, long i_size);

/*file*/
extern FILE *i_file;
extern FILE *o_file;

int main(int argc, char **argv)
{
	struct wave_file trgt_file;
	long sou_size;

	if(interpret_parameter(argc, (const char **)argv) != 0)
	{
		return 1;
	}

	if(fseek(i_file, 0L, SEEK_END) == 0) /*black-man-???*/
	{
		puts("Some error occurred on input file!");
		return -1;
	}
	sou_size = ftell(i_file);
	if(sou_size == -1L)
	{
		perror("Input file: ");
		return -1;
	}
	if(sou_size)
	fseek(i_file, 0L, SEEK_SET);

	format_header(&trgt_file, (unsigned int)sou_size);

	fclose(i_file);
	fclose(o_file);

	return 0;
}