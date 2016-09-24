#ifndef DATA_FORMAT_H
#define DATA_FORMAT_H

/*ext name of wave flie*/
#define EXT_WAVE '.wa'

/*common parameter for wave format*/
#define RIFF_ID 0x46464952/*'RIFF' in little-end, for riff_id of riff_chunk*/
#define FORMAT 0x45564157/*'WAVE' in little-end, for format of riff_chunk*/
#define FMT_ID 0x20746D66/*'fmt ' in little-end, for fmt_id of fmt_chunk*/
#define FMT_SIZE 0x00000010/*16 in little-end, for fmt_size of fmt_chunk*/
#define DATA_ID 0x61746164/*'DATA' in little-end, for data_id of data_chunk*/
#define FORMAT_TAG 0x0001/*1 in little-end, for format_tag of wav_meta, stand for 'WAVE_FORMAT_PCM'*/

/*optional options*/
#define OPT_STEREO 's'
#define OPT_MONO 'm'
#define OPT_TELEPHONE 't'
#define OPT_RADIO 'r'
#define OPT_CD 'c'
#define OPT_DVD 'd'
#define OPT_LOW 'l'
#define OPT_NOMAL 'n'
#define OPT_HIGH 'h'

/*option name*/
#define CHANNELS 'c'
#define SAMPLE_PS 's'
#define BITS_PER_SAMPLE 'b'
#define HELP 'h'

/*some parameter in options*/
enum opt_channels
{
	mono = 1,
	stereo = 2
};/*default stereo*/

enum opt_sample_ps
{
	telephone = 8000,
	radio = 22050,
	cd = 44100,
	dvd = 48000
};/*Hz | default cd*/

enum opt_bits_per_sample
{
	low = 8,
	nomal = 16,
	high = 24
};/*bit | default nomal*/

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
	wav_meta wav_m;
};

struct data_chunk
{
	unsigned int data_id;/*const*/
	unsigned int data_size;/*after compute*/
	unsigned char *data;
};

struct wave_file
{
	riff_chunk *riff_head;
	fmt_chunk *fmt_head;
	data_chunk *pcm_data;
};

#endif