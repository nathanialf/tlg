/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <algorithm>

#include "tlg_game_name.h"

/* derived names: a record of nine values at +0x8, the constant one at
 * 0x14f06c0 among them (FUN_0044e770, FUN_0044f9e0 and FUN_00459dc0 pass it,
 * and read its +0x24 for the target's +0x8c elsewhere). Not traced past
 * them; the values are copied as 32-bit words. */
struct Source00acdb40 { /* derived name */
    u8 unknown0[0x8];
    float unknown8;  /* +0x8: FUN_00acdc60 offsets it and keeps it at least 0 */
    float unknownc;  /* +0xc: likewise */
    float unknown10; /* +0x10: likewise */
    int unknown14;   /* +0x14 */
    float unknown18; /* +0x18: likewise */
    float unknown1c; /* +0x1c: likewise */
    int unknown20;   /* +0x20 */
    int unknown24;   /* +0x24 */
    int unknown28;   /* +0x28 */
};

/* derived names: the record the values go to: nine values at +0x70, then
 * three names */
struct Target00acdb40 { /* derived name */
    u8 unknown0[0x70];
    float unknown70; /* +0x70 */
    float unknown74; /* +0x74 */
    float unknown78; /* +0x78 */
    int unknown7c;   /* +0x7c */
    float unknown80; /* +0x80 */
    float unknown84; /* +0x84 */
    int unknown88;   /* +0x88 */
    int unknown8c;   /* +0x8c */
    int unknown90;   /* +0x90 */
    Name name94;     /* +0x94 */
    Name name98;     /* +0x98 */
    Name name9c;     /* +0x9c */
};

/* FUN_00acdb40: the target's names released, then the source's values
 * copied one by one in order */
void FUN_00acdb40(const Source00acdb40 *source, Target00acdb40 *target) /* derived name */
{
    target->name94.release();
    target->name98.release();
    target->name9c.release();
    target->unknown70 = source->unknown8;
    target->unknown74 = source->unknownc;
    target->unknown78 = source->unknown10;
    target->unknown7c = source->unknown14;
    target->unknown80 = source->unknown18;
    target->unknown84 = source->unknown1c;
    target->unknown88 = source->unknown20;
    target->unknown8c = source->unknown24;
    target->unknown90 = source->unknown28;
}

/* FUN_00acdc60 (called by FUN_0044f9e0): as FUN_00acdb40, with an offset added
 * to the five float values, each kept at least 0 */
void FUN_00acdc60(const Source00acdb40 *source, Target00acdb40 *target,
                  float offset) /* derived name */
{
    target->name94.release();
    target->name98.release();
    target->name9c.release();
    target->unknown70 = std::max(source->unknown8 + offset, 0.0f);
    target->unknown74 = std::max(source->unknownc + offset, 0.0f);
    target->unknown78 = std::max(source->unknown10 + offset, 0.0f);
    target->unknown7c = source->unknown14;
    target->unknown80 = std::max(source->unknown18 + offset, 0.0f);
    target->unknown84 = std::max(source->unknown1c + offset, 0.0f);
    target->unknown88 = source->unknown20;
    target->unknown8c = source->unknown24;
    target->unknown90 = source->unknown28;
}
