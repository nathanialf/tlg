/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_readlock.h"

#include "tlg_sce_kernel.h"

/* derived names: a job (its address stored at 0xd8db2f) that runs
 * FUN_00c56950 on its target (+0x18) under a read lock of the lock the
 * object at 0x5938c40 holds at +0x108, as FUN_00ca2880 does (the reader
 * count at +0x23c taken by FUN_01331c10 and dropped atomically, both skipped
 * when the calling thread is the lock's writer at +0x248), and adds the
 * result atomically to the int its +0x10 points to. The target's class is
 * not traced. */

struct Lock00d8fe30 { /* derived name */
    u8 unknown0[0x23c];
    ReadLock01331c10 readers; /* +0x23c */
    u8 unknown240[0x8];
    pthread_t writer; /* +0x248 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x108];
    Lock00d8fe30 *lock; /* +0x108 */

    void lockRead() /* derived name */
    {
        Lock00d8fe30 *lock = this->lock;
        if (scePthreadSelf() != lock->writer)
            FUN_01331c10(&lock->readers);
    }

    void unlockRead() /* derived name */
    {
        Lock00d8fe30 *lock = this->lock;
        if (scePthreadSelf() != lock->writer)
            __sync_fetch_and_sub(&lock->readers.count, 1);
    }
};

extern Object05938c40 *D_5938c40;

struct Target00d8fe30; /* derived name */

int FUN_00c56950(Target00d8fe30 *target); /* derived name */

struct Job00d8fe30 { /* derived name */
    u8 unknown0[0x10];
    int *total;             /* +0x10, derived name */
    Target00d8fe30 *target; /* +0x18, derived name */
};

void FUN_00d8fe30(Job00d8fe30 *job) /* derived name */
{
    int *total = job->total;
    Target00d8fe30 *target = job->target;
    D_5938c40->lockRead();
    int value = FUN_00c56950(target);
    D_5938c40->unlockRead();
    __sync_fetch_and_add(total, value);
}
