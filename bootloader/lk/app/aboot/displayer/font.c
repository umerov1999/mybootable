#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "font.h"

static unsigned char Ascii_index[] = {
	
	0x20, // - -

	0x21, // -!-

	0x22, // -"-

	0x23, // -#-

	0x24, // -$-

	0x25, // -%-

	0x26, // -&-

	0x27, // -'-

	0x28, // -(-

	0x29, // -)-

	0x2a, // -*-

	0x2b, // -+-

	0x2c, // -,-

	0x2d, // ---

	0x2e, // -.-

	0x2f, // -/-

	0x30, // -0-

	0x31, // -1-

	0x32, // -2-

	0x33, // -3-

	0x34, // -4-

	0x35, // -5-

	0x36, // -6-

	0x37, // -7-

	0x38, // -8-

	0x39, // -9-

	0x3a, // -:-

	0x3b, // -;-

	0x3c, // -<-

	0x3d, // -=-

	0x3e, // ->-

	0x3f, // -?-

	0x40, // -@-

	0x41, // -A-

	0x42, // -B-

	0x43, // -C-

	0x44, // -D-

	0x45, // -E-

	0x46, // -F-

	0x47, // -G-

	0x48, // -H-

	0x49, // -I-

	0x4a, // -J-

	0x4b, // -K-

	0x4c, // -L-

	0x4d, // -M-

	0x4e, // -N-

	0x4f, // -O-

	0x50, // -P-

	0x51, // -Q-

	0x52, // -R-

	0x53, // -S-

	0x54, // -T-

	0x55, // -U-

	0x56, // -V-

	0x57, // -W-

	0x58, // -X-

	0x59, // -Y-

	0x5a, // -Z-

	0x5b, // -[-

	0x5c, // -\-

	0x5d, // -]-

	0x5e, // -^-

	0x5f, // -_-

	0x60, // -`-

	0x61, // -a-

	0x62, // -b-

	0x63, // -c-

	0x64, // -d-

	0x65, // -e-

	0x66, // -f-

	0x67, // -g-

	0x68, // -h-

	0x69, // -i-

	0x6a, // -j-

	0x6b, // -k-

	0x6c, // -l-

	0x6d, // -m-

	0x6e, // -n-

	0x6f, // -o-

	0x70, // -p-

	0x71, // -q-

	0x72, // -r-

	0x73, // -s-

	0x74, // -t-

	0x75, // -u-

	0x76, // -v-

	0x77, // -w-

	0x78, // -x-

	0x79, // -y-

	0x7a, // -z-

	0x7b, // -{-

	0x7c, // -|-

	0x7d, // -}-

	0x7e, // -~-

	0x7f, // --
};


static unsigned char Ascii_16x8_Dot[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // - -
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x38,0x00,0xFC,0x0D,  // -!-
	0xFC,0x0D,0x38,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x0E,0x00,0x1E,0x00,0x00,0x00,  // -"-
	0x00,0x00,0x1E,0x00,0x0E,0x00,0x00,0x00,

	0x20,0x02,0xF8,0x0F,0xF8,0x0F,0x20,0x02,  // -#-
	0xF8,0x0F,0xF8,0x0F,0x20,0x02,0x00,0x00,

	0x38,0x03,0x7C,0x06,0x44,0x04,0x47,0x1C,  // -$-
	0x47,0x1C,0xCC,0x07,0x98,0x03,0x00,0x00,

	0x30,0x0C,0x30,0x06,0x00,0x03,0x80,0x01,  // -%-
	0xC0,0x00,0x60,0x0C,0x30,0x0C,0x00,0x00,

	0x80,0x07,0xD8,0x0F,0x7C,0x08,0xE4,0x08,  // -&-
	0xBC,0x07,0xD8,0x0F,0x40,0x08,0x00,0x00,

	0x00,0x00,0x10,0x00,0x1E,0x00,0x0E,0x00,  // -'-
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0xF0,0x03,0xF8,0x07,  // -(-
	0x0C,0x0C,0x04,0x08,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x0C,  // -)-
	0xF8,0x07,0xF0,0x03,0x00,0x00,0x00,0x00,

	0x80,0x00,0xA0,0x02,0xE0,0x03,0xC0,0x01,  // -*-
	0xC0,0x01,0xE0,0x03,0xA0,0x02,0x80,0x00,

	0x00,0x00,0x80,0x00,0x80,0x00,0xE0,0x03,  // -+-
	0xE0,0x03,0x80,0x00,0x80,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x1E,  // -,-
	0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,

	0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,  // ---
	0x80,0x00,0x80,0x00,0x80,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,  // -.-
	0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x0C,0x00,0x06,0x00,0x03,0x80,0x01,  // -/-
	0xC0,0x00,0x60,0x00,0x30,0x00,0x00,0x00,

	0xF8,0x07,0xFC,0x0F,0x04,0x09,0xC4,0x08,  // -0-
	0x24,0x08,0xFC,0x0F,0xF8,0x07,0x00,0x00,

	0x00,0x00,0x10,0x08,0x18,0x08,0xFC,0x0F,  // -1-
	0xFC,0x0F,0x00,0x08,0x00,0x08,0x00,0x00,

	0x08,0x0E,0x0C,0x0F,0x84,0x09,0xC4,0x08,  // -2-
	0x64,0x08,0x3C,0x0C,0x18,0x0C,0x00,0x00,

	0x08,0x04,0x0C,0x0C,0x44,0x08,0x44,0x08,  // -3-
	0x44,0x08,0xFC,0x0F,0xB8,0x07,0x00,0x00,

	0xC0,0x00,0xE0,0x00,0xB0,0x00,0x98,0x08,  // -4-
	0xFC,0x0F,0xFC,0x0F,0x80,0x08,0x00,0x00,

	0x7C,0x04,0x7C,0x0C,0x44,0x08,0x44,0x08,  // -5-
	0xC4,0x08,0xC4,0x0F,0x84,0x07,0x00,0x00,

	0xF0,0x07,0xF8,0x0F,0x4C,0x08,0x44,0x08,  // -6-
	0x44,0x08,0xC0,0x0F,0x80,0x07,0x00,0x00,

	0x0C,0x00,0x0C,0x00,0x04,0x0F,0x84,0x0F,  // -7-
	0xC4,0x00,0x7C,0x00,0x3C,0x00,0x00,0x00,

	0xB8,0x07,0xFC,0x0F,0x44,0x08,0x44,0x08,  // -8-
	0x44,0x08,0xFC,0x0F,0xB8,0x07,0x00,0x00,

	0x38,0x00,0x7C,0x08,0x44,0x08,0x44,0x08,  // -9-
	0x44,0x0C,0xFC,0x07,0xF8,0x03,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x06,  // -:-
	0x30,0x06,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x08,0x30,0x0E,  // -;-
	0x30,0x06,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x80,0x00,0xC0,0x01,0x60,0x03,  // -<-
	0x30,0x06,0x18,0x0C,0x08,0x08,0x00,0x00,

	0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x02,  // -=-
	0x40,0x02,0x40,0x02,0x40,0x02,0x00,0x00,

	0x00,0x00,0x08,0x08,0x18,0x0C,0x30,0x06,  // ->-
	0x60,0x03,0xC0,0x01,0x80,0x00,0x00,0x00,

	0x18,0x00,0x1C,0x00,0x04,0x00,0xC4,0x0D,  // -?-
	0xE4,0x0D,0x3C,0x00,0x18,0x00,0x00,0x00,

	0xF0,0x07,0xF8,0x0F,0x08,0x08,0xC8,0x0B,  // -@-
	0xC8,0x0B,0xF8,0x0B,0xF0,0x01,0x00,0x00,

	0xE0,0x0F,0xF0,0x0F,0x98,0x00,0x8C,0x00,  // -A-
	0x98,0x00,0xF0,0x0F,0xE0,0x0F,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x44,0x08,  // -B-
	0x44,0x08,0xFC,0x0F,0xB8,0x07,0x00,0x00,

	0xF0,0x03,0xF8,0x07,0x0C,0x0C,0x04,0x08,  // -C-
	0x04,0x08,0x0C,0x0C,0x18,0x06,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x04,0x08,  // -D-
	0x0C,0x0C,0xF8,0x07,0xF0,0x03,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x44,0x08,  // -E-
	0xE4,0x08,0x0C,0x0C,0x1C,0x0E,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x44,0x08,  // -F-
	0xE4,0x00,0x0C,0x00,0x1C,0x00,0x00,0x00,

	0xF0,0x03,0xF8,0x07,0x0C,0x0C,0x84,0x08,  // -G-
	0x84,0x08,0x8C,0x07,0x98,0x0F,0x00,0x00,

	0xFC,0x0F,0xFC,0x0F,0x40,0x00,0x40,0x00,  // -H-
	0x40,0x00,0xFC,0x0F,0xFC,0x0F,0x00,0x00,

	0x00,0x00,0x00,0x00,0x04,0x08,0xFC,0x0F,  // -I-
	0xFC,0x0F,0x04,0x08,0x00,0x00,0x00,0x00,

	0x00,0x07,0x00,0x0F,0x00,0x08,0x04,0x08,  // -J-
	0xFC,0x0F,0xFC,0x07,0x04,0x00,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0xC0,0x00,  // -K-
	0xF0,0x01,0x3C,0x0F,0x0C,0x0E,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x04,0x08,  // -L-
	0x00,0x08,0x00,0x0C,0x00,0x0E,0x00,0x00,

	0xFC,0x0F,0xFC,0x0F,0x38,0x00,0x70,0x00,  // -M-
	0x38,0x00,0xFC,0x0F,0xFC,0x0F,0x00,0x00,

	0xFC,0x0F,0xFC,0x0F,0x38,0x00,0x70,0x00,  // -N-
	0xE0,0x00,0xFC,0x0F,0xFC,0x0F,0x00,0x00,

	0xF0,0x03,0xF8,0x07,0x0C,0x0C,0x04,0x08,  // -O-
	0x0C,0x0C,0xF8,0x07,0xF0,0x03,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x44,0x08,  // -P-
	0x44,0x00,0x7C,0x00,0x38,0x00,0x00,0x00,

	0xF8,0x07,0xFC,0x0F,0x04,0x08,0x04,0x0E,  // -Q-
	0x04,0x3C,0xFC,0x3F,0xF8,0x27,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x44,0x00,  // -R-
	0xC4,0x00,0xFC,0x0F,0x38,0x0F,0x00,0x00,

	0x18,0x06,0x3C,0x0E,0x64,0x08,0x44,0x08,  // -S-
	0xC4,0x08,0x9C,0x0F,0x18,0x07,0x00,0x00,

	0x00,0x00,0x1C,0x00,0x0C,0x08,0xFC,0x0F,  // -T-
	0xFC,0x0F,0x0C,0x08,0x1C,0x00,0x00,0x00,

	0xFC,0x07,0xFC,0x0F,0x00,0x08,0x00,0x08,  // -U-
	0x00,0x08,0xFC,0x0F,0xFC,0x07,0x00,0x00,

	0xFC,0x01,0xFC,0x03,0x00,0x06,0x00,0x0C,  // -V-
	0x00,0x06,0xFC,0x03,0xFC,0x01,0x00,0x00,

	0xFC,0x03,0xFC,0x0F,0x00,0x0E,0x80,0x03,  // -W-
	0x00,0x0E,0xFC,0x0F,0xFC,0x03,0x00,0x00,

	0x0C,0x0C,0x3C,0x0F,0xF0,0x03,0xC0,0x00,  // -X-
	0xF0,0x03,0x3C,0x0F,0x0C,0x0C,0x00,0x00,

	0x00,0x00,0x3C,0x00,0x7C,0x08,0xC0,0x0F,  // -Y-
	0xC0,0x0F,0x7C,0x08,0x3C,0x00,0x00,0x00,

	0x1C,0x0E,0x0C,0x0F,0x84,0x09,0xC4,0x08,  // -Z-
	0x64,0x08,0x3C,0x0C,0x1C,0x0E,0x00,0x00,

	0x00,0x00,0x00,0x00,0xFC,0x0F,0xFC,0x0F,  // -[-
	0x04,0x08,0x04,0x08,0x00,0x00,0x00,0x00,

	0x38,0x00,0x70,0x00,0xE0,0x00,0xC0,0x01,  // -\-
	0x80,0x03,0x00,0x07,0x00,0x0E,0x00,0x00,

	0x00,0x00,0x00,0x00,0x04,0x08,0x04,0x08,  // -]-
	0xFC,0x0F,0xFC,0x0F,0x00,0x00,0x00,0x00,

	0x08,0x00,0x0C,0x00,0x06,0x00,0x03,0x00,  // -^-
	0x06,0x00,0x0C,0x00,0x08,0x00,0x00,0x00,

	0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,  // -_-
	0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,

	0x00,0x00,0x00,0x00,0x03,0x00,0x07,0x00,  // -`-
	0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x07,0xA0,0x0F,0xA0,0x08,0xA0,0x08,  // -a-
	0xE0,0x07,0xC0,0x0F,0x00,0x08,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x07,0x20,0x08,  // -b-
	0x60,0x08,0xC0,0x0F,0x80,0x07,0x00,0x00,

	0xC0,0x07,0xE0,0x0F,0x20,0x08,0x20,0x08,  // -c-
	0x20,0x08,0x60,0x0C,0x40,0x04,0x00,0x00,

	0x80,0x07,0xC0,0x0F,0x60,0x08,0x24,0x08,  // -d-
	0xFC,0x07,0xFC,0x0F,0x00,0x08,0x00,0x00,

	0xC0,0x07,0xE0,0x0F,0xA0,0x08,0xA0,0x08,  // -e-
	0xA0,0x08,0xE0,0x0C,0xC0,0x04,0x00,0x00,

	0x40,0x08,0xF8,0x0F,0xFC,0x0F,0x44,0x08,  // -f-
	0x0C,0x00,0x18,0x00,0x00,0x00,0x00,0x00,

	0xC0,0x27,0xE0,0x6F,0x20,0x48,0x20,0x48,  // -g-
	0xC0,0x7F,0xE0,0x3F,0x20,0x00,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x40,0x00,  // -h-
	0x20,0x00,0xE0,0x0F,0xC0,0x0F,0x00,0x00,

	0x00,0x00,0x00,0x00,0x20,0x08,0xEC,0x0F,  // -i-
	0xEC,0x0F,0x00,0x08,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x30,0x00,0x70,0x00,0x40,  // -j-
	0x20,0x40,0xEC,0x7F,0xEC,0x3F,0x00,0x00,

	0x04,0x08,0xFC,0x0F,0xFC,0x0F,0x80,0x01,  // -k-
	0xC0,0x03,0x60,0x0E,0x20,0x0C,0x00,0x00,

	0x00,0x00,0x00,0x00,0x04,0x08,0xFC,0x0F,  // -l-
	0xFC,0x0F,0x00,0x08,0x00,0x00,0x00,0x00,

	0xE0,0x0F,0xE0,0x0F,0x60,0x00,0xC0,0x0F,  // -m-
	0x60,0x00,0xE0,0x0F,0xC0,0x0F,0x00,0x00,

	0x20,0x00,0xE0,0x0F,0xC0,0x0F,0x20,0x00,  // -n-
	0x20,0x00,0xE0,0x0F,0xC0,0x0F,0x00,0x00,

	0xC0,0x07,0xE0,0x0F,0x20,0x08,0x20,0x08,  // -o-
	0x20,0x08,0xE0,0x0F,0xC0,0x07,0x00,0x00,

	0x20,0x40,0xE0,0x7F,0xC0,0x7F,0x20,0x48,  // -p-
	0x20,0x08,0xE0,0x0F,0xC0,0x07,0x00,0x00,

	0xC0,0x07,0xE0,0x0F,0x20,0x08,0x20,0x48,  // -q-
	0xC0,0x7F,0xE0,0x7F,0x20,0x40,0x00,0x00,

	0x20,0x08,0xE0,0x0F,0xC0,0x0F,0x60,0x08,  // -r-
	0x20,0x00,0x60,0x00,0xC0,0x00,0x00,0x00,

	0x40,0x04,0xE0,0x0C,0xA0,0x09,0x20,0x09,  // -s-
	0x20,0x0B,0x60,0x0E,0x40,0x04,0x00,0x00,

	0x20,0x00,0x20,0x00,0xF8,0x07,0xFC,0x0F,  // -t-
	0x20,0x08,0x20,0x0C,0x00,0x04,0x00,0x00,

	0xE0,0x07,0xE0,0x0F,0x00,0x08,0x00,0x08,  // -u-
	0xE0,0x07,0xE0,0x0F,0x00,0x08,0x00,0x00,

	0x00,0x00,0xE0,0x03,0xE0,0x07,0x00,0x0C,  // -v-
	0x00,0x0C,0xE0,0x07,0xE0,0x03,0x00,0x00,

	0xE0,0x07,0xE0,0x0F,0x00,0x0C,0x00,0x07,  // -w-
	0x00,0x0C,0xE0,0x0F,0xE0,0x07,0x00,0x00,

	0x20,0x08,0x60,0x0C,0xC0,0x07,0x80,0x03,  // -x-
	0xC0,0x07,0x60,0x0C,0x20,0x08,0x00,0x00,

	0xE0,0x47,0xE0,0x4F,0x00,0x48,0x00,0x48,  // -y-
	0x00,0x68,0xE0,0x3F,0xE0,0x1F,0x00,0x00,

	0x60,0x0C,0x60,0x0E,0x20,0x0B,0xA0,0x09,  // -z-
	0xE0,0x08,0x60,0x0C,0x20,0x0C,0x00,0x00,

	0x00,0x00,0x40,0x00,0x40,0x00,0xF8,0x07,  // -{-
	0xBC,0x0F,0x04,0x08,0x04,0x08,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0xBC,0x0F,  // -|-
	0xBC,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x04,0x08,0x04,0x08,0xBC,0x0F,  // -}-
	0xF8,0x07,0x40,0x00,0x40,0x00,0x00,0x00,

	0x08,0x00,0x0C,0x00,0x04,0x00,0x0C,0x00,  // -~-
	0x08,0x00,0x0C,0x00,0x04,0x00,0x00,0x00,

	0x80,0x07,0xC0,0x07,0x60,0x04,0x30,0x04,  // --
	0x60,0x04,0xC0,0x07,0x80,0x07,0x00,0x00,
};


static unsigned char Ascii_8x5_Dot[] =
{
	0x00,0x00,0x00,0x00,0x00, // - -

	0x00,0x00,0x5F,0x00,0x00, // -!-

	0x00,0x07,0x00,0x07,0x00, // -"-

	0x14,0x7F,0x14,0x7F,0x14, // -#-

	0x24,0x2E,0x7B,0x2A,0x12, // -$-

	0x23,0x13,0x08,0x64,0x62, // -%-

	0x36,0x49,0x56,0x20,0x50, // -&-

	0x00,0x04,0x03,0x01,0x00, // -'-

	0x00,0x1C,0x22,0x41,0x00, // -(-

	0x00,0x41,0x22,0x1C,0x00, // -)-

	0x22,0x14,0x7F,0x14,0x22, // -*-

	0x08,0x08,0x7F,0x08,0x08, // -+-

	0x40,0x30,0x10,0x00,0x00, // -,-

	0x08,0x08,0x08,0x08,0x08, // ---

	0x00,0x60,0x60,0x00,0x00, // -.-

	0x20,0x10,0x08,0x04,0x02, // -/-

	0x3E,0x51,0x49,0x45,0x3E, // -0-

	0x00,0x42,0x7F,0x40,0x00, // -1-

	0x62,0x51,0x49,0x49,0x46, // -2-

	0x21,0x41,0x49,0x4D,0x33, // -3-

	0x18,0x14,0x12,0x7F,0x10, // -4-

	0x27,0x45,0x45,0x45,0x39, // -5-

	0x3C,0x4A,0x49,0x49,0x31, // -6-

	0x01,0x71,0x09,0x05,0x03, // -7-

	0x36,0x49,0x49,0x49,0x36, // -8-

	0x46,0x49,0x49,0x29,0x1E, // -9-

	0x00,0x36,0x36,0x00,0x00, // -:-

	0x40,0x36,0x36,0x00,0x00, // -;-

	0x08,0x14,0x22,0x41,0x00, // -<-

	0x14,0x14,0x14,0x14,0x14, // -=-

	0x00,0x41,0x22,0x14,0x08, // ->-

	0x02,0x01,0x59,0x05,0x02, // -?-

	0x3E,0x41,0x5D,0x55,0x5E, // -@-

	0x7C,0x12,0x11,0x12,0x7C, // -A-

	0x7F,0x49,0x49,0x49,0x36, // -B-

	0x3E,0x41,0x41,0x41,0x22, // -C-

	0x7F,0x41,0x41,0x41,0x3E, // -D-

	0x7F,0x49,0x49,0x49,0x41, // -E-

	0x7F,0x09,0x09,0x09,0x01, // -F-

	0x3E,0x41,0x51,0x51,0x72, // -G-

	0x7F,0x08,0x08,0x08,0x7F, // -H-

	0x00,0x41,0x7F,0x41,0x00, // -I-

	0x20,0x40,0x41,0x3F,0x01, // -J-

	0x7F,0x08,0x14,0x22,0x41, // -K-

	0x7F,0x40,0x40,0x40,0x40, // -L-

	0x7F,0x02,0x0C,0x02,0x7F, // -M-

	0x7F,0x04,0x08,0x10,0x7F, // -N-

	0x3E,0x41,0x41,0x41,0x3E, // -O-

	0x7F,0x09,0x09,0x09,0x06, // -P-

	0x3E,0x41,0x51,0x21,0x5E, // -Q-

	0x7F,0x09,0x19,0x29,0x46, // -R-

	0x26,0x49,0x49,0x49,0x32, // -S-

	0x01,0x01,0x7F,0x01,0x01, // -T-

	0x3F,0x40,0x40,0x40,0x3F, // -U-

	0x1F,0x20,0x40,0x20,0x1F, // -V-

	0x7F,0x20,0x18,0x20,0x7F, // -W-

	0x63,0x14,0x08,0x14,0x63, // -X-

	0x03,0x04,0x78,0x04,0x03, // -Y-

	0x61,0x51,0x49,0x45,0x43, // -Z-

	0x7F,0x7F,0x41,0x41,0x00, // -[-

	0x02,0x04,0x08,0x10,0x20, // -\-

	0x00,0x41,0x41,0x7F,0x7F, // -]-

	0x04,0x02,0x7F,0x02,0x04, // -^-

	0x08,0x1C,0x2A,0x08,0x08, // -_-

	0x00,0x00,0x01,0x02,0x04, // -`-

	0x24,0x54,0x54,0x38,0x40, // -a-

	0x7F,0x28,0x44,0x44,0x38, // -b-

	0x38,0x44,0x44,0x44,0x08, // -c-

	0x38,0x44,0x44,0x28,0x7F, // -d-

	0x38,0x54,0x54,0x54,0x08, // -e-

	0x08,0x7E,0x09,0x09,0x02, // -f-

	0x98,0xA4,0xA4,0xA4,0x78, // -g-

	0x7F,0x08,0x04,0x04,0x78, // -h-

	0x00,0x00,0x79,0x00,0x00, // -i-

	0x00,0x80,0x88,0x79,0x00, // -j-

	0x7F,0x10,0x28,0x44,0x40, // -k-

	0x00,0x41,0x7F,0x40,0x00, // -l-

	0x78,0x04,0x78,0x04,0x78, // -m-

	0x04,0x78,0x04,0x04,0x78, // -n-

	0x38,0x44,0x44,0x44,0x38, // -o-

	0xFC,0x24,0x24,0x24,0x18, // -p-

	0x18,0x24,0x24,0x24,0xFC, // -q-

	0x04,0x78,0x04,0x04,0x08, // -r-

	0x48,0x54,0x54,0x54,0x24, // -s-

	0x04,0x3F,0x44,0x44,0x24, // -t-

	0x3C,0x40,0x40,0x3C,0x40, // -u-

	0x1C,0x20,0x40,0x20,0x1C, // -v-

	0x3C,0x40,0x3C,0x40,0x3C, // -w-

	0x44,0x28,0x10,0x28,0x44, // -x-

	0x9C,0xA0,0xA0,0x90,0x7C, // -y-

	0x44,0x64,0x54,0x4C,0x44, // -z-

	0x08,0x36,0x41,0x00,0x00, // -{-

	0x00,0x00,0x77,0x00,0x00, // -|-

	0x00,0x00,0x41,0x36,0x08, // -}-

	0x08,0x04,0x08,0x10,0x08, // -~-

	0x55,0x2A,0x55,0x2A,0x55, // --
};
 
static Font_Data g_font_data;
Font_Data *get_font_data_by_char(E_LANGUAGE language, FONT_TYPE ftype, char c)
{ 
	unsigned int i;
	unsigned char *font_arry = NULL;
	unsigned int font_data_len = 0;
	if(language == ENGLISH || language == BAHASA){
		switch(ftype){
			case FONT_TYPE_16X8:
					font_arry = Ascii_16x8_Dot;
					font_data_len = 16;
					break;
						
			case FONT_TYPE_8X5:
					font_arry = Ascii_8x5_Dot;
					font_data_len = 5;
					break;
			default:
				return NULL;
		}
		for(i = 0; i < sizeof(Ascii_index)/sizeof(Ascii_index[0]); i++){
			if(Ascii_index[i] ==(unsigned char)c){
				memcpy(g_font_data.data,&font_arry[font_data_len*i],font_data_len);
				g_font_data.len = font_data_len;
				return &g_font_data;
			}
		}
		return NULL;
	}
	return NULL;
}