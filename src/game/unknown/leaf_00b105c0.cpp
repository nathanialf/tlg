/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback whose address FUN_00b10ec0 takes (lea at
 * 0xb11d22): while the flag at 0x583260c is set (FUN_00b10510 and
 * FUN_00b127e0 set and clear it), answers whether the object the pointer at
 * 0x58325c8 holds has the int at +0x20a0 set and either of bits 6 and 7 of
 * its byte at +0x20a4, with the int at +0x67c of the object at 0x58325d8 at
 * 15; when it does not, the flag is cleared. Its arguments are not read and
 * not traced. The fields' meaning is not traced. */
struct Object058325c8 { /* derived name */
    u8 unknown0[0x20a0];
    int unknown20a0; /* +0x20a0 */
    u8 unknown20a4;  /* +0x20a4 */
};

struct Object058325d8_67c { /* derived name: the view of 0x58325d8's object here */
    u8 unknown0[0x67c];
    int unknown67c; /* +0x67c */
};

extern bool D_583260c;
extern Object058325c8 *D_58325c8;
extern Object058325d8_67c *D_58325d8;

// NONMATCHING: the flag's test, the base `movzx eax, byte; and eax, 1` (imm32)
// `; cmp eax, 1`, is D46's form of a static bool GlobalOpt shrank to i1: the flag
// is a static of the file of its writers FUN_00b10510 and FUN_00b127e0 (unwritten;
// with this reader alone GlobalOpt folds it to false). Parked with them.
bool FUN_00b105c0() /* derived name */
{
    if (D_583260c) {
        if (D_58325c8->unknown20a0 != 0 && D_58325d8->unknown67c == 15 &&
            (D_58325c8->unknown20a4 & 0xc0) != 0)
            return true;
        D_583260c = false;
    }
    return false;
}
