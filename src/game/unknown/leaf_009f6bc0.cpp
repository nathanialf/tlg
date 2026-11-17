/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: slot 5 of the vtables at 0x16b19f0 (FUN_009f6bc0) and at
 * 0x16b1a48 (FUN_009f8a90), one body: true when the node has a component of
 * neither the type the pointer at 0x5823928 holds nor the one at 0x5823930
 * (or of one derived from either), each searched under the node's reader
 * count. The object itself is not read; each is a free function here, as
 * the classes' other slots are (leaf_009f6ca0.cpp). */
class Object016b19f0;
class Object016b1a48;

extern const Type00503fb0 *D_5823928; /* derived name */
extern const Type00503fb0 *D_5823930; /* derived name */

// NONMATCHING: the reader count's exits (leaf_009f54b0.cpp's class): the
// base leaves the first search through one `lock dec` block with "none
// found" in al (`test rdi, rdi; sete al` on a find) and the second through a
// decrement on each exit; this build does the reverse (each exit of the
// first its own decrement, the second merged): 12/74, 205 bytes against
// 223. The same in FUN_009f8a90.
int FUN_009f6bc0(Object016b19f0 *, Node00503fb0 *node) /* derived name */
{
    return !node->findComponent(D_5823928) && !node->findComponent(D_5823930);
}

/* FUN_009f8a90: the same body */
int FUN_009f8a90(Object016b1a48 *, Node00503fb0 *node) /* derived name */
{
    return !node->findComponent(D_5823928) && !node->findComponent(D_5823930);
}
