/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_target004ad600.h"

/* derived names: the handler FUN_004acae0 stores at 0x57d74c8, beside the
 * hash of "Marker.fire.enter" at 0x57d74c0: the object the target's map
 * holds under self's name, when there is one and the manager FUN_004ae010
 * takes has its own object at +0xa8: the found object's value at +0x120
 * (FUN_01352bb0) handed to FUN_004ae010 with that object. Class and method
 * unknown. */
void FUN_004ad190(Object004ad600 *self, Target004ad600 *target) /* derived name */
{
    Object01350fa0 *found = FUN_004ab790(target, self->unknown14);
    if (found) {
        Manager004ae010 *manager = D_57c9390->unknown38->unknown900->unknown88;
        Object016b9108 *object = manager->unknowna8;
        if (object) {
            Float4A value;
            FUN_01352bb0(value, found);
            FUN_004ae010(manager, value, object);
        }
    }
}
