/* The Sony kernel functions the executable imports, declared here because the
 * build is freestanding (-nostdinc). Each name is the import's verified NID
 * name (tools/nid_names.py), reached through its PLT stub; the parameter
 * types are read from the calls in the base. */
#ifndef TLG_SCE_KERNEL_H
#define TLG_SCE_KERNEL_H

struct SceKernelSemaObject;                 /* derived name */
typedef SceKernelSemaObject *SceKernelSema; /* derived name: an 8-byte handle */

extern "C" {
int sceKernelCreateSema(SceKernelSema *sema, const char *name, unsigned int attr, int initCount,
                        int maxCount, const void *option);
int sceKernelDeleteSema(SceKernelSema sema);
int sceKernelWaitSema(SceKernelSema sema, int needCount, unsigned int *timeout);
int sceKernelSignalSema(SceKernelSema sema, int signalCount);
}

#endif
