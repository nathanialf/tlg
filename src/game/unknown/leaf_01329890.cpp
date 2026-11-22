/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0130acb0.h"
#include "tlg_types.h"
#include "tlg_game_object05adaaa8.h"
#include "tlg_sce_gnm.h"

void FUN_0131e2d0(Target0131e2d0 *target, void *entry); /* derived name */

/* derived names: the class whose vtable is at 0x16c5590
 * (config/vtables.derived.base.txt; made by FUN_00b8a480) over the class
 * whose destructor is 0x130acb0: a compute queue's id at +0x38 and two
 * entries at +0x88 and +0x90 handed back to the list at +0x100e8 of the
 * object at 0x5adaaa8, as FUN_013224a0 hands its own back. Its complete
 * destructor FUN_01329890 unmaps the queue, gives the entries back and
 * tail-calls the base's destructor; FUN_01329930, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016c5590 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c5590();

  private:
    u8 unknown10[0x28];
    unsigned queue38; /* +0x38: the compute queue (sceGnmUnmapComputeQueue) */
    u8 unknown3c[0x4c];
    void *entry88; /* +0x88 */
    void *entry90; /* +0x90 */
};

/* derived name: an entry handed back to the owner's list, counted */
static void giveBack(void *entry)
{
    Object05adaaa8 *owner = D_5adaaa8;
    if (entry) {
        FUN_0131e2d0(owner->unknown100e8, entry);
        __sync_fetch_and_add(&owner->unknown100b0, 1);
    }
}

Object016c5590::~Object016c5590()
{
    sceGnmUnmapComputeQueue(queue38);
    queue38 = 0;
    giveBack(entry88);
    giveBack(entry90);
    entry88 = 0;
    entry90 = 0;
}
