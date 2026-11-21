/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_sndx_instance.h"
#include "tlg_sndx_lock.h"
#include "tlg_types.h"

/* derived names: functions of sndx_instance.c (its name at 0x15c2def, the
 * file FUN_00ed8740's reports name), the sound runtime's instances. */
extern u32 D_179efa0; /* the log mask */
/* volatile: no code of the executable stores to it (leaf_00eeac70.cpp) */
extern volatile s32 D_5a8e0b0; /* derived name */
extern const char D_15c2def[]; /* the source file's path */
extern const char D_15c2dc6[]; /* "sceSndxInstance%s() unknown handle (%d)\n" */
extern const char D_15c2c25[]; /* "GetCategoryFlags" */

int FUN_00ef9960(int, int, int code, const char *file, int line, const char *format,
                 va_list args); /* derived name */

// NONMATCHING: the error report of the file, the shape of leaf_00eeac70.cpp's FUN_00eeadf0 (its
// list-ilp residual); its second parameter is not read (the callers leave rsi unset)
int FUN_00ed8740(int code, int, int line, const char *format, ...) /* derived name */
{
    if ((D_179efa0 & 1) || D_5a8e0b0 != 0) {
        va_list args;
        va_start(args, format);
        FUN_00ef9960(0, 1, code, D_15c2def, line, format, args);
        va_end(args);
    }
    return code;
}

// NONMATCHING: block placement: the base puts the range check's report out of line (`jb` to
// 0xed89f1, after the releases), the build falls through to it
int FUN_00ed88e0(u32 handle, bool unknown1, const char *caller, SndxInstance05a8e008 **instance)
{
    *instance = 0;
    const u32 index = handle & D_5a8e008->indexMask;
    const s32 slot = index - D_5a8e008->firstIndex;
    if (index < D_5a8e008->firstIndex || slot < 0 || index > D_5a8e008->lastIndex) {
        if (caller)
            FUN_00ed8740(-9, 0, 455, D_15c2dc6, caller, handle);
        return -9;
    }
    SndxInstance05a8e008 *found = &D_5a8e008->instances[slot];
    if (!sndxInstanceAcquire(found))
        return -9;
    if (found->handle != handle) {
        sndxInstanceRelease(found);
        return -9;
    }
    if ((found->unknownF0 & 1) &&
        (!unknown1 || (!(found->unknown138 & 0x40) && found->unknown440 == 0))) {
        *instance = found;
        return 0;
    }
    sndxInstanceRelease(found);
    return -9;
}

/* the API's GetCategoryFlags (sceSndxInstanceGetCategoryFlags by the name it
 * passes FUN_00ed88e0): the category flags of the instance of `handle`
 * through `flags` (0 first, and when there is no such instance) */
// NONMATCHING: the base reads `instance` once (rbx) for the lock, the flags and the release; the
// build reloads it after the spin lock, whose volatile store to its count of tries clobbers every
// load for GVN (MemoryDependence 3.7: a store that is not unordered); and the base keeps the
// final `result >= 0` (its spill at -0x4c) where the build folds it
void FUN_00ed7980(u32 handle, u32 *flags) /* derived name */
{
    SndxInstance05a8e008 *instance;
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 current;
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 next;
    if (flags)
        *flags = 0;
    if (sndxEnter(current, next) == 0) {
        u32 value;
        const int result = FUN_00ed88e0(handle, true, D_15c2c25, &instance);
        if (result >= 0) {
            sndxSpinLock(&instance->lock10c);
            value = instance->categoryFlags;
            sndxSpinUnlock(&instance->lock10c);
            sndxInstanceRelease(instance);
        }
        if (flags && result >= 0)
            *flags = value;
        sndxLeave(current, next);
    }
}

/* derived name: the state bits of the instance of `handle` (the word at
 * +0xf0, 0x40 when +0x454 is past +0x450, 0x8, 0x10 and 0x200 for its flags,
 * 0x40000000 for +0xfb, 0x20000000 when it is the block's instance at
 * +0x158), 0 when there is none, -3 when the runtime is not running */
// NONMATCHING: order only: the build loads D_5a8e008 first in the block that reads +0xfb and the
// handle, the base after them (105 of 108 instructions equal)
int FUN_00ed8100(u32 handle) /* derived name */
{
    SndxInstance05a8e008 *instance;
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 current;
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 next;
    int result = -3;
    if (sndxEnter(current, next) == 0) {
        int state = 0;
        if (FUN_00ed88e0(handle, true, 0, &instance) >= 0) {
            state = instance->unknownF0;
            if (instance->unknown454 > instance->unknown450)
                state |= 0x40;
            if (instance->unknownF6)
                state |= 0x8;
            if (instance->unknownF7)
                state |= 0x10;
            if (instance->unknown30 < 0)
                state |= 0x200;
            if (instance->unknownFB)
                state |= 0x40000000;
            if (instance->handle == D_5a8e008->unknown158)
                state |= 0x20000000;
            sndxInstanceRelease(instance);
        }
        if (sndxLeave(current, next) == 0)
            result = state;
    }
    return result;
}
