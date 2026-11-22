/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_collection00214e10.h"
#include "tlg_game_object00774560.h"
#include "tlg_game_object016b85e0.h"

/* derived names: what the object at +0x1e8 of Object016ad480 holds: an int
 * at +0x120 and six values from +0x130, copied from the body by slot 11,
 * then handed to FUN_00206df0; the rest is not traced */
struct Record0078b710 { /* derived name */
    u8 unknown0[0x120];
    int unknown120; /* +0x120 */
    u8 unknown124[0xc];
    Float4A unknown130; /* +0x130 */
    Float4A unknown140; /* +0x140 */
    Float4A unknown150; /* +0x150 */
    Float4A unknown160; /* +0x160 */
    Float4A unknown170; /* +0x170 */
    Float4A unknown180; /* +0x180 */
};

void FUN_00206df0(Record0078b710 *record); /* derived name: not traced */

/* derived names: the class whose vtable is at 0x16ad480
 * (config/vtables.derived.base.txt, stored by FUN_00783b40 FUN_007847d0),
 * derived from Object00774560; only what slot 11 reads is traced */
/* derived names: the 0x90-byte record Object016ad480 holds at +0x250 and
 * +0x5a0, set back by slot 15 (FUN_0078ce00): the ints at +0x0 and +0x70
 * to -1, two rotations to the identity, the pointers at +0x20 and +0x28
 * (set by FUN_00784d50) to null and the nine floats at +0x4c to the identity
 * matrix; the point at +0x30 (FUN_00784d50) is left alone */
struct Track0078ce00 { /* derived name */

    void reset() /* derived name */
    {
        unknown0 = -1;
        unknown4 = 0;
        unknown10.set(0.0f, 0.0f, 0.0f, 1.0f);
        unknown20 = 0;
        unknown28 = 0;
        unknown40 = 0;
        unknown44 = 0;
        unknown48 = 0;
        matrix4c[0] = 1.0f;
        matrix4c[1] = 0.0f;
        matrix4c[2] = 0.0f;
        matrix4c[3] = 0.0f;
        matrix4c[4] = 1.0f;
        matrix4c[5] = 0.0f;
        matrix4c[6] = 0.0f;
        matrix4c[7] = 0.0f;
        matrix4c[8] = 1.0f;
        unknown70 = -1;
        unknown74 = 0;
        unknown78 = 0;
        unknown80.set(0.0f, 0.0f, 0.0f, 1.0f);
    }

    int unknown0; /* +0x0 */
    int unknown4; /* +0x4 */
    u8 unknown8[0x8];
    Float4A unknown10; /* +0x10 */
    void *unknown20;   /* +0x20 */
    void *unknown28;   /* +0x28 */
    Float4A unknown30; /* +0x30 */
    int unknown40;     /* +0x40 */
    int unknown44;     /* +0x44 */
    int unknown48;     /* +0x48 */
    float matrix4c[9]; /* +0x4c */
    int unknown70;     /* +0x70 */
    int unknown74;     /* +0x74 */
    int unknown78;     /* +0x78 */
    u8 unknown7c[0x4];
    Float4A unknown80; /* +0x80 */
};

class Object016ad480 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016ad480();
    virtual void slot11(); /* FUN_0078b710 */
    virtual void slot15(); /* FUN_0078ce00 */

  private:
    u8 unknownfc[0xec];
    Record0078b710 *unknown1e8; /* +0x1e8 */
    u8 unknown1f0[0x60];
    Track0078ce00 unknown250;  /* +0x250 */
    Object00214e10 unknown2e0; /* +0x2e0 */
    Track0078ce00 unknown5a0;  /* +0x5a0 */
    u8 unknown630[0x20];
    AtomicRef0045c470<Object016b85e0> unknown650; /* +0x650 */
};

/* derived names: slot 11 of the vtable at 0x16ad480: while slot 22 says so,
 * the body's int at +0x1330 and its values at +0x1390, +0x13a0 and +0x13c0 to
 * +0x13f0 are copied to the record at +0x1e8 (the body and the record read
 * again for each), which is then handed to FUN_00206df0 */
void Object016ad480::slot11()
{
    if (slot22()) {
        unknown1e8->unknown120 = unknown68->unknown1330;
        unknown1e8->unknown130 = unknown68->unknown1390;
        unknown1e8->unknown140 = unknown68->unknown13a0;
        unknown1e8->unknown150 = unknown68->unknown13c0;
        unknown1e8->unknown160 = unknown68->unknown13d0;
        unknown1e8->unknown170 = unknown68->unknown13e0;
        unknown1e8->unknown180 = unknown68->unknown13f0;
        FUN_00206df0(unknown1e8);
    }
}

/* derived names: slot 15 of the vtable at 0x16ad480: both records set
 * back, the object at +0x2e0 reset (FUN_00214e10) and the reference at
 * +0x650 emptied */
// NONMATCHING: 495 bytes as the base, every store as the base's; the
// vector (1, 0, 0, 0) of the first matrix is loaded (`vmovss xmm2, [pool]`)
// where the base builds it as integers (`mov eax, 0x3f800000; vmovd xmm2,
// eax`). The matrix copied from an identity constant (integer stores) moves
// SLP's 16-store chunks: a static constant gives +0x29c as the base's, then
// +0x2b8..+0x2c4 as one vector; an extern one folded at the link, one 8-wide
// vector at +0x29c
void Object016ad480::slot15()
{
    unknown250.reset();
    unknown5a0.reset();
    FUN_00214e10(&unknown2e0);
    unknown650.clear();
}
