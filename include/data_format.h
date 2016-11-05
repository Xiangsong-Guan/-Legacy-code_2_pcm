#ifndef DATA_FORMAT_H
#define DATA_FORMAT_H 1

#include <stdint.h>

/*data format for wave file*/
struct riff_chunk
{
	uint32_t riff_id;/*const*/
	uint32_t riff_size;/*after compute: 36 + input_size*/
	uint32_t format;/*const*/
};

struct wave_meta
{
	uint16_t format_tag;/*const*/
	uint16_t channels;/*option*/
	uint32_t sample_ps;/*option*/
	uint32_t bytes_ps;/*after compute: channels * sample_ps * bytes_per_sample*/
	uint16_t block_align;/*after compute: must be product of channels and bits_per_sample divided by 8*/
	uint16_t bits_per_sample;/*option*/
};

struct fmt_chunk
{
	uint32_t fmt_id;/*const*/
	uint32_t fmt_size;/*const*/
	struct wave_meta wav_m;
};

struct data_chunk
{
	uint32_t data_id;/*const*/
	uint32_t data_size;/*after compute: input_size*/
};

struct wave_file
{
	struct riff_chunk riff_head;
	struct fmt_chunk fmt_head;
	struct data_chunk pcm_data;
};

#endif