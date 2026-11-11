/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 6 of the vtable at 0x16abea0 (its pointer at 0x16abee0;
 * stored by FUN_006187d0 and FUN_00618980): 1
 * when the name at +0x30 of the object has a record (the pointer at +0x18 of
 * its entry in the name table) and either that record's flag 4 at +0x16 is
 * set or this thread's flag at 0x16dc098 is, else 0. The record and the slot's
 * meaning are not traced. */
struct Record00618b00 { /* derived name */
    u8 unknown0[0x16];
    u8 unknown16; /* +0x16: flags */
};

/* this thread's flag: 1,158 game sites reach it through its GOT slot
 * 0x16d80f0, from 0x1b1931 on, so it is no file's local. */
extern __thread bool D_16dc098; /* derived name */

struct Object00618b00 { /* derived name */
    u8 unknown0[0x30];
    Name unknown30; /* +0x30 */
};

// NONMATCHING: the base reads the thread's flag only after the record's flag
// test fails and tests it `movzx; and 1; cmp 1` (the shape at most of the
// flag's 1,158 sites); here the read is speculated and or-ed with the record's
// flag. A definition in this file gives the same bytes; a static one is
// folded to false (nothing in the file writes it).
int FUN_00618b00(const Object00618b00 *self) /* derived name */
{
    const Record00618b00 *record =
        static_cast<const Record00618b00 *>(D_17ac870[self->unknown30.index].record18);
    if (record) {
        if (record->unknown16 & 4)
            return 1;
        if (D_16dc098)
            return 1;
    }
    return 0;
}
