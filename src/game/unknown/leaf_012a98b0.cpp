/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_object012ada80.h"
#include "tlg_game_object016c31a0.h"
#include "tlg_game_owner00f707b0.h"

/* derived name: the pair of tables of Object016c31a0 (the first, the type its
 * creator FUN_012a79b0 takes) and of the class below (the second, FUN_012a8080's) */
extern Tables00c1ac70 D_5ad8da0;

/* derived names: the class whose vtable is at 0x16c31d8
 * (config/vtables.derived.base.txt, stored by FUN_012a8080 FUN_012a98b0), over
 * Base016b4560 (its creator FUN_012a8080 clears the int at +0x24 before the
 * vptr store). 0x28 bytes (`mov edi, 0x28` before operator new in the
 * creator). FUN_012a9be0, slot 1, is the deleting destructor. */
class Object016c31d8 : public Base016b4560 /* derived name */
{
  public:
    Object016c31d8(const Name &name) : Base016b4560(name) {}

    virtual ~Object016c31d8();
    virtual void slot5(); /* derived name; FUN_012a81e0, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */
};

/* derived name: the complete destructor: every object of Object016c31a0's
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
Object016c31d8::~Object016c31d8()
{
    Array01343a80<Object016b9108 *> objects;
    unsigned count = FUN_00cb8240(D_5ad8da0.first, &objects);
    for (unsigned i = 0; i < count; ++i) {
        Object016c31a0 *object = static_cast<Object016c31a0 *>(objects.at(i));
        AtomicRef0045c470<Object016b9108> owner(object->owner);
        if (Owner00f707b0 *holder = static_cast<Owner00f707b0 *>(owner.get()))
            for (int j = holder->held.size() - 1; j >= 0; --j)
                if (holder->held.at(j).get() == object)
                    holder->held.removeAt(j);
    }
}
