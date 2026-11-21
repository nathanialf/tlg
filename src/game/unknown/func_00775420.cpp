/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object00774560.h"
#include "tlg_game_object00774760.h"
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
void FUN_0136b6f0(Object0136b6f0 *object); /* derived name */

void FUN_00774760(Object00774760 *self, const Start00774760 *start) /* derived name */
{
    memset(&self->unknown24, 0, sizeof(self->unknown24));
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
    memset(&self->unknown24, 0, sizeof(self->unknown24));
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

/* derived names: slot 7 of the vtable at 0x16acd78: the pose not read; the
 * body's rotation and point both set to this file's VECTOR_W, each a copy of it as plain
 * floats taken after the body is read, then stored lane by lane (the body
 * and the constant read again for the second) */
void Object00774560::slot7(Pose0077bac0 *)
{
    unknown68->rotation = Float4Data(reinterpret_cast<const Float4Data &>(VECTOR_W));
    unknown68->position = Float4Data(reinterpret_cast<const Float4Data &>(VECTOR_W));
}

/* derived names: the overrides of slot 6 in the classes over 0x16acd78 that
 * read this file's VECTOR_W: each starts with the base's body (FUN_00774760,
 * inlined), then sets its own fields */
/* derived name: not traced; the tail of Object016ac990's slot 6 */
void FUN_007633f0(Object00774760 *self, const Start00774760 *start);

/* FUN_007640a0: slot 6 of the vtable at 0x16ac990 */
void FUN_007640a0(Object00774760 *self, const Start00774760 *start) /* derived name */
{
    FUN_00774760(self, start);
    self->unknown24.unknown4 = 1;
    self->unknown24.unknown8 = 1;
    self->unknown24.unknown2c = 1;
    self->unknown68->unknownc00->setUnknown60(0);
    self->unknown68->unknown22c8 = 0;
    FUN_007633f0(self, start);
}

/* derived names: Object016acf08's own int at +0x120 */
struct Object00777fb0 : public Object00774760 { /* derived name */
    u8 unknownfc[0x24];
    int unknown120; /* +0x120 */
};

/* FUN_00777fb0: slot 6 of the vtable at 0x16acf08 */
void FUN_00777fb0(Object00777fb0 *self, const Start00774760 *start) /* derived name */
{
    FUN_00774760(self, start);
    if (self->unknown120)
        self->unknown24.unknown2c = 1;
}

/* FUN_00778f70: slot 6 of the vtable at 0x16ad098 */
void FUN_00778f70(Object00774760 *self, const Start00774760 *start) /* derived name */
{
    FUN_00774760(self, start);
    self->unknown24.unknownc = 1;
    self->unknown68->unknownc00->setUnknown60(0);
    self->unknown68->unknownc00->setUnknown64(self->unknown68->unknownb0c);
}

/* FUN_007792e0: slot 6 of the vtable at 0x16ad160 */
void FUN_007792e0(Object00774760 *self, const Start00774760 *start) /* derived name */
{
    FUN_00774760(self, start);
    self->unknown24.unknown0 = 1;
    self->unknown24.unknownc = 1;
    self->unknown68->unknownc00->setUnknown60(0);
    self->unknown68->unknownc00->setUnknown64(self->unknown68->unknownb0c);
}

/* derived names: Object016ad868's own int at +0x100 and point at +0x110 */
struct Object00799ae0 : public Object00774760 { /* derived name */
    u8 unknownfc[0x4];
    int unknown100; /* +0x100 */
    u8 unknown104[0xc];
    Float4A unknown110; /* +0x110 */
};

/* FUN_00799ae0: slot 6 of the vtable at 0x16ad868: the point at +0x110
 * the body's at +0x2120 when its int at +0x678 is 2, else the argument's at
 * +0xe0 */
void FUN_00799ae0(Object00799ae0 *self, const Start00774760 *start) /* derived name */
{
    FUN_00774760(self, start);
    self->unknown24.unknownc = 1;
    self->unknown24.unknown2c = 1;
    self->unknown24.unknown20 = 1;
    const int value = self->unknown68->unknownb08;
    self->unknown68->unknownc00->setUnknown60(value);
    self->unknown68->unknownc00->setUnknown64(self->unknown68->unknownb0c);
    self->unknown100 = 0;
    if (self->unknown68->unknown678 == 2)
        self->unknown110 = self->unknown68->unknown2120;
    else
        self->unknown110 = start->unknowne0;
}

/* FUN_007a09d0: slot 6 of the vtable at 0x16adc50 */
void FUN_007a09d0(Object00774760 *self, const Start00774760 *start) /* derived name */
{
    FUN_00774760(self, start);
    self->unknown24.unknown0 = 1;
    self->unknown24.unknown4 = 1;
    self->unknown24.unknown8 = 1;
    self->unknown24.unknownc = 1;
    self->unknown24.unknown14 = 1;
    const int value = self->unknown68->unknownb08;
    self->unknown68->unknownc00->setUnknown60(value);
    self->unknown68->unknownc00->setUnknown64(self->unknown68->unknownb0c);
}
