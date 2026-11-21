/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_object012ada80.h"
#include "tlg_game_object016c1bf8.h"
#include "tlg_game_owner00f707b0.h"

/* derived name: the pair of tables of Object016c1bf8 (the first, the type its
 * creator FUN_011edbd0 takes) and of the class below (the second, FUN_011ee280's) */
extern Tables00c1ac70 D_5ad73f0;

/* derived names: the class whose vtable is at 0x16c1c30
 * (config/vtables.derived.base.txt, stored by FUN_011ee280 FUN_011ee630), over
 * Base016b4560 (its creator FUN_011ee280 clears the int at +0x24 before the
 * vptr store), with four arrays of counted references at +0x30 to +0x78, destroyed last first after the loop (the calls of Array05943280<Ref00503fb0<Object016b9108>>::~Array05943280 from +0x78 down). 0x90 bytes (`mov edi, 0x90` before operator
 * new in the creator). FUN_011ee980, slot 1, is the deleting destructor. The
 * destructor of FUN_00f707b0 (leaf_00f707b0.cpp) with these members. */
class Object016c1c30 : public Base016b4560 /* derived name */
{
  public:
    Object016c1c30(const Name &name) : Base016b4560(name), unknown28(0) {}

    virtual ~Object016c1c30();
    virtual void slot5(); /* derived name; FUN_011ee4d0, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */
    virtual void slot7(); /* derived name; FUN_011ee4c0 (leaf_011ee4c0.cpp), the name string */

  private:
    void *unknown28; /* +0x28: null from the constructor; not traced */
    Array05943280<Ref00503fb0<Object016b9108>> refs30; /* +0x30 */
    Array05943280<Ref00503fb0<Object016b9108>> refs48; /* +0x48 */
    Array05943280<Ref00503fb0<Object016b9108>> refs60; /* +0x60 */
    Array05943280<Ref00503fb0<Object016b9108>> refs78; /* +0x78 */
};

/* derived name: the complete destructor: every object of Object016c1bf8's
 * table is taken out of its owner's array, the owner held meanwhile by a
 * counted reference, every reference to it taken out last first; then
 * the members and the base's destructor, inlined. */
Object016c1c30::~Object016c1c30()
{
    Registry00cb8240 *registry = D_5ad73f0.first;
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(registry, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object016c1bf8 *object = static_cast<Object016c1bf8 *>(objects.at(i));
        AtomicRef0045c470<Object016b9108> owner(object->owner);
        if (owner.get())
            static_cast<Owner00f707b0 *>(owner.get())->held.removeEvery(object);
    }
}
