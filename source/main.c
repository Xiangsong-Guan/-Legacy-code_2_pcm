#include <stdlib.h>
#include <include/macro_defines.h>
#include <api/fill_file.h>
#include <api/interpret_cmd.h>

/*verify*/
const char *verify = "#" INFO_AUTHOR "#" INFO_TILTE "#" INFO_TIME "#" INFO_VERIFY "#" INFO_VERSION;

int main(int argc, char **argv)
{
	struct wave_file trgt_file;
	size_t sou_size, full_size;
	char *buf;
	int return_msg;

	return_msg = interpret_parameter(argc, (const char **)argv);
	if(return_msg != SUCCESS)
	{
		return return_msg;
	}

	/*get the input file's size*/
	if(fseek(i_file, 0L, SEEK_END) != SUCCESS)
	{
		puts("Some error occurred on input file!");
		return ERROR;
	}
	sou_size = ftell(i_file);
	if(sou_size & 0xFFFFFFFF80000000ULL)
	{
		puts("Input files may be too large!");
		return ERROR;
	}
	rewind(i_file);

	/*alloc space for input file*/
	full_size = sou_size + format_header(&trgt_file, sou_size);
	buf = calloc(full_size, 1ULL);

	/*write the file's header*/
	fwrite(&trgt_file, sizeof(struct wave_file), 1ULL, o_file);

	/*write the file's data*/
	fread(buf, 1ULL, sou_size, i_file);
	fwrite(buf, 1ULL, full_size, o_file);

	free(buf);
	fclose(i_file);
	fclose(o_file);

	return SUCCESS;
}