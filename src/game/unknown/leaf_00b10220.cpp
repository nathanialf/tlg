/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: two conditions FUN_00b10ec0 registers in its table (the
 * function at +0x8 of an entry, 0 beside it at +0x10: lea at 0xb11aef and
 * 0xb11ba6), taking no parameters and returning a bool in al, and the flag at
 * 0x58325eb they share. FUN_00b10220 sets the flag and returns true when the
 * ints at +0x54c and +0x608 of the object the pointer at 0x58325c0 holds are
 * both nonzero; FUN_00b10250, while the flag is set, returns true when the int
 * at +0x1c18 of the object the pointer at 0x58325d8 holds is 8 and otherwise
 * clears the flag. The flag is this file's: only these two and FUN_00b12xxx's
 * clear (0xb1294f) touch it, and the program stores only 0 and 1, so GlobalOpt
 * shrinks it to a bool (the base's `movzx eax, byte; and eax, 1; cmp eax, 1`).
 * The pointers 0x58325c0 and 0x58325d8 are read by many functions of the
 * region (FUN_00b0fcb0 sets 0x58325c0 with cmpxchg) and are declared. The
 * objects' other fields are not traced. */
struct Object058325c0 { /* derived name */
    u8 unknown0[0x54c];
    int unknown54c;
    u8 unknown550[0xb8];
    int unknown608;
};

struct Object058325d8 { /* derived name */
    u8 unknown0[0x1c18];
    int unknown1c18;
};

extern Object058325c0 *D_58325c0;
extern Object058325d8 *D_58325d8;

static bool D_58325eb;

bool FUN_00b10220() /* derived name */
{
    if (D_58325c0->unknown54c == 0)
        return false;
    if (D_58325c0->unknown608 == 0)
        return false;
    D_58325eb = true;
    return true;
}

bool FUN_00b10250() /* derived name */
{
    if (D_58325eb) {
        if (D_58325d8->unknown1c18 == 8)
            return true;
        D_58325eb = false;
    }
    return false;
}
