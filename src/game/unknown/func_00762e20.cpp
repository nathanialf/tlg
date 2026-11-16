/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_math.h"
#include "tlg_types.h"
#include <algorithm>

/* derived names: FUN_00762e20 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 3 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15946d1[11];
extern const char D_1595794[18];
extern const char D_15ca367[8];

Name D_58174a4(D_15ca367, false);
Name D_58174a0(D_1595794, false);
Name D_58174a8(D_15946d1, false);

/* derived names: what FUN_0136a480 is handed: a target, this file's
 * VECTOR_W (copied whole as plain floats, then lane by lane: two 64-bit
 * loads, four 32-bit stores), a point, then a scale and two flags; the
 * fields' meaning is not traced */
struct Request0136a480 { /* derived name */
    void *target;        /* +0x0 */
    Float4A rotation;    /* +0x10 */
    Float4A position;    /* +0x20 */
    int unknown30;       /* +0x30 */
    float scale;         /* +0x34 */
    float unknown38;     /* +0x38 */
    float unknown3c;     /* +0x3c */
    int unknown40;       /* +0x40 */
    int unknown44;       /* +0x44 */
};

struct Queue0136a480 { /* derived name: not traced */
};

void FUN_0136a480(Queue0136a480 *queue, const Request0136a480 *request); /* derived name */

/* derived names: the object at +0x70 of slot 19's: the queue at +0xb0 */
struct Owner0136a480 { /* derived name */
    u8 unknown0[0xb0];
    Queue0136a480 queue; /* +0xb0 */
};

/* derived names: slot 19's argument: the step's length at +0x4, a point at
 * +0x180 and a target at +0x190 */
struct Step00762d20 { /* derived name */
    u8 unknown0[0x4];
    float length; /* +0x4 */
    u8 unknown8[0x178];
    Float4A position; /* +0x180 */
    void *target;     /* +0x190 */
};

/* derived names: the body at +0x68 of the object: a float at +0xd0 and the
 * total at +0x2394 */
struct Body00762d20 { /* derived name */
    u8 unknown0[0xd0];
    float unknownd0; /* +0xd0 */
    u8 unknownd4[0x22c0];
    float total; /* +0x2394 */
};

/* derived names: the class whose vtable is at 0x16ac8c8 (leaf_00761150.cpp)
 * as far as its slot 19 reads it */
struct Object00762d20 { /* derived name */
    u8 unknown0[0x44];
    int requested; /* +0x44 */
    u8 unknown48[0x20];
    Body00762d20 *body;   /* +0x68 */
    Owner0136a480 *owner; /* +0x70 */
    u8 unknown78[0x8c];
    float unknown104; /* +0x104 */
};

/* derived names: slot 19 of the vtable at 0x16ac8c8: the body's total
 * raised by the float at +0x104, at most zero, times the body's float at
 * +0xd0, over the step's length (the reciprocal taken first); with a
 * target the request handed to the owner's queue first and +0x44 set */
void FUN_00762d20(Object00762d20 *self, const Step00762d20 *step) /* derived name */
{
    const float amount =
        std::min(self->unknown104, 0.0f) * self->body->unknownd0 * (1.0f / step->length);
    void *target = step->target;
    self->requested = 0;
    if (target) {
        const Float4Data unit = reinterpret_cast<const Float4Data &>(VECTOR_W);
        Request0136a480 request;
        request.rotation = unit;
        request.target = target;
        request.position = step->position;
        request.unknown30 = 0;
        request.scale = amount;
        request.unknown38 = 0.0f;
        request.unknown3c = 1.0f;
        request.unknown40 = 1;
        request.unknown44 = 0;
        FUN_0136a480(&self->owner->queue, &request);
        self->requested = 1;
    }
    self->body->total += amount;
}
