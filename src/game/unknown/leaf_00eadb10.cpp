/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the constraint whose id is at +0x8 of the argument disabled
 * in the object's world (hknpWorld::FUN_0004fcf0), then, when the
 * constraint's user data is an object whose pointer at +0x20 is set, the int
 * at +0x88 of that one set to 1. The classes are not traced. */
struct Owner00eadb10 { /* derived name */
    u8 unknown0[0x88];
    int unknown88; /* +0x88 */
};

struct User00eadb10 { /* derived name: a constraint's user data */
    u8 unknown0[0x20];
    Owner00eadb10 *unknown20; /* +0x20 */
};

struct Argument00eadb10 { /* derived name */
    u8 unknown0[0x8];
    u32 constraintId; /* +0x8 */
};

struct Object00eadb10 { /* derived name */
    hknpWorld *world;   /* +0x0 */
};

// NONMATCHING: register assignment only: the base keeps the argument in r14 and the object in
// rbx (the world in rax, the shifted id in rcx); here the reverse (24 instructions, the same
// order)
// Round 507D: both arguments are local ranges of the one block, assigned in order: the copy of rsi
// comes first here (the DAG's order of the two CopyFromReg nodes) and takes rbx; the base's copy
// of rdi comes first.
void FUN_00eadb10(Object00eadb10 *self, const Argument00eadb10 *argument) /* derived name */
{
    self->world->FUN_0004fcf0(argument->constraintId);
    User00eadb10 *user = reinterpret_cast<User00eadb10 *>(
        self->world->constraintManager.constraints[argument->constraintId].userData);
    if (user && user->unknown20)
        user->unknown20->unknown88 = 1;
}
