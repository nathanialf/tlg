/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a job's function (the function at 0x10ebbd8 stores its
 * address at +0x4e0 of its object's job record): with the 16-bit count at
 * 0x5823544 raised atomically around it, it passes the areas at +0xf0, +0x30,
 * +0x1190 and +0x1400 of the context the job's pointer at +0x10 holds, its
 * floats at +0x15e0 and +0x15e4, the pointer at +0xaf20 of the settings the
 * context's owner reaches (+0x8, then +0x258), whether the settings' int at
 * +0xaf28 is 0, and 0x4000000 to FUN_0098bd10. The count is also taken with
 * `lock cmpxchg` by the functions at 0x10c74f1 and on. The fields' types
 * are not traced. */
struct Settings010f17f0 { /* derived name */
    u8 unknown0[0xaf20];
    void *unknownaf20; /* +0xaf20 */
    int unknownaf28;   /* +0xaf28 */
};

struct Member010f17f0 { /* derived name */
    u8 unknown0[0x258];
    Settings010f17f0 *settings; /* +0x258 */
};

struct Owner010f17f0 { /* derived name */
    u8 unknown0[0x8];
    Member010f17f0 *unknown8; /* +0x8 */
};

struct Context010f17f0 {  /* derived name */
    Owner010f17f0 *owner; /* +0x0 */
    u8 unknown8[0x28];
    u8 unknown30[0xf0 - 0x30];
    u8 unknownf0[0x1190 - 0xf0];
    u8 unknown1190[0x1400 - 0x1190];
    u8 unknown1400[0x15e0 - 0x1400];
    float unknown15e0; /* +0x15e0 */
    float unknown15e4; /* +0x15e4 */
};

struct Job010f17f0 { /* derived name */
    u8 unknown0[0x10];
    Context010f17f0 *context; /* +0x10 */
};

extern short D_5823544;

void FUN_0098bd10(void *first, void *second, void *settings, bool unset, int flags, void *third,
                  void *fourth, float x, float y); /* derived name */

// NONMATCHING: the base passes the settings' test as a branch (mov ecx, 0 or 1, the stack argument stored in both arms: D49's select on a single-use load), the build as sete; the argument loads follow in another order
void FUN_010f17f0(Job010f17f0 *job) /* derived name */
{
    __sync_fetch_and_add(&D_5823544, 1);
    Context010f17f0 *context = job->context;
    Settings010f17f0 *settings = context->owner->unknown8->settings;
    FUN_0098bd10(context->unknownf0, context->unknown30, settings->unknownaf20,
                 settings->unknownaf28 == 0, 0x4000000, context->unknown1190, context->unknown1400,
                 context->unknown15e0, context->unknown15e4);
    __sync_fetch_and_sub(&D_5823544, 1);
}
