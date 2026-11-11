/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: slots 41 and 42 of the vtables at 0x16be490 and 0x16b93f8.
 * Slot 41 takes the recursive lock: unless the calling thread already owns
 * it, locks the mutex at +0x330 and becomes the owner at +0x338; then counts
 * one more level at +0x340 and returns 1. Slot 42 drops one
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

int FUN_00ea2bd0(Object00ea2c20 *self) /* derived name */
{
    pthread_t thread = scePthreadSelf();
    if (self->owner != thread) {
        scePthreadMutexLock(&self->mutex);
        self->owner = thread;
    }
    ++self->depth;
    return 1;
}
