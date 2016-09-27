#ifndef DATA_FORMAT_H
#define DATA_FORMAT_H

/*data format for wave file*/
struct riff_chunk
{
	unsigned int riff_id;/*const*/
	unsigned int riff_size;/*after compute*/
	unsigned int format;/*const*/
};

struct wav_meta
{
	unsigned short format_tag;/*const*/
	unsigned short channels;/*option*/
	unsigned int sample_ps;/*option*/
	unsigned int bytes_ps;/*after compute*/
	unsigned short block_align;/*must be product of channels and bits_per_sample divided by 8*/
	unsigned short bits_per_sample;/*option*/
};

struct fmt_chunk
{
	unsigned int fmt_id;/*const*/
	unsigned int fmt_size;/*const*/
	struct wav_meta wav_m;
};

struct data_chunk
{
	unsigned int data_id;/*const*/
	unsigned int data_size;/*after compute*/
	unsigned char *data;
};

struct wave_file
{
	struct riff_chunk *riff_head;
	struct fmt_chunk *fmt_head;
	struct data_chunk *pcm_data;
};

#endif