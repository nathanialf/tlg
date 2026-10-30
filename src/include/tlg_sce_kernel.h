/* The Sony kernel functions the executable imports, declared here because the
 * build is freestanding (-nostdinc). Each name is the import's verified NID
 * name (tools/nid_names.py), reached through its PLT stub; the parameter
 * types are read from the calls in the base. */
#ifndef TLG_SCE_KERNEL_H
#define TLG_SCE_KERNEL_H

struct SceKernelSemaObject;                 /* derived name */
typedef SceKernelSemaObject *SceKernelSema; /* derived name: an 8-byte handle */

/* The POSIX mutex of the kernel library: a handle, as FreeBSD's
 * pthread_mutex_t is a pointer to the library's own record (the critical
 * section's 16 bytes hold it and an int). */
struct pthread_mutex;
typedef pthread_mutex *pthread_mutex_t;

/* A thread of the kernel library: a handle (hkThread keeps one, 0x104c0). */
struct pthread;
typedef pthread *pthread_t;

extern "C" {
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_join(pthread_t thread, void **valuePtr);
int sceKernelCreateSema(SceKernelSema *sema, const char *name, unsigned int attr, int initCount,
                        int maxCount, const void *option);
int sceKernelDeleteSema(SceKernelSema sema);
int sceKernelWaitSema(SceKernelSema sema, int needCount, unsigned int *timeout);
int sceKernelSignalSema(SceKernelSema sema, int signalCount);
}

#endif
