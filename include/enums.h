#ifndef ENUMS_H
#define ENUMS_H

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

#endif