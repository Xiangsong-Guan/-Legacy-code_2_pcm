# code_2_pcm

鑳℃€濅贡鎯崇郴鍒楋紝灏嗕唬鐮侊紙涓€鍒囨枃浠讹級杩涜闊抽杞崲鈥︹€�

# 鍛ㄨ竟

minGW-w64 / win-x86_64 / ANSI C

# Usage

Encode your source code file to a pcm codec wave file, just for fun.

code_2_pcm [options] _input_file_path_

EXAMPLE: `code_2_pcm -c s -s r -b n inputfile.someting`

options:
*  -h  print this usage.
*  -v  print version infomation.
*  -o  output file (wave file)'s path.

       [default]when miss this option, the default value 'o.wav' will be applied.

*  -c  decide the number of Sound Channel.

       m(ono)      -> single sound channel.
       s(tereo)    -> output file will contain left & right sound channel.

       [default]when miss this option, the default value 'mono' will be applied.

*  -s  decide the sample per second.

       t(elephone) -> 8000Hz which is used by Telecommunication.
       r(adio)     -> 22050Hz which is used by Radio broadcasting.
       c(d)        -> 44100Hz which is used by CD quality.
       d(vd)       -> 48000Hz which is used by High quality DVD and Digital TV.

       [default]when miss this option, the default value 'telephone' will be applied.

*  -b  decide the bits per sample.

       l(ow)       -> 8bits which make low Fidelity.
       n(omal)     -> 16bits which is widly used in music & video.
       h(igh)      -> 24bits which is used to make high Fidelity.

       [default]when miss this option, the default value 'low' will be applied.

2016 qiu