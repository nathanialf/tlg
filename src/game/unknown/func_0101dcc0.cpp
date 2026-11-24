/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_frames013fb310.h"
#include "tlg_game_object016d7a28.h"

/* derived names: FUN_0101dcc0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acfdb0(D_15cb5dd, false);
Name D_5acfdb4(D_15cb5e6, false);

/* derived name: this file's frame record (tlg_game_frames013fb310.h), its
 * frames made with this file's VECTOR_W */
struct FrameRecord0101dcc0 : FrameRecord013ef6b0 { /* derived name */
    FrameRecord0101dcc0();
};

/* FUN_013ef6b0 */
FrameRecord0101dcc0::FrameRecord0101dcc0()
{
    vectors.resize(2);
    frames.resize(2);
}

/* FUN_013ef390: the keys' arrays sized, the frame sets by FUN_013e71b0 (out of
 * line), the frames built from this file's VECTOR_W; then each key's two
 * values cleared and its frame set again, the zero stored whole and the
 * vector copied lane by lane (Frame016c1128::resetSecond), under an 8-bit
 * counter (`mov al, 1; ...; movzx ecx, al; dec al`) compared with the
 * argument */
Object016d52c8::Object016d52c8(unsigned count) : model(0), count(count)
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

/* FUN_013f0770: slot 3 of Object016d52f0 (tlg_game_object016d7a28.h), each key's
 * frame set resized with this file's VECTOR_W */
// The base's loop is split on the frame count being 0 by the unit pipeline's
// LoopUnswitch (tools/patches/llvm-3.7.1-unswitch-01-whole-invariant-branch.patch).
void Object016d52f0::FUN_013f0770(FadeModel013d4610 *model, unsigned frames, int value9c,
                                  int valuea0)
{
    this->model = model;
    unknown9c = value9c;
    unknowna0 = valuea0;
    for (unsigned i = 0; i < count; ++i)
        sets28.at(i).frames.resize(frames);
}

/* FUN_013f0fa0: slot 3 of Object016d5288, the same with a third value */
// The base's loop is split on the frame count being 0 by the unit pipeline's
// LoopUnswitch (tools/patches/llvm-3.7.1-unswitch-01-whole-invariant-branch.patch).
void Object016d5288::FUN_013f0fa0(FadeModel013d4610 *model, int value9c, unsigned frames,
                                  int valuea0, int valuea4)
{
    this->model = model;
    unknown9c = value9c;
    unknowna0 = valuea0;
    unknowna4 = valuea4;
    for (unsigned i = 0; i < count; ++i)
        sets28.at(i).frames.resize(frames);
}
