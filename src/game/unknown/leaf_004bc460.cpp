/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: one sample of a motion history, 0x20 bytes: the time it
 * covers at +0x0, the move at +0x10 (x, y and z, and its length in x and z
 * as w) */
struct MotionSample004bc460 { /* derived name */
    float time;               /* +0x0 */
    u8 unknown4[0xc];
    Float4A move; /* +0x10 */
};

/* derived names: the last thirty moves of a position (FUN_004315b0 and
 * FUN_004b8c60 record them): the number held (up to 30) at +0x0, the next
 * sample to write at +0x4, the time and the position of the last record at
 * +0x8 and +0x10, the samples from +0x20 */
struct MotionHistory004bc460 { /* derived name */
    int count;                 /* +0x0 */
    int next;                  /* +0x4 */
    float time;                /* +0x8 */
    u8 unknownc[0x4];
    Float4A position;                 /* +0x10 */
    MotionSample004bc460 samples[30]; /* +0x20 */

    /* the count grows to 30 */
    void grow() /* derived name */
    {
        if (count < 30)
            ++count;
    }
};

/* derived names: a position recorded with its time: the move from the
 * last one is kept with the last one's time, a zero move when that time is
 * not positive (the first record) */
void FUN_004bc460(MotionHistory004bc460 *history, float time,
                  const Float4A &position) /* derived name */
{
    float last = history->time;
    Float4A previous = history->position;
    history->position = position;
    history->time = time;
    if (last > 0.0f) {
        float dx = position.x - previous.x;
        float dy = position.y - previous.y;
        float dz = position.z - previous.z;
        history->grow();
        int index = history->next;
        MotionSample004bc460 &sample = history->samples[index];
        sample.time = last;
        sample.move.x = dx;
        sample.move.y = dy;
        sample.move.z = dz;
        sample.move.w = sqrtf(dx * dx + dz * dz);
        history->next = index >= 29 ? 0 : index + 1;
    } else {
        history->grow();
        int index = history->next;
        MotionSample004bc460 &sample = history->samples[index];
        sample.time = last;
        sample.move = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        history->next = index >= 29 ? 0 : index + 1;
    }
}
