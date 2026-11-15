/* src/include/tlg_game_object05945a38.h: the object the pointer at
 * 0x5945a38 holds (757 functions read it), as far as the four update
 * functions FUN_0133f330, FUN_01340240, FUN_01340310 and FUN_01342d50 read
 * it: the recursive lock at +0x201028. derived names throughout. */
#ifndef TLG_GAME_OBJECT05945A38_H
#define TLG_GAME_OBJECT05945A38_H

#include "tlg_game_node.h"
#include "tlg_sce_kernel.h"
#include "tlg_types.h"

/* the recursive lock (unless the calling thread already owns it, locks the
 * mutex and becomes the owner; then counts one more level; the last unlock
 * clears the owner and unlocks the mutex) */
struct RecursiveLock05945a38 { /* derived name */

    void lock()
    {
        pthread_t thread = scePthreadSelf();
        if (owner != thread) {
            scePthreadMutexLock(&mutex);
            owner = thread;
        }
        ++depth;
    }

    void unlock()
    {
        --depth;
        if (depth == 0) {
            owner = 0;
            scePthreadMutexUnlock(&mutex);
        }
    }

    pthread_mutex_t mutex; /* +0x0 */
    /* volatile: the state the recursive lock shares between threads, as
     * FUN_00ea2bd0's (cookbook 1205): the owner is compared with the calling
     * thread before the mutex is held (the base reads it into a register of
     * its own), the depth tested again after its decrement. */
    pthread_t volatile owner; /* +0x8 */
    volatile int depth;       /* +0x10 */
};

struct Object05945a38 { /* derived name */
    u8 unknown0[0x201028];
    RecursiveLock05945a38 lock201028; /* +0x201028 */
};

extern Object05945a38 *D_5945a38;

/* the object of a type under a name. A name that already names an object
 * this thread may use: with mode 1 the object gives its name up
 * (FUN_00cbc2d0 with the empty name) and a new one is made; with any other
 * mode the object itself is returned when its type is `type`, else null.
 * Otherwise a new one is made under the lock: the type's function runs with
 * the second heap of the table at 0x5943280 as the thread's heap and the
 * thread's flag at 0x16dc089 set, the type's listener is told, and the
 * object is registered (FUN_00cbb990). Null for a null type and for a type
 * that makes nothing. */
Node00503fb0 *FUN_00cbc5a0(Object05945a38 *owner, Type00503fb0 *type, const Name &name,
                           int mode); /* derived name */
/* gives the object the name; the result is not read where it is called */
int FUN_00cbc2d0(Object05945a38 *owner, Node00503fb0 *object, const Name &name); /* derived name */
/* registers a new object of the type under the name at +0xc of it */
void FUN_00cbb990(Object05945a38 *owner, Type00503fb0 *type, Node00503fb0 *object,
                  const Name *name); /* derived name */

#endif
