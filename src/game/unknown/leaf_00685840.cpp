/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01388080.h"
#include "tlg_game_object016aed28.h"

void FUN_00c57220(Object016b85e0 *node); /* derived name */

/* derived names: the class whose vtable is at 0x16ac3a8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00684a90
 * and its complete destructor FUN_00685840), over Object016aed28. Its
 * fields are traced where the destructor tears them down: two names. */
class Object016ac3a8 : public Object016aed28 /* derived name */
{
  public:
    virtual ~Object016ac3a8();

  private:
    /* the child taken out under the world's write lock: the child is read
     * before the lock is taken (`mov r14, [rbx+0x2a0]` before `call
     * 0xd8f040`) */
    void removeLocked(Object016b9108 *child) /* derived name */
    {
        D_5938c40->world->lockWrite();
        removeChild(child);
        D_5938c40->world->unlockWrite();
    }

    u8 unknown580[0x8];
    Name name588; /* +0x588 */
    Name name58c; /* +0x58c */
};

/* derived name: the complete destructor FUN_00685840: the references at
 * +0x2a0 and +0x290 taken out of the node's children under the world's write
 * lock, the node handed to FUN_00c57220; the members are released, last
 * first, and the base's destructor 0x83df00 runs as a tail call.
 * FUN_00685a20, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016ac3a8::~Object016ac3a8()
{
    removeLocked(ref2a0.get());
    removeLocked(ref290.get());
    FUN_00c57220(this);
}
