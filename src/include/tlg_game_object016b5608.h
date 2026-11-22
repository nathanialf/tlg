/* The class whose vtable is at 0x16b5608 (config/vtables.derived.base.txt
 * names it; stored by FUN_00b33e00, FUN_00b34150 and FUN_00b34200), the base
 * of 0x16b55a0's class (tlg's leaf_00b32f80.cpp: its destructor ends in
 * `jmp 0xb34150`). All names derived. */
#ifndef TLG_GAME_OBJECT016B5608_H
#define TLG_GAME_OBJECT016B5608_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_sce_kernel.h"

/* derived names: a read-write lock and the byte that says it was made: the
 * destructor clears the byte when the lock is destroyed (`call
 * scePthreadRwlockDestroy; test eax, eax; jne; mov byte [rbx+0x30], 0`).
 * The bytes between are not traced. */
class RwLock016b5608 /* derived name */
{
  public:
    ~RwLock016b5608()
    {
        if (scePthreadRwlockDestroy(&lock) == 0)
            created = false;
    }

  private:
    pthread_rwlock_t
        lock; /* +0x0: taken by FUN_01393750 and FUN_01393770, released by FUN_01393760 */
    u8 unknown8[0x20];
    bool created; /* +0x28 */
};

/* derived names: the record slot 2 frees at +0x38: its entries (0x68
 * bytes each, the count at +0x30) each with a block at +0x50 freed when bit 0
 * of the flags at +0x5c is set, a block at +0x40, the entries' block and the
 * record itself, all through the function pointer at 0x17ac730 */
struct Entry016b5608 { /* derived name */
    u8 unknown0[0x50];
    void *block;   /* +0x50 */
    int unknown58; /* +0x58 */
    u32 flags;     /* +0x5c */
    u8 unknown60[0x8];
};

struct Table016b5608 { /* derived name */
    u8 unknown0[0x30];
    int count; /* +0x30 */
    u8 unknown34[0xc];
    void *unknown40; /* +0x40 */
    u8 unknown48[0x8];
    Entry016b5608 *entries; /* +0x50 */
};

struct Object009066d0; /* derived name: freed by FUN_00b342b0 through FUN_009066d0 */

/* The complete destructor, the key function, runs slot 2 (FUN_00b342b0) and
 * then the members' destructors, the names at +0x8c and +0x88 and the lock
 * at +0x8. Slot 2 frees the nine objects at +0x40 and the record at +0x38,
 * clearing each. Slots 3 to 10 are not traced. */
class Object016b5608 /* derived name */
{
  public:
    virtual ~Object016b5608();
    virtual void FUN_00b342b0(); /* derived name: slot 2 */

  private:
    RwLock016b5608 lock;        /* +0x8 */
    Table016b5608 *table;       /* +0x38 */
    Object009066d0 *objects[9]; /* +0x40 */
    Name name88;                /* +0x88 */
    Name name8c;                /* +0x8c */
};

#endif
