/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: an unlock callback FUN_00eb45d0 stores at +0x4cd8 of a
 * record: on the recursive lock in the record the pointer at +0x100 of the
 * object the pointer at 0x5938c40 holds, clears the int at +0x188, drops one
 * from the depth at +0x180 and, at zero, clears the owner at +0x178 and
 * unlocks the mutex at +0x170 (a tail call), as leaf_00ea2c20.cpp's unlock
 * does. The callback's signature is taken from its body. */
struct Lock00ebf490 /* derived name */
{
    u8 unknown0[0x170];
    pthread_mutex_t mutex;
    /* volatile: the state the recursive lock shares between threads (as in
     * leaf_00ea2c20.cpp); the base re-reads the depth after decrementing it. */
    void *volatile owner; /* +0x178, derived name */
    volatile int depth;   /* +0x180, derived name */
    int unknown184;
    int unknown188; /* +0x188 */
};

struct Object05938c40 /* derived name */
{
    u8 unknown0[0x100];
    Lock00ebf490 *unknown100; /* +0x100 */
};

extern Object05938c40 *D_5938c40;

void FUN_00ebf490() /* derived name */
{
    Lock00ebf490 *lock = D_5938c40->unknown100;
    lock->unknown188 = 0;
    --lock->depth;
    if (lock->depth == 0) {
        lock->owner = 0;
        scePthreadMutexUnlock(&lock->mutex);
    }
}
