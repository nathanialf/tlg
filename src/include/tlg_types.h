/* Shared fixed-width types for the rebuilt sources. The build is freestanding
 * (-nostdinc): nothing from a host libc is included. */
#ifndef TLG_TYPES_H
#define TLG_TYPES_H

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;
typedef float f32;
typedef double f64;

#endif
