/* Havok's threading primitives over the Sony kernel. */
#ifndef TLG_HK_THREAD_H
#define TLG_HK_THREAD_H

#include "tlg_hk_reflect.h"
#include "tlg_sce_kernel.h"

/* hkSemaphore: one kernel semaphore handle at +0, created under the name
 * "hkSemaphore" (0x14b4978) by its constructor 0x1a420 (initial and maximum
 * counts in its second and third arguments, attribute 1; the pool's
 * constructor at 0x6dcb passes a fourth, 0, which the kernel version does
 * not use). The destructor (0x1a440) deletes it (its callers then free the
 * object: Class168e810's destructor at 0x17010), FUN_0001a490 waits for one
 * count and FUN_0001a4a0 signals the given count. */
class hkSemaphore
{
  public:
    hkSemaphore(int initialCount, int maxCount, int numSpinIterations); /* derived names */
    ~hkSemaphore();

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

/* The object at +0x18 of Class168e810: a list of blocks at +0, a critical
 * section at +0x10; FUN_00015700 and FUN_000158f0 take a pointer and a
 * count under it. */
struct Object00015700 /* derived name */
{
    /* An entry of a block (derived names), 0x40 bytes: an array of 8-byte
     * values at +0x10. */
    struct Entry {
        u8 unknown0[0x10];
        hkArray<u64> values;
        u8 unknown20[0x20];
    };

    /* A block of 63 entries and the next block (derived names), 0xfc8
     * bytes from the thread's heap. */
    struct Block {
        /* Back to the thread's heap at its size unless null, as
         * hkReferencedObject's own delete tests (0x15d71). derived name. */
        static void operator delete(void *object, unsigned long numBytes);

        Entry entries[63];
        Block *next;
    };

    /* Out of line (0x15cd0; Class168e810's destructor deletes the object
     * at 0x16fc6): every block deleted, then the critical section. */
    ~Object00015700();

    /* Back to the thread's heap at the class's size, untested (0x16fed:
     * the delete expression has tested the pointer). derived name. */
    static void operator delete(void *object, unsigned long numBytes);

    Block *firstBlock; /* derived name */
    u8 unknown8[8];
    hkCriticalSection lock; /* derived name */
};

void FUN_00015700(Object00015700 *self, void *pointer, int count); /* derived name */
void FUN_000158f0(Object00015700 *self, void *pointer, int count); /* derived name */

struct TaskNode000172c0;

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
    /* Empty and inline: Class168e810's destructor destroys its member with no
     * call (0x16f90), so the vtable and the deleting destructor are emitted
     * with the key function, slot 3 (func_00091af0.cpp). */
    virtual ~Runner00016350() {}

    virtual void unknownVirtual2() {} /* the empty 0xe5c0 */

    /* Slot 3 (0x91af0): a name and attributes for the task graph's dumps
     * (FUN_00091b30's fill colours are such attributes): "Unnamed", and no
     * attributes when asked for them. derived name. */
    virtual void FUN_00091af0(hkStringBuf &name, hkStringBuf *attributes) const;

    static void operator delete(void *object, unsigned long numBytes);

    u8 unknown8[8];
};

/* A task node of Class168e810's graph (derived names): its count of
 * unfinished predecessors at +0, -1 once the node is done (what FUN_00016350
 * waits for, slot 10 and slot 11 skip); the priority at +4 and the runner at
 * +0x38, both set by slot 6 (FUN_00017280); the threads waiting for it as
 * one bit each by their semaphore's index at +8, and the nodes that wait on
 * it at +0x10 (slot 7 links them, FUN_00016350 counts them down when it
 * finishes the node). */
struct TaskNode000172c0 /* derived name */
{
    int counter;
    /* The node's priority, the high half of its key in the ready queue,
     * and the sequence number slot 9 gives it when it is counted down
     * (0x17540). derived names. */
    u16 priority;
    u16 sequence;
    u64 waitingThreads;
    hkArray<TaskNode000172c0 *> successors;
    u8 unknown20[0x18];
    Runner00016350 *runner;
};

/* A node and one that is to wait on it (derived names): slot 8 (0x173f0)
 * links an array of them. */
struct TaskPair000173f0 /* derived name */
{
    TaskNode000172c0 *node;
    TaskNode000172c0 *successor;
};

/* An interface of ten slots, the second base (at +0x10, vtable address point
 * 0x168e888) of Class168e810, which overrides slots 2 to 9 in its primary
 * slots 5 to 12. */
class Interface168e888 /* derived name */
{
  public:
    /* Empty and inline: Class168e810's destructor destroys the base with no
     * call (0x16f90). */
    virtual ~Interface168e888() {}

    virtual void FUN_00017240(void *pointer, int count) = 0; /* slot 2; derived name */
    virtual void FUN_00017280(TaskNode000172c0 *item, Runner00016350 *runner,
                              u16 value) = 0; /* slot 3; derived name */
    virtual void FUN_000172c0(TaskNode000172c0 *node,
                              TaskNode000172c0 *successor) = 0; /* slot 4; derived name */
    virtual void FUN_000173f0(const TaskPair000173f0 *pairs,
                              int numPairs) = 0; /* slot 5; derived name */
    virtual void FUN_00017540(TaskNode000172c0 *const *nodes,
                              int numNodes) = 0;           /* slot 6; derived name */
    virtual void FUN_00017930(TaskNode000172c0 *node) = 0; /* slot 7; derived name */
    virtual void FUN_00017970(TaskNode000172c0 *const *nodes,
                              int numNodes) = 0;             /* slot 8; derived name */
    virtual void FUN_00017260(void *pointer, int count) = 0; /* slot 9; derived name */
};

/* A waiting thread's semaphore of Class168e810 (derived names): built by the
 * constructor 0x16d40 for the first four of 64 entries (0x10 bytes from the
 * thread's heap, the count 0 of at most 1, the owner's spin count), not
 * waiting, its index at +0xc; FUN_000170d0 signals each waiting one. */
struct WaitingSemaphore00016d40 /* derived name */
{
    /* No count of at most one, not waiting; the index is the slot's, set by
     * the one who builds it (0x16d40 after storing it, 0x16350 before). */
    WaitingSemaphore00016d40(int spinCount) : semaphore(0, 1, spinCount), waiting(false) {}

    /* From the thread's heap, untested (0x16410). derived name. */
    static void *operator new(unsigned long numBytes);
    /* Back to the thread's heap at the class's size, untested (0x17037).
     * derived name. */
    static void operator delete(void *object, unsigned long numBytes);

    hkSemaphore semaphore; /* derived name */
    hkBool waiting;        /* derived name */
    int index;             /* derived name */
};

/* An entry of Class168e810's ready queue (derived names), a binary heap
 * slot 9 (0x17540) pushes: a key of the node's priority and a sequence
 * number, and the node. */
struct ReadyEntry00017540 /* derived name */
{
    int key;
    TaskNode000172c0 *node;
};

/* A reference-counted object (vtable address points 0x168e810 and, for the
 * second base, 0x168e888, both stored by its constructor 0x16d40 and its
 * complete destructor 0x16f90; size 0x370 by its deleting destructor)
 * with the interface above at +0x10, the object above at +0x18, a binary
 * heap of ready nodes at +0x20, a critical section at +0x30, a free list
 * of 64 slots at +0x40 and 64 semaphores from +0x148 (the first four
 * built), each released once by FUN_000170d0 under the lock (flag at
 * +0x362). Slots 5 and 12 forward to the object at +0x18; slots 7, 8 and 9
 * (FUN_000172c0, FUN_000173f0, FUN_00017540) run under the critical
 * section, slot 11 (FUN_00017970) takes no lock. */
class Class168e810 : public hkReferencedObject, public Interface168e888 /* derived name */
{
  public:
    /* Out of line (0x16f90, slot 0, and its thunk 0x170c0; the deleting one
     * 0x16ee0 and its thunk 0x16f30 before it): the waiting threads
     * released, the object at +0x18 and the semaphores deleted, then the
     * members. */
    virtual ~Class168e810();

    /* The reference-counted class delete (freeReferencedObject in
     * tlg_lib_unknown.h). */
    static void operator delete(void *object, unsigned long numBytes);

    virtual void FUN_00017240(void *pointer, int count); /* vtable slot 5; derived name */
    virtual void FUN_00017280(TaskNode000172c0 *item, Runner00016350 *runner,
                              u16 value); /* vtable slot 6; derived name */
    /* Slot 7 (0x172c0), under the lock: a node made to wait on another
     * unless that one is done, its count raised (0x173f0 links pairs of
     * them). derived names. */
    virtual void FUN_000172c0(TaskNode000172c0 *node, TaskNode000172c0 *successor);
    /* Slot 8 (0x173f0), under the lock: slot 7's link for each pair.
     * derived names. */
    virtual void FUN_000173f0(const TaskPair000173f0 *pairs, int numPairs);
    /* Slot 9 (0x17540), under the lock: each node counted down with the
     * next sequence number, the ones that reach zero pushed on the ready
     * queue by priority, as many waiting semaphores taken; then, the lock
     * left, those semaphores signalled. derived names. */
    virtual void FUN_00017540(TaskNode000172c0 *const *nodes, int numNodes);
    virtual void FUN_00017930(TaskNode000172c0 *node); /* vtable slot 10; derived name */
    /* Slot 11 (0x17970): the nodes not yet done gathered into a
     * temporary array and handed to the interface's run of several
     * (FUN_00092fe0). derived name. */
    virtual void FUN_00017970(TaskNode000172c0 *const *nodes, int numNodes);
    virtual void FUN_00017260(void *pointer, int count); /* vtable slot 12; derived name */

    /* 0x170d0: under the lock, once (the flag at +0x362), every waiting
     * semaphore signalled. derived name. */
    void FUN_000170d0();

    Object00015700 *object18;               /* derived name */
    hkArray<ReadyEntry00017540> readyQueue; /* derived name */
    hkCriticalSection lock;                 /* derived name; slots 7 to 9 run under it */
    /* A lock-free list of the 64 semaphore slots (derived names): the head's
     * low 7 bits the first free slot, the bits above a tag each take
     * advances; each slot's next, 0x7f for none. volatile: every thread
     * takes and gives back slots without the lock (FUN_00016350), so each
     * read is the memory's (the base loads the next slot on its own, 0x163b9). */
    volatile int firstFreeSlot;               /* 0 on construction */
    volatile int nextFreeSlot[64];            /* i + 1, the last 0x7f */
    WaitingSemaphore00016d40 *semaphores[64]; /* derived name */
    u8 unknown348[8];
    Runner00016350 defaultRunner; /* derived name */
    u16 sequence;                 /* derived name: slot 9's counter */
    hkBool released;              /* derived name: set by FUN_000170d0 */
    int spinCount;                /* derived name */
    u8 unknown368[8];
};

/* Nodes run through an interface (0x92fe0; Class168e810's slot 11 hands
 * it the ones not yet done): one through slot 7, two or more as a
 * batch. derived name. */
void FUN_00092fe0(Interface168e888 *runner, TaskNode000172c0 *const *nodes,
                  int numNodes); /* derived name */

/* The calling thread takes a free semaphore slot and processes ready nodes
 * until the node it waits for is done; without one, until the queue is
 * empty in mode 1, or until the object is released (derived names). Slot 10
 * (FUN_00017930) waits for a node not yet done, FUN_00017920 for none, and
 * the callback FUN_00007730 runs FUN_00017920 with mode 0. */
void FUN_00016350(Class168e810 *self, int mode, TaskNode000172c0 *waitFor); /* derived name */
void FUN_00017920(Class168e810 *self, int mode);                            /* derived name */

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
struct CollideShared0015ea30;

/* What the deactivation tasks reach the collide stage's shared data
 * through (derived names): it at +0x10. */
struct TaskOwner0014e850 /* derived name */
{
    u8 unknown0[0x10];
    CollideShared0015ea30 *shared; /* derived name */
};

class hknpAddActiveBodyPairsTask : public hkReferencedObject,
                                   public hknpTaskInterface /* derived name */
{
  public:
    /* Slot 5 (0x14e850; the interface's thunk 0x14ea10): the class's key
     * function. */
    virtual void process();
    /* slot 6 (0x14e9c0) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    TaskOwner0014e850 *owner;          /* derived name */
    hknpWorldContextPool *contextPool; /* derived name */
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

    void *unknown18;                   /* derived name */
    hknpWorldContextPool *contextPool; /* derived name */
    u8 unknown28[8];
    /* The commands slot 5 wrote, the context's command range copied whole
     * (the builder 0x150f68 clears its count and link). derived name. */
    LinkedRange0015ea30 commands;
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

/* What the constraints' preparation fills (derived names): the
 * constraints gathered (0xc5e30, from the world's constraints up to the
 * highest id in use), their count at +8, then their groups (0xc6630, over
 * the gathered ones from the first to the last of +0x10). */
struct ConstraintGather000c5e30 /* derived name */
{
    void FUN_000c5e30(hknpWorld *world, hknpConstraint *constraints, int numConstraints);

    u8 unknown0[8];
    int numConstraints; /* derived name */
    u8 unknownC[4];
    int numEntries10; /* derived name */
};

struct ConstraintGroups000c6630 /* derived name */
{
    void FUN_000c6630(hknpWorld *world, const ConstraintGather000c5e30 *gather, int first, int last,
                      hknpConstraint *constraints);
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

    /* The objects slot 5 fills, read from the task at each use (0x155011
     * reads +0x20 again after the gather). derived names. */
    ConstraintGather000c5e30 *gather() const
    {
        return static_cast<ConstraintGather000c5e30 *>(unknown20);
    }

    ConstraintGroups000c6630 *groups() const
    {
        return static_cast<ConstraintGroups000c6630 *>(unknown28);
    }

    void *unknown18; /* derived name: the world */
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
    /* The pairs given to the world's object at +0x4f8 when the world has it
     * (0x15b7a0), else the pairs prepared (0x15b8e0). derived name. */
    void FUN_0015b8e0(hknpWorldContextPool::Context *context);

    void *unknown18;                   /* derived name */
    hknpWorldContextPool *contextPool; /* derived name: slot 5 takes a context from it */
    const hkBlockStream *stream28;     /* derived name: read from its start by slot 5 */
    hkInplaceArray<int, 256> ids;      /* derived name: filled by 0x63ec0 */
    void *unknown440;                  /* derived name */

    /* A byte at +0x132 slot 5 sets when the world's object found one of the
     * ids (derived name). */
    struct Status0015b7a0 {
        u8 unknown0[0x132];
        bool found; /* derived name */
    } *status;

    u8 unknown450[0xc];
    int unknown45c;   /* derived name */
    void *unknown460; /* derived name */
    /* Two pointers, the constructor storing the second; the first is not
     * read yet. derived name. */
    void *unknown468[2];
    u8 unknown478[8];
};

/* The command ranges of a context by grid cell (derived name). */
struct CommandRanges0015ea30 /* derived name */
{
    LinkedRange0015ea30 *ranges;
};

/* A collide task's output range (derived names), 0x38 bytes on a 16-byte
 * boundary (0x40 a slot), a stack object of 0x15ea30 built empty: a linked
 * range, a flag, and the counts of the writer it was taken from. */
struct CollideRange0015ea30 /* derived name */
{
    CollideRange0015ea30() : next(0), flag(false), unknown2c(0)
    {
        range.numElements = 0;
        writerCounts[0] = 0;
        writerCounts[1] = 0;
    }

    hkBlockStreamRange range __attribute__((aligned(16)));
    CollideRange0015ea30 *next;
    hkBool flag; /* derived name */
    u8 unknown19[0x13];
    int unknown2c;
    int writerCounts[2]; /* derived name */
};

/* A range appended to a list whose first range is kept in place: copied
 * into the list's first when that is empty, else written into the stream
 * and linked in after it (derived name; the collide task's slot 5). */
template <typename T>
inline void appendLinkedRange(T &list, const T &range, hkBlockStreamWriter &writer)
{
    if (list.range.numElements == 0) {
        list = range;
        return;
    }
    T *added = static_cast<T *>(writer.reserve(int(sizeof(T))));
    *added = range;
    if (list.range.numElements == 0) {
        list = *added;
    } else {
        added->next = list.next;
        list.next = added;
    }
    writer.advance(int(sizeof(T)));
}

/* What the collide tasks share (derived names): the output lists by grid
 * cell at +0x10 and +0x20, and five streams a context at +0x140. */
struct CollideShared0015ea30 /* derived name */
{
    u8 unknown0[0x10];
    CollideRange0015ea30 *rangesA; /* derived name */
    u8 unknown18[8];
    CollideRange0015ea30 *rangesB; /* derived name */
    u8 unknown28[0x118];
    hkBlockStream (*contextStreams)[5]; /* derived name */
    int numContexts;                    /* derived name */
};

/* The pairs of a batch through the collision detectors (0x15c5f0; the
 * collide task's slot 5 calls it once a batch, the second consumer null
 * when there are no new pairs to read). derived names. */
void FUN_0015c5f0(hknpWorldContextPool::Context *context, void *shared, int cellIndex,
                  hkBlockStreamConsumer *consumer, void *argument4, void *argument5,
                  hkBlockStreamConsumer *consumer2, void *argument7, void *argument8,
                  hkBlockStreamWriter *writer0, hkBlockStreamWriter *writer28,
                  hkBlockStreamWriter *writer50, hkBlockStreamWriter *writer78,
                  hkBlockStreamWriter *writer128, hkBlockStreamWriter *writer150,
                  hkBlockStreamWriter *writer100, hknpWorldObject380Record *record0,
                  hknpWorldObject380Record *record1, hknpWorldObject380Record *record2,
                  void *output);

/* The narrow phase's pairs task (derived name; vtables 0x16a4ee0 and
 * 0x16a4f28), 0x170 bytes, built inline by FUN_00150330: slot 6 opens
 * "Collide/Existing Pairs" or "Collide/New Pairs". The destructor is the
 * implicit one, emitted with the vtable in the file of the key function,
 * slot 5: the base destructor 0x15dee0 restores both vtables and destroys
 * the arrays from the last member; the complete destructor 0x15dc50 jumps
 * to it and the deleting one 0x15dc60 calls it (a linkonce destructor is
 * not aliased by clang 3.3, CGCXX.cpp:124-127). */
class hknpCollidePairsTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* An element of the array at +0xd8, 0x20 bytes (derived names): the
     * range the batch writes, then the two grid cells it belongs to. */
    struct Entry20 {
        hkBlockStreamRange range;
        u8 unknown10[4];
        u8 cellB; /* derived name */
        u8 cellA; /* derived name: 0xff for none */
        u8 unknown16[0xa];
    };

    /* An element of the array at +0xe8, 0x70 bytes (derived names): the
     * range the batch reads, its output and its command range. */
    struct Entry70 {
        hkBlockStreamRange range;
        CollideRange0015ea30 output;
        LinkedRange0015ea30 commands;
    };

    /* The heap's block given back at the class's size when the object is
     * not null (tlg_lib_unknown.h; the deleting destructor 0x15dc60 frees
     * 0x170 bytes, not the object's recorded size). */
    static void operator delete(void *object, unsigned long numBytes);

    /* Slot 5 (0x15ea30; the interface's thunk 0x15fa40): the work, the
     * class's key function. Its functions.base.txt row carries the mangled
     * name so that the thunk's jump resolves while it is unmatched. */
    virtual void process();
    /* slot 6 (0x15e7f0; the interface's thunk 0x15e850) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    u8 unknown18[8];
    u8 shared20[0x48]; /* derived name: handed to 0x15c5f0 */
    void *unknown68;   /* derived name */
    void *unknown70;   /* derived name */
    void *unknown78;   /* derived name */
    void *unknown80;   /* derived name */
    u8 unknown88[0x38];
    hknpWorldContextPool *contextPool; /* derived name */
    u8 unknownC8[8];
    int pairsKind;            /* derived name: 1 for the existing pairs */
    hkArray<Entry20> cells;   /* derived name: the existing pairs' batches */
    hkArray<Entry70> batches; /* derived name: the new pairs' batches */
    u8 unknownF8[8];
    int *nextBatch; /* derived name: taken atomically by each worker */
    /* The step's stream sets, one in use per context (slot 5 picks the
     * set by the context's index). derived name. */
    hkArray<StepStreams0015e980> streamSets;
    CollideShared0015ea30 *shared; /* derived name */
    hkBlockStream *stream120;      /* derived name */
    void *unknown128;              /* derived name */
    u8 firstContextIndex;          /* derived name */
    u8 unknown131;
    hkBool flag132; /* derived name */
    hkBool flag133; /* derived name */
    u8 unknown134[4];
    const hkBlockStreamRange *ranges138; /* derived name */
    const hkBlockStreamRange *ranges140; /* derived name */
    hkBlockStream *stream148;            /* derived name */
    void *unknown150;                    /* derived name */
    hkBlockStreamRange *rangesOut158;    /* derived name */
    hkBlockStreamRange *rangesOut160;    /* derived name */
    u8 unknown168[8];
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
struct BroadPhaseTaskData0018d050;

class hknpBroadPhaseUpdateLayerTask : public hknpTaskInterface /* derived name */
{
  public:
    /* Slot 2 (0x18d130): under the collide stage's broad phase timer, the
     * layer's tree updated when it holds boxes, as a volatile layer
     * (0x142a40) or a pending one (0x142af0). derived name. */
    void FUN_0018d130();

    void FUN_0018ce30(hkStringBuf *name,
                      hkStringBuf *description) const; /* vtable slot 3; derived name */

    BroadPhaseTaskData0018d050 *owner; /* derived name */
    int layer;                         /* derived name */
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
/* What the solver's stage tasks run over (derived names): the world's
 * context pool at +0x10 and, at +0x28, an object whose int at +0xbc is the
 * number of sub-stages of a stage (0x18efd5). */
struct SolverStageConfig0018ef40 /* derived name */
{
    u8 unknown0[0xbc];
    int numSubStages; /* derived name */
};

/* A stage list of the solver (derived names): records of a stride at +0
 * from +0x18, each with a count at +0xc that the stage task's name prints
 * (0x18f1a6). */
struct SolverStageList0018f140 /* derived name */
{
    struct Record {
        u8 unknown0[0xc];
        int count;
    };

    const Record &get(int i) const
    {
        return *reinterpret_cast<const Record *>(records + i * stride);
    }

    int stride;
    u8 unknown4[0x14];
    const char *records;
};

struct SolverStages0018ef40 /* derived name */
{
    u8 unknown0[0x10];
    hknpWorldContextPool *contextPool; /* derived name */
    u8 unknown18[0x10];
    SolverStageConfig0018ef40 *config; /* derived name */
    u8 unknown30[0x40];
    SolverStageList0018f140 *lists[3]; /* derived name: by a stage's first index */
};

/* A stage's description (derived names): its type first (1 and 0 name the
 * stage differently, 0x18f153), then three indices, the fifth byte read by
 * the stage's run (0x18f05a), and flags (bit 0, 0x18f0d6). */
struct SolverStageInfo0018ef40 /* derived name */
{
    u8 type;
    u8 index1;
    u8 index2;
    u8 index3;
    u8 index4;
    u8 flags;
    u8 unknown6[2]; /* to the task's +0x28 */
};

class hknpSolverStageTask : public hkReferencedObject, public hknpTaskInterface /* derived name */
{
  public:
    /* slot 5 (0x18ef40; the interface's slot 2 through a thunk) */
    virtual void process();
    /* slot 6 (0x18f140; the interface's slot 3 through the thunk 0x18f280,
     * emitted with it) */
    virtual void getName(hkStringBuf *name, hkStringBuf *description) const;

    SolverStages0018ef40 *stages; /* derived name */
    SolverStageInfo0018ef40 info; /* derived name */
    /* The stage and sub-stage the next run takes, cleared by the builder
     * (0x18e77a); each run steps the sub-stage, wrapping into the next
     * stage. derived names. */
    u8 stage;
    u8 subStage;
};

/* The two kinds of a stage's work (derived names): 0x198f30 over one
 * index of the description, 0x198b40 over all four. */
void FUN_00198f30(hknpWorldContextPool::Context *context, int stage, int subStage, int threadIndex,
                  u8 index, SolverStages0018ef40 *stages); /* derived name */
void FUN_00198b40(hknpWorldContextPool::Context *context, int stage, int subStage, int threadIndex,
                  u8 index1, u8 index2, u8 index3, u8 index4,
                  SolverStages0018ef40 *stages); /* derived name */

/* A stage's work on a context from the pool (0x18f030): the stage's
 * calls by its type, on the thread's index; on the last sub-stage the
 * calls its flags ask for. Always false (`xor al, al`). derived name. */
bool FUN_0018f030(hknpWorldContextPool::Context *context, SolverStages0018ef40 *stages, int stage,
                  int subStage, int threadIndex,
                  const SolverStageInfo0018ef40 *info); /* derived name */

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
void FUN_0014ea20(hknpSolveFinalizeTask *self);             /* vtable slot 5; derived name */
void FUN_0014f190(hknpProcessSecondRoundResultsTask *self); /* vtable slot 5; derived name */
void FUN_0014fa50(hknpProcessFirstRoundResultsTask *self);  /* vtable slot 5; derived name */
void FUN_001551a0(hknpBuildConstraintsTask *self);          /* vtable slot 5; derived name */
void FUN_0016eaa0(hknpSolveDataTask *self);                 /* derived name */
void FUN_0016e9f0(hknpSolveDataTask *self); /* vtable slot 1 (0x16a5680); derived name */
/* The interface's thunk of it (slot 1 of the second vtable, 0x16ea40), on
 * the object 16 bytes before the interface. derived name. */
void FUN_0016ea40(hknpTaskInterface *self);
void FUN_001798c0(hknpPrepareExistingPairsTask *self); /* vtable slot 5; derived name */
void FUN_0018ef40(hknpSolverStageTask *self);          /* vtable slot 5; derived name */

#endif
