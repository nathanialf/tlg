/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c55550.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16ae418
 * (config/vtables.derived.base.txt, stored by FUN_0080aeb0 FUN_0080b5d0 FUN_0080b680), derived from
 * Object00c55550 (the class whose destructor is 0xc55550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_0080b5d0 tears them
 * down (the counted reference at +0x240); the rest are not traced. */
class Object016ae418 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016ae418();

  private:
    u8 unknown8[0x238];
    /* +0x240: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held240;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00c55550 runs as a tail call. FUN_0080b680, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ae418::~Object016ae418() {}
