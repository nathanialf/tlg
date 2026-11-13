/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b82c8
 * (config/vtables.derived.base.txt, stored by FUN_00c1f3b0 FUN_00c1f5e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00c1f5e0 tears them
 * down (the counted references at +0x78, +0x70); the rest are not traced. */
class Object016b82c8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b82c8();

  private:
    u8 unknown24[0x4c];
    /* +0x70: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held70;
    /* +0x78: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held78;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00c1f780, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b82c8::~Object016b82c8() {}
