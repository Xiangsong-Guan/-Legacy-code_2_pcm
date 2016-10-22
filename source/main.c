#include <data_format.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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
	size_t sou_size, full_size;
	char *buf;

	if(interpret_parameter(argc, (const char **)argv) != 0)
	{
		return 1;
	}

	/*get the input file's size*/
	if(fseek(i_file, 0L, SEEK_END) != 0)
	{
		puts("Some error occurred on input file!");
		return -1;
	}
	sou_size = (size_t)ftell(i_file);
	if(sou_size & 0x80000000)
	{
		puts("Input files may be too large!");
		return -1;
	}
	fseek(i_file, 0L, SEEK_SET);

	/*alloc space for input file*/
	full_size = sou_size + (size_t)format_header(&trgt_file, (unsigned int)sou_size);
	buf = calloc(full_size, 1UL);

	/*write the file's header*/
	fwrite(&trgt_file, sizeof(struct wave_file), 1UL, o_file);

	/*write the file's data*/
	fread(buf, 1UL, sou_size, i_file);
	fwrite(buf, 1UL, full_size, o_file);

	free(buf);
	fclose(i_file);
	fclose(o_file);

	return 0;
}