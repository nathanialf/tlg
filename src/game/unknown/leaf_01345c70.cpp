/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16c70d0
 * (config/vtables.derived.base.txt; its constructor FUN_002148f0): a counted
 * reference at +0x10, an array of references at +0x18 and two arrays at
 * +0x30 and +0x48 whose elements have no destructor (their blocks given
 * back). Slot 2 is 0x69a0. FUN_01345d90, slot 1, is the deleting
 * destructor. The other fields and the arrays' elements are not traced. */
class Object016c70d0 /* derived name */
{
  public:
    virtual ~Object016c70d0();

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Object016b9108> held10; /* +0x10 */
    Object0134f620 unknown18;           /* +0x18 */
    Array05943280<u32> unknown30;       /* +0x30 */
    Array05943280<u32> unknown48;       /* +0x48 */
};

// NONMATCHING (the deleting destructor FUN_01345d90 only): the base's holds this body inlined
// (292 bytes); the module calls the complete destructor (an inline-cost margin).
Object016c70d0::~Object016c70d0() {}
