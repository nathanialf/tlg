/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_object012ada80.h"
#include "tlg_game_object016c0200.h"
#include "tlg_game_owner00f707b0.h"

/* derived name: the pair of tables of Object016c0200 (the first, the type its
 * creator FUN_00fc71f0 takes) and of the class below (the second, FUN_00fd6460's) */
extern Tables00c1ac70 D_5acf298;

/* derived names: the class whose vtable is at 0x16c0238
 * (config/vtables.derived.base.txt, stored by FUN_00fd6460 FUN_00fd8930), over
 * Base016b4560 (its creator FUN_00fd6460 clears the int at +0x24 before the
 * vptr store). 0x28 bytes (`mov edi, 0x28` before operator new in the
 * creator). FUN_00fd8c60, slot 1, is the deleting destructor. */
class Object016c0238 : public Base016b4560 /* derived name */
{
  public:
    Object016c0238(const Name &name) : Base016b4560(name) {}

    virtual ~Object016c0238();
    virtual void slot5(); /* derived name; FUN_00fd65c0, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */
};

/* derived name: the complete destructor: every object of Object016c0200's
 * table is taken out of its owner's array, the owner held meanwhile by a
 * counted reference, every reference to it taken out last first (the count
 * read again after each removal, `dec dword [rbx+0xc8]`); the table is
 * read before the array is made (its load comes before the stores of the
 * array's index and lock word); then the base's destructor, inlined. */
Object016c0238::~Object016c0238()
{
    Registry00cb8240 *registry = D_5acf298.first;
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(registry, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object016c0200 *object = static_cast<Object016c0200 *>(objects.at(i));
        AtomicRef0045c470<Object016b9108> owner(object->owner);
        if (owner.get())
            static_cast<Owner00f707b0 *>(owner.get())->held.removeEvery(object);
    }
}
