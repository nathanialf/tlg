/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the span at +0x58 (a pointer) and +0x60 (an int) of its
 * second argument from the block the pointer at +0x28 holds and the int at
 * +0x30: the block's address plus the offset at its +0x8 and the int less that
 * offset, both cleared first and left so when the block is null or the int 0.
 * Slot 1 of the vtable at 0x16b9758 (its pointer at 0x16b9770; no constructor
 * stores it), its slot 0 the empty method FUN_001af750. The object itself is
 * not read. The block's other fields are not traced. */
struct Object00cef1b0; /* derived name */

struct Block00cef1b0 { /* derived name */
    u8 unknown0[8];
    unsigned unknown8; /* +0x8: the offset of the data */
};

struct Argument00cef1b0 { /* derived name */
    u8 unknown0[0x28];
    Block00cef1b0 *unknown28;
    int unknown30;
    u8 unknown34[0x24];
    u8 *unknown58;
    int unknown60;
};

// NONMATCHING: the block's address plus its offset is `lea rdx, [rdx + rax]` in the base, `add
// rdx, rax` in the compile (TwoAddress's add-to-lea, the class of FUN_01393620); every instruction
// else equal
void FUN_00cef1b0(Object00cef1b0 *, Argument00cef1b0 *argument) /* derived name */
{
    argument->unknown58 = 0;
    argument->unknown60 = 0;
    Block00cef1b0 *block = argument->unknown28;
    if (block && argument->unknown30) {
        argument->unknown58 = reinterpret_cast<u8 *>(block) + block->unknown8;
        argument->unknown60 = argument->unknown30 - block->unknown8;
    }
}
