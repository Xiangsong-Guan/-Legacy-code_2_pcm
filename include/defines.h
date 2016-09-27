#ifndef DEFINES_H
#define DEFINES_H

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

#endif