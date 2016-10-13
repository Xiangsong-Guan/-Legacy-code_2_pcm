#include <defines.h>
#include <data_format.h>

/*optional parameters*/
extern enum opt_channels opt_ch;
extern enum opt_sample_ps opt_sps;
extern enum opt_bits_per_sample opt_bps;

/*format the target file's header*/
int format_header(struct wave_file *pwf, unsigned int i_size)
{
	/*parameters check*/

	/*some common parameters*/
	pwf->riff_head.riff_id = RIFF_ID;
	pwf->riff_head.format = FORMAT;
	pwf->fmt_head.fmt_id = FMT_ID;
	pwf->fmt_head.fmt_size = FMT_SIZE;
	pwf->fmt_head.wav_m.format_tag = FORMAT_TAG;
	pwf->pcm_data.data_id = DATA_ID;

	/*some optional parameters*/
	pwf->fmt_head.wav_m.channels = opt_ch;
	pwf->fmt_head.wav_m.sample_ps = opt_sps;
	pwf->fmt_head.wav_m.bits_per_sample = opt_bps;

	/*some computered parameters*/
	pwf->riff_head.riff_size = i_size + 36U;/*plus wave file's header exclude of first 8 bytes*/
	pwf->fmt_head.wav_m.bytes_ps = (pwf->fmt_head.wav_m.bits_per_sample / 8U) * pwf->fmt_head.wav_m.sample_ps * pwf->fmt_head.wav_m.channels;/*Regulations*/
	pwf->fmt_head.wav_m.block_align = pwf->fmt_head.wav_m.channels * (pwf->fmt_head.wav_m.bits_per_sample / 8U);/*Regulations*/
	pwf->pcm_data.data_size = i_size;

	return 0;
}