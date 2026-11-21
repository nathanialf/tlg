/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00ccd4f0: 78/248 in the module, the instructions and the length the base's; the release of the reference at +0x80 after the second child is taken out: the base keeps the pointer its test read on the path that took no lock (`mov r15, [r14+0x80]` at 0xccd5bc, used at 0xccd693; the two ends of the registry's unlock meet in one block at 0xccd67c first), the module reads it again where the three paths meet. Not the reference held as an array of five, nor the unlock out of line (the link inlines it: further off). */
#include "tlg_game_node.h"
#include "tlg_game_object00ced570.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: an object the class below holds by counted reference at
 * +0x78 and +0x80: its parent at +0x28 (the node whose slot 6 takes it
 * out, FUN_00c575d0, which tests the same field), a pointer at +0x38 the
 * holder clears before. Nothing else of it is traced. */
class Child016b92a0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[4];
    Object016b85e0 *parent28; /* +0x28 */
    u8 unknown30[8];
    void *unknown38; /* +0x38 */
};

/* derived names: the class whose vtable is at 0x16b92a0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00ccd350
 * and its complete destructor FUN_00ccd4f0), over Object00ced570 (the
 * destructor tail-calls 0xced570): five counted references from +0x60.
 * The destructor takes each of the objects at +0x78 and +0x80 that has a
 * parent out of it under the world's write lock (its pointer at +0x38
 * cleared first); then the references are released and the base's
 * destructor runs. FUN_00ccd920, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable;
 * its other slots are not traced. */
class Object016b92a0 : public Object00ced570 /* derived name */
{
  public:
    virtual ~Object016b92a0();

  private:
    /* the child taken out of its parent under the world's write lock: the
     * child and its parent are read before the lock is taken (`mov rbx,
     * [r15+0x28]` before `call 0xd8f040`), the reference read again after
     * the store at +0x38 (`mov r15, [r14+0x78]` at 0xccd525) */
    static void detach(const Ref00503fb0<Child016b92a0> &child) /* derived name */
    {
        if (child.get()->parent28 != 0) {
            child.get()->unknown38 = 0;
            removeLocked(child.get()->parent28, child.get());
        }
    }

    static void removeLocked(Object016b85e0 *parent, Child016b92a0 *child) /* derived name */
    {
        D_5938c40->world->lockWrite();
        parent->removeChild(child);
        D_5938c40->world->unlockWrite();
    }

    Ref00503fb0<Object016b9108> unknown60; /* +0x60 */
    Ref00503fb0<Object016b9108> unknown68; /* +0x68 */
    Ref00503fb0<Object016b9108> unknown70; /* +0x70 */
    Ref00503fb0<Child016b92a0> child78;    /* +0x78 */
    Ref00503fb0<Child016b92a0> child80;    /* +0x80 */
};

Object016b92a0::~Object016b92a0()
{
    detach(child78);
    detach(child80);
}
