/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the unit of the counted base (tlg_game_object016b9108.h's
 * Counted00c14bc0), named for FUN_00c14bc0, the later release every counted
 * class shares (not written yet). The raise a copy of a counted reference
 * makes (tlg_game_node.h's Ref00503fb0) is defined here and not beside the
 * root class: the root's own constructor calls the shared append
 * FUN_0138e360 (0xcb6310), so the append's copy was a call in the root
 * class's unit too and the raise's body was not there. Its body has no
 * address in the executable: every call was inlined by the link and the
 * copy discarded, as func_00cbb000.cpp's threadMayUse was. Which unit of
 * the original held it is not known. */
void raiseReference(Counted00c14bc0 *object) /* derived name */
{
    addReference(object);
}
