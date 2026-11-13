/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00ca38f0.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b5380
 * (config/vtables.derived.base.txt, stored by FUN_00b1f270 FUN_00b1f3e0), derived from
 * Object00ca38f0 (the class whose destructor is 0xca38f0): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00b1f3e0 tears them
 * down (the counted references at +0x60, +0x58); the rest are not traced. */
class Object016b5380 : public Object00ca38f0 /* derived name */
{
  public:
    virtual ~Object016b5380();

  private:
    u8 unknown8[0x50];
    /* +0x58: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held58;
    /* +0x60: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held60;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00ca38f0 runs as a tail call. FUN_00b1f510, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b5380::~Object016b5380() {}
