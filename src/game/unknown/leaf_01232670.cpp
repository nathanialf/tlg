/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_object012ada80.h"
#include "tlg_game_object016c23e0.h"
#include "tlg_game_owner00f707b0.h"

/* derived name: the pair of tables of Object016c23e0 (the first, the type its
 * creator FUN_012275e0 takes) and of the class below (the second, FUN_01231f80's) */
extern Tables00c1ac70 D_5ad7918;

/* derived names: the class whose vtable is at 0x16c2418
 * (config/vtables.derived.base.txt, stored by FUN_01231f80 FUN_01232670), over
 * Base016b4560 (its creator FUN_01231f80 clears the int at +0x24 before the
 * vptr store), with a counted reference at +0x28, released after the loop (cleared, then the count dropped). 0x30 bytes (`mov edi, 0x30` before operator
 * new in the creator). FUN_01232a20, slot 1, is the deleting destructor. The
 * destructor of FUN_00f707b0 (leaf_00f707b0.cpp) with these members. */
class Object016c2418 : public Base016b4560 /* derived name */
{
  public:
    Object016c2418(const Name &name) : Base016b4560(name) {}

    virtual ~Object016c2418();
    virtual void slot5(Context016b4560 *context); /* derived name; FUN_012320e0, not traced */
    virtual void slot6();                         /* derived name; FUN_00c1b350, not traced */

  private:
    Ref00503fb0<Object016b9108>
        held28; /* +0x28: null from the constructor; released after the loop */
};

/* derived name: the complete destructor: every object of Object016c23e0's
 * table is taken out of its owner's array, the owner held meanwhile by a
 * counted reference, every reference to it taken out last first; then
 * the members and the base's destructor, inlined. */
Object016c2418::~Object016c2418()
{
    Registry00cb8240 *registry = D_5ad7918.first;
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(registry, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object016c23e0 *object = static_cast<Object016c23e0 *>(objects.at(i));
        AtomicRef0045c470<Object016b9108> owner(object->owner);
        if (owner.get())
            static_cast<Owner00f707b0 *>(owner.get())->held.removeEvery(object);
    }
}
