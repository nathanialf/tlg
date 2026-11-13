/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16cdd50
 * (config/vtables.derived.base.txt, stored by FUN_009bb920 FUN_01384540 FUN_01384660), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_01384540 tears them
 * down (the counted reference at +0x40, the record at +0x28); the rest are not traced. */
class Object016cdd50 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cdd50();

  private:
    u8 unknown24[0x4];
    /* +0x28: torn down by the destructor (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Object0134f620 record28;
    /* +0x40: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held40;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_01384660, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_01384660 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_01384660 too)
Object016cdd50::~Object016cdd50() {}
