/* src/include/tlg_game_mutex.h: the game's mutex wrapper. derived names. The
 * mutex at +0x0, its owner at +0x8 and depth at +0x10 (a recursive lock),
 * and, at +0x14, whether it was created; the destructor (leaf_013847e0.cpp)
 * destroys a created mutex and clears both. */
#ifndef TLG_GAME_MUTEX_H
#define TLG_GAME_MUTEX_H

#include "tlg_types.h"

#include "tlg_sce_kernel.h"

class Mutex013847e0 /* derived name */
{
  public:
    ~Mutex013847e0();

    /* unless the calling thread already owns it, locks the mutex and
     * becomes the owner; then counts one more level (the file system's
     * handle pool, 0xe5bb5e) */
    void lock()
    {
        pthread_t thread = scePthreadSelf();
        if (owner != thread) {
            scePthreadMutexLock(&mutex);
            owner = thread;
        }
        ++depth;
    }

    /* one level less; the last clears the owner and unlocks the mutex */
    void unlock()
    {
        --depth;
        if (depth == 0) {
            owner = 0;
            scePthreadMutexUnlock(&mutex);
        }
    }

  private:
    pthread_mutex_t mutex;
    /* volatile: shared between threads as RecursiveLock05945a38's are
     * (tlg_game_object05945a38.h): the owner compared before the mutex is
     * held, the depth tested again after its decrement (0xe5bbbc). */
    pthread_t volatile owner; /* +0x8 */
    volatile int depth;       /* +0x10 */
    int created;              /* +0x14 */
};

#endif
