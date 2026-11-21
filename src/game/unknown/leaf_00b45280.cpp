/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the objects of the type the pointer at 0x59385b8 holds
 * that the class below makes in its constructor FUN_00b44ec0 (FUN_00cbc5a0
 * with it) and adds as its children (slot 5, addChild); its destructor marks them with
 * the flag 0x10 at +0x38 and the values 0x10 and 0xf at +0x48. Nothing else
 * of them is traced. */
class Object059385b8 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x14];
    int flags38; /* +0x38 */
    u8 unknown3c[0xc];
    int unknown48; /* +0x48 */
};

/* derived names: the class whose vtable is at 0x16b60b0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b44ec0
 * and its complete destructor FUN_00b45280), over Object016b85e0: two
 * counted references to objects it made and added as its children (+0x250
 * and +0x258, each set by compare-and-swap in the constructor and added
 * through addChild under the world's write lock), a name at +0x248 and an int
 * at +0x244 (1 once built). The destructor clears the int, marks the two
 * objects, takes each out through removeChild under the world's write lock
 * (World05938c40::lockWrite and unlockWrite), then the members are released
 * and the base's destructor 0xc55550 runs as a tail call. FUN_00b45570,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. */
class Object016b60b0 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b60b0();

  private:
    /* the child taken out under the world's write lock: the child is read
     * before the lock is taken (`mov r14, [r15+0x250]` before `call
     * 0xd8f040`) */
    void removeLocked(Object059385b8 *child) /* derived name */
    {
        D_5938c40->world->lockWrite();
        removeChild(child);
        D_5938c40->world->unlockWrite();
    }

    u8 unknown24[0x220];
    int unknown244;                             /* +0x244 */
    Name unknown248;                            /* +0x248 */
    AtomicRef0045c470<Object059385b8> child250; /* +0x250 */
    AtomicRef0045c470<Object059385b8> child258; /* +0x258 */
};

Object016b60b0::~Object016b60b0()
{
    unknown244 = 0;
    child250.get()->flags38 |= 0x10;
    child250.get()->unknown48 = 0x10;
    child258.get()->flags38 |= 0x10;
    child258.get()->unknown48 = 0xf;
    removeLocked(child250.get());
    removeLocked(child258.get());
}
