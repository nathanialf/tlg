/* src/include/tlg_game_object016c3be0.h: the class whose vtable is at
 * 0x16c3be0, over Object0130acb0, whose entries go back to the object at
 * 0x5adaaa8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C3BE0_H
#define TLG_GAME_OBJECT016C3BE0_H

#include "tlg_types.h"
#include "tlg_game_object05adaaa8.h"

void FUN_0131e2d0(Target0131e2d0 *target, void *entry); /* derived name */

/* an entry handed back to the object 0x5adaaa8 points at, nothing done for
 * none: FUN_0131e2d0 with its member at +0x100b8, then its count at
 * +0x100a0 incremented (as leaf_0131e770.cpp's) */
inline void returnEntry(void *entry) /* derived name */
{
    if (entry) {
        Object05adaaa8 *owner = D_5adaaa8;
        FUN_0131e2d0(owner->unknown100b8, entry);
        __sync_fetch_and_add(&owner->unknown100a0, 1);
    }
}

/* the base whose destructor 0x130acb0 (its row named for it, D15) the
 * destructors over it run as a tail call */
class Object0130acb0 /* derived name */
{
  public:
    virtual ~Object0130acb0();
};

/* derived names: the class whose vtable is at 0x16c3be0
 * (config/vtables.derived.base.txt; built by FUN_012ff2f0 and others). Its
 * complete destructor (0x131fdb0, the row named Object0131fdb0's) hands
 * back the four entries at +0x30, +0x40, +0x48 and +0x58 unless its state
 * at +0x124 is 1 or 3 (`or eax, 2; cmp eax, 3; je`), then runs the base's.
 * The classes over it (leaf_01324580.cpp) hand them back themselves. The
 * other fields are not traced. */
class Object016c3be0 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c3be0();

  protected:
    u8 unknown8[0x28];
    void *entry30; /* +0x30 */
    u8 unknown38[0x8];
    void *entry40; /* +0x40 */
    void *entry48; /* +0x48 */
    u8 unknown50[0x8];
    void *entry58; /* +0x58 */
    u8 unknown60[0xc4];
    int state124; /* +0x124 */
};

#endif
