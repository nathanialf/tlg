/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16a7e28
 * (config/vtables.derived.base.txt, stored by FUN_002aa2a0 FUN_002aa490), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_002aa490 tears them
 * down (the counted references at +0x68, +0x48, the records at +0x50, +0x30); the rest are not traced. */
class Object016a7e28 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a7e28();

  private:
    u8 unknown24[0xc];
    /* +0x30: torn down by the destructor (`lea rdi, [rbx+0x30]; call 0x134f620`) */
    Object0134f620 record30;
    /* +0x48: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held48;
    /* +0x50: torn down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Object0134f620 record50;
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held68;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_002aa630, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a7e28::~Object016a7e28() {}
