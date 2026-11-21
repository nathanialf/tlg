/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016d15b0.h"

/* derived names: the class whose vtable is at 0x16bad98
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d86010
 * and its destructor FUN_00d86290), derived from Object016d15b0
 * (tlg_game_object016d15b0.h). Its fields are traced where the destructor
 * tears them down: seven counted references from +0xb0 to +0xe0. */
class Object016bad98 : public Object016d15b0 /* derived name */
{
  public:
    virtual ~Object016bad98();

  private:
    u8 unknown90[0x20];
    Ref00503fb0<Object016b9108> heldb0; /* +0xb0 */
    Ref00503fb0<Object016b9108> heldb8; /* +0xb8 */
    Ref00503fb0<Object016b9108> heldc0; /* +0xc0 */
    Ref00503fb0<Object016b9108> heldc8; /* +0xc8 */
    Ref00503fb0<Object016b9108> heldd0; /* +0xd0 */
    Ref00503fb0<Object016b9108> heldd8; /* +0xd8 */
    Ref00503fb0<Object016b9108> helde0; /* +0xe0 */
};

/* derived name: the complete destructor: the body is empty; the
 * references are released, last first, then the base's inline destructor
 * (its blocks at +0x88 and +0x70), and Object00d30550's as a tail call.
 * FUN_00d866c0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable, and with it the base's
 * vtable and its two destructors (0x13a9e60, 0x13a9f00), which this unit
 * uses. */
Object016bad98::~Object016bad98() {}
