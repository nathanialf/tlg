/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_target004ad600.h"

/* derived names: the handler FUN_004acae0 stores at 0x57d75a8, beside the
 * hash of "Marker.settime.enter" at 0x57d75a0: reads self's name as two
 * numbers "a,b" as FUN_004ad530 does, without setting the bool and without
 * its test for the empty name (the entry of index 0 read: `mov eax, [rdi+0x14];
 * shl rax, 5` with no `test`). Class and method unknown. */
void FUN_004ad750(Object004ad600 *self, Target004ad600 *target) /* derived name */
{
    const char *string = D_17ac870[self->unknown14.index].string0;
    if (string && *string) {
        char *end = 0;
        float value = strtof(string, &end);
        if (end != string)
            target->unknown1ac = value;
        if (*end == ',') {
            char *secondEnd = 0;
            value = strtof(end + 1, &secondEnd);
            if (end + 1 != secondEnd)
                target->unknown1b0 = value;
        }
    }
}
