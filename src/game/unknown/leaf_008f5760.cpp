/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cc398.h"

/* derived names: the class whose vtable is at 0x16b0968 (config/
 * vtables.base.txt, stored by its constructor FUN_008f55f0), over
 * Object016cc398, adding no field the destructor sees */
class Object016b0968 : public Object016cc398 /* derived name */
{
  public:
    virtual ~Object016b0968();
};

/* derived names: the complete destructor: the body is empty and the class
 * adds no field, so its own vptr store is dropped and the base's destructor
 * (tlg_game_object016cc398.h) is inlined, its vptr store first.
 * FUN_008f5830, slot 1, is the deleting one, holding the same body. The
 * destructor is the class's key function, so this file emits the vtable, and
 * with it the base's vtable and destructors (0xb225a0, 0xb22670). */
Object016b0968::~Object016b0968() {}
