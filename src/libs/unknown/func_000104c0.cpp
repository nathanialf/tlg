/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* A started thread joined and forgotten (0x10520). */
void hkThread::joinThread()
{
    if (m_thread) {
        HK_POSIX_CHECK(HK_POSIX_THREAD_CPP, 41, pthread_join((pthread_t)m_thread, HK_NULL));
        m_thread = 0;
    }
}

/* hkThread's destructor (0x104c0): the thread joined, inline. */
hkThread::~hkThread()
{
    joinThread();
}

/* derived name: the thread started (0x10580). */
hkResult hkThread::startThread(void *(*startFunction)(void *), void *arg, const char *name,
                               int stackSize)
{
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, 0);
    if (stackSize > 0) {
        pthread_attr_setstacksize(&attr, stackSize);
    }
    const int result = pthread_create_name_np(&thread, &attr, startFunction, arg, name);
    pthread_attr_destroy(&attr);
    if (result != 0) {
        perror("Thread Error\n");
        return HK_FAILURE;
    }
    m_thread = thread;
    status = 1;
    return HK_SUCCESS;
}
