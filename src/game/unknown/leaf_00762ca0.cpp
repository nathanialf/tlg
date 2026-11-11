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
};

struct Source00762ca0 { /* derived name */
    u8 unknown0[0xe0];
    Float4A position; /* +0xe0 */
};

struct Record00762ca0 { /* derived name */
    u8 unknown0[0x2130];
    Float4_00762ca0 offset; /* +0x2130 */
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

// NONMATCHING: list-ilp order: the base loads the point x, y, z upward and the record pointer before
// the fourth word, the build z, y, x and the word first (the same with the offset built by copy and
// subtractions); 7 of 17, size equal
void FUN_00762ca0(Object00762ca0 *self, const Source00762ca0 *source) /* derived name */
{
    self->position = source->position;
    if (!self->unknown140) {
        Float4_00762ca0 offset = {self->point.x - self->position.x,
                                  self->point.y - self->position.y,
                                  self->point.z - self->position.z, self->point.w};
        self->record->offset = offset;
    }
}

// NONMATCHING: list-ilp order: the base loads the point x, y, z upward and the record pointer before
// the fourth word, the build z, y, x and the word first (the same with the offset built by copy and
// subtractions); as FUN_00762ca0
void FUN_0079a960(Object0079a960 *self, const Source00762ca0 *source) /* derived name */
{
    self->position = source->position;
    if (!self->unknown100) {
        Float4_00762ca0 offset = {self->point.x - self->position.x,
                                  self->point.y - self->position.y,
                                  self->point.z - self->position.z, self->point.w};
        self->record->offset = offset;
    }
}
