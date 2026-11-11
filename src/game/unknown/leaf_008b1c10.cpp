/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the call slot (slot 2) of the callable holder whose vtable is
 * at 0x16afd70 (leaf_008b1c90.cpp): the object is not read. When the parity of
 * the int at +0x4c of the record the pointer at +0x100 of the object at
 * 0x57c9390 holds differs from the parity of that int plus the int the
 * argument points at, the int is moved to the value of the other parity in
 * its pair ((value - 1) / 2 * 2, plus 1 - parity, plus 1: InstCombine turns
 * the sum into `and -2; or; xor 1; inc`, the base's). The meaning is not
 * traced. */
struct Object008b1c10; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x4c];
    int unknown4c;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: list-ilp order and greedy's assignment: the arithmetic is the base's, but the build loads *step before the record at +0x100 (the base after it, into eax once rax is free) and so copies the value for its parity test into esi where the base uses edi and `lea esi, [rdx - 1]`
void FUN_008b1c10(Object008b1c10 *, const int *step) /* derived name */
{
    Member057c9390_100 *record = D_57c9390->unknown100;
    int parity = (*step + record->unknown4c) & 1;
    if ((record->unknown4c & 1) != parity)
        record->unknown4c = (record->unknown4c - 1) / 2 * 2 + (1 - parity) + 1;
}
