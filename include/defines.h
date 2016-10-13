#ifndef DEFINES_H
#define DEFINES_H

/*ext name of wave flie*/
#define EXT_WAVE '.wav'

/*common parameter for wave format*/
#define RIFF_ID 0x46464952U/*'RIFF' in little-end, for riff_id of riff_chunk*/
#define FORMAT 0x45564157U/*'WAVE' in little-end, for format of riff_chunk*/
#define FMT_ID 0x20746D66U/*'fmt ' in little-end, for fmt_id of fmt_chunk*/
#define FMT_SIZE 0x00000010U/*16 in little-end, for fmt_size of fmt_chunk*/
#define DATA_ID 0x61746164U/*'DATA' in little-end, for data_id of data_chunk*/
#define FORMAT_TAG 0x0001U/*1 in little-end, for format_tag of wav_meta, stand for 'WAVE_FORMAT_PCM'*/

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

/*option name-in-short*/
#define CHANNELS 'c'
#define SAMPLE_PS 's'
#define BITS_PER_SAMPLE 'b'
#define HELP 'h'

/*some parameter in options*/
enum opt_channels
{
	mono = 1U,
	stereo = 2U
};/*default stereo*/

enum opt_sample_ps
{
	telephone = 8000U,
	radio = 22050U,
	cd = 44100U,
	dvd = 48000U
};/*Hz | default cd*/

enum opt_bits_per_sample
{
	low = 8U,
	nomal = 16U,
	high = 24U
};/*bit | default nomal*/

#endif