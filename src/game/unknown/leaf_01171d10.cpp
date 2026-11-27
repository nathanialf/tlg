/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_object012ada80.h"
#include "tlg_game_object016c17c0.h"
#include "tlg_game_owner00f707b0.h"

/* derived name: the pair of tables of Object016c17c0 (the first, the type its
 * creator FUN_01166a20 takes) and of the class below (the second, FUN_0116ede0's) */
extern Tables00c1ac70 D_5ad4780;

/* derived names: the class whose vtable is at 0x16c17f8
 * (config/vtables.derived.base.txt, stored by FUN_0116ede0 FUN_01171d10), over
 * Base016b4560 (its creator FUN_0116ede0 clears the int at +0x24 before the
 * vptr store). 0x28 bytes (`mov edi, 0x28` before operator new in the
 * creator). FUN_01172040, slot 1, is the deleting destructor. */
class Object016c17f8 : public Base016b4560 /* derived name */
{
  public:
    Object016c17f8(const Name &name) : Base016b4560(name) {}

    virtual ~Object016c17f8();
    virtual void slot5(Context016b4560 *context); /* derived name; FUN_0116ef40, not traced */
    virtual void slot6();                         /* derived name; FUN_00c1b350, not traced */
};

/* derived name: the complete destructor: every object of Object016c17c0's
 * table is taken out of its owner's array, the owner held meanwhile by a
 * counted reference, every reference to it taken out last first (the count
 * read again after each removal, `dec dword [rbx+0xc8]`); the table is
 * read before the array is made (its load comes before the stores of the
 * array's index and lock word); then the base's destructor, inlined. */
Object016c17f8::~Object016c17f8()
{
    Registry00cb8240 *registry = D_5ad4780.first;
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(registry, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object016c17c0 *object = static_cast<Object016c17c0 *>(objects.at(i));
        AtomicRef0045c470<Object016b9108> owner(object->owner);
        if (owner.get())
            static_cast<Owner00f707b0 *>(owner.get())->held.removeEvery(object);
    }
}
