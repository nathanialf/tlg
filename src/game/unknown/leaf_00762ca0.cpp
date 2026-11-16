/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: two functions of one shape on two layouts (the second's
 * fields 0x40 lower): the vector at +0xe0 of the source becomes the object's
 * position (+0x160, +0x120); unless the int before it (+0x140, +0x100) is
 * set, the record at +0x68 gets the point at +0x150 (+0x110) less the
 * position, its fourth word copied, at +0x2130. Their callers and the
 * fields' meaning are not traced. */
struct Float4_00762ca0 { /* derived name */
    float x, y, z, w;

    void set(float x_, float y_, float z_, float w_) /* derived name */
    {
        x = x_;
        y = y_;
        z = z_;
        w = w_;
    }
};

struct Source00762ca0 { /* derived name */
    u8 unknown0[0xe0];
    Float4A position; /* +0xe0 */
};

struct Record00762ca0 { /* derived name */
    u8 unknown0[0x678];
    int unknown678; /* +0x678: 3 has FUN_0079a610 add the offset to the point */
    u8 unknown67c[0x1a64];
    int unknown20e0; /* +0x20e0 */
    u8 unknown20e4[0x4c];
    Float4A offset; /* +0x2130 */
    u8 unknown2140[0x188];
    int unknown22c8; /* +0x22c8 */
};

struct Object00762ca0 { /* derived name */
    u8 unknown0[0x68];
    Record00762ca0 *record; /* +0x68 */
    u8 unknown70[0xd0];
    int unknown140; /* +0x140 */
    u8 unknown144[0xc];
    Float4_00762ca0 point; /* +0x150 */
    Float4A position;      /* +0x160 */
};

struct Object0079a960 { /* derived name */
    u8 unknown0[0x68];
    Record00762ca0 *record; /* +0x68 */
    u8 unknown70[0x90];
    int unknown100; /* +0x100 */
    u8 unknown104[0xc];
    Float4_00762ca0 point; /* +0x110 */
    Float4A position;      /* +0x120 */
};

void FUN_00762ca0(Object00762ca0 *self, const Source00762ca0 *source) /* derived name */
{
    self->position = source->position;
    if (!self->unknown140) {
        const float x = self->point.x - self->position.x;
        const float y = self->point.y - self->position.y;
        const float z = self->point.z - self->position.z;
        self->record->offset.set(x, y, z, self->point.w);
    }
}

void FUN_0079a960(Object0079a960 *self, const Source00762ca0 *source) /* derived name */
{
    self->position = source->position;
    if (!self->unknown100) {
        const float x = self->point.x - self->position.x;
        const float y = self->point.y - self->position.y;
        const float z = self->point.z - self->position.z;
        self->record->offset.set(x, y, z, self->point.w);
    }
}

/* derived names: slot 16 of the vtable at 0x16ad868, on the second layout:
 * with the record's int at +0x678 at 3 the point takes the record's offset
 * in x, y and z, else, unless its int at +0x20e0 is set, the record's int
 * at +0x22c8 is cleared; then the offset is reset to (0, 0, 0, 1) */
void FUN_0079a610(Object0079a960 *self) /* derived name */
{
    Record00762ca0 *record = self->record;
    if (record->unknown678 == 3) {
        const float x = self->point.x + record->offset.x;
        const float y = self->point.y + record->offset.y;
        const float z = self->point.z + record->offset.z;
        self->point.x = x;
        self->point.y = y;
        self->point.z = z;
    } else if (!record->unknown20e0) {
        record->unknown22c8 = 0;
    }
    record->offset.set(0.0f, 0.0f, 0.0f, 1.0f);
}
