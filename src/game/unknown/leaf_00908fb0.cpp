/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: a point, three floats copied whole (`mov r15d, [rsi]` and
 * the next two before the lock) */
struct Point00908fb0 { /* derived name */
    float x;
    float y;
    float z;
};

/* derived names: one element of the pool, 0x68 bytes (the handle's index is
 * the element's distance from the block over 0x68: `shr rsi, 3; imul esi,
 * 0xc4ec4ec5`): a point and two floats at its start, the element's
 * generation at +0x54 (kept over the clear and the high half of a handle),
 * a flag at +0x56 set while it is in use and the next free element at
 * +0x60 */
struct Element00908fb0 { /* derived name */
    Point00908fb0 point; /* +0x0 */
    float unknownc;      /* +0xc */
    float unknown10;     /* +0x10 */
    u8 unknown14[0x40];
    u16 generation; /* +0x54 */
    u8 used;        /* +0x56 */
    u8 unknown57[0x9];
    Element00908fb0 *next; /* +0x60 */
};

/* derived names: a used element's place in the pool's list of 64: a word
 * cleared and the element's handle */
struct Entry00908fb0 { /* derived name */
    u32 unknown0;
    u32 handle;
};

struct Pool00908fb0 { /* derived name */
    u8 unknown0[0x58];
    int capacity; /* +0x58: the elements in the block */
    u8 unknown5c[0x1c];
    Element00908fb0 *elements; /* +0x78 */
    Element00908fb0 *free;     /* +0x80 */
    Entry00908fb0 entries[64]; /* +0x88 */
    int count;                 /* +0x288 */
};

/* derived names: the lock at +0x240 of the owner: slot 9 takes it, slot 10
 * gives it back */
class Lock00908fb0
{ /* derived name */
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void lock();   /* derived name; slot 9 */
    virtual void unlock(); /* derived name; slot 10 */
};

/* derived name: the lock held for a scope: taken by slot 9, given back by
 * slot 10, both called through the lock's vtable */
class ScopedLock00908fb0 /* derived name */
{
  public:
    explicit ScopedLock00908fb0(Lock00908fb0 &lock) : lock(lock)
    {
        lock.lock();
    }

    ~ScopedLock00908fb0()
    {
        lock.unlock();
    }

  private:
    Lock00908fb0 &lock;
};

struct Owner00908fb0 { /* derived name */
    u8 unknown0[0x240];
    Lock00908fb0 lock; /* +0x240 */
    u8 unknown248[0x168];
    Pool00908fb0 *pool; /* +0x3b0 */
};

/* derived names: under the owner's lock, while fewer than 64 are in use, a
 * free element taken, cleared but for its generation, marked used and set
 * to the point and the two floats, and listed with its handle (the
 * generation in the high half, the index in the low); returns the handle,
 * 0 when none was taken; the entry is value-initialised and its word set
 * before the handle (`mov qword [e], 0` then `mov dword [e], 0`). Called by
 * FUN_003e8300 and FUN_00911780. */
u32 FUN_00908fb0(Owner00908fb0 *owner, const Point00908fb0 &point, float a,
                 float b) /* derived name */
{
    const float x = point.x;
    const float y = point.y;
    const float z = point.z;
    ScopedLock00908fb0 guard(owner->lock);
    u32 handle = 0;
    Pool00908fb0 *pool = owner->pool;
    if (pool->count < 64) {
        if (Element00908fb0 *element = pool->free) {
            pool->free = element->next;
            element->next = 0;
            const u16 generation = element->generation;
            memset(element, 0, sizeof *element);
            element->generation = generation;
            element->used = 1;
            element->point.x = x;
            element->point.y = y;
            element->point.z = z;
            element->unknownc = a;
            element->unknown10 = b;
            Entry00908fb0 &entry = pool->entries[pool->count++];
            entry = Entry00908fb0();
            entry.unknown0 = 0;
            handle = u32(element - pool->elements) | element->generation << 16;
            entry.handle = handle;
        }
    }
    return handle;
}

/* derived names: under the owner's lock, every element of the pool in use
 * listed with its handle (the entry's word set to 1), while fewer than 64
 * are listed; an element's handle is 0 when it has none. Called by
 * FUN_003ebc90 and FUN_00911780. */
// NONMATCHING: the handle's index: the base keeps the element's distance from the block
// over 0x68 (`shr rdi, 3; imul edi, 0xc4ec4ec5`), the build folds it to the loop's counter
// (lead: the handle taken by a getter the base inlined only at the link)
void FUN_009090d0(Owner00908fb0 *owner) /* derived name */
{
    ScopedLock00908fb0 guard(owner->lock);
    for (int i = 0; i < owner->pool->capacity; ++i) {
        Element00908fb0 *element = &owner->pool->elements[i];
        if (!element->used)
            continue;
        const u32 handle =
            element ? u32(element - owner->pool->elements) | element->generation << 16 : 0;
        if (handle == 0)
            continue;
        if (owner->pool->count < 64) {
            Entry00908fb0 &entry = owner->pool->entries[owner->pool->count++];
            entry = Entry00908fb0();
            entry.unknown0 = 1;
            entry.handle = handle;
        }
    }
}
