/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_sce_kernel.h"

/* derived names: takes the read-write lock at +0x8 for writing through
 * scePthreadRwlockWrlock (the import's name verified by its NID,
 * tools/nid_names.py) as a tail call; slot 9 of the vtable at 0x16b55a0 (its
 * pointer at 0x16b55f8), the vtable stored by FUN_00908b80 FUN_00b32dd0
 * FUN_00b32f80 FUN_00b32fc0; slot 9 of the vtable at 0x16b5608 (its pointer at
 * 0x16b5660), the vtable stored by FUN_00b33e00 FUN_00b34150 FUN_00b34200. The
 * return type is not traced. Class and method unknown. */
struct Object01393750 { /* derived name */
    u8 unknown0[0x8];
    pthread_rwlock_t lock; /* taken by FUN_01393750 and FUN_01393770, released by FUN_01393760 */
};

void FUN_01393770(Object01393750 *self) /* derived name */
{
    scePthreadRwlockWrlock(&self->lock);
}
