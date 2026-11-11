/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object05adaaa8.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16c3af0 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_013143e0): it stores the vtable, hands each of the entries at +0x30 and
 * +0x38 that is set back to the object 0x5adaaa8 points at (FUN_0131e2d0 with
 * its member at +0x100b8, then its count at +0x100a0 incremented), then runs
 * its base's destructor FUN_0130acb0 (its row named for it, D15) as a tail
 * call. FUN_0131e7e0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
void FUN_0131e2d0(Target0131e2d0 *target, void *entry); /* derived name */

inline void returnEntry(void *entry) /* derived name */
{
    if (entry) {
        Object05adaaa8 *owner = D_5adaaa8;
        FUN_0131e2d0(owner->unknown100b8, entry);
        __sync_fetch_and_add(&owner->unknown100a0, 1);
    }
}

class Object0130acb0 /* derived name */
{
  public:
    virtual ~Object0130acb0();
};

class Object016c3af0 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c3af0();

  private:
    u8 unknown8[0x28];
    void *unknown30; /* +0x30 */
    void *unknown38; /* +0x38 */
};

Object016c3af0::~Object016c3af0()
{
    returnEntry(unknown30);
    returnEntry(unknown38);
}
