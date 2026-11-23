/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b6590.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016c7d08.h"

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_00b4c130, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b6590::~Object016b6590() {}

/* derived names: the scene node an Object016b6590 names at +0x78, of the
 * type at 0x5833e58: an int at +0x264 that slot 8 sets */
class Node00b4c750 : public Object016b85e0 /* derived name */
{
  public:
    u8 unknown238[0x2c];
    int unknown264; /* +0x264 */
};

extern Type00503fb0 *D_5833e58; /* derived name: the type of the node above */

/* leaf_00c57120.cpp: the node taken out of its parent under the world's
 * write lock */
void FUN_00c57220(Object016b85e0 *node); /* derived name */

/* derived names: slot 8: the node the name at +0x78 names, when this
 * thread may use it and it is of the type at 0x5833e58, is marked (1 at
 * +0x264) and taken out of its parent while the int at +0x58 is clear; the
 * name is dropped; then, with either pointer at +0x38 set, the mutex at
 * +0xa0 of the object at +0x78 of the one 0x57c9390 points to is taken and
 * given back (when that object is there) and the pointer at +0x48
 * cleared. */
// NONMATCHING: 324 bytes against 346, every instruction in the base's order but the registers: the
// base computes the name's address once (`lea r12, [r14+0x78]` at entry) and reads the name through it
// in each block, with a fifth callee-saved register; the build folds the offset into each access.
// Model (not compiled): CodeGenPrepare sinks the field's address into each block when every use is an
// address, so in the base's IR the address had another use.
void Object016b6590::slot8()
{
    Node00b4c750 *node = findNamed<Node00b4c750>(name78, D_5833e58);
    if (node && unknown58 == 0) {
        node->unknown264 = 1;
        FUN_00c57220(node);
    }
    name78.release();
    if (unknown38 || unknown40) {
        Owner057c9390 *owner = D_57c9390->unknown78;
        if (owner) {
            owner->mutexa0.lock();
            owner->mutexa0.unlock();
            unknown48 = 0;
        }
    }
}
