/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_008506c0 registers under "asset_fx_ray_snd" (its
 * id the FUN_013bad90 hash of the string; lea at 0x850985): passes its second
 * and third arguments, the string of the name its fifth argument refers to
 * (the first field of the 32-byte entry of the table at 0x17ac870 the name's
 * index selects), its fourth argument, the name at 0x581d69c (which
 * FUN_008506c0 interns), 1 and 1 (the last on the stack) to FUN_008540e0 and
 * returns 1, as leaf_00857620.cpp's callback passes a literal. The first
 * argument is not read; the parameters' types and the callee's return type
 * are not traced. */
struct Object00857450;   /* derived name */
struct Argument00857450; /* derived name */

struct Entry017ac870 {   /* derived name */
    const char *string0; /* +0x0: the name's string */
    u8 unknown8[0x18];
};

extern Entry017ac870 D_17ac870[];

struct Name00857450 { /* derived name */
    unsigned index;   /* derived name */
};

extern Name00857450 D_581d69c;

void FUN_008540e0(Argument00857450 *argument, void *second, const char *name, void *third,
                  Name00857450 *key, int flag, int value); /* derived name */

int FUN_00857450(Object00857450 *, Argument00857450 *argument, void *second, void *third,
                 const Name00857450 *name) /* derived name */
{
    FUN_008540e0(argument, second, D_17ac870[name->index].string0, third, &D_581d69c, 1, 1);
    return 1;
}
