/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_log.h"
#include "tlg_game_name.h"
#include "tlg_math.h"

/* FixCamera (the class's name from its messages "FixCamera(%s)::Init" and
 * "FixCamera(%s)::Term"; derived names otherwise), its vtable at 0x16abef8
 * (config/vtables.derived.base.txt; stored by FUN_0061ab50 and the
 * destructors FUN_0061adc0 and FUN_0061ae10). Its base's destructor
 * FUN_00afd410 stores the vtable at 0x16c7d08 (no row) and its row is named
 * for it (D15); the name at +0xc is the base's, released there. The
 * destructor is the key function, so this file emits the vtable. Both
 * messages go through the variadic FUN_00c831d0 (tlg_game_log.h), whose
 * first argument is not read, so the calls leave rdi unset (D50 addendum). */
class Object00afd410 /* derived name */
{
  public:
    virtual ~Object00afd410();

    u8 unknown8[4];
    Name unknownC; /* +0xc */
};

class FixCamera : public Object00afd410
{
  public:
    virtual ~FixCamera();

    u8 unknown10[0x50];
    Float4A unknown60; /* +0x60: FUN_0061aeb0 */
    Float4A unknown70; /* +0x70: FUN_0061aeb0 */
};

struct Source0061aeb0 { /* derived name */
    u8 unknown0[0x120];
    Float4A unknown120; /* +0x120 */
    u8 unknown130[0x10];
    Float4A unknown140; /* +0x140 */
};

Float4A FUN_0134ab60(const Float4A &value); /* derived name; not traced */

extern const char D_158983a[]; /* "FixCamera(%s)::Term\n" */
extern const char D_158984f[]; /* "FixCamera(%s)::Init\n" */

void FUN_00afded0(FixCamera *self, int unknown, int kind); /* derived name */

FixCamera::~FixCamera()
{
    FUN_00c831d0(this, D_158983a, D_17ac870[unknownC.index].string0);
}

/* Slot 5 of the vtable (its pointer at 0x16abf30), written as a free
 * function: calls FUN_00afded0 with 26 and 2, then logs the Init message
 * with the name's string, a tail call. Called also directly by
 * FUN_0061ab50. */
void FUN_0061ae60(FixCamera *self) /* derived name */
{
    FUN_00afded0(self, 26, 2);
    FUN_00c831d0(self, D_158984f, D_17ac870[self->unknownC.index].string0);
}

/* The function at 0x16abf40 in the vtable, written as a free function:
 * copies the row at +0x120 of its source and FUN_0134ab60's answer for the
 * row at +0x140 into the rows at +0x60 and +0x70. */
void FUN_0061aeb0(FixCamera *self, const Source0061aeb0 *source) /* derived name */
{
    self->unknown60 = source->unknown120;
    self->unknown70 = FUN_0134ab60(source->unknown140);
}
