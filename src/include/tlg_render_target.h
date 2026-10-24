/* A target object reached through +0x68 of its owner, with two rows at
 * +0xb90 and +0xba0 and two source rows at +0x13c0 and +0x13e0. Three
 * matched functions in src/game/unknown/ write to it; its real name is not
 * known. derived names throughout. */
#ifndef TLG_RENDER_TARGET_H
#define TLG_RENDER_TARGET_H

#include "tlg_types.h"
#include "tlg_simd.h"

struct Target779070 {
    u8 unknown0[0xb90];
    Vec4 rowB;
    Vec4 rowA;
    u8 unknownBB0[0x13c0 - 0xbb0];
    Vec4 sourceA;
    Vec4 unknown13d0;
    Vec4 sourceB;
};

struct Owner779070 {
    u8 unknown0[0x68];
    Target779070 *target;
};

struct Source779070 {
    u8 unknown0[0x80];
    Vec4 a;
    Vec4 b;
};

#endif
