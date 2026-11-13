/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16ab7c8
 * (config/vtables.derived.base.txt, stored by FUN_0057e850 FUN_0057e9d0 FUN_0057eaf0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 6 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_0057e9d0 tears them
 * down (the counted reference at +0x30); the rest are not traced. */
class Object016ab7c8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ab7c8();
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0xc];
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held30;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0057eaf0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_0057eaf0 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_0057eaf0 too)
Object016ab7c8::~Object016ab7c8() {}
