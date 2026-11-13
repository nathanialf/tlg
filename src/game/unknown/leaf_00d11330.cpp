/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00d157e0.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b9f78
 * (config/vtables.derived.base.txt, stored by FUN_00d11040 FUN_00d11330), derived from
 * Object00d157e0 (the class whose destructor is 0xd157e0): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00d11330 tears them
 * down (the counted references at +0x80, +0x78, the record at +0x60); the rest are not traced. */
class Object016b9f78 : public Object00d157e0 /* derived name */
{
  public:
    virtual ~Object016b9f78();

  private:
    u8 unknown8[0x58];
    /* +0x60: torn down by the destructor (`lea rdi, [rbx+0x60]; call 0x134f620`) */
    Object0134f620 record60;
    /* +0x78: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held78;
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held80;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00d157e0 runs as a tail call. FUN_00d11460, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b9f78::~Object016b9f78() {}
