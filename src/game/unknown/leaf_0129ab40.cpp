/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object012ada80.h"
#include "tlg_game_object016c3040.h"
#include "tlg_game_owner00f707b0.h"

/* derived name: the pair of tables of Object016c3040 (the first, the type its
 * creator FUN_0129a0e0 takes) and of the class below (the second, FUN_0129a790's) */
extern Tables00c1ac70 D_5ad8708;

/* derived names: the class whose vtable is at 0x16c3078
 * (config/vtables.derived.base.txt, stored by FUN_0129a790 FUN_0129ab40), over
 * Base016b4560 (its creator FUN_0129a790 clears the int at +0x24 before the
 * vptr store), with four arrays of counted references at +0x30 to +0x78, destroyed last first after the loop (the calls of Array05943280<Ref00503fb0<Object016b9108>>::~Array05943280 from +0x78 down). 0x90 bytes (`mov edi, 0x90` before operator
 * new in the creator). FUN_0129ae90, slot 1, is the deleting destructor. The
 * destructor of FUN_00f707b0 (leaf_00f707b0.cpp) with these members. */
class Object016c3078 : public Base016b4560 /* derived name */
{
  public:
    Object016c3078(const Name &name) : Base016b4560(name), unknown28(0) {}

    virtual ~Object016c3078();
    virtual void slot5(Context016b4560 *context); /* derived name; FUN_0129a9e0 */
    virtual void slot6();                         /* derived name; FUN_00c1b350, not traced */
    virtual void slot7(); /* derived name; FUN_0129a9d0 (leaf_0129a9d0.cpp), the name string */

  private:
    void *unknown28; /* +0x28: null from the constructor; not traced */
    Array05943280<Ref00503fb0<Object016b9108>> refs30; /* +0x30 */
    Array05943280<Ref00503fb0<Object016b9108>> refs48; /* +0x48 */
    Array05943280<Ref00503fb0<Object016b9108>> refs60; /* +0x60 */
    Array05943280<Ref00503fb0<Object016b9108>> refs78; /* +0x78 */
};

/* derived name: the complete destructor: every object of Object016c3040's
 * table is taken out of its owner's array, the owner held meanwhile by a
 * counted reference, every reference to it taken out last first; then
 * the members and the base's destructor, inlined. */
Object016c3078::~Object016c3078()
{
    Registry00cb8240 *registry = D_5ad8708.first;
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(registry, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object016c3040 *object = static_cast<Object016c3040 *>(objects.at(i));
        AtomicRef0045c470<Object016b9108> owner(object->owner);
        if (owner.get())
            static_cast<Owner00f707b0 *>(owner.get())->held.removeEvery(object);
    }
}

/* derived names: slot 5 (FUN_0129a9e0): the context is given the pointer at
 * +0x28 and its node's component of the type at 0x57fd340; the objects of
 * the arrays at +0x48 and +0x60 (mode 2) or at +0x78 run with it, the pass
 * set to the array's number before each array that holds any; then the
 * pass is -1 and the pair cleared (one 16-byte store). */
// The pair's address (`lea r15, [ctx+0x668]`) stays above the reader's drop and the store at +0x670 by
// the scheduler rule for a locked decrement
// (tools/patches/llvm-3.7.1-lockdec-01-locked-dec-one-micro-op.patch and lockdec-02, D97).
void Object016c3078::slot5(Context016b4560 *context)
{
    context->group668 = unknown28;
    context->component670 = context->node28->component(D_57fd340);
    if (context->mode4 == 2) {
        runAll(refs48, context, 0);
        runAll(refs60, context, 1);
    } else {
        runAll(refs78, context, 2);
    }
    context->pass678 = -1;
    context->group668 = 0;
    context->component670 = 0;
}
