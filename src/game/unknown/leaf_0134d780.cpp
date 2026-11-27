/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00823c90.h"

/* derived names: slot 16 of the vtables at 0x16a8830 and 0x16c7608 (its pointers at
 * 0x16a88c0 and 0x16c7698): returns what FUN_00823c90 gives for the object and its own
 * string (passed on in rsi untouched), after
 * calling FUN_0134d0e0 on it. Class and method unknown. */
int FUN_0134d780(Object00823c90 *self, const char *string) /* derived name */
{
    int result = FUN_00823c90(self, string);
    FUN_0134d0e0(self);
    return result;
}
