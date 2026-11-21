/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16a8db0
 * (config/vtables.derived.base.txt): three counted references at +0x10,
 * +0x18 and +0x20, released last to first by its destructor; no base.
 * FUN_0037ac70, slot 1, is the deleting destructor. The first field is not
 * traced. */
class Object016a8db0 /* derived name */
{
  public:
    virtual ~Object016a8db0();

  private:
    u8 unknown8[0x8];
    Ref00503fb0<Object016b9108> held10; /* +0x10 */
    Ref00503fb0<Object016b9108> held18; /* +0x18 */
    Ref00503fb0<Object016b9108> held20; /* +0x20 */
};

Object016a8db0::~Object016a8db0() {}
