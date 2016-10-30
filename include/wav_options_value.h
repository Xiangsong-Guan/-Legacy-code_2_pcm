#ifndef WAV_OPTIONS_VALUE_H
#define WAV_OPTIONS_VALUE_H

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