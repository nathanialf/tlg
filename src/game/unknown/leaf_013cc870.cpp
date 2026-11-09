/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls the function pointer at +0x18 with its own two further
 * arguments, as a tail call (both moved down a register, 64 bits wide); slot
 * 13 of the vtable at 0x16d34d0 (its pointer at 0x16d3548), the vtable stored
 * by FUN_013cc900 FUN_013cc950. The pointer's signature beyond that and the
 * return type are not traced. Class and method unknown. */
struct Object013cc870 { /* derived name */
    u8 unknown0[0x18];
    void (*unknown18)(
        void *, void *); /* parameters 64 bits wide; their types and the return type not traced */
};

void FUN_013cc870(Object013cc870 *self, void *a, void *b) /* derived name */
{
    self->unknown18(a, b);
}
