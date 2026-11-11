/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include <functional>

/* derived names: FUN_01061610 (2473 bytes) builds two std::function
 * objects in place on its frame (rbp-0xc0 and rbp-0xf0, the `lea`s at
 * 0x10617ca and 0x10617d1: implementations 0x16c1088 and 0x16c10d8), each a
 * lambda capturing the object it works on (`this`, read once from the
 * closure: r15, kept at rbp-0x130), and
 * copies them into the entries it adds (0x1061847 on). The first takes a
 * value and stores its inverse (0 for 0) at +0xf04 and +0xf3c of the record
 * at +0x248 of the object's first member; the second stores the inverses of
 * that record's +0xf14 and +0xf4c there. Each divide is guarded by a single
 * `je` on `vucomiss`, an ordered not-equal compare: fabsf(x) > 0, which
 * InstCombine turns into `fcmp one`. The rest is not traced. */
struct Record01061610 { /* derived name */
    u8 unknown0[0xf04];
    float unknownf04; /* +0xf04 */
    u8 unknownf08[0xc];
    float unknownf14; /* +0xf14 */
    u8 unknownf18[0x24];
    float unknownf3c; /* +0xf3c */
    u8 unknownf40[0xc];
    float unknownf4c; /* +0xf4c */
};

struct Holder01061610 { /* derived name */
    u8 unknown0[0x248];
    Record01061610 *unknown248; /* +0x248 */
};

struct Owner01061610 {        /* derived name */
    Holder01061610 *unknown0; /* +0x0 */
    u8 unknown8[0x418];
    std::function<void(float)> onValue; /* +0x420, derived name: not traced */
    std::function<void()> onReset;      /* derived name: not traced */

    void FUN_01061610(); /* derived name */
};

// NONMATCHING: not written beyond the lambdas. Slot 2 of the first
// (0x1064150): the base keeps each arm's store to +0xf04 (the immediate 0 in
// one), where this build sinks them into one store after the arms (D54's
// question).
void Owner01061610::FUN_01061610()
{
    std::function<void(float)> value = [this](float scale) {
        Record01061610 *record = unknown0->unknown248;
        if (fabsf(scale) > 0.0f)
            record->unknownf04 = 1.0f / scale;
        else
            record->unknownf04 = 0.0f;
        unknown0->unknown248->unknownf3c = record->unknownf04;
    };
    std::function<void()> reset = [this]() {
        Record01061610 *record = unknown0->unknown248;
        record->unknownf04 = fabsf(record->unknownf14) > 0.0f ? 1.0f / record->unknownf14 : 0.0f;
        record = unknown0->unknown248;
        record->unknownf3c = fabsf(record->unknownf4c) > 0.0f ? 1.0f / record->unknownf4c : 0.0f;
    };
    onValue = value;
    onReset = reset;
}
