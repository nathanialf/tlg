/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an event sent to the voice whose index a record holds at
 * +0x8 in the runtime's rack (D_5a8dfa0's +0x80): sceNgs2RackGetVoiceHandle,
 * then sceNgs2VoiceControl with one parameter of 12 bytes, id 6, carrying 1
 * for mode 2 and 3 otherwise (the two functions' NIDs verified). */
struct Ngs2Handle00ecc780; /* derived name: opaque */

struct Ngs2ParamHead00ecc780 { /* derived name */
    u16 size;
    s16 next;
    u32 id;
};

struct Ngs2EventParam00ecc780 { /* derived name */
    Ngs2ParamHead00ecc780 header;
    u32 event;
};

extern "C" int sceNgs2RackGetVoiceHandle(Ngs2Handle00ecc780 *rack, u32 voiceIndex,
                                         Ngs2Handle00ecc780 **voice);
extern "C" int sceNgs2VoiceControl(Ngs2Handle00ecc780 *voice,
                                   const Ngs2ParamHead00ecc780 *parameters);

struct Runtime00ecc780 { /* derived name */
    u8 unknown0[0x80];
    Ngs2Handle00ecc780 *rack; /* +0x80 */
};

extern Runtime00ecc780 *D_5a8dfa0; /* derived name */

struct Voice00ecc780 { /* derived name */
    u8 unknown0[0x8];
    u16 index; /* +0x8 */
};

void FUN_00ecc780(const Voice00ecc780 *voice, int mode) /* derived name */
{
    Ngs2EventParam00ecc780 parameter;
    Ngs2Handle00ecc780 *handle;
    sceNgs2RackGetVoiceHandle(D_5a8dfa0->rack, voice->index, &handle);
    parameter.header.size = sizeof(parameter);
    parameter.header.next = 0;
    parameter.header.id = 6;
    parameter.event = mode == 2 ? 1 : 3;
    sceNgs2VoiceControl(handle, &parameter.header);
}
