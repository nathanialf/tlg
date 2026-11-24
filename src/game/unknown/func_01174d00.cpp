/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object016d4d28.h"

/* derived names: FUN_01174d00 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad4c60(D_15cb5dd, false);
Name D_5ad4c64(D_15cb5e6, false);

/* FUN_01446a80: FUN_013ef390's body (func_0101dcc0.cpp) with this file's VECTOR_W */
Object016d6178::Object016d6178(unsigned count) : model(0), count(count)
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

/* derived names: the class whose vtable is at 0x16d6130 (seven slots: slot 1
 * 0x14482e0, slot 3 0x1448740, slot 4 0x1447300, slot 6 0x1448aa0 its own),
 * Object016d5668's shape (func_0108cf60.cpp) over Object016d6178: an int in
 * the base's tail padding at +0x9c, a vector set per pose, five zero vectors,
 * a vector of ones and four frames. The slots are not traced. */
class Object016d6130 : public Object016d6178 /* derived name */
{
  public:
    Object016d6130();

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

/* the vector sets' array made five long through its resize (FUN_0108d540),
 * the zero vectors' in line (FUN_013fb410's body over Object016d6178) */
inline Object016d6130::Object016d6130()
    : Object016d6178(5), unknown9c(0), unknownd0(_mm_set1_ps(1.0f))
{
    vectorSets.resize(5);
    vectorsb8.resize(5);
}

/* derived names: built by FUN_01446550 (called by FUN_01166b80): over
 * Object016d6130, four ints made -1 and four frame sets, each made three
 * frames long. No virtual of its own: its vtable is the same constant as
 * Object016d6130's, which the link stage merges (FUN_01446550 stores
 * 0x16d6140 twice, `mov [r12], r15` at 0x1446575 and 0x1446763). */
class Object01446550 : public Object016d6130 /* derived name */
{
  public:
    Object01446550();

  private:
    int unknown160[4];                       /* +0x160: -1 */
    Array01343a80<FrameSet00fda5c0> sets170; /* +0x170: four (FUN_013e71b0) */
};

/* FUN_01446550 */
// NONMATCHING: 1295 bytes for the base's 1325 (round 575E): the vtable of Object01446550,
// merged in the base with Object016d6130's at 0x16d6130, has no row in
// config/vtables.derived.base.txt (and Object016d6130's slots are not written, so its vtable is
// not emitted to merge with); with two constants the base's r15, the one vtable address stored
// twice, is formed twice. The zero vectors' resize: the base looks the block's owner up with the
// tag-10 test (tlg_game_block.h's reallocateOwnedBlock, the open split of round 324E), this
// build without it. The four sets are written one by one: as a loop of four 3.7.1 keeps the
// loop (815 bytes), the base has four copies
Object01446550::Object01446550()
{
    sets170.resize(4);
    unknown160[0] = -1;
    sets170.at(0).frames.resize(3);
    unknown160[1] = -1;
    sets170.at(1).frames.resize(3);
    unknown160[2] = -1;
    sets170.at(2).frames.resize(3);
    unknown160[3] = -1;
    sets170.at(3).frames.resize(3);
}
