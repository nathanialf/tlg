/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774760.h"

/* derived names: Object016ad480's own fields as its slot 6 sets them */
struct Object00785d40 : public Object00774760 { /* derived name */
    u8 unknownfc[0x18];
    float unknown114; /* +0x114 */
    u8 unknown118[0x4];
    float unknown11c; /* +0x11c */
    float unknown120; /* +0x120 */
    float unknown124; /* +0x124 */
    u8 unknown128[0x8];
    Float4A unknown130; /* +0x130 */
    Float4A unknown140; /* +0x140 */
    int unknown150;     /* +0x150: the bits of the body's +0xb08 not passed on */
    u8 unknown154[0xb0];
    int unknown204; /* +0x204 */
    int unknown208; /* +0x208 */
    u8 unknown20c[0xc];
    int unknown218; /* +0x218 */
    int unknown21c; /* +0x21c */
    u8 unknown220[0x1c];
    int unknown23c; /* +0x23c */
    u8 unknown240[0x4d4];
    int unknown714; /* +0x714 */
};

/* derived name: not traced; the tail of Object016ad480's slot 6 */
void FUN_00784d50(Object00785d40 *self, const Start00774760 *start);

/* FUN_00785d40: slot 6 of the vtable at 0x16ad480, in its own unit: the
 * base's body (FUN_00774760) is a call at the unit's own stage and inlined
 * by the link (the six ones from +0x44 stored as 16 + 8 bytes: SLP's chunk
 * of 16 stores starts at +0x44 only when the inlined body's stores are not
 * in the block). The flags at +0x21c are the body's at +0x3928, with more
 * bits unless the argument's object says not to. */
// NONMATCHING: 99/102 in the whole module, same size: case 7's read of
// +0x3928 is scheduled before the compare of +0x13c (base: `cmp [rax+0x13c],
// 0; mov eax, [rcx+0x3928]`, the pointer in rax); with the test written the
// other way the order is the base's but the case's store is not tail-merged
// into case 3's (base `jne 0x785f39`)
void FUN_00785d40(Object00785d40 *self, const Start00774760 *start) /* derived name */
{
    FUN_00774760(self, start);
    self->unknown24.unknown4 = 1;
    self->unknown24.unknown8 = 1;
    self->unknown24.unknownc = 1;
    self->unknown24.unknown20 = 1;
    self->unknown24.unknown24 = 1;
    self->unknown24.unknown28 = 1;
    self->unknown24.unknown2c = 1;
    self->unknown24.unknown30 = 1;
    self->unknown24.unknown34 = 1;
    self->unknown24.unknown3c = 16;
    self->unknown70->unknownc8 = 0;
    const int value = self->unknown68->unknownb08 & ~self->unknown150;
    self->unknown68->unknownc00->setUnknown60(value);
    self->unknown68->unknownc00->setUnknown64(self->unknown68->unknownb0c);
    self->unknown68->unknownc50.set(0.0f, 0.0f, 0.0f, 1.0f);
    self->unknownb0.set(0.0f, 0.0f, 0.0f, 1.0f);
    self->unknown114 = -1.0f;
    self->unknown120 = self->unknown11c;
    self->unknown124 = 1.0f;
    self->unknown130.set(0.0f, 0.0f, 0.0f, 1.0f);
    self->unknown140.set(0.0f, 0.0f, 0.0f, 1.0f);
    self->unknown714 = -1;
    self->unknown218 = 0;
    self->unknown23c = 0;
    Body00774760 *body = self->unknown68;
    switch (body->unknown1c18) {
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
        self->unknown204 = 1;
        self->unknown208 = 1;
        self->unknown21c = body->unknown3928;
        break;
    case 7:
        self->unknown204 = -1;
        self->unknown208 = -1;
        if (!start->unknown58->unknown13c)
            self->unknown21c =
                body->unknown3928 |
                ((body->unknownad9 & 2) ? (body->unknownafc | body->unknownb00) : body->unknownaf8);
        else
            self->unknown21c = body->unknown3928;
        break;
    }
    FUN_00784d50(self, start);
}
