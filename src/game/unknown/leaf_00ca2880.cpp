/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_sce_kernel.h"

/* derived names: slots of the vtables holding them at 0x16b8c90 and
 * 0x16b8c68: each runs FUN_00c569b0 on its argument (with 0) under a read
 * lock of the lock the object at 0x5938c40 holds at +0x108: the reader count
 * at +0x23c taken by FUN_01331c10 and dropped atomically, both skipped when
 * the calling thread is the lock's writer (+0x248). The object itself is not
 * read. Classes and methods unknown. */
void FUN_01331c10(int *readers); /* derived name */

struct Lock00ca2880 { /* derived name */
    u8 unknown0[0x23c];
    int readers; /* +0x23c */
    u8 unknown240[0x8];
    pthread_t writer; /* +0x248 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x108];
    Lock00ca2880 *lock; /* +0x108 */

    void lockRead() /* derived name */
    {
        Lock00ca2880 *lock = this->lock;
        if (scePthreadSelf() != lock->writer)
            FUN_01331c10(&lock->readers);
    }

    void unlockRead() /* derived name */
    {
        Lock00ca2880 *lock = this->lock;
        if (scePthreadSelf() != lock->writer)
            __sync_fetch_and_sub(&lock->readers, 1);
    }
};

extern Object05938c40 *D_5938c40;

struct Object00ca2880; /* derived name */
struct Target00ca2880; /* derived name */

int FUN_00c569b0(Target00ca2880 *target,
                 int value); /* derived name; FUN_00d8feb0 adds its result */

void FUN_00ca2880(Object00ca2880 *, void *, Target00ca2880 *target) /* derived name */
{
    D_5938c40->lockRead();
    FUN_00c569b0(target, 0);
    D_5938c40->unlockRead();
}

void FUN_00ca28f0(Object00ca2880 *, Target00ca2880 *target) /* derived name */
{
    D_5938c40->lockRead();
    FUN_00c569b0(target, 0);
    D_5938c40->unlockRead();
}
