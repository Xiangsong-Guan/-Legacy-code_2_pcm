#ifndef WAV_OPTIONS_NAME_H
#define WAV_OPTIONS_NAME_H 1

/**********************************

		consts

 **********************************/

/*app infomations*/
#define INFO_AUTHOR  "Xiangsong Guan"
#define INFO_TILTE   "code_2_pcm"
#define INFO_TIME    "2016 qiu"
#define INFO_VERIFY  "KaSiKoi KaWai eRiCHi!"
#define INFO_VERSION "0.1.1"

/*return msg*/
#define SUCCESS 0
#define ERROR   1
#define SKIP_TO_END 2

/*common parameter for wave format*/
#define RIFF_ID 0x46464952U/*'RIFF' in little-end, for riff_id of riff_chunk*/
#define FORMAT 0x45564157U/*'WAVE' in little-end, for format of riff_chunk*/
#define FMT_ID 0x20746D66U/*'fmt ' in little-end, for fmt_id of fmt_chunk*/
#define FMT_SIZE 0x00000010U/*16 in little-end, for fmt_size of fmt_chunk*/
#define DATA_ID 0x61746164U/*'DATA' in little-end, for data_id of data_chunk*/
#define FORMAT_TAG 0x0001U/*1 in little-end, for format_tag of wav_meta, stand for 'WAVE_FORMAT_PCM'*/

/*ext name of wave flie*/
#define EXT_WAVE '.wav'

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
#define OUTPUT_PATH 'o'

/*default output file (wave file)'s path*/
#define DEFAULT_OUTPUT_PATH "o.wav"

/**********************************************

		functions

 **********************************************/

/*some macro to save lines*/
#define FUNC_USAGE_AND_RETURN(msg) \
{                                  \
	usage(msg);                      \
	return 1;                        \
}

#define FUNC_ASS_AND_BREAK(t, v) \
{                                \
	(t) = (v);                     \
	break;                         \
}

#endif