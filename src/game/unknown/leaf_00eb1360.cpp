/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: copies a value from the record at +0x20 into the record at
 * +0x28 (re-read after every group of stores): the eight bytes at +0x38
 * first, then by the kind at +0x40: kind 1 the six ints of two ranges, kind 2
 * a pair of ints, kind 3 the pair and whether the float after it is not
 * zero. The classes are not traced. */
struct Source00eb1360 { /* derived name */
    u8 unknown0[0x38];

    union {
        u64 value; /* +0x38 */

        struct {
            int first;  /* +0x38 */
            int second; /* +0x3c */
        };
    };

    int kind; /* +0x40 */
    u8 unknown44[0xc];
    int unknown50;
    int unknown54;

    union {
        int unknown58;
        float amount; /* +0x58 */
    };

    int unknown5c;
};

struct Target00eb1360 { /* derived name */
    u8 unknown0[0x10];

    union {
        u64 value; /* +0x10 */

        struct {
            int first;  /* +0x10 */
            int second; /* +0x14 */
        };
    };

    int unknown18;
    int unknown1c;

    union {
        int unknown20;
        bool enabled; /* +0x20 */
    };

    int unknown24;
};

struct Object00eb1360 { /* derived name */
    u8 unknown0[0x20];
    Source00eb1360 *source; /* +0x20 */
    Target00eb1360 *target; /* +0x28 */
};

// NONMATCHING: 21/43, 129 bytes of 129, the compares (3, 2, then 1) and the blocks are the base's;
// left, two instructions in the other order in each arm (first difference at instruction 11: the
// base loads the target, `mov rcx, [rdi + 0x28]`, before the first int, the build after it)
void FUN_00eb1360(Object00eb1360 *self) /* derived name */
{
    Source00eb1360 *source = self->source;
    if (!source)
        return;
    self->target->value = source->value;
    switch (source->kind) {
    case 1: {
        Target00eb1360 *target = self->target;
        target->first = source->first;
        target->second = source->second;
        target->unknown18 = source->unknown50;
        target->unknown1c = source->unknown54;
        target->unknown20 = source->unknown58;
        target->unknown24 = source->unknown5c;
        break;
    }
    case 2: {
        Target00eb1360 *target = self->target;
        target->unknown18 = source->unknown50;
        target->unknown1c = source->unknown54;
        break;
    }
    case 3: {
        Target00eb1360 *target = self->target;
        target->unknown18 = source->unknown50;
        target->unknown1c = source->unknown54;
        target->enabled = fabsf(source->amount) > 0.0f;
        break;
    }
    }
}
