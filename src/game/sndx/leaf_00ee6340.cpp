/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a voice's settings taken from a request: the byte at +0x503
 * cleared, the flag at +0x3f0 set, three bytes and an int copied, and the
 * four bytes the request points to at +0x18 (zeros for none); 0 is
 * returned. The structures are not traced further. */
struct Request00ee6340 { /* derived name */
    u8 unknown0[0x18];
    const u8 *unknown18; /* +0x18: four bytes */
    u8 unknown20[0x8];
    u8 unknown28; /* +0x28 */
    u8 unknown29[0x3];
    u8 unknown2c; /* +0x2c */
    u8 unknown2d[0x3];
    int unknown30; /* +0x30 */
    u8 unknown34;  /* +0x34 */
};

struct Voice00ee6340 { /* derived name */
    u8 unknown0[0x3f0];
    u8 unknown3f0;
    u8 unknown3f1;
    u8 unknown3f2;
    u8 unknown3f3;
    int unknown3f4;
    u8 unknown3f8[0x4];
    u8 unknown3fc[0x107];
    u8 unknown503; /* +0x503 */
};

// NONMATCHING: the four bytes' stores: the base keeps the first in each arm and stores the other
// three after the join from the bytes read together (`mov cl, [rax+1]; mov dl, [rax+2]; mov al,
// [rax+3]`, zeros in the other arm); here only the last is sunk (each byte read and stored in
// turn; if/else and four conditional expressions give the same)
int FUN_00ee6340(Voice00ee6340 *voice, const Request00ee6340 *request) /* derived name */
{
    const u8 *values = request->unknown18;
    voice->unknown503 = 0;
    voice->unknown3f0 = 1;
    voice->unknown3f1 = request->unknown28;
    voice->unknown3f4 = request->unknown30;
    voice->unknown3f2 = request->unknown34;
    voice->unknown3f3 = request->unknown2c;
    if (values) {
        voice->unknown3f8[0] = values[0];
        voice->unknown3f8[1] = values[1];
        voice->unknown3f8[2] = values[2];
        voice->unknown3f8[3] = values[3];
    } else {
        voice->unknown3f8[0] = 0;
        voice->unknown3f8[1] = 0;
        voice->unknown3f8[2] = 0;
        voice->unknown3f8[3] = 0;
    }
    return 0;
}
