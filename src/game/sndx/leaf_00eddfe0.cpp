/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_00ee22d0 passes twice (lea at 0xee350f and
 * 0xee3d68) with a context on its stack, a float and a count (the count zeroed
 * before the call): counts the object when its float at +0x3e0 is not positive
 * or is above the context's value times its float at +0x3e8 plus its float at
 * +0x3e4, and returns 0. The callback's caller and the meaning of the return
 * value are not traced. */
struct Object00eddfe0 { /* derived name */
    u8 unknown0[0x3e0];
    float unknown3e0;
    float unknown3e4;
    float unknown3e8;
};

struct Context00eddfe0 { /* derived name */
    float value;         /* derived name */
    int count;           /* derived name */
};

int FUN_00eddfe0(Object00eddfe0 *object, Context00eddfe0 *context) /* derived name */
{
    float limit = object->unknown3e0;
    if (limit <= 0.0f || limit > context->value * object->unknown3e8 + object->unknown3e4) {
        context->count++;
    }
    return 0;
}
