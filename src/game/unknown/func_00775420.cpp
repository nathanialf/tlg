/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object00774560.h"
#include "tlg_math.h"
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: FUN_00775420 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_1594c93[26];
extern const char D_1594cad[19];

Name D_5817a30(D_1594c93, false);
Name D_5817a34(D_1594cad, false);

/* derived names: slot 6 of the vtable at 0x16acd78 (FUN_00774760) and of
 * the one at 0x16aca58 (FUN_00765630), one body, each reading this file's
 * VECTOR_W: the object made ready to start again. The block at +0x24 is
 * cleared, the object at +0x70 handed to FUN_0136b6f0, the length at +0x80
 * taken from the argument's float at +0x8 or, when that is negative, from
 * +0x7c, and the fields after it reset, the rotation at +0xa0 to VECTOR_W
 * (copied whole as plain floats, then lane by lane). Class and method
 * unknown; the fields' meaning is not traced. */
struct Start00774760 { /* derived name */
    u8 unknown0[0x8];
    float length; /* +0x8 */
};

struct Object0136b6f0; /* derived name: not traced */

void FUN_0136b6f0(Object0136b6f0 *object); /* derived name */

struct Object00774760 { /* derived name */
    u8 unknown0[0x24];
    u8 unknown24[0x40];
    u8 unknown64[0xc];
    Object0136b6f0 *unknown70; /* +0x70 */
    int unknown78;             /* +0x78 */
    float unknown7c;           /* +0x7c */
    float length;              /* +0x80 */
    float unknown84;           /* +0x84 */
    float unknown88;           /* +0x88 */
    int unknown8c;             /* +0x8c */
    int unknown90;             /* +0x90 */
    int unknown94;             /* +0x94 */
    u8 unknown98[0x8];
    Float4A rotation; /* +0xa0 */
    u8 unknownb0[0x44];
    int unknownf4;   /* +0xf4 */
    float unknownf8; /* +0xf8 */
};

void FUN_00774760(Object00774760 *self, const Start00774760 *start) /* derived name */
{
    memset(self->unknown24, 0, sizeof(self->unknown24));
    FUN_0136b6f0(self->unknown70);
    self->unknown78 = 0;
    float length = start->length;
    if (length < 0.0f)
        length = self->unknown7c;
    self->length = length;
    self->unknown84 = 0.0f;
    self->unknown88 = 0.0f;
    self->unknown8c = 1;
    self->unknown90 = 1;
    self->unknown94 = 0;
    self->unknownf4 = 1;
    self->unknownf8 = 0.0f;
    const Float4Data unit = reinterpret_cast<const Float4Data &>(VECTOR_W);
    self->rotation = unit;
}

/* FUN_00765630: the same body */
void FUN_00765630(Object00774760 *self, const Start00774760 *start) /* derived name */
{
    memset(self->unknown24, 0, sizeof(self->unknown24));
    FUN_0136b6f0(self->unknown70);
    self->unknown78 = 0;
    float length = start->length;
    if (length < 0.0f)
        length = self->unknown7c;
    self->length = length;
    self->unknown84 = 0.0f;
    self->unknown88 = 0.0f;
    self->unknown8c = 1;
    self->unknown90 = 1;
    self->unknown94 = 0;
    self->unknownf4 = 1;
    self->unknownf8 = 0.0f;
    const Float4Data unit = reinterpret_cast<const Float4Data &>(VECTOR_W);
    self->rotation = unit;
}

/* derived names: slot 7 of the vtable at 0x16acd78: the body's rotation and
 * point both set to this file's VECTOR_W, each a copy of it as plain
 * floats taken after the body is read, then stored lane by lane (the body
 * and the constant read again for the second) */
void Object00774560::slot7()
{
    unknown68->rotation = Float4Data(reinterpret_cast<const Float4Data &>(VECTOR_W));
    unknown68->position = Float4Data(reinterpret_cast<const Float4Data &>(VECTOR_W));
}
