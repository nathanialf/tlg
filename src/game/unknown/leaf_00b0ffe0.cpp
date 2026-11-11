/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: two timers driven by a pair of axes of the object the
 * pointer at 0x5938c40 holds (+0xe38/+0xe3c and +0xe44/+0xe48): while either
 * axis of the pair is not zero, the timer at +0x70 of the argument advances
 * by the frame time at +0x194 and, once it reaches 1, is reset to 0 and the
 * function returns true; otherwise false. */
struct Axes05938c40 /* derived name */
{
    float x;
    float y;

    bool active() const
    {
        return fabsf(x) > 0.0f || fabsf(y) > 0.0f;
    }
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x194];
    float frameTime194; /* +0x194 */
    u8 unknown198[0xca0];
    Axes05938c40 axes0e38; /* +0xe38 */
    u8 unknowne40[4];
    Axes05938c40 axes0e44; /* +0xe44 */
};

extern Object05938c40 *D_5938c40;

struct Timer00b0ffe0 { /* derived name */
    u8 unknown0[0x70];
    float elapsed; /* +0x70 */
};

// NONMATCHING: the base computes both axes' tests (`setne; setne; or`) and
// compares the 8-bit result with 1 at i32 (`movzx ecx, dl; cmp ecx, 1`, the
// cmp-01 form); the build branches on each test; form not found
bool FUN_00b0ffe0(Timer00b0ffe0 *timer) /* derived name */
{
    Object05938c40 *object = D_5938c40;
    if (object->axes0e38.active()) {
        timer->elapsed += object->frameTime194;
        if (timer->elapsed >= 1.0f) {
            timer->elapsed = 0;
            return true;
        }
    }
    return false;
}

// NONMATCHING: the base computes both axes' tests (`setne; setne; or`) and
// compares the 8-bit result with 1 at i32 (`movzx ecx, dl; cmp ecx, 1`, the
// cmp-01 form); the build branches on each test; form not found
bool FUN_00b10040(Timer00b0ffe0 *timer) /* derived name */
{
    Object05938c40 *object = D_5938c40;
    if (object->axes0e44.active()) {
        timer->elapsed += object->frameTime194;
        if (timer->elapsed >= 1.0f) {
            timer->elapsed = 0;
            return true;
        }
    }
    return false;
}
