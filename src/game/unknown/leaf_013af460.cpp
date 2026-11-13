/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00ced570.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d1ca0
 * (config/vtables.derived.base.txt, stored by FUN_00cd6540 FUN_013af460 FUN_013af510), derived from
 * Object00ced570 (the class whose destructor is 0xced570): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013af460 tears them
 * down (the counted reference at +0x68); the rest are not traced. */
class Object016d1ca0 : public Object00ced570 /* derived name */
{
  public:
    virtual ~Object016d1ca0();

  private:
    u8 unknown8[0x60];
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held68;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00ced570 runs as a tail call. FUN_013af510, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016d1ca0::~Object016d1ca0() {}
