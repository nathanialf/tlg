/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: what the object at 0x57c9390 holds at +0x40, seen from
 * here: a current record at +0x1a0 with its name at +0x68 */
struct Record005b0500 { /* derived name */
    u8 unknown0[0x68];
    Name name; /* +0x68 */
};

struct Holder005b0500 { /* derived name */
    u8 unknown0[0x1a0];
    Record005b0500 *current; /* +0x1a0 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x40];
    Holder005b0500 *unknown40; /* +0x40 */
};

extern Object057c9390 *D_57c9390;
extern const char D_1585aa2[17]; /* "GestureGazeTrico" */

/* derived names: slot 17 of the vtable at 0x16abb00 and slot 5 of the one
 * at 0x16cb1a0 (both stored by FUN_005b05b0 and FUN_005b14b0); the object
 * is not read. Whether the current record at 0x57c9390's +0x40 is named
 * "GestureGazeTrico" (a static of the function, looked up once, not
 * interned). */
// NONMATCHING: 39/42, 157 bytes against 164: the base materializes the result as an int
// (`mov eax, 1` before the compare, `xor eax, eax` in the block every failing path joins);
// returning bool gives that block structure with `mov al, 1`; returning int (1 and 0, or a
// bool local) folds the two null tests' zeros into the return (`xor eax, eax` before them).
// Round 560C, link-stage IR cut and compiled alone: the same IR returning i32 makes the entry's 0
// (the int form above); returning i32 with every failure (both null tests and the compare)
// branching to one block of 0, the return's phi [0, that block], [1, the compare], is equal. The
// unit's JumpThreading threads the null tests' edges past that block (`.thread`, `.thread4`); a
// source form that keeps it is not found.
bool FUN_005b0500(void *) /* derived name */
{
    if (Holder005b0500 *holder = D_57c9390->unknown40) {
        if (Record005b0500 *current = holder->current) {
            static Name D_57fd4f8(D_1585aa2, false);
            if (current->name == D_57fd4f8)
                return true;
        }
    }
    return false;
}
