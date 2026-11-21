/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived names: the counted object FUN_00ad84a0 starts from and holds: a
 * range of two floats at +0x24 and +0x28 and an int at +0x38. Their meaning
 * is not traced. */
struct Params00ad84a0 : Object016b9108 /* derived name */
{
    float max24; /* +0x24 */
    float min28; /* +0x28 */
    u8 unknown2c[0xc];
    int unknown38; /* +0x38 */
};

/* derived names: the object FUN_00482b90, FUN_004ae010 and FUN_004ae230
 * start through FUN_00ad84a0: flags at +0x8 to +0xd, a time at +0x14 drawn
 * between the parameters' two floats, two copies of a point at +0x40 and
 * +0x50, a point at +0x60 and the parameters held at +0x88. Their meaning
 * is not traced. */
struct Object00ad84a0 /* derived name */
{
    /* 0xad84a0 */
    void start(const Float4A &position, Params00ad84a0 &params); /* derived name */

    u8 unknown0[0x8];
    bool unknown8; /* +0x8 */
    bool unknown9; /* +0x9 */
    bool unknownA; /* +0xa */
    bool unknownB; /* +0xb */
    bool unknownC; /* +0xc */
    bool unknownD; /* +0xd */
    u8 unknownE[0x2];
    int unknown10;   /* +0x10 */
    float time14;    /* +0x14 */
    int unknown18;   /* +0x18 */
    int unknown1c;   /* +0x1c */
    float unknown20; /* +0x20 */
    u8 unknown24[0x1c];
    Float4A unknown40; /* +0x40 */
    Float4A unknown50; /* +0x50 */
    Float4A unknown60; /* +0x60 */
    u8 unknown70[0x18];
    AtomicRef0045c470<Object016b9108> held88; /* +0x88 */
};

void Object00ad84a0::start(const Float4A &position, Params00ad84a0 &params)
{
    unknown8 = false;
    unknown9 = false;
    unknownA = false;
    unknown40 = position;
    unknown50 = position;
    unknown60 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
    time14 = params.min28 + (params.max24 - params.min28) * (rand() / (float)RAND_MAX);
    unknown18 = 0;
    unknown1c = params.unknown38;
    unknown20 = HUGE_VALF;
    held88.set(&params);
    unknownC = false;
    unknownB = false;
    unknownD = false;
    unknown10 = 0;
}
