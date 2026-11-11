/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_sce_kernel.h"
#include <functional>

/* derived names: FUN_0069cb70 builds a 0x50-byte object (vtable 0x16cb6a0,
 * stored at 0x69cd35) whose std::function member at +0x20 (its
 * implementation pointer at +0x40) takes the lambda below: its
 * implementation's vtable is 0x16ac620 (the `lea` at 0x69cd0d), an empty
 * lambda taking its argument by reference. The lambda reads the record at
 * +0x10 of the argument under the lock the object at 0x5938c40 holds at
 * +0x108 (taken through FUN_01331c10 and released with an atomic decrement
 * unless the calling thread owns it), passes the record to FUN_00c56950,
 * then, when the object at +0x8 of the argument has a pointer at +0xf8,
 * clears its int at +0x194 and calls FUN_00d501d0 on it with 1. The types
 * are not traced beyond these fields. */
struct Lock0069d410 { /* derived name */
    u8 unknown0[0x23c];
    int readers; /* +0x23c, derived name */
    u8 unknown240[8];
    pthread_t owner; /* +0x248, derived name */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x108];
    Lock0069d410 *unknown108; /* +0x108 */
};

extern Object05938c40 *D_5938c40;

struct Target0069d410 { /* derived name */
    u8 unknown0[0xf8];
    void *unknownf8; /* +0xf8 */
    u8 unknown100[0x94];
    int unknown194; /* +0x194 */
};

struct Arg0069d410 { /* derived name */
    u8 unknown0[8];
    Target0069d410 *unknown8; /* +0x8 */
    void *unknown10;          /* +0x10 */
};

void FUN_01331c10(int *readers);          /* derived name */
void FUN_00c56950(void *record);          /* derived name */
void FUN_00d501d0(Target0069d410 *, int); /* derived name */

/* the 0x50-byte object (its vtable's row in config/vtables.derived.base.txt
 * names the class): slots 0 and 1 its destructors, which destroy the
 * std::function member; slot 2 is the library's 0x69a0 (folded), slot 3
 * FUN_013580d0, which calls the member with the pointer at +0x10. Its other
 * members are not traced. */
class Object013606c0 /* derived name */
{
  public:
    virtual ~Object013606c0();
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; FUN_013580d0 */

    u8 unknown8[8];
    Arg0069d410 *unknown10; /* +0x10 */
    u8 unknown18[8];
    std::function<void(Arg0069d410 &)> callback; /* +0x20 */
    u8 unknown48[8];
};

// NONMATCHING: 0x1360680 and 0x13606c0 (15 of 21): the base loads the
// implementation's vtable before the deallocate flag (`mov rcx, [rdi]` first,
// as at all 18 such calls in the base); this build computes the flag first
Object013606c0::~Object013606c0() {}

// NONMATCHING: not written beyond the lambda
void FUN_0069cb70(Object013606c0 *task) /* derived name */
{
    task->callback = std::function<void(Arg0069d410 &)>([](Arg0069d410 &arg) {
        void *record = arg.unknown10;
        Lock0069d410 *lock = D_5938c40->unknown108;
        if (scePthreadSelf() != lock->owner)
            FUN_01331c10(&lock->readers);
        FUN_00c56950(record);
        lock = D_5938c40->unknown108;
        if (scePthreadSelf() != lock->owner)
            __sync_fetch_and_sub(&lock->readers, 1);
        if (arg.unknown8->unknownf8) {
            arg.unknown8->unknown194 = 0;
            FUN_00d501d0(arg.unknown8, 1);
        }
    });
}
