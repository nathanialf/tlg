/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_sndx_lock.h"
#include "tlg_types.h"

/* derived names: the sound runtime's state, the object the pointer at
 * 0x5a8dfa0 holds, as far as its voices */
struct SndxVoice05a8dfa0;

struct SndxVoiceOwner05a8dfa0 { /* derived name */
    u8 unknown0[0x80];
    SndxVoice05a8dfa0 *voice80; /* +0x80: the voice that plays for it */
    u8 unknown88[0x79];
    u8 unknown101; /* +0x101: the voice at +0x80 stands in */
};

struct SndxVoice05a8dfa0 {         /* derived name */
    SndxVoiceOwner05a8dfa0 *owner; /* +0x0 */
    u8 unknown8[0x14];
    s32 unknown1c; /* +0x1c: not zero while the voice plays */
    u8 unknown20[0x88];
};

struct SndxRuntime05a8dfa0 { /* derived name */
    u8 unknown0[0x40];
    SndxVoice05a8dfa0 *voices; /* +0x40: 0xa8 bytes each */
    u32 voiceCount;            /* +0x48 */
};

extern SndxRuntime05a8dfa0 *D_5a8dfa0;

/* derived name: the count of the voices that play (a voice whose owner's
 * flag at +0x101 is set counts by the owner's voice), -3 when the runtime is
 * not running */
static int countPlayingVoices()
{
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 current;
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 next;
    int result = -3;
    if (sndxEnter(current, next) == 0) {
        int count = 0;
        SndxVoice05a8dfa0 *voice = D_5a8dfa0->voices;
        for (u32 i = 0; i < D_5a8dfa0->voiceCount; ++i, ++voice) {
            const SndxVoice05a8dfa0 *playing = voice;
            if (voice->owner && voice->owner->unknown101)
                playing = voice->owner->voice80;
            if (playing->unknown1c)
                ++count;
        }
        if (sndxLeave(current, next) == 0)
            result = count;
    }
    return result;
}

/* derived names: slot 31 of the vtable at 0x16be9a8 (Object00eb3c90's):
 * the count of the voices that play, 0 when the runtime is not running */
struct Object00ebf0f0; /* derived name */

// NONMATCHING: the count: the base keeps `cmp dword [rdi+0x1c], 0; je; inc r9d` where the
// build folds the increment into `cmp 1; sbb esi, -1` (InstCombine's FoldSelectIntoOp makes the
// select a zext add). A branch from a select is CodeGenPrepare's (a compare of a load with one
// use), so the base's select was made after the last InstCombine, by the link's late
// CFGSimplification: the increment was not an SSA value in any unit's own pipeline (round 406D
// probes: a count through a pointer gives two selects, not one)
int FUN_00ebf0f0(Object00ebf0f0 *self) /* derived name */
{
    const int count = countPlayingVoices();
    return count < 0 ? 0 : count;
}
