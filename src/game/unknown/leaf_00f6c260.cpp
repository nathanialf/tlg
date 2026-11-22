/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ad0.h"

/* derived names: the class whose vtable is at 0x16ca238
 * (config/vtables.derived.base.txt; stored by FUN_00f59e00), derived from
 * Object016d3ad0, keeping the base's slots 0 to 6 (slot 4 still pure) and
 * adding two: slot 7 (FUN_00f6c270, not traced) and slot 8 (FUN_00f6c260:
 * the base's slot 2 alone, a tail call). The classes of 0x16bfa30 and
 * 0x16bfa88 derive from it (their own slots 2 and 4). Slot 7 is the key
 * function: the vtable is emitted with it, in no file yet. */
class Object016ca238 : public Object016d3ad0 /* derived name */
{
  public:
    virtual void slot7(); /* derived name: FUN_00f6c270, not traced */
    virtual void slot8(); /* derived name */
};

void Object016ca238::slot8()
{
    Object016d3ad0::slot2();
}
