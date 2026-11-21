/* src/include/tlg_game_object0042dbe0.h: the objects FUN_0042dbe0 and the
 * slots that run its body work on (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT0042DBE0_H
#define TLG_GAME_OBJECT0042DBE0_H

#include "tlg_types.h"
#include "tlg_game_name.h"

struct Source0042dbe0; /* derived name */

struct Target0042dbe0 /* derived name */
{
    u8 unknown0[0x100];
    u8 flags100; /* +0x100 */
};

struct Position0042dbe0 { /* derived name */
    int x;                /* copied whole */
    float y;              /* raised by 0.5 for the debug text */
    int z;                /* copied whole */
    int w;                /* copied whole */
};

struct Object0042dbe0 /* derived name */
{
    u8 unknown0[0x28];
    Source0042dbe0 *unknown28; /* +0x28 */
    u8 unknown30[0x20];
    Position0042dbe0 position; /* +0x50 */
    u8 unknown60[0xa8];
    Target0042dbe0 *unknown108; /* +0x108 */
    Name
        animation; /* +0x110: the running animation's name (derived name, after FUN_0050b280's text) */
    u8 unknown114[0x20];
    int unknown134; /* +0x134: FUN_0050b280 draws the name only when set */
    u8 unknown138[0xa4];
    float jumpSpeed; /* +0x1dc: derived name, after its debug text */
};

void FUN_002054d0(Target0042dbe0 **slot, Source0042dbe0 *source, int flag); /* derived name */

/* the slot at +0x108 filled from the pointer at +0x28 (leaf_0042dbe0.cpp) */
void FUN_0042dbe0(Object0042dbe0 *self); /* derived name */

/* derived names: a debug text's colour and scale (FUN_00205720) */
struct TextStyle0042dbe0 { /* derived name */
    u32 colour;
    float scale;
};

void FUN_00205720(const Position0042dbe0 *position, const TextStyle0042dbe0 *style, int flag,
                  const char *format, ...); /* derived name */

#endif
