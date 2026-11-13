/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16b64a0
 * (config/vtables.derived.base.txt, stored by FUN_00b4aaf0 FUN_00b4aca0 FUN_00b4adc0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00b4aca0 tears them
 * down (the counted reference at +0x48, the record at +0x50); the rest are not traced. */
class Object016b64a0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b64a0();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x24];
    /* +0x48: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held48;
    /* +0x50: torn down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Object0134f620 record50;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00b4adc0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_00b4adc0 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_00b4adc0 too)
Object016b64a0::~Object016b64a0() {}
