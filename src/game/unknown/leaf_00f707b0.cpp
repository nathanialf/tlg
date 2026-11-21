/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_object012ada80.h"
#include "tlg_game_object016bfb28.h"
#include "tlg_game_owner00f707b0.h"

/* derived name: the pair of tables of Object016bfb28 (the first, the type its
 * creator FUN_00f6f0c0 takes) and of the class below (the second, FUN_00f6f830's) */
extern Tables00c1ac70 D_5aceaa8;

/* derived names: the class whose vtable is at 0x16bfb60
 * (config/vtables.derived.base.txt, stored by FUN_00f6f830 FUN_00f707b0), over
 * Base016b4560 (its creator FUN_00f6f830 clears the int at +0x24 before the
 * vptr store). 0x28 bytes (`mov edi, 0x28` before operator new in the
 * creator). FUN_00f70ae0, slot 1, is the deleting destructor. */
class Object016bfb60 : public Base016b4560 /* derived name */
{
  public:
    Object016bfb60(const Name &name) : Base016b4560(name) {}

    virtual ~Object016bfb60();
    virtual void slot5(); /* derived name; FUN_00f6f990, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */
};

/* derived name: the complete destructor: every object of Object016bfb28's
 * table is taken out of its owner's array, the owner held meanwhile by a
 * counted reference, every reference to it taken out last first (the count
 * read again after each removal, `dec dword [rbx+0xc8]`), the count
 * taken signed and the element before it compared (`movsxd r14, dword
 * [rbx+0xc8]; test r14, r14; jle`, `cmp [rax+r14*8-8], rcx`); then the base's destructor, inlined. */
// NONMATCHING: 807 bytes against 808, the owner's loop: the base widens its index signed (`movsxd
// r14, dword [rbx+0xc8]; test r14, r14; jle`, the element at `[rax+r14*8-8]`, `mov r15d, r12d`
// for the removal); the build's index is 32-bit (`dec eax; js; movsxd`), and the registers
// differ from the start (the base keeps this in r15). Written `j > 0` with `at(j - 1)`, the
// loop widens from the removal's zero extension instead (`zext` of the count, a `movsxd` of
// j - 1 left in the loop)
Object016bfb60::~Object016bfb60()
{
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(D_5aceaa8.first, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object016bfb28 *object = static_cast<Object016bfb28 *>(objects.at(i));
        AtomicRef0045c470<Object016b9108> owner(object->owner);
        if (Owner00f707b0 *holder = static_cast<Owner00f707b0 *>(owner.get()))
            for (int j = holder->held.size() - 1; j >= 0; --j)
                if (holder->held.at(j).get() == object)
                    holder->held.removeAt(j);
    }
}
