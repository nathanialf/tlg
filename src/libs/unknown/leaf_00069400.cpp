/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: initializes a 32-bit word to 0xffffff00 (low byte clear,
 * the rest set). Its one caller, the constructor FUN_00048b20 of a large
 * object, runs it on the word at +0x70c (0x48d4e) among the clears of its
 * other fields. Class unknown. */
struct Word00069400 /* derived name */
{
    u32 value; /* derived name */
};

void FUN_00069400(Word00069400 *self) /* derived name */
{
    self->value = 0xffffff00;
}
