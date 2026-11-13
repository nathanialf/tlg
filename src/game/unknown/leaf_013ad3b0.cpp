/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d1728
 * (config/vtables.derived.base.txt, stored by FUN_00ca9000 FUN_013ad3b0 FUN_013ad4d0), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_013ad3b0 tears them
 * down (the counted reference at +0x50); the rest are not traced. */
class Object016d1728 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d1728();

  private:
    u8 unknown24[0x2c];
    /* +0x50: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held50;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_013ad4d0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_013ad4d0 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_013ad4d0 too)
Object016d1728::~Object016d1728() {}
