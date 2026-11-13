/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00cf7fb0.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16d1f68
 * (config/vtables.derived.base.txt, stored by FUN_00cf9470 FUN_013b34f0 FUN_013b35a0), derived from
 * Object00cf7fb0 (the class whose destructor is 0xcf7fb0): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013b34f0 tears them
 * down (the counted reference at +0xe0, the record at +0xc8); the rest are not traced. */
class Object016d1f68 : public Object00cf7fb0 /* derived name */
{
  public:
    virtual ~Object016d1f68();

  private:
    u8 unknown8[0xc0];
    /* +0xc8: torn down by the destructor (`lea rdi, [rbx+0xc8]; call 0x134f620`) */
    Object0134f620 recordc8;
    /* +0xe0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> helde0;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00cf7fb0 runs as a tail call. FUN_013b35a0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016d1f68::~Object016d1f68() {}
