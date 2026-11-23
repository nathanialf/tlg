/* src/include/tlg_game_object01388080.h: the commands of the queue at +0xb0
 * of the object the pointer at 0x5938c40 holds, and the queue (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT01388080_H
#define TLG_GAME_OBJECT01388080_H

#include <new>

#include "tlg_game_name.h"
#include "tlg_game_object05945a38.h"
#include "tlg_types.h"

/* derived names: the kind and the size of a command of the queue below,
 * the first bytes after a command's vptr: a base of its class that is not
 * polymorphic, so a command's constructor stores them before its vptr
 * (`movabs rsi, 0x1800000006; mov [rdx+rax+8], rsi` at 0x7aa127, then the
 * vtable at 0x7aa13d) */
struct CommandHeader01388080 { /* derived name */

    CommandHeader01388080(u32 kind, u32 size) : kind(kind), size(size) {}

    u32 kind; /* +0x8 */
    u32 size; /* +0xc */
};

/* derived names: the class whose vtable is at 0x16cae00
 * (config/vtables.derived.base.txt): a command of the queue below, a name at
 * +0x10 after its header. Its complete destructor 0x1388080 stores the
 * vtable and destroys the name; the deleting one 0x13880d0 is the
 * compiler's. A command built in the queue stores its header, this vtable,
 * then its own class's vtable over it. */
class Object01388080 : public CommandHeader01388080 /* derived name */
{
  public:
    Object01388080(const CommandHeader01388080 &header, const Name &name)
        : CommandHeader01388080(header), unknown10(name)
    {
    }

    virtual ~Object01388080();

  private:
    Name unknown10; /* +0x10 */
};

/* derived names: the class of the vtable at 0x16cdf90, derived from the one
 * above: a second Name at +0x14, in the base's tail padding. Its complete
 * destructor 0x1387f60 releases it, then runs the base's; the deleting one
 * 0x1387ff0 is the compiler's. */
class Object016cdf90 : public Object01388080 /* derived name */
{
  public:
    virtual ~Object016cdf90();

  private:
    Name unknown14; /* +0x14 */
};

/* derived names: the command of kind 6 the slots 7 of the classes at
 * 0x16add68, 0x16addb8 and 0x16ade08 queue (0x7aa0a0, 0x7abb80, 0x7ac330),
 * whose vtable is at 0x16cb830 (config/vtables.base.txt, from the stores):
 * an object's name and an int at +0x14, zero. Its vtable holds the base's
 * destructors. */
class Object016cb830 : public Object01388080 /* derived name */
{
  public:
    Object016cb830(const Name &name)
        : Object01388080(CommandHeader01388080(6, sizeof(Object016cb830)), name), unknown14(0)
    {
    }

  private:
    int unknown14; /* +0x14 */
};

/* derived names: the command of kind 9 0x9f5c80 queues, whose vtable is at
 * 0x16cdfb0 (config/vtables.base.txt, from the stores): an object's name.
 * Its vtable holds the base's destructors. */
class Object016cdfb0 : public Object01388080 /* derived name */
{
  public:
    Object016cdfb0(const Name &name)
        : Object01388080(CommandHeader01388080(9, sizeof(Object016cdfb0)), name)
    {
    }
};

/* derived names: the queue the commands are built in, under the recursive
 * lock at +0x348: the block at +0x388, the bytes used at +0x390 and the
 * block's size at +0x394; each command takes its size rounded up to 16
 * bytes, and one that does not fit is dropped. */
struct CommandQueue05938c40 { /* derived name */

    /* a command of class T built from the name at the end of the block
     * when it fits, the bytes used raised after it */
    template <class T> void push(const Name &name)
    {
        u32 end = used + ((sizeof(T) + 15) & ~15);
        if (end < capacity) {
            new (block + used) T(name);
            used = end;
        }
    }

    u8 unknown0[0x348];
    RecursiveLock05945a38 lock; /* +0x348 */
    u8 unknown360[0x28];
    u8 *block;    /* +0x388 */
    u32 used;     /* +0x390 */
    u32 capacity; /* +0x394 */
};

/* derived names: the object at +0x108 of the one below, as far as the lock
 * its readers take (the script C functions "UpdateWorldTransform" and
 * "LuaBindings::UpdateTransform", 0xe6d420 and 0xe75e40): a thread that is
 * not the writer at +0x248 takes a reader's place in the count at +0x23c
 * (FUN_01331c10) and gives it back with an atomic decrement; the writers'
 * count is at +0x240. A writer takes the registry's recursive lock and then
 * this one (FUN_00d8f040: the writer exchanged in from null unless it is the
 * calling thread, one more level in the writers' count, and at the first
 * level the readers' count exchanged from 0 to 0x10000); the unlock is
 * inline at every site (0xb452fa, 0xe87b05): the last level clears the
 * writer and empties the readers' count by compare-and-swap, then the
 * registry's lock is given back. The rest is not traced. */
struct World05938c40;

void FUN_00d8f040(World05938c40 *world); /* derived name: lockWrite() */

struct World05938c40 { /* derived name */

    void lockWrite() /* derived name */
    {
        FUN_00d8f040(this);
    }

    void unlockWrite() /* derived name */
    {
        if (__sync_fetch_and_sub(&writers, 1) == 1) {
            writer = 0;
            int count;
            do
                count = readers;
            while (compareAndSwap(&readers, count, 0) != count);
        }
        D_5945a38->lock201028.unlock();
    }

    void lockRead() /* derived name */
    {
        if (scePthreadSelf() != writer)
            FUN_01331c10(&readers);
    }

    void unlockRead() /* derived name */
    {
        if (scePthreadSelf() != writer)
            __sync_fetch_and_sub(&readers, 1);
    }

    u8 unknown0[0x23c];
    int readers;      /* +0x23c */
    int writers;      /* +0x240 */
    pthread_t writer; /* +0x248 */
};

/* derived name: the script C functions' registry (FUN_00c87e30 registers
 * one in it, FUN_008191e0) */
struct ScriptFunctions05938c40; /* derived name */

/* derived name: the links between objects by name (FUN_00c63970 takes one
 * out; tlg_game_links00c63970.h) */
struct Links05938c40;

/* derived names: the flags of the game's content chunks, whether each is
 * there yet, one byte each from +0x14 (the file system's slot 29, 0xe5f590,
 * mounts an archive only once its chunk is) */
struct Chunks05938c40 { /* derived name */
    u8 unknown0[0x14];
    bool present[1]; /* +0x14; its extent not traced */
};

/* derived names: the file system the game reads through (+0x28): its
 * slots as CreateBlob (0xb98790) calls them */
class FileSystem05938c40 /* derived name */
{
  public:
    virtual void slot0();                                  /* not traced */
    virtual void slot1();                                  /* not traced */
    virtual void slot2();                                  /* not traced */
    virtual void *open(const char *name, int mode);        /* slot 3 */
    virtual void close(void *file);                        /* slot 4 */
    virtual void slot5();                                  /* not traced */
    virtual void slot6();                                  /* not traced */
    virtual u32 size(void *file);                          /* slot 7 */
    virtual void slot8();                                  /* not traced */
    virtual void slot9();                                  /* not traced */
    virtual void slot10();                                 /* not traced */
    virtual void slot11();                                 /* not traced */
    virtual void slot12();                                 /* not traced */
    virtual void slot13();                                 /* not traced */
    virtual void read(void *file, void *buffer, u64 size); /* slot 14 */
};

/* derived names: the object the pointer at 0x5938c40 holds, as far as the
 * file system at +0x28, the script functions at +0x40, the queue at +0xb0 and the world at +0x108
 * (handed to FUN_00c55dd0 by FUN_0082de00), with the links at +0xd0 and
 * the content chunks at +0xf58 */
struct Object05938c40 { /* derived name */
    u8 unknown0[0x28];
    FileSystem05938c40 *fileSystem; /* +0x28 */
    u8 unknown30[0x10];
    ScriptFunctions05938c40 *functions; /* +0x40 */
    u8 unknown48[0x68];
    CommandQueue05938c40 *queue; /* +0xb0 */
    u8 unknownb8[0x18];
    Links05938c40 *links; /* +0xd0 */
    u8 unknownd8[0x30];
    World05938c40 *world; /* +0x108 */
    u8 unknown110[0x7c];
    float
        unknown18c; /* +0x18c: a time, by its use (FUN_00822740 takes the sine of five times it) */
    u8 unknown190[0xdc8];
    Chunks05938c40 *chunks; /* +0xf58 */
};

extern Object05938c40 *D_5938c40;

/* derived name: the world's write lock held for a scope: the constructor
 * takes it (World05938c40::lockWrite) and the destructor gives it back
 * (unlockWrite), both out of line (func_00d8f040.cpp) and inlined by the
 * link, which keeps no copy of either. From the bytes: FUN_00c57220,
 * FUN_00c572d0, FUN_00c57940 and FUN_00c5a160 end in the registry's unlock,
 * and each calls it and returns (`call 0x14b0568; pop; ret`) where a
 * sibling call would do. Only the unit's own optimiser marks sibling calls
 * (TailCallElim; the link's pipeline has none) and it marks none after a
 * local's address has left the function, so each had a local handed by
 * address to a function the unit did not see, and the local is gone after
 * the link: an object with nothing in it. FUN_00516350 and FUN_00e87a90,
 * written with it from the first, are equal (the latter holds
 * FUN_00c5a160's body, its unlock a call before a jump to the end).
 *
 * OPEN (round 475E): two forms of the lock. The helpers that take a child
 * out under it inside a destructor (removeLocked of leaf_00b45280.cpp,
 * leaf_00685840.cpp, leaf_00b554d0.cpp and leaf_00ccd4f0.cpp) call
 * lockWrite() and unlockWrite() directly: FUN_00b45280 and FUN_00685840
 * end in a sibling call after the unlock (`jmp 0x83df00`), so no local of
 * theirs had left the function at the unit stage; with this object in the
 * helper both lose the jump (measured: 155 of 162 and 96 of 101). Either
 * the removal under the lock is one out-of-line function of the node in a
 * unit that does not see this object's members, or those sites lock by
 * hand. Not decided by the bytes written so far. */
struct WorldWriteLock05938c40 { /* derived name */
    WorldWriteLock05938c40();
    ~WorldWriteLock05938c40();
};

#endif
