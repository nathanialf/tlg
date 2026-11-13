/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16a8ca8
 * (config/vtables.derived.base.txt, stored by FUN_003795e0 FUN_00379710 FUN_00379830), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_00379710 tears them
 * down (the counted reference at +0xe8); the rest are not traced. */
class Object016a8ca8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a8ca8();

  private:
    u8 unknown24[0xc4];
    /* +0xe8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> helde8;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00379830, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_00379830 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_00379830 too)
Object016a8ca8::~Object016a8ca8() {}
