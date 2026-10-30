/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkCriticalSection::hkCriticalSection(int spinCount) : spinCount(spinCount)
{
    pthread_mutexattr_t attr;
    HK_POSIX_CHECK(HK_POSIX_CRITICAL_SECTION_INL, 16, pthread_mutexattr_init(&attr));
    HK_POSIX_CHECK(HK_POSIX_CRITICAL_SECTION_INL, 17,
                   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE));
    HK_POSIX_CHECK(HK_POSIX_CRITICAL_SECTION_INL, 18, pthread_mutex_init(&m_mutex, &attr));
    HK_POSIX_CHECK(HK_POSIX_CRITICAL_SECTION_INL, 19, pthread_mutexattr_destroy(&attr));
}
