/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_0020d3d0 appends a counted reference to the array at
 * 0x57c9f58 (tlg_game_array.h's push), which the function reaches directly:
 * the file's own object (D17). The array is destroyed at exit, so the
 * counted class is one the references can release: the node's interface
 * (tlg_game_node.h; the real class is not traced). */
static Array05943280<Ref00503fb0<Object016b9108>> D_57c9f58;

void FUN_0020d3d0(const Ref00503fb0<Object016b9108> &value) /* derived name */
{
    D_57c9f58.push(value);
}
