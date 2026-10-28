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
