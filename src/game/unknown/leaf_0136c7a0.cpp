/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16cbe60
 * (config/vtables.derived.base.txt, stored by FUN_007aedb0 FUN_0136c7a0 FUN_0136c8f0), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_0136c7a0 tears them
 * down (the counted reference at +0x28, the Name at +0x24); the rest are not traced. */
class Object016cbe60 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cbe60();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held28;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0136c8f0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_0136c8f0 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_0136c8f0 too)
Object016cbe60::~Object016cbe60() {}
