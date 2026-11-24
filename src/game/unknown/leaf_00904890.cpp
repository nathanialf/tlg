/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the node of the tree under `node` (itself excluded) whose
 * Name at +0x210 is `name`: the children are searched first, under the
 * world's reader lock, then each child's tree in turn; null when none. Both
 * walks read the children's array and count once. */
// NONMATCHING: 238 bytes against 248: the base returns the found child apart (`mov rax, rbx; jmp`
// at 0x90493a) and the subtrees' result in rax; here both share rbx (round 573D)
Object016b85e0 *FUN_00904890(Object016b85e0 *node, const Name &name) /* derived name */
{
    D_5938c40->world->lockRead();
    Object016b85e0 *found = 0;
    for (Ref00503fb0<Object016b85e0> *child = node->children, *end = child + node->childCount;
         child != end; ++child) {
        Object016b85e0 *object = child->get();
        if (object && object->name210 == name) {
            found = object;
            break;
        }
    }
    D_5938c40->world->unlockRead();
    if (found)
        return found;
    for (Ref00503fb0<Object016b85e0> *child = node->children, *end = child + node->childCount;
         child != end; ++child) {
        if (Object016b85e0 *object = FUN_00904890(child->get(), name))
            return object;
    }
    return 0;
}
