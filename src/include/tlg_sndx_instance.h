/* src/include/tlg_sndx_instance.h: the sound runtime's block at 0x5a8e008 and
 * the instances its table holds (game region, the sndx runtime at 0xec18b0 to
 * 0xf15220; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_SNDX_INSTANCE_H
#define TLG_SNDX_INSTANCE_H

#include "tlg_sndx_lock.h"
#include "tlg_types.h"

/* derived names: an instance of the table at +0x38 of the block, 0x568 bytes
 * each (FUN_00ed88e0's `imul 0x568`; "instance" from its message
 * "sceSndxInstance%s() unknown handle (%d)" at 0x15c2dc6, in
 * sndx_instance.c by the file name at 0x15c2def) */
struct SndxInstance05a8e008 { /* derived name */
    u32 handle;               /* +0x0: the handle it is found by */
    u8 unknown4[0x8];
    /* +0xc: its users, the top bit set when it is let go (FUN_00ed88e0 takes
     * a place while the count is not negative; sndxInstanceRelease gives it
     * back) */
    s32 users;
    u8 unknown10[0x20];
    s32 unknown30;
    u8 unknown34[0xbc];
    u16 unknownF0;
    u8 unknownF2[0x4];
    u8 unknownF6;
    u8 unknownF7;
    u8 unknownF8[0x3];
    u8 unknownFB;
    u8 unknownFC[0x10];
    s32 lock10c; /* +0x10c: taken by sndxSpinLock around +0x428 */
    u8 unknown110[0x28];
    u8 unknown138; /* +0x138: bit 0x40 refused by FUN_00ed88e0 */
    u8 unknown139[0x2ef];
    u32 categoryFlags; /* +0x428: what GetCategoryFlags gives */
    u8 unknown42c[0x14];
    u8 unknown440; /* +0x440: not zero refused by FUN_00ed88e0 */
    u8 unknown441[0xf];
    f32 unknown450;
    f32 unknown454;
    u8 unknown458[0x110];
};

struct Block05a8e008 { /* derived name */
    u8 unknown0[0x38];
    SndxInstance05a8e008 *instances; /* +0x38 */
    u8 unknown40[0x4];
    u32 firstIndex; /* +0x44: the index of instances[0] */
    u32 lastIndex;  /* +0x48 */
    u32 indexMask;  /* +0x4c: a handle's bits that are its index */
    u8 unknown50[0x108];
    u32 unknown158; /* +0x158: an instance's handle */
    u8 unknown15c[0x32c];
};

extern Block05a8e008 *D_5a8e008;

/* derived name: the instance of `handle` with a place taken in its users,
 * through `instance` (0 when none), -9 when there is none; `caller` the API
 * function's name for its message */
int FUN_00ed88e0(u32 handle, bool unknown1, const char *caller, SndxInstance05a8e008 **instance);

/* one user more of `instance`, false when it is let go (the count
 * negative); the value read and the one written are volatile as in
 * sndxInstanceRelease below (0xed8950) */
inline bool sndxInstanceAcquire(SndxInstance05a8e008 *instance) /* derived name */
{
    /* volatile: the count other threads change, as read (see below) */
    volatile s32 current;
    /* volatile: the value to exchange it for (see below) */
    volatile s32 next;
    do {
        const s32 count = instance->users;
        current = count;
        if (count < 0)
            return false;
        next = current + 1;
    } while (sndxCompareAndSwap(&instance->users, current, next) != current);
    return true;
}

/* one user less of `instance`, its top bit kept. The value read and the one
 * written are volatile as in sndxStepCallers: the count is changed by every
 * thread that holds the instance, and each site keeps both in the frame (one
 * load per mention: 0xed7ac0, 0xed81f0, 0xed89c0, 0xef6f80). */
inline void sndxInstanceRelease(SndxInstance05a8e008 *instance) /* derived name */
{
    /* volatile: the count other threads change, as read (see above) */
    volatile s32 current;
    /* volatile: the value to exchange it for (see above) */
    volatile s32 next;
    do {
        current = instance->users;
        next = (current & 0x80000000) | ((current & 0x7fffffff) - 1);
    } while (sndxCompareAndSwap(&instance->users, current, next) != current);
}

#endif
