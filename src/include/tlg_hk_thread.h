/* Havok's threading primitives over the Sony kernel. */
#ifndef TLG_HK_THREAD_H
#define TLG_HK_THREAD_H

#include "tlg_hk_reflect.h"
#include "tlg_sce_kernel.h"

/* hkSemaphore: one kernel semaphore handle at +0, created under the name
 * "hkSemaphore" (0x14b4978) by its constructor 0x1a420 (initial and maximum
 * counts in its second and third arguments, attribute 1; the pool's
 * constructor at 0x6dcb passes a fourth, 0, which the kernel version does
 * not use). FUN_0001a440 deletes it (its callers then free the object),
 * FUN_0001a490 waits for one count and FUN_0001a4a0 signals the given
 * count. */
class hkSemaphore
{
  public:
    hkSemaphore(int initialCount, int maxCount, int numSpinIterations); /* derived names */

    void FUN_0001a440();          /* derived name: the destructor's body */
    void FUN_0001a490();          /* derived name: acquire */
    void FUN_0001a4a0(int count); /* derived name: release */

    SceKernelSema semaphore; /* derived name */
};

/* The object at +0x18 of Class168e810: a spin lock at +0x10; FUN_00015700
 * and FUN_000158f0 take a pointer and a count under it. */
struct Object00015700; /* derived name */

void FUN_00015700(Object00015700 *self, void *pointer, int count); /* derived name */
void FUN_000158f0(Object00015700 *self, void *pointer, int count); /* derived name */

struct Handle00016350;

/* What runs a work item (derived name): polymorphic, slot 2 the call
 * FUN_00016350 makes on the item's runner. Class168e810 keeps a default one
 * at +0x350 (vtable 0x168e7d0, address point 0x168e7e0, stored by the
 * constructor 0x16d40; slot 2 the empty 0xe5c0). */
class Runner00016350 /* derived name */
{
  public:
    virtual ~Runner00016350();
};

/* A work item (derived names): a 16-bit value at +4 and its runner at
 * +0x38, both set by slot 6 of Class168e810 (FUN_00017280). */
struct WorkItem00017280 /* derived name */
{
    u8 unknown0[4];
    u16 value4; /* derived name */
    u8 unknown6[0x32];
    Runner00016350 *runner; /* derived name */
};

/* An interface of ten slots, the second base (at +0x10, vtable address point
 * 0x168e888) of Class168e810, which overrides slots 2 to 9 in its primary
 * slots 5 to 12. */
class Interface168e888 /* derived name */
{
  public:
    virtual ~Interface168e888();

    virtual void FUN_00017240(void *pointer, int count) = 0; /* slot 2; derived name */
    virtual void FUN_00017280(WorkItem00017280 *item, Runner00016350 *runner,
                              u16 value) = 0; /* slot 3; derived name */
    /* Slots 4 to 6 and 8: their thunks FUN_000173e0, FUN_00017530, the
     * thunk of FUN_00017540 and FUN_00017a50 (signatures there). */
    virtual void unknownVirtual4() = 0;
    virtual void unknownVirtual5() = 0;
    virtual void unknownVirtual6() = 0;
    virtual void FUN_00017930(const Handle00016350 *handle) = 0; /* slot 7; derived name */
    virtual void unknownVirtual8() = 0;
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
    virtual void FUN_00017280(WorkItem00017280 *item, Runner00016350 *runner,
                              u16 value);                    /* vtable slot 6; derived name */
    virtual void FUN_00017930(const Handle00016350 *handle); /* vtable slot 10; derived name */
    virtual void FUN_00017260(void *pointer, int count);     /* vtable slot 12; derived name */

    Object00015700 *object18; /* derived name */
    u8 unknown20[0x330];
    Runner00016350 defaultRunner; /* derived name */
};

void FUN_00016f90(Class168e810 *self);                             /* derived name */
void FUN_000172c0(Class168e810 *self, void *pointer, void *other); /* derived name */
void FUN_000173f0(Class168e810 *self, void *pointer, int count);   /* derived name */
void FUN_00017540(Class168e810 *self, void *pointer, int count);   /* derived name */
void FUN_00017970(Class168e810 *self, void *pointer, int count);   /* derived name */

/* What FUN_00016350 runs on the object with a mode: the work of one handle,
 * or of none (derived names). A handle whose first int is -1 names
 * nothing: slot 10 (FUN_00017930) then does nothing, FUN_00017920 passes no
 * handle, and the callback FUN_00007730 runs FUN_00017920 with mode 0. */
struct Handle00016350 /* derived name */
{
    s32 value; /* derived name */
};

void FUN_00016350(Class168e810 *self, int mode, const Handle00016350 *handle); /* derived name */
void FUN_00017920(Class168e810 *self, int mode);                               /* derived name */

/* The interface of the physics world's tasks (derived name): the second
 * base, at +0x10, of each task class below (an hkReferencedObject first).
 * Its vtable holds the destructors, then the overriders of the class's
 * primary slots 5 (the task's work, taking only the task) and 6 (opens the
 * task's timer, whose name each one loads). Slot 2 of the second vtable is
 * the this-adjusting thunk of primary slot 5, which is too large to inline
 * into it; slot 3 is primary slot 6's thunk with the body inlined, folded
 * with the body itself where the body does not read the object. */
class hknpTaskInterface /* derived name */
{
  public:
    /* Empty and inline: no task destructor calls one or stores this
     * interface's vtable (0x14e4b0 stores only its own two). */
    virtual ~hknpTaskInterface() {}

    /* Slot 2: the task's work (derived name). */
    virtual void process() = 0;
    /* Slot 3: the task's timer name, and a description when one is asked
     * for (0x14e760 copies "Solve/SolverFactory"; derived name). */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const = 0;
};

/* The task classes (derived names, from their timer names): primary vtable
 * address point, second vtable address point, primary slot 5. */

/* The arrays the solver factory task fills (derived name): a reference-
 * counted object of 0x50 bytes (vtable 0x1698f40, no type info; slots 0
 * 0x481b0, 1 0x481c0, then the common 0x270, 0x42d0, 0x69a0), constructed
 * by FUN_00092280 (the four arrays empty), destroyed by 0x48040, which
 * restores the vtable, releases the references from the last and frees
 * the four arrays. The complete destructor 0x481b0 is a lone jump to that
 * base destructor, the shape of a destructor the compiler could not alias
 * (cookbook 9): the destructor is the class's implicit, inline one. Here it
 * is declared, as the tasks reach it through a call. */
class RefArrays /* derived name */ : public hkReferencedObject
{
  public:
    ~RefArrays();

    hkArray<Vec4> array10;                    /* derived name */
    hkArray<int> array20;                     /* derived name */
    hkArray<void *> array30;                  /* derived name */
    hkArray<hkReferencedObject *> references; /* derived name */
};

/* hknpSolverFactoryTask: vtables 0x16a4090 and 0x16a40d8; slot 6 opens the
 * timer "Solve/SolverFactory". 0x90 bytes, built by FUN_00151250 at
 * 0x1515a1 (value-initialized, then the four pointers stored); slot 5
 * (0x14e540) builds the solve data task (0x16e0e0) in the object at +0x20
 * and fills the arrays from the solver's data. Destructors 0x14e4b0 (and
 * its thunk 0x14e7b0), deleting 0x14e4d0 (0x14e7d0). */
class hknpSolverFactoryTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    virtual ~hknpSolverFactoryTask();

    /* slot 5 (0x14e540; the interface's slot 2 through the thunk 0x14e840) */
    virtual void process();
    /* slot 6 (0x14e760, also the interface's slot 3) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    void *unknown18;  /* derived name; its slots 2 and 3 called by the builder, 4 and 6 by slot 5 */
    void *unknown20;  /* derived name; the object whose +0x190 holds the solve data task */
    void *unknown28;  /* derived name */
    void *unknown30;  /* derived name; written by unknown18's slot 2 */
    RefArrays arrays; /* derived name */
    u8 unknown88[8];
};

/* hknpAddActiveBodyPairsTask: vtables 0x16a4110 and 0x16a4158; slot 6 opens the timer "Deactivation/AddActiveBodyPairs". */
class hknpAddActiveBodyPairsTask : public hkReferencedObject,
                                   public hknpTaskInterface /* derived name */
{
};

/* hknpSolveFinalizeTask: vtables 0x16a4190 and 0x16a41d8; slot 6 opens the timer "Solve/Finalize". */
class hknpSolveFinalizeTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
};

/* hknpCleanInactiveCachesTask: vtables 0x16a4210 and 0x16a4258; slot 6 opens the timer "Deactivation/Clean Inactive Caches". */
class hknpCleanInactiveCachesTask : public hkReferencedObject,
                                    public hknpTaskInterface /* derived name */
{
};

/* hknpProcessSecondRoundResultsTask: vtables 0x16a4290 and 0x16a42d8; slot 6 opens the timer "Collide/Process Second Round Results". */
class hknpProcessSecondRoundResultsTask : public hkReferencedObject,
                                          public hknpTaskInterface /* derived name */
{
};

/* hknpProcessFirstRoundResultsTask: vtables 0x16a4310 and 0x16a4358; slot 6 opens the timer "Collide/Process First Round Results". */
class hknpProcessFirstRoundResultsTask : public hkReferencedObject,
                                         public hknpTaskInterface /* derived name */
{
};

/* hknpPrepareConstraintsTask: vtables 0x16a4650 and 0x16a4698; slot 6 opens the timer "Constraints/Prepare". */
class hknpPrepareConstraintsTask : public hkReferencedObject,
                                   public hknpTaskInterface /* derived name */
{
};

/* hknpBuildConstraintsTask: vtables 0x16a46d0 and 0x16a4718; slot 6 opens the timer "Constraints/Build Active" or "Build Activated Constraints". */
class hknpBuildConstraintsTask : public hkReferencedObject,
                                 public hknpTaskInterface /* derived name */
{
};

/* hknpPrepareNewPairsTask: vtables 0x16a4ce0 and 0x16a4d28; slot 6 opens the timer "Collide/Prepare New Pairs". */
class hknpPrepareNewPairsTask : public hkReferencedObject,
                                public hknpTaskInterface /* derived name */
{
};

/* The narrow phase's pairs task (derived name; vtables 0x16a4ee0 and
 * 0x16a4f28): slot 6 opens "Collide/Existing Pairs" or "Collide/New Pairs";
 * its complete destructor FUN_0015dc50 jumps to FUN_0015dee0, which
 * restores both vtables and destroys the 0x710-byte records of the array
 * at +0x108. */
class hknpCollidePairsTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
};

/* A 16-byte task of the broad phase (derived name from its timer name;
 * vtable 0x16a6690, stored at 0x18d673 into +0x20 of the object at +8): the
 * task interface implemented directly, its owner at +8. Slot 3
 * (FUN_0018ce10) names it "BroadPhase/Update dirty bodies". */
class hknpBroadPhaseUpdateDirtyBodiesTask : public hknpTaskInterface /* derived name */
{
  public:
    void FUN_0018ce10(hkStringBuf *name,
                      hkStringBuf *description) const; /* vtable slot 3; derived name */

    void *owner; /* derived name */
};

/* The solver's stage tasks (derived name): 0x30-byte objects built in an
 * array by 0x18e6e0, vtables 0x16a6760 and 0x16a67a8; slot 6 (0x18f140)
 * writes the task's name ("Solve/%s %i", the stage code from +0x20) into a
 * string buffer, and a node description into the second when given. The
 * second vtable's slots 2 and 3 are the this-adjusting thunks of primary
 * slots 5 and 6, both too large to inline; the complete destructor is the
 * shared empty body 0x17de10. */
class hknpSolverStageTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
};

/* hknpPrepareExistingPairsTask (derived name): vtables 0x16a5c70 and 0x16a5cb8,
 * constructor 0x179840 (stores the two arguments at +0x18 and +0x20); slot 6
 * opens the timer "Collide/Prepare Existing Pairs"; its complete destructor
 * is the shared empty body 0x175a80. */
class hknpPrepareExistingPairsTask : public hkReferencedObject,
                                     public hknpTaskInterface /* derived name */
{
  public:
    hknpPrepareExistingPairsTask(void *unknown18, void *unknown20);

    /* slot 5 (0x1798c0; the interface's slot 2 through the thunk 0x179c70) */
    virtual void process();
    /* slot 6 (0x179870, also the interface's slot 3) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    void *
        unknown18; /* derived name; passed to FUN_0016ff90 by slot 5 and by the builder FUN_00150330 */
    void *unknown20; /* derived name; the builder's own object */
};

/* The solver's data task (derived name; vtables 0x16a5690 and 0x16a56d8,
 * constructor 0x16e0e0): slot 5 (0x16ec30) opens the timer "Solve/Data";
 * its complete destructor FUN_0016eaa0 restores both vtables and frees the
 * arrays at +0x20 and +0xc0 (48-byte polymorphic elements) and the blocks at
 * +0x30, +0x38 and +0xb8; the deleting destructor frees 0xe0 bytes by
 * default. */
class hknpSolveDataTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
};

void FUN_0014e540(hknpSolverFactoryTask *self);             /* vtable slot 5; derived name */
void FUN_0014e850(hknpAddActiveBodyPairsTask *self);        /* vtable slot 5; derived name */
void FUN_0014ea20(hknpSolveFinalizeTask *self);             /* vtable slot 5; derived name */
void FUN_0014eee0(hknpCleanInactiveCachesTask *self);       /* vtable slot 5; derived name */
void FUN_0014f190(hknpProcessSecondRoundResultsTask *self); /* vtable slot 5; derived name */
void FUN_0014fa50(hknpProcessFirstRoundResultsTask *self);  /* vtable slot 5; derived name */
void FUN_00154f50(hknpPrepareConstraintsTask *self);        /* vtable slot 5; derived name */
void FUN_001551a0(hknpBuildConstraintsTask *self);          /* vtable slot 5; derived name */
void FUN_0015b7a0(hknpPrepareNewPairsTask *self);           /* vtable slot 5; derived name */
void FUN_0015dee0(hknpCollidePairsTask *self);              /* derived name */
void FUN_0015ea30(hknpCollidePairsTask *self);              /* vtable slot 5; derived name */
void FUN_0016eaa0(hknpSolveDataTask *self);                 /* derived name */
void FUN_001798c0(hknpPrepareExistingPairsTask *self);      /* vtable slot 5; derived name */
void FUN_0018ef40(hknpSolverStageTask *self);               /* vtable slot 5; derived name */
void FUN_0018f140(hknpSolverStageTask *self, hkStringBuf *name,
                  hkStringBuf *description); /* vtable slot 6; derived name */

#endif
