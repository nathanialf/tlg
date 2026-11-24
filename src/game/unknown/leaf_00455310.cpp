/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: in the tree under `root`, the node named by the Name at
 * 0x57d5374 is looked up (FUN_0048fe20) under the world's reader lock; when
 * it is of the type the pointer at 0x5820840 holds (or one derived from it),
 * its slot 10 is called (a sibling call, `jmp [rax+0x50]`). The class and
 * the slot's parameters are not traced beyond this. */
extern const Name D_57d5374;    /* derived name */
extern Type00503fb0 *D_5820840; /* derived name: the found node's type */

class Node00455310 : public Object016b85e0 /* derived name */
{
  public:
    virtual void slot10(); /* derived name */
};

Object016b85e0 *FUN_0048fe20(const Name &name, Object016b85e0 *node);

void FUN_00455310(Object016b85e0 *root) /* derived name */
{
    if (!root)
        return;
    D_5938c40->world->lockRead();
    Object016b85e0 *found = FUN_0048fe20(D_57d5374, root);
    D_5938c40->world->unlockRead();
    if (found && found->isKindOf(D_5820840))
        static_cast<Node00455310 *>(found)->slot10();
}
