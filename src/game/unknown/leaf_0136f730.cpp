/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0136f730.h"

/* derived names: slot 6 of the vtable at 0x16cbf68 (no row; its pointer at
 * 0x16cbfa8): for each of the four pairs of pointers at +0x58 and +0x78 of
 * its second argument it calls FUN_008113a0 with the pointer at +0x28 of its
 * third, read again after each call (tlg_game_object0136f730.h). The
 * object itself is not used; the types are not traced. */
struct Context0136f730 /* derived name */
{
    u8 unknown0[0x28];
    void *unknown28; /* +0x28 */
};

void FUN_0136f730(void *, const Object0136f730 *object,
                  const Context0136f730 *context) /* derived name */
{
    for (int i = 0; i < 4; i++)
        FUN_008113a0(context->unknown28, object->first58[i].get(), object->second78[i].get());
}
