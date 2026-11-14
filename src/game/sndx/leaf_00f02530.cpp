/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00f02560 with its third argument, 2, and its fourth
 * to sixth, as a tail call; the object and the second argument are unused;
 * slot 52 of the vtable at 0x16beae0 (its pointer at 0x16bec90); its sibling
 * FUN_00f02510 passes 1 and zeros. The types are not traced. Class and method
 * unknown. */
struct Object00f02530; /* derived name */

void FUN_00f02560(void *target, int kind, void *a, void *b, void *c); /* derived name */

void FUN_00f02530(Object00f02530 *, void *, void *target, void *a, void *b,
                  void *c) /* derived name */
{
    FUN_00f02560(target, 2, a, b, c);
}
