/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16be108 (config/vtables.derived.base.txt; stored by the constructor
 * FUN_00e744c0 and by its destructors): it stores the vtable and passes the
 * int at +0x20 of the record its pointer at +0x10 holds to FUN_00cbb8d0 on the
 * object the pointer at 0x5945a38 holds, a tail call. FUN_00e82710, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. */
struct Object05945a38; /* derived name */

extern Object05945a38 *D_5945a38;

void FUN_00cbb8d0(Object05945a38 *self, int id); /* derived name */

struct Member00e826f0_10 /* derived name */
{
    u8 unknown0[0x20];
    int unknown20; /* +0x20 */
};

class Object00e826f0 /* derived name */
{
  public:
    virtual ~Object00e826f0();

  private:
    u8 unknown8[8];
    Member00e826f0_10 *unknown10; /* +0x10 */
};

// NONMATCHING: greedy's assignment, the copy kept: the base loads the pointer at
// 0x5945a38 into rax after the member and copies it to rdi (`mov rdi, rax`) where
// this loads it into rdi; the deleting destructor FUN_00e82710 is equal.
Object00e826f0::~Object00e826f0()
{
    FUN_00cbb8d0(D_5945a38, unknown10->unknown20);
}
