/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: stores its pointer argument at +0x60, then calls FUN_009531c0
 * on the object as a tail call; slot 5 of the vtable at 0x16cf260. The
 * compiler emits beside it the thunk 0x1395c20 for the base at +0x28 (slot 0
 * of the secondary vtable at 0x16cf318: this - 0x28, the body inlined).
 * FUN_009531c0 does not read its second argument register before its first
 * call. The pointer's target and the return type are not traced. */
void FUN_009531c0(Object01395de0 *self); /* derived name */

void Object01395de0::FUN_01395de0(Target01395de0 *value)
{
    unknown60 = value;
    FUN_009531c0(this);
}
