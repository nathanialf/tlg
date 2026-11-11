/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: slot 42 of the vtables at 0x16be490 and 0x16b93f8: drops one
 * level of the lock count at +0x340 and, at the last, clears the owner at
 * +0x338 and unlocks the mutex at +0x330. Class and method unknown. */
struct Object00ea2c20 { /* derived name */
    u8 unknown0[0x330];
    pthread_mutex_t mutex;
    /* volatile: the state the recursive lock shares between threads (its lock,
     * FUN_00ea2bd0, compares the owner with the calling thread before it
     * holds the mutex); the base re-reads the depth after decrementing it. */
    void *volatile owner; /* +0x338, derived name */
    volatile int depth;   /* +0x340, derived name */
};

void FUN_00ea2c20(Object00ea2c20 *self) /* derived name */
{
    --self->depth;
    if (self->depth == 0) {
        self->owner = 0;
        scePthreadMutexUnlock(&self->mutex);
    }
}
