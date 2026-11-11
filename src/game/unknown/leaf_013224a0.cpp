/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object05adaaa8.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16c3c08 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00b8a480): it stores the vtable, hands the entry at +0x30, when set,
 * back to the object 0x5adaaa8 points at (FUN_0131e2d0 with its member at
 * +0x100e8, then its count at +0x100b0 incremented), drops its reference to
 * that object, then runs its base's destructor FUN_0130acb0 as a tail call.
 * FUN_01322510, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
void FUN_0131e2d0(Target0131e2d0 *target, void *entry); /* derived name */

class Object0130acb0 /* derived name */
{
  public:
    virtual ~Object0130acb0();
};

class Object016c3c08 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c3c08();

  private:
    u8 unknown8[0x28];
    void *unknown30; /* +0x30 */
};

Object016c3c08::~Object016c3c08()
{
    if (unknown30) {
        Object05adaaa8 *owner = D_5adaaa8;
        FUN_0131e2d0(owner->unknown100e8, unknown30);
        __sync_fetch_and_add(&owner->unknown100b0, 1);
    }
    D_5adaaa8->release();
}
