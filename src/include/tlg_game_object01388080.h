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

/* derived names: the object the pointer at 0x5938c40 holds, as far as the
 * queue at +0xb0 and the pointer at +0x108 (handed to FUN_00c55dd0 by
 * FUN_0082de00) */
struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    CommandQueue05938c40 *queue; /* +0xb0 */
    u8 unknownb8[0x50];
    void *unknown108; /* +0x108 */
};

extern Object05938c40 *D_5938c40;

#endif
