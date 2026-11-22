/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived name: the count of components of each surface format (-1 for the
 * formats with none defined); FUN_012fd3e0 reads it too */
extern const int D_15252d0[61];
const int D_15252d0[61] = {
#include "gen/D_15252d0.inc"
};

/* derived name: a data format of a surface format, a texture channel type
 * and four channel selects */
static inline u32 dataFormat012fd020(u32 format, u32 type, u32 x, u32 y, u32 z, u32 w)
{
    return (type & 0xf) << 8 | (format & 0xff) | (x & 7) << 12 | (y & 7) << 15 | (z & 7) << 18 |
           (w & 7) << 21;
}

/* derived name: the render target's data format of its format, channel type
 * and channel order (0 standard, 1 alternate, 2 reversed, 3 alternate
 * reversed): the channel selects (0 and 1 the constants, 4 to 7 the
 * components x to w) placed for the format's count of components; the
 * render target's sRGB type (6) is the texture's (9). Its body in the module
 * lets the link know it reads no memory it does not own (its callers' fields
 * are read once around it). */
int FUN_012fd020(u32 format, u32 channelType, u32 channelOrder)
{
    /* the channels declared from w to x: the order the join block holds them */
    u32 w = 1;
    u32 z = 0;
    u32 y = 0;
    u32 x = 0;
    int count = D_15252d0[format];
    if (count == 1) {
        if (channelOrder == 0) {
            x = 4;
        } else if (channelOrder == 1) {
            y = 4;
        } else if (channelOrder == 2) {
            z = 4;
        } else if (channelOrder == 3) {
            w = 4;
        }
    } else if (count == 2) {
        if (channelOrder == 0) {
            x = 4;
            y = 5;
        } else if (channelOrder == 1) {
            x = 4;
            w = 5;
        } else if (channelOrder == 2) {
            x = 5;
            y = 4;
        } else if (channelOrder == 3) {
            x = 5;
            w = 4;
        }
    } else if (count == 3) {
        if (channelOrder == 0) {
            x = 4;
            y = 5;
            z = 6;
        } else if (channelOrder == 1) {
            x = 4;
            y = 5;
            w = 6;
        } else if (channelOrder == 2) {
            x = 6;
            y = 5;
            z = 4;
        } else if (channelOrder == 3) {
            x = 6;
            y = 5;
            w = 4;
        }
    } else if (count == 4) {
        if (channelOrder == 0) {
            x = 4;
            y = 5;
            z = 6;
            w = 7;
        } else if (channelOrder == 1) {
            x = 6;
            y = 5;
            z = 4;
            w = 7;
        } else if (channelOrder == 2) {
            x = 7;
            y = 6;
            z = 5;
            w = 4;
        } else if (channelOrder == 3) {
            x = 5;
            y = 6;
            z = 7;
            w = 4;
        }
    }
    return dataFormat012fd020(format, channelType == 6 ? 9 : channelType, x, y, z, w);
}
