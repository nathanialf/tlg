/* Havok's threading primitives over the Sony kernel. */
#ifndef TLG_HK_THREAD_H
#define TLG_HK_THREAD_H

#include "tlg_hk_reflect.h"
#include "tlg_sce_kernel.h"

/* hkSemaphore: one kernel semaphore handle at +0, created under the name
 * "hkSemaphore" (0x14b4978) by FUN_0001a420 (initial and maximum counts in
 * its second and third arguments, attribute 1). FUN_0001a440 deletes it (its
 * callers then free the object), FUN_0001a490 waits for one count and
 * FUN_0001a4a0 signals the given count. */
class hkSemaphore
{
  public:
    void FUN_0001a440();          /* derived name: the destructor's body */
    void FUN_0001a4a0(int count); /* derived name: release */

    SceKernelSema semaphore; /* derived name */
};

/* The object at +0x18 of Class168e810: a spin lock at +0x10; FUN_00015700
 * and FUN_000158f0 take a pointer and a count under it. */
struct Object00015700; /* derived name */

void FUN_00015700(Object00015700 *self, void *pointer, int count); /* derived name */
void FUN_000158f0(Object00015700 *self, void *pointer, int count); /* derived name */

/* An interface of ten slots, the second base (at +0x10, vtable address point
 * 0x168e888) of Class168e810, which overrides slots 2 to 9 in its primary
 * slots 5 to 12. */
class Interface168e888 /* derived name */
{
  public:
    virtual ~Interface168e888();

    virtual void FUN_00017240(void *pointer, int count) = 0; /* slot 2; derived name */
    virtual void FUN_00017260(void *pointer, int count) = 0; /* slot 9; derived name */
};

/* A reference-counted object (vtable address points 0x168e810 and, for the
 * second base, 0x168e888, both stored by its constructor 0x16d40 and its
 * complete destructor FUN_00016f90; size 0x370 by its deleting destructor)
 * with the interface above at +0x10, the object above at +0x18, a critical
 * section at +0x30 and 64 semaphores from +0x148, each released once by
 * FUN_000170d0 under the lock (flag at +0x362). Slots 5 and 12 forward to
 * the object at +0x18; slots 7, 8, 9 and 11 (FUN_000172c0, FUN_000173f0,
 * FUN_00017540, FUN_00017970) run under the critical section. */
class Class168e810 : public hkReferencedObject, public Interface168e888 /* derived name */
{
  public:
    virtual ~Class168e810();

    virtual void FUN_00017240(void *pointer, int count); /* vtable slot 5; derived name */
    virtual void FUN_00017260(void *pointer, int count); /* vtable slot 12; derived name */

    Object00015700 *object18; /* derived name */
};

void FUN_00016f90(Class168e810 *self);                             /* derived name */
void FUN_000172c0(Class168e810 *self, void *pointer, void *other); /* derived name */
void FUN_000173f0(Class168e810 *self, void *pointer, int count);   /* derived name */
void FUN_00017540(Class168e810 *self, void *pointer, int count);   /* derived name */
void FUN_00017970(Class168e810 *self, void *pointer, int count);   /* derived name */

#endif
