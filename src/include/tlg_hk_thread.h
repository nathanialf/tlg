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

/* hkThread (derived name; its functions are hkPosixThread.cpp's, the path
 * its checks print): the kernel thread at +0 (m_thread, the name its check's
 * text gives), null until started, and a status at +8 (2 on construction,
 * 0x104b0). The destructor (0x104c0) joins a started thread as joinThread
 * (0x10520, the name its check prints) does, inline. */
class hkThread /* derived name */
{
  public:
    ~hkThread();

    void joinThread();

    /* The thread started on a function and its argument, under a name,
     * joinable, with the stack size given when it is positive (0x10580);
     * "Thread Error" printed and a failure when it cannot be. derived
     * names. */
    hkResult startThread(void *(*startFunction)(void *), void *arg, const char *name,
                         int stackSize);

    void *m_thread;
    s64 status; /* derived name: 2 before the start, 1 after (8-byte stores) */
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
    /* Empty (the shared 0xe5c0); the deleting destructor 0x13e50 frees
     * the object's 16 bytes on the thread's heap, the body ten other
     * vtables of 16-byte classes with empty destructors cite by address. */
    virtual ~Runner00016350();

    virtual void unknownVirtual2(); /* the empty 0xe5c0 */

    /* Slot 3 (0x91af0): a name and attributes for the task graph's dumps
     * (FUN_00091b30's fill colours are such attributes): "Unnamed", and no
     * attributes when asked for them. derived name. */
    virtual void FUN_00091af0(hkStringBuf &name, hkStringBuf *attributes) const;

    static void operator delete(void *object, unsigned long numBytes);

    u8 unknown8[8];
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
 * the object at +0x18; slots 7, 8 and 9 (FUN_000172c0, FUN_000173f0,
 * FUN_00017540) run under the critical section, slot 11 (FUN_00017970)
 * takes no lock. */
class Class168e810 : public hkReferencedObject, public Interface168e888 /* derived name */
{
  public:
    virtual ~Class168e810();

    virtual void FUN_00017240(void *pointer, int count); /* vtable slot 5; derived name */
    virtual void FUN_00017280(WorkItem00017280 *item, Runner00016350 *runner,
                              u16 value);                    /* vtable slot 6; derived name */
    virtual void FUN_00017930(const Handle00016350 *handle); /* vtable slot 10; derived name */
    virtual void FUN_00017260(void *pointer, int count);     /* vtable slot 12; derived name */

    /* Slot 11 (0x17970): the handles that name something gathered into a
     * temporary array and handed to the interface's run of several
     * (FUN_00092fe0). derived name. */
    void FUN_00017970(const Handle00016350 *const *handles, int numHandles);

    Object00015700 *object18; /* derived name */
    u8 unknown20[0x330];
    Runner00016350 defaultRunner; /* derived name */
    u8 unknown360[0x10];
};

void FUN_00016f90(Class168e810 *self); /* derived name */
/* Its deleting destructor (slot 1, 0x16ee0), written as calls while the
 * destructor is not (cookbook 15, 97). derived name. */
void FUN_00016ee0(Class168e810 *self);
/* The interface's thunk of it (slot 1 of the second vtable, 0x16f30), on
 * the object 16 bytes before the interface. derived name. */
void FUN_00016f30(Interface168e888 *self);
void FUN_000172c0(Class168e810 *self, void *pointer, void *other); /* derived name */
void FUN_000173f0(Class168e810 *self, void *pointer, int count);   /* derived name */
void FUN_00017540(Class168e810 *self, void *pointer, int count);   /* derived name */

/* Handles run through an interface (0x92fe0; Class168e810's slot 11 hands
 * it the ones that name something): one through slot 7, two or more as a
 * batch. derived name. */
void FUN_00092fe0(Interface168e888 *runner, const Handle00016350 *const *handles,
                  int numHandles); /* derived name */

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

/* derived name: the Graphviz fill colour of a node in one of three states
 * (0x91b30), the attributes the tasks' names come with. */
const char *FUN_00091b30(int state); /* derived name */

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
/* What a RefArrays hands its pointers back to (derived name; the third
 * argument of 0x50880 and 0x514a0): slot 7 takes what 0x92650 builds from
 * the arrays, slot 9 a list of pointers. */
class RefArraysOwner /* derived name */
{
  public:
    virtual ~RefArraysOwner();
    virtual void unknownVirtual2();
    virtual void unknownVirtual3();
    virtual void unknownVirtual4();
    virtual void unknownVirtual5();
    virtual void unknownVirtual6();
    virtual void unknownVirtual7(void *built);
    virtual void unknownVirtual8();
    virtual void unknownVirtual9(void *const *pointers, int numPointers);
};

/* What hands the solver's arrays their objects (derived name; the factory
 * task's +0x18, whose slots 2 and 3 the builder calls): slot 2 fills a
 * count of pointers. */
class RefArraysAllocator /* derived name */
{
  public:
    virtual void unknownVirtual0();
    virtual void unknownVirtual1();
    virtual void allocate(void **pointersOut, int numPointers); /* slot 2; derived name */
};

class RefArrays /* derived name */ : public hkReferencedObject
{
  public:
    /* An entry's 16-bit index, passed by value as a two-byte struct (the
     * callee widens it, 0x925e4). derived name. */
    struct EntryId {
        u16 value; /* derived name */
    };

    /* A 16-byte entry of the first array (derived names): the task and two
     * 16-bit values it is added with (0x922f0), then two 16-bit fields,
     * reset to 0xffff and 0 by 0x92e70. */
    struct Entry10 {
        hknpTaskInterface *task;
        u16 unknown8;
        u16 unknownA;
        u16 unknownC;
        u16 unknownE;
    };

    /* Out of line (0x92280; the solver's tasks build one on the stack at
     * 0x508e6 and 0x51501, its derived class's constructor at 0x15160f):
     * the four arrays empty. */
    RefArrays();

    ~RefArrays();

    /* The pointers handed back to the owner's slot 9 and dropped, and every
     * entry of the first array reset (0x92e70, after the arrays' use at
     * 0x50997 and 0x515b1). derived name. */
    void FUN_00092e70(RefArraysOwner *owner);

    /* A new pointer from the allocator appended to the third array, the
     * entry at an index marked (+0xe) and given its position there (+0xc)
     * (0x925d0; the factory task's slot 5 at 0x14e6da). derived name. */
    void *FUN_000925d0(RefArraysAllocator *allocator, EntryId entryId);

    /* A task appended to the first array with its two values, its fields
     * at +0xc and +0xe reset; the new entry's index returned (0x922f0; the
     * world's step stages at 0x50554, 0x50e76 and 0x50f42, the solver
     * factory task at 0x14e69f, 0x18d960 six times). derived name. */
    EntryId FUN_000922f0(hknpTaskInterface *task, int value8, int valueA);

    /* Room reserved for a number of entries in the first array and the
     * references, and for a number of ints in the second (0x92510; the
     * world's step stages at 0x504d8 and 0x50e28, the solver factory task at
     * 0x14e68e). derived name. */
    void FUN_00092510(int numEntries, int numInts);

    hkArray<Entry10> array10;                 /* derived name */
    hkArray<int> array20;                     /* derived name */
    hkArray<void *> array30;                  /* derived name */
    hkArray<hkReferencedObject *> references; /* derived name */
};

/* The deleting destructor of RefArrays (0x481c0, slot 1 of its vtable): the
 * base destructor, then its 0x50 bytes back to the thread's heap unless
 * null. Written as calls while the inline destructor's body is not written
 * (cookbook 15). derived name. */
void FUN_000481c0(RefArrays *self); /* derived name */

/* A RefArrays with two 64-bit values after it, both -1 when built (vtable
 * 0x1698f80, no type info; built on the stack at 0x508eb and 0x51506 over
 * RefArrays's constructor FUN_00092280; slot 0 the shared 0x481b0, slot 1
 * its deleting destructor 0x48210, which frees 0x60 bytes). derived
 * names. */
class RefArrays1698f80 : public RefArrays /* derived name */
{
  public:
    s64 value50; /* derived name */
    s64 value58; /* derived name */
};

void FUN_00048210(RefArrays1698f80 *self); /* derived name */

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

    /* The reference-counted class delete (tlg_lib_unknown.h): the deleting
     * destructor 0x14e4d0 frees at the recorded size, 0x90 by default. */
    static void operator delete(void *object, unsigned long numBytes);

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
  public:
    /* slot 6 (0x14e9c0) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;
};

/* hknpSolveFinalizeTask: vtables 0x16a4190 and 0x16a41d8; slot 6 opens the timer "Solve/Finalize". */
class hknpSolveFinalizeTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* slot 6 (0x14ee80) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;
};

/* hknpCleanInactiveCachesTask: vtables 0x16a4210 and 0x16a4258; slot 6 opens the timer "Deactivation/Clean Inactive Caches".
 * 0x50 bytes from the thread's heap, built inline by FUN_00150330 at
 * 0x150f68 (+0x3c and +0x40 cleared, the owner and a second pointer at
 * +0x18 and +0x20). */
class hknpCleanInactiveCachesTask : public hkReferencedObject,
                                    public hknpTaskInterface /* derived name */
{
  public:
    /* Empty (the shared 0xadd50); its deleting destructor is the shared
     * 0x8a210 and the interface's thunk of it, 0x14f130, sits beside this
     * class's slots (D15), cited by this vtable alone. */
    virtual ~hknpCleanInactiveCachesTask();

    static void operator delete(void *object, unsigned long numBytes);

    /* slot 5 (0x14eee0) */
    virtual void process();
    /* slot 6 (0x14f0e0) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    void *unknown18;    /* derived name */
    void *unknown20;    /* derived name */
    u8 unknown28[0x14]; /* derived name */
    int unknown3c;      /* derived name */
    void *unknown40;    /* derived name */
    u8 unknown48[8];    /* derived name */
};

/* hknpProcessSecondRoundResultsTask: vtables 0x16a4290 and 0x16a42d8; slot 6 opens the timer "Collide/Process Second Round Results". */
class hknpProcessSecondRoundResultsTask : public hkReferencedObject,
                                          public hknpTaskInterface /* derived name */
{
  public:
    /* slot 6 (0x14f9f0) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;
};

/* hknpProcessFirstRoundResultsTask: vtables 0x16a4310 and 0x16a4358; slot 6 opens the timer "Collide/Process First Round Results". */
class hknpProcessFirstRoundResultsTask : public hkReferencedObject,
                                         public hknpTaskInterface /* derived name */
{
  public:
    /* slot 6 (0x1501e0) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;
};

/* hknpPrepareConstraintsTask: vtables 0x16a4650 and 0x16a4698; slot 6 opens the timer "Constraints/Prepare". */
class hknpPrepareConstraintsTask : public hkReferencedObject,
                                   public hknpTaskInterface /* derived name */
{
  public:
    /* 0x154ed0, called by FUN_00150330 with two members of its object
     * (+0x120 and +0x138). */
    hknpPrepareConstraintsTask(void *unknown18, void *unknown20, void *unknown28);

    /* slot 5 (0x154f50; the interface's slot 2 through the thunk 0x1550b0) */
    virtual void process();
    /* slot 6 (0x154f00, also the interface's slot 3) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    void *unknown18; /* derived name */
    void *unknown20; /* derived name */
    void *unknown28; /* derived name */
};

/* Three tasks the world's set-up FUN_00048b20 builds (vtables 0x1699060,
 * 0x16990e0 and 0x1699160, no type info; slots 0 to 4 those of the
 * constraint tasks, 0x3b640, 0x383f0, 0x270, 0x42d0, 0x69a0), named after
 * the names their slot 6 gives: "Post Solve" (0x14bdd14), "Pre Solve"
 * (0x14bdd32) and "Post Collide" (0x14bdd3c), described in the third
 * state's colour. Slot 5 (0x48670, 0x487c0, 0x48960) runs under the
 * timer "Physics". Each is 0x30 bytes from the thread's heap, zeroed,
 * then +0x20 and +0x18 cleared again; slot 5 passes +0x18 to the world's
 * step functions. */
class hknpPostSolveTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* slot 5 (0x48670) */
    virtual void process();
    /* slot 6 (0x486f0) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    hknpWorld *world; /* derived name */
    void *unknown20;  /* derived name */
    void *unknown28;  /* derived name */
};

class hknpPreSolveTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* Empty; its deleting destructor is the shared 0x383f0 and the
     * interface's thunk of it, 0x48890, sits beside this class's slots
     * (D15), slot 1 of the three tasks' second vtables and of seven other
     * 0x30-byte tasks'. */
    virtual ~hknpPreSolveTask();

    static void operator delete(void *object, unsigned long numBytes);

    /* slot 5 (0x487c0) */
    virtual void process();
    /* slot 6 (0x48840) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    hknpWorld *world; /* derived name */
    void *unknown20;  /* derived name */
    void *unknown28;  /* derived name */
};

class hknpPostCollideTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* slot 5 (0x48960) */
    virtual void process();
    /* slot 6 (0x489f0) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    hknpWorld *world; /* derived name */
    void *unknown20;  /* derived name */
    void *unknown28;  /* derived name */
};

/* hknpBuildConstraintsTask: vtables 0x16a46d0 and 0x16a4718; slot 6 opens the timer "Constraints/Build Active" or "Build Activated Constraints". */
class hknpBuildConstraintsTask : public hkReferencedObject,
                                 public hknpTaskInterface /* derived name */
{
  public:
    /* 0x1550c0, called by FUN_00150330 (0x150c33, 0x150daa) on 0x40 bytes
     * from the thread's heap: an int (0 at 0x150c2b), two pointers and an
     * address inside the owner (+0x138); the count at +0x38 starts at 0. */
    hknpBuildConstraintsTask(int unknown18, void *unknown28, void *unknown20, void *unknown30);

    /* Empty (the shared 0xadd50); its deleting destructor is the shared
     * 0x1ba80 (named for hknpRefMassDistribution, D15) and the interface's
     * thunk of it is 0x154e80, cited by this vtable alone. */
    virtual ~hknpBuildConstraintsTask();

    static void operator delete(void *object, unsigned long numBytes);

    /* slot 5 (0x1551a0) */
    virtual void process();
    /* slot 6 (0x155100; the interface's thunk 0x155150) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    int unknown18;   /* derived name */
    void *unknown20; /* derived name */
    void *unknown28; /* derived name */
    void *unknown30; /* derived name */
    int unknown38;   /* derived name */
};

/* hknpPrepareNewPairsTask: vtables 0x16a4ce0 and 0x16a4d28; slot 6 opens the timer "Collide/Prepare New Pairs". */
class hknpPrepareNewPairsTask : public hkReferencedObject,
                                public hknpTaskInterface /* derived name */
{
  public:
    /* Out of line (0x15b6c0; built at 0x1505fa): the five pointers kept,
     * the inplace array empty, three fields after it cleared. */
    hknpPrepareNewPairsTask(void *argument1, void *argument2, void *argument3, void *argument4,
                            void *argument5);

    /* Out of line (0x15b410, slot 0; its thunk from the task interface at
     * +0x10, 0x15b500, has the body inlined): the inplace array's storage
     * given back when it outgrew the object; the deleting destructor
     * (0x15b470, thunk 0x15b560) frees at the recorded size, 0x480 by
     * default. */
    virtual ~hknpPrepareNewPairsTask();

    /* The reference-counted class delete (tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    /* slot 5 (0x15b7a0) */
    virtual void process();
    /* slot 6 (0x15b740) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    /* The three pointers and two more the constructor 0x15b6c0 stores
     * (+0x440 and +0x470). Whatever holds +0x470 is an array element, not
     * a field of its own: the interface thunk 0x15b560 addresses the
     * members from the interface pointer, which InstCombine does only
     * when the -0x10 GEP ends in an array index (with a pointer field at
     * +0x470 it ends there and every member is addressed from the
     * adjusted pointer: `add rbx, -0x10`). */
    void *unknown18;                    /* derived name */
    void *unknown20;                    /* derived name */
    void *unknown28;                    /* derived name */
    hkInplaceArray<int, 256> unknown30; /* derived name */
    void *unknown440;                   /* derived name */
    void *unknown448;                   /* derived name */
    u8 unknown450[0xc];
    int unknown45c;   /* derived name */
    void *unknown460; /* derived name */
    /* Two pointers, the constructor storing the second; the first is not
     * read yet. derived name. */
    void *unknown468[2];
    u8 unknown478[8];
};

/* The narrow phase's pairs task (derived name; vtables 0x16a4ee0 and
 * 0x16a4f28): slot 6 opens "Collide/Existing Pairs" or "Collide/New Pairs";
 * its complete destructor FUN_0015dc50 jumps to FUN_0015dee0, which
 * restores both vtables and destroys the 0x710-byte records of the array
 * at +0x108. */
class hknpCollidePairsTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* slot 6 (0x15e7f0; the interface's thunk 0x15e850) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    u8 unknown18[0xb8];
    int pairsKind; /* derived name: 1 for the existing pairs */
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

/* Two more 16-byte tasks of the broad phase (derived names from their
 * names; the task interface implemented directly, the shared empty body
 * 0x17de10 and the 16-byte deleting destructor 0x13e50 in slots 0 and 1):
 * vtable address point 0x16a6670 (slot 2 the empty 0x17de10, slot 3
 * 0x18d000, "BroadPhase/UpdateFinished") and 0x16a6730 (slot 2 0x18d440,
 * slot 3 0x18cfb0, "BroadPhase/Export new pairs"); both describe
 * themselves in the second state's colour. */
class hknpBroadPhaseUpdateFinishedTask : public hknpTaskInterface /* derived name */
{
  public:
    void FUN_0018d000(hkStringBuf *name,
                      hkStringBuf *description) const; /* vtable slot 3; derived name */
};

/* The broad phase's per-layer update task (derived name from its name;
 * vtable address point 0x16a66d0, 0x20 bytes, four built by FUN_0018d640
 * for the layers 0 to 3, each with its owner at +8 and its layer at +0x10):
 * slot 2 (0x18d130) the work, slot 3 (0x18ce30) "BroadPhase/Update layer
 * %i" with the layer, described in the first state's colour. */
class hknpBroadPhaseUpdateLayerTask : public hknpTaskInterface /* derived name */
{
  public:
    void FUN_0018ce30(hkStringBuf *name,
                      hkStringBuf *description) const; /* vtable slot 3; derived name */

    void *owner; /* derived name */
    int layer;   /* derived name */
};

class hknpBroadPhaseExportNewPairsTask : public hknpTaskInterface /* derived name */
{
  public:
    void FUN_0018cfb0(hkStringBuf *name,
                      hkStringBuf *description) const; /* vtable slot 3; derived name */
};

/* The broad phase's collide task (derived name after its slot 3's format
 * "BroadPhase/Collide %i vs %i"; vtable 0x16a66f0): 0x120 bytes from the
 * thread's heap, sixteen built inline by FUN_0018d640 (from 0x18d820) with
 * the owner at +8, the index at +0x10 and an empty inplace array of 24
 * eight-byte entries at +0x40. Slot 2 (0x18d230) is the work. */
/* What the broad phase's collide tasks name themselves from (derived
 * names): the layer pairs at +0x68 of the object at +8 of the owner, two
 * ints a pair. */
struct BroadPhaseLayers0018cf50 /* derived name */
{
    u8 unknown0[0x68];
    const int *layerPairs; /* derived name */
};

struct BroadPhaseOwner0018cf50 /* derived name */
{
    u8 unknown0[8];
    BroadPhaseLayers0018cf50 *layers; /* derived name */
};

class BroadPhaseCollideTask : public hknpTaskInterface /* derived name */
{
  public:
    /* Out of line (0x18ce80, slot 0): the array's storage given back; the
     * deleting destructor (0x18ced0, slot 1) frees the 0x120 bytes. */
    virtual ~BroadPhaseCollideTask();

    static void operator delete(void *object, unsigned long numBytes);

    /* slot 2 (0x18d230) */
    virtual void process();
    /* slot 3 (0x18cf50) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    BroadPhaseOwner0018cf50 *owner; /* derived name */
    int index;                      /* derived name: the pair it collides */
    u8 unknown14[0x2c];
    hkInplaceArrayAligned16<u64, 24> entries; /* derived name */
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
 * constructor 0x16e0e0): slot 5 (0x16ec30, before the work at slot 6,
 * 0x16a370) gives the name "Solve/Data";
 * its complete destructor FUN_0016eaa0 restores both vtables and frees the
 * arrays at +0x20 and +0xc0 (48-byte polymorphic elements) and the blocks at
 * +0x30, +0x38 and +0xb8; the deleting destructor frees 0xe0 bytes by
 * default. */
class hknpSolveDataTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* slot 5 (0x16ec30), declared before the work */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    u8 unknown18[0xc8]; /* to the 0xe0 bytes */
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
void FUN_0015dc60(hknpCollidePairsTask *self);              /* vtable slot 1; derived name */
void FUN_0015dee0(hknpCollidePairsTask *self);              /* derived name */
void FUN_0015ea30(hknpCollidePairsTask *self);              /* vtable slot 5; derived name */
void FUN_0016eaa0(hknpSolveDataTask *self);                 /* derived name */
void FUN_0016e9f0(hknpSolveDataTask *self); /* vtable slot 1 (0x16a5680); derived name */
/* The interface's thunk of it (slot 1 of the second vtable, 0x16ea40), on
 * the object 16 bytes before the interface. derived name. */
void FUN_0016ea40(hknpTaskInterface *self);
void FUN_001798c0(hknpPrepareExistingPairsTask *self); /* vtable slot 5; derived name */
void FUN_0018ef40(hknpSolverStageTask *self);          /* vtable slot 5; derived name */
void FUN_0018f140(hknpSolverStageTask *self, hkStringBuf *name,
                  hkStringBuf *description); /* vtable slot 6; derived name */

#endif
