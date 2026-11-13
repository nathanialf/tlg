/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0139d760.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b6d70
 * (config/vtables.derived.base.txt, stored by FUN_00b7d020 FUN_00b7dd00 FUN_00b7ddb0), derived from
 * Object0139d760 (the class whose destructor is 0x139d760): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00b7dd00 tears them
 * down (the counted reference at +0x110); the rest are not traced. */
class Object016b6d70 : public Object0139d760 /* derived name */
{
  public:
    virtual ~Object016b6d70();

  private:
    u8 unknown8[0x108];
    /* +0x110: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held110;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_0139d760 runs as a tail call. FUN_00b7ddb0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b6d70::~Object016b6d70() {}
