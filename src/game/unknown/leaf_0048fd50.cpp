/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_sce_kernel.h"

/* derived names: under the reader count at +0x23c of the record at +0x108 of
 * the global at 0x5938c40 (taken by FUN_01331c10 and dropped by an atomic
 * decrement, both skipped when the record's owner at +0x248 is the calling
 * thread), looks the key up in the table at 0x57d6fe8 (FUN_0048fe20); an
 * object found whose class chain (+0x18, each class's parent at +0) reaches
 * the class the pointer at 0x593a6c0 holds gets bit 0 of its flags at +0x240
 * cleared when asked, set otherwise. */
struct Class0048fd50 { /* derived name: a class record, its parent at +0 */
    const Class0048fd50 *parent;
};

struct Object0048fd50 { /* derived name */
    u8 unknown0[0x18];
    const Class0048fd50 *type; /* +0x18 */
    u8 unknown20[0x220];
    u32 flags; /* +0x240 */

    bool isKindOf(const Class0048fd50 *of) const
    {
        const Class0048fd50 *c = type;
        while (c != of) {
            c = c->parent;
            if (!c)
                return false;
        }
        return true;
    }
};

struct Lock0048fd50 { /* derived name */
    u8 unknown0[0x23c];
    int readers; /* +0x23c */
    u8 unknown240[8];
    pthread_t owner; /* +0x248 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x108];
    Lock0048fd50 *unknown108; /* +0x108 */
};

struct Table057d6fe8; /* derived name */

extern Object05938c40 *D_5938c40;
extern Table057d6fe8 D_57d6fe8;
extern const Class0048fd50 *D_593a6c0; /* derived name: the class of the objects whose bit is set */

void FUN_01331c10(int *readers);                                     /* derived name */
Object0048fd50 *FUN_0048fe20(Table057d6fe8 *table, const void *key); /* derived name */

// NONMATCHING: the class walk: the base tests each parent against the class before the null
// test inside the loop (`mov rcx, [rcx]; cmp rcx, rax; je; test rcx, rcx; jne`, the first
// compare before it), the build rotates it the other way (`cmp; je` at the top, `mov; test;
// jne`) (an unrotated loop, the parked class), and loads the class pointer after the object's
// type (list-ilp); a do-while spelling compiles the same; everything before it equal
void FUN_0048fd50(const void *key, int clear) /* derived name */
{
    Lock0048fd50 *lock = D_5938c40->unknown108;
    if (scePthreadSelf() != lock->owner)
        FUN_01331c10(&lock->readers);
    Object0048fd50 *found = FUN_0048fe20(&D_57d6fe8, key);
    lock = D_5938c40->unknown108;
    if (scePthreadSelf() != lock->owner)
        __sync_fetch_and_sub(&lock->readers, 1);
    if (found && found->isKindOf(D_593a6c0)) {
        if (clear)
            found->flags &= ~1u;
        else
            found->flags |= 1;
    }
}
