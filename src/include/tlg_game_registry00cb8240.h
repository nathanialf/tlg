/* src/include/tlg_game_registry00cb8240.h: a table of named objects under a
 * recursive lock, and the list FUN_00cb8240 makes of it. derived names
 * throughout. The buckets at +0x60 (their count at +0x68) hold chains of
 * entries (the object at +0x8, the next entry at +0x10); the number of
 * objects is at +0x88, the lock at +0x90 (owner +0x98, depth +0xa0), and at
 * +0x20 the id FUN_00cbb8d0 takes (0x12adb7e). */
#ifndef TLG_GAME_REGISTRY00CB8240_H
#define TLG_GAME_REGISTRY00CB8240_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"

/* the lock held for a scope (0xcb8281: the lock's address kept for the
 * unlock at 0xcb8474) */
class ScopedLock05945a38 /* derived name */
{
  public:
    ScopedLock05945a38(RecursiveLock05945a38 *held) : lock(held)
    {
        lock->lock();
    }

    ~ScopedLock05945a38()
    {
        lock->unlock();
    }

  private:
    RecursiveLock05945a38 *lock;
};

/* an object of the table, as far as the functions that list them read it:
 * the name at +0xc, the flags at +0x16 and the type at +0x18 are the node's
 * (tlg_game_node.h) */
struct Object00cb8240 { /* derived name */
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x6];
    u8 flags16; /* +0x16 (`test byte [rax+0x16], 4` at 0xcb838d) */
    u8 unknown17;
    const Type00503fb0 *type; /* +0x18 */
};

struct Registry00cb8240 { /* derived name */

    struct Entry {
        u8 unknown0[0x8];
        Object00cb8240 *object; /* +0x8 */
        Entry *next;            /* +0x10 */
    };

    /* walks every entry, bucket by bucket; the walk has moved on before
     * the entry it gave is used (0xcb8333) */
    class Iterator
    {
      public:
        Iterator(const Registry00cb8240 *owner) : registry(owner), entry(0), bucket(0)
        {
            nextBucket();
        }

        bool done() const
        {
            return entry == 0;
        }

        Object00cb8240 *next()
        {
            Entry *current = entry;
            entry = current->next;
            if (!entry)
                nextBucket();
            return current->object;
        }

      private:
        void nextBucket()
        {
            while (bucket < registry->bucketCount) {
                entry = registry->buckets[bucket++];
                if (entry)
                    break;
            }
        }

        const Registry00cb8240 *registry;
        Entry *entry;
        unsigned bucket;
    };

    u8 unknown0[0x20];
    int id; /* +0x20 */
    u8 unknown24[0x3c];
    Entry **buckets;      /* +0x60 */
    unsigned bucketCount; /* +0x68 */
    u8 unknown6c[0x1c];
    unsigned count; /* +0x88 */
    u8 unknown8c[0x4];
    RecursiveLock05945a38 lock; /* +0x90 */
};

/* appends the table's usable objects to the array and returns the array's
 * count (leaf_00cb8240.cpp) */
int FUN_00cb8240(Registry00cb8240 *self, Array05943280<Object00cb8240 *> *objects);

/* leaf_00c1ac70.cpp */
void FUN_00c1ac70(Registry00cb8240 *self);

void FUN_00cbb8d0(Object05945a38 *self, int id);

#endif
