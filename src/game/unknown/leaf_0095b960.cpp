/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: calls FUN_0095b640 on the object when the int at +0x1f0 is
 * non-zero, FUN_0095b160 otherwise, as tail calls; slot 10 of the vtable at
 * 0x16c7b78. The compiler emits beside it the thunk 0x95b980 for the base at
 * +0x128 (slot 0 of the secondary vtable whose pointer is at 0x16c7c28:
 * this - 0x128, the body inlined). The callees' other parameters and return
 * types are not traced. */
void FUN_0095b640(Object0095b960 *self); /* derived name */
void FUN_0095b160(Object0095b960 *self); /* derived name */

void Object0095b960::FUN_0095b960()
{
    if (unknown1f0) {
        FUN_0095b640(this);
    } else {
        FUN_0095b160(this);
    }
}
