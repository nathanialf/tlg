/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_joint013eb0a0.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object016d7510.h"

/* derived names: the class whose vtable is at 0x16d5050
 * (config/vtables.derived.base.txt, stored by FUN_00ffe8c0 FUN_013ed250 FUN_013ed2e0): ten slots, no base
 * that its destructor shows. Its fields are traced only where the destructor
 * tears them down: a counted reference at +0x10 (tlg_game_node.h's
 * Ref00503fb0: the count at +0x8 of the object, its slot 2 called when the
 * last reference goes on a thread that destroys at once), a scene node.
 * Slot 2 (FUN_013eb670) returns the node's frame (+0x120 and +0x140), or
 * the frame of the node at +0x2630 of the subject's target while the
 * target's +0x25c0 is set. The rest is not traced. */
class Object016d5050 /* derived name */
{
  public:
    virtual ~Object016d5050();
    virtual JointFrame013eb0a0 slot2(const Subject01480e70 *subject); /* derived name */
    virtual void slot3(); /* derived name; FUN_0002abc0, not traced */
    virtual void slot4(); /* derived name; FUN_000058a0, not traced */
    virtual void slot5(); /* derived name; FUN_013eb6e0, not traced */
    virtual void slot6(); /* derived name; FUN_013eb010, not traced */
    virtual void slot7(); /* derived name; FUN_013eb6f0, not traced */
    virtual void slot8(); /* derived name; FUN_013eb1f0, not traced */
    virtual void slot9(); /* derived name; FUN_00013e90, not traced */

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Object016b85e0> node; /* +0x10: released by the destructor */
};

/* derived name: the complete destructor: the body is empty; the reference is
 * released. FUN_013ed2e0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016d5050::~Object016d5050() {}

/* Slot 2: the node's frame, or the target's node's while the target says so */
JointFrame013eb0a0 Object016d5050::slot2(const Subject01480e70 *subject)
{
    const Object016b85e0 *self = node.get();
    JointFrame013eb0a0 frame(self->unknown120, self->unknown140);
    const Target01480e70 *target = subject->target;
    if (target && target->unknown25c0 != 0 && target->node2630) {
        frame.position = target->node2630->unknown120;
        frame.rotation = target->node2630->unknown140;
    }
    return frame;
}
