/* src/include/tlg_game_render_mutex.h: the render library's mutex and
 * condition variable (render/ps4/util/mutex.h and condition_variable.h, as
 * their reports name the files), whose inline methods report with the path
 * the including unit gives the header: the unit defines RENDER_UTIL_DIR, the
 * directory up to and with "util/", before including this. m_initialized is
 * named by Lock's check (0x130a965); the methods by their reports. The
 * destructors run Destory, inline: every unit that destroys one inlines it
 * with its own path (0x149aa20). Mutex0139ddf0 and ConditionVariable0139ded0
 * (leaf_0139ddf0.cpp, leaf_0139ded0.cpp) are the same types as the out-of-line
 * copies a props unit emits; they keep their own definitions there. */
#ifndef TLG_GAME_RENDER_MUTEX_H
#define TLG_GAME_RENDER_MUTEX_H

#include "tlg_types.h"

#include "tlg_game_assert.h"
#include "tlg_sce_kernel.h"

#ifndef RENDER_UTIL_DIR
#error "RENDER_UTIL_DIR: the including unit's path to render/ps4/util/"
#endif

class Mutex /* derived name, from the header's file name */
{
    friend class ConditionVariable;

  public:
    ~Mutex()
    {
        Destory();
    }

    void Lock()
    {
        ANZU_ASSERT(RENDER_UTIL_DIR "mutex.h", 135, m_initialized);
        int rc = scePthreadMutexLock(&m_mutex);
        ANZU_ASSERT(RENDER_UTIL_DIR "mutex.h", 137, rc == SCE_OK);
    }

    void Unlock()
    {
        ANZU_ASSERT(RENDER_UTIL_DIR "mutex.h", 152, m_initialized);
        int rc = scePthreadMutexUnlock(&m_mutex);
        ANZU_ASSERT(RENDER_UTIL_DIR "mutex.h", 154, rc == SCE_OK);
    }

    void Destory()
    {
        if (m_initialized) {
            int rc = scePthreadMutexDestroy(&m_mutex);
            ANZU_ASSERT(RENDER_UTIL_DIR "mutex.h", 126, rc == SCE_OK);
            m_initialized = false;
        }
    }

  private:
    pthread_mutex_t m_mutex; /* derived name */
    bool m_initialized;      /* +0x8 */
};

class ConditionVariable /* derived name, from the header's file name */
{
  public:
    ~ConditionVariable()
    {
        Destory();
    }

    void Wait(Mutex &mutex)
    {
        ANZU_ASSERT(RENDER_UTIL_DIR "condition_variable.h", 128, m_initialized);
        int ret = scePthreadCondWait(&m_cond, &mutex.m_mutex);
        ANZU_ASSERT(RENDER_UTIL_DIR "condition_variable.h", 130, ret == SCE_OK);
    }

    void Signal()
    {
        ANZU_ASSERT(RENDER_UTIL_DIR "condition_variable.h", 144, m_initialized);
        int ret = scePthreadCondSignal(&m_cond);
        ANZU_ASSERT(RENDER_UTIL_DIR "condition_variable.h", 146, ret == SCE_OK);
    }

    void Broadcast()
    {
        ANZU_ASSERT(RENDER_UTIL_DIR "condition_variable.h", 153, m_initialized);
        int ret = scePthreadCondBroadcast(&m_cond);
        ANZU_ASSERT(RENDER_UTIL_DIR "condition_variable.h", 155, ret == SCE_OK);
    }

    void Destory()
    {
        if (m_initialized) {
            int ret = scePthreadCondDestroy(&m_cond);
            ANZU_ASSERT(RENDER_UTIL_DIR "condition_variable.h", 119, ret == SCE_OK);
            m_initialized = false;
        }
    }

  private:
    pthread_cond_t m_cond; /* derived name */
    bool m_initialized;    /* derived name, as the mutex's; +0x8 */
};

#endif
