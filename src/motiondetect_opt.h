/*
 *  motiondetect_opt.h
 *
 *  Copyright (C) Georg Martius - February 2011
 *   georg dot martius at web dot de  
 *  Copyright (C) Alexey Osipov - Jule 2011
 *   simba at lerlan dot ru
 *   speed optimizations (threshold, spiral, SSE, asm)
 *
 *  This file is part of vid.stab video stabilization library
 *      
 *  vid.stab is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License,
 *   WITH THE RESTRICTION for NONCOMMERICIAL USAGE see below, 
 *  as published by the Free Software Foundation; either version 2, or 
 *  (at your option) any later version. 
 * 
 *  vid.stab is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *   
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
 *
 *  This work is licensed under the Creative Commons         
 *  Attribution-NonCommercial-ShareAlike 2.5 License. To view a copy of   
 *  this license, visit http://creativecommons.org/licenses/by-nc-sa/2.5/ 
 *  or send a letter to Creative Commons, 543 Howard Street, 5th Floor,   
 *  San Francisco, California, 94105, USA.                                
 *  This EXCLUDES COMMERCIAL USAGE
 *
 */

#ifndef MOTIONDETECT_OPT_H
#define MOTIONDETECT_OPT_H

#include "motiondetect.h"

#ifdef USE_SSE2_ASM //enable SSE2 inline asm code
#define compareSubImg compareSubImg_thr_sse2_asm
#elif defined(USE_SSE2)      //enable SSE2 code
#define compareSubImg compareSubImg_thr_sse2
#elif defined(USE_ORC)
#define compareSubImg compareSubImg_thr_orc
#else
#define compareSubImg compareSubImg_thr
#endif

#ifdef USE_SSE2
double contrastSubImg1_SSE(unsigned char* const I, const Field* field,
                           int width, int height);
#endif

#ifdef USE_ORC
double contrastSubImg_variance_orc(unsigned char* const I, const Field* field,
                          int width, int height);
double contrastSubImg_variance_C(unsigned char* const I, const Field* field,
                        int width, int height);

#endif

#ifdef USE_ORC
unsigned int compareSubImg_orc(unsigned char* const I1, unsigned char* const I2,
			                   const Field* field, int width, int height,
			                   int bytesPerPixel, int d_x, int d_y,
			                   unsigned int threshold);


unsigned int compareSubImg_thr_orc(unsigned char* const I1, unsigned char* const I2,
                                   const Field* field,
                                   int width, int height, int bytesPerPixel,
                                   int d_x, int d_y, unsigned int threshold);
#endif

#ifdef USE_SSE2
unsigned int compareSubImg_thr_sse2(unsigned char* const I1, unsigned char* const I2,
                                const Field* field, int width, int height,
                                int bytesPerPixel,
                                int d_x, int d_y, unsigned int threshold);
#endif

#ifdef USE_SSE2_ASM
unsigned int compareSubImg_thr_sse2_asm(unsigned char* const I1, unsigned char* const I2,
                                        const Field* field, int width, int height,
                                        int bytesPerPixel,
                                        int d_x, int d_y, unsigned int threshold);
#endif

#endif  /* MOTIONDETECT_OPT_H */

/*
 * Local variables:
 *   c-file-style: "stroustrup"
 *   c-file-offsets: ((case-label . *) (statement-case-intro . *))
 *   indent-tabs-mode: nil
 * End:
 *
 * vim: expandtab shiftwidth=4:
 */