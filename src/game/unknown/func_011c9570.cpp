/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object0143e060.h"

/* derived names: FUN_011c9570 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad6ac0(D_15cb5dd, false);
Name D_5ad6ac4(D_15cb5e6, false);

/* derived names: 0x70 bytes, 16-byte aligned: three pairs of a vector set to
 * zero and one set to this unit's VECTOR_W, then a pointer cleared, by the
 * default constructor (Element0140d5c0 of func_010ef520.cpp, over this
 * unit's VECTOR_W); not traced further. */
struct Element01467950 { /* derived name */

    Element01467950()
        : unknown0(_mm_setzero_ps()), unknown10(VECTOR_W.v), unknown20(_mm_setzero_ps()),
          unknown30(VECTOR_W.v), unknown40(_mm_setzero_ps()), unknown50(VECTOR_W.v), unknown60(0)
    {
    }

    Vec4 unknown0;   /* +0x0 */
    Vec4 unknown10;  /* +0x10 */
    Vec4 unknown20;  /* +0x20 */
    Vec4 unknown30;  /* +0x30 */
    Vec4 unknown40;  /* +0x40 */
    Vec4 unknown50;  /* +0x50 */
    void *unknown60; /* +0x60 */
};

/* FUN_01467950: sets the count of an array of them (tlg_game_array.h's
 * resize). Called from 3 sites in 2 functions (FUN_011bd1d0, FUN_01467570). */
template void Array05943280<Element01467950>::resize(unsigned);

/* derived name: this file's frame entry (tlg_game_frames013fb310.h): one
 * element type per file, as the base holds one resize of them per file */
struct FrameEntry011c9570 : FrameEntry013fb310 { /* derived name */
};

/* FUN_01467c60 */
template void Array05943280<FrameEntry011c9570>::resize(unsigned);

/* FUN_0146dae0: FUN_013ef390's body (func_0101dcc0.cpp) with this file's VECTOR_W */
Object016d65f0::Object016d65f0(unsigned count) : model(0), count(count)
{
    values10.resize(count);
    sets28.resize(count);
    frames40.resize(count);
    values80.resize(count);
    for (u8 key = 0; key < count; ++key) {
        values10[key] = 0;
        values80[key] = 0;
        frames40[key].unknown0 = _mm_setzero_ps();
        frames40[key].resetSecond();
    }
}

/* derived name: FUN_013e5560's body (func_00fda5c0.cpp) with this file's
 * VECTOR_W: every frame set of the poser made `count` frames long */
// The base's loop is split on the frame count being 0 by the unit pipeline's
// LoopUnswitch (tools/patches/llvm-3.7.1-unswitch-01-whole-invariant-branch.patch).
void FUN_014677a0(FramePoser013fccf0 *self, int count) /* derived name */
{
    for (unsigned i = 0; i < self->count; ++i)
        self->sets.at(i).frames.resize(count);
}

/* derived name: slot 3 of the vtable at 0x16d65a8: the model kept at +0x8
 * and the int at +0x9c, every frame set made `count` frames long (FUN_014677a0),
 * then each of the five vector sets made `count` vectors long, zero, and
 * every vector set to one (the base splits the five sets' loop on count
 * being 0, docs/DECISIONS.md D92) */
void FUN_01471260(VectorPoser01404660 *self, FadeModel013d4610 *model, int value,
                  unsigned count) /* derived name */
{
    self->model = model;
    self->unknown9c = value;
    FUN_014677a0(self, count);
    for (int i = 0; i < 5; ++i) {
        self->vectorSets.at(i).vectors.resize(count);
        for (unsigned k = 0; k < count; ++k)
            self->vectorSets.at(i).vectors.at(k) = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
    }
}

/* derived names: the class whose vtable is at 0x16d65a8 (seven slots: slot 3
 * is FUN_01471260 and slot 4 FUN_01471440), over Object016d65f0: this file's
 * Object016d5668 (func_0108cf60.cpp). The slots are not traced. */
class Object016d65a8 : public Object016d65f0 /* derived name */
{
  public:
    Object016d65a8();

    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */

  private:
    int unknown9c;                               /* +0x9c: in the base's tail padding */
    Array01343a80<VectorSet01404660> vectorSets; /* +0xa0: five */
    Array01343a80<ZeroVector013ef6b0> vectorsb8; /* +0xb8: five */
    Vec4 unknownd0;                              /* +0xd0: ones */
    Frame016c1128 framese0[4];                   /* +0xe0 */
};

/* FUN_01467d60: the vector sets' array made five long through its resize
 * (FUN_0108d540), the zero vectors' in line */
Object016d65a8::Object016d65a8() : Object016d65f0(5), unknown9c(0), unknownd0(_mm_set1_ps(1.0f))
{
    vectorSets.resize(5);
    vectorsb8.resize(5);
}
