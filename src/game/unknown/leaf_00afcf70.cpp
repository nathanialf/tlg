/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object01388080.h"

/* derived names: a record of 0x34 bytes FUN_00612440 and FUN_006147e0 pass
 * from an array of 0x90-byte entries: seven words (a float first, flags at
 * +0x18), three names, two ints after the second and after the third */
struct Settings00afcf70 { /* derived name */
    float unknown0;       /* +0x0 */
    u32 unknown4[5];      /* +0x4 */
    u32 flags;            /* +0x18 */
    Name name1c;          /* +0x1c */
    Name name20;          /* +0x20 */
    int unknown24;        /* +0x24 */
    Name name28;          /* +0x28 */
    int unknown2c;        /* +0x2c */
    int unknown30;        /* +0x30 */
};

/* derived names: the object those callers hand the record to: the record
 * copied at +0x130, a flags word at +0x1c0 and a state at +0x1c8 */
struct Object00afcf70 {                                 /* derived name */
    void setSettings(const Settings00afcf70 &settings); /* derived name */

    u8 unknown0[0x130];
    Settings00afcf70 settings; /* +0x130 */
    u8 unknown164[0x5c];
    u32 flags; /* +0x1c0 */
    u8 unknown1c4[0x4];
    int state; /* +0x1c8 */
};

/* FUN_00afcf70: the record copied; with its first value zero or its flag
 * set, the word at +0xf80 of the object at 0x5938c40 set, the flag 2 raised
 * and the state made 2 */
// NONMATCHING: FUN_00afcf70, 73/85 at 388 bytes against 390: the copy and the float test are equal; the
// base tests the flag as `mov eax, [r14+0x18]; and eax, 1; je` (an X86ISD::AND kept for its value or a
// truncated test, X86ISelLowering.cpp EmitTest), the build as `test byte [r14+0x18], 1` (the load narrowed
// and folded). A one-bit bitfield and the test read through the copy give the build's form again.
void Object00afcf70::setSettings(const Settings00afcf70 &settings)
{
    this->settings = settings;
    if (settings.unknown0 == 0.0f || (settings.flags & 1)) {
        D_5938c40->unknownf80 = 1;
        flags |= 2;
        state = 2;
    }
}
