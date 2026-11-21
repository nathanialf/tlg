/* src/include/tlg_game_object058325c8.h: the objects the pointers at
 * 0x58325c8 and 0x58325d8 hold, as the condition callbacks FUN_00b10ec0
 * registers read them (game region; docs/TARGETS.md). Every name here is
 * derived; the objects' other fields and their meaning are not traced. */
#ifndef TLG_GAME_OBJECT058325C8_H
#define TLG_GAME_OBJECT058325C8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array.h"

/* derived names: the object at 0x58325c8 */
struct Object058325c8 { /* derived name */
    u8 unknown0[0x18a4];
    int unknown18a4; /* +0x18a4: tested against zero (0xb10bbf) */
    u8 unknown18a8[0x7f8];
    int unknown20a0; /* +0x20a0 */
    u8 unknown20a4;  /* +0x20a4: bits 6 and 7 tested (FUN_00b105c0) */
    u8 unknown20a5[0x853];
    /* +0x28f8: names the callbacks look their own up in (the block at
     * +0x28f8, the count at +0x2900: `mov eax, [rbx+0x2900]; mov rcx,
     * [rbx+0x28f8]; cmp edx, [rcx+rsi*4]` at 0xb10ab8) */
    Array05943280<Name> names28f8;
};

/* derived names: the object at 0x58325d8 */
struct Object058325d8 { /* derived name */
    u8 unknown0[0x67c];
    int unknown67c; /* +0x67c: compared with 5 (0xb10a3e) and 15 (FUN_00b105c0) */
    u8 unknown680[0x1598];
    int unknown1c18; /* +0x1c18: compared with 3 (0xb10c2e) and 8 (FUN_00b10250) */
};

extern Object058325c8 *D_58325c8;
extern Object058325d8 *D_58325d8;

#endif
