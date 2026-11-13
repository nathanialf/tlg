/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d1668
 * (config/vtables.derived.base.txt, stored by FUN_00c91f20 FUN_013abbe0 FUN_013abd00), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_013abbe0 tears them
 * down (the counted reference at +0x30); the rest are not traced. */
class Object016d1668 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d1668();

  private:
    u8 unknown24[0xc];
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held30;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_013abd00, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_013abd00 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_013abd00 too)
Object016d1668::~Object016d1668() {}
