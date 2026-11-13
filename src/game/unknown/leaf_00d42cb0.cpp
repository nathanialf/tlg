/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00d30550.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16ba2c8
 * (config/vtables.derived.base.txt, stored by FUN_00d42af0 FUN_00d42cb0), derived from
 * Object00d30550 (the class whose destructor is 0xd30550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00d42cb0 tears them
 * down (the counted references at +0x88, +0x80); the rest are not traced. */
class Object016ba2c8 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object016ba2c8();

  private:
    u8 unknown8[0x78];
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held80;
    /* +0x88: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held88;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00d30550 runs as a tail call. FUN_00d42de0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ba2c8::~Object016ba2c8() {}
