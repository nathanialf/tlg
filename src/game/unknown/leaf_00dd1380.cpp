/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtables at 0x16bba90, 0x16bc170 and 0x16d2818
 * (their pointers at 0x16bbad8, 0x16bc1b8, 0x16d2860), whose slot 11 is
 * FUN_00dd1730: calls FUN_013bfaf0 on the object with the pointer at +0x10
 * of its argument; then the pointer at +0x18, when set, goes with its low
 * bit cleared to FUN_013bf9a0 if that bit is set, else to FUN_013bfaf0; last
 * the pointer at +0x8 to FUN_013bfc40, as a tail call. The record, the
 * pointers' targets and the return types are not traced. Class and method
 * unknown. */
struct Object00dd1730; /* derived name */
struct Target00dd1730; /* derived name */
struct Target00dd1380; /* derived name: the target of a set low bit */
struct Target013bfc40; /* derived name */

struct Argument00dd1380 { /* derived name */
    u8 unknown0[0x8];
    Target013bfc40 *unknown8;  /* +0x8 */
    Target00dd1730 *unknown10; /* +0x10 */
    u64 unknown18;             /* +0x18: a pointer, its low bit the kind */
};

void FUN_013bfaf0(Object00dd1730 *self, Target00dd1730 *value); /* derived name */
void FUN_013bf9a0(Object00dd1730 *self, Target00dd1380 *value); /* derived name */
void FUN_013bfc40(Object00dd1730 *self, Target013bfc40 *value); /* derived name */

void FUN_00dd1380(Object00dd1730 *self, const Argument00dd1380 *argument) /* derived name */
{
    FUN_013bfaf0(self, argument->unknown10);
    if (u64 value = argument->unknown18) {
        if (value & 1)
            FUN_013bf9a0(self, reinterpret_cast<Target00dd1380 *>(value & ~u64(1)));
        else
            FUN_013bfaf0(self, reinterpret_cast<Target00dd1730 *>(value));
    }
    FUN_013bfc40(self, argument->unknown8);
}
