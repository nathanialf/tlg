/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_target004ad600.h"

/* derived names: the handler FUN_004acae0 stores at 0x57d74f8, beside the
 * hash of "Marker.fire3.enter" at 0x57d74f0: the object the target's map
 * holds under self's name, when there is one and the target's object at
 * +0xf8 is of the type D_57d76f8 points to (or one derived from it): the
 * found object's value at +0x120 (FUN_01352bb0) handed to FUN_004ae010 with
 * the target's object. Class and method unknown. */
void FUN_004ad3b0(Object004ad600 *self, Target004ad600 *target) /* derived name */
{
    Object01350fa0 *found = FUN_004ab790(target, self->unknown14);
    if (found) {
        Object016b9108 *object = target->unknownf8;
        if (object && object->isKindOf(D_57d76f8)) {
            Manager004ae010 *manager = D_57c9390->unknown38->unknown900->unknown88;
            Float4A value;
            FUN_01352bb0(value, found);
            FUN_004ae010(manager, value, object);
        }
    }
}
