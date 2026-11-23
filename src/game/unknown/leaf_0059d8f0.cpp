/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_object016b7e70.h"

/* derived names: the value a node keeps in the owner's list for the
 * handlers of FUN_00525530's table at +0xfa8: two Object016b7e70 (the
 * same pair FUN_0059e8d0 keeps on its stack at -0xe0 and -0x88). Its
 * destructor empties both, then their destructors run, the second first. */
struct Pair0059d8f0 { /* derived name */

    ~Pair0059d8f0()
    {
        first.reset();
        second.reset();
    }

    Object016b7e70 first;  /* +0x0 */
    Object016b7e70 second; /* +0x58 */
};

/* derived names: a handler whose address FUN_00525530 stores at +0x1038 of
 * the object it constructs (index 18 of the table at +0xfa8): a node found
 * in the owner's list has the pair its value holds destroyed in place.
 * Returns 0. Handler unknown. */
// NONMATCHING: 95/104 in the module, 389 bytes against 378: the second
// object's pointer fields (+0x38 to +0x58) are addressed in the base from
// its own address, the destructor's argument (`mov rax, [r14+0x38]`,
// `vmovups [r14+0x40]`), its ints from the pair's (`[rbx+0x78]`); the build
// folds all of them off the pair (`[rbx+0x90]`). The pair as an array of two
// reset in a loop loses the second's address altogether. Not traced.
int FUN_0059d8f0(Owner583950 *self, Node583950 *node) /* derived name */
{
    if (self->cursor.select(node)) {
        Pair0059d8f0 *pair = reinterpret_cast<Pair0059d8f0 *>(self->cursor.value());
        if (pair)
            pair->~Pair0059d8f0();
    }
    return 0;
}
