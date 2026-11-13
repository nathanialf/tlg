/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b6c20
 * (config/vtables.derived.base.txt, stored by FUN_00b766d0 FUN_00b76da0 FUN_00b76ec0 FUN_00b781a0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 12 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00b76da0 tears them
 * down (the counted reference at +0x60); the rest are not traced. */
class Object016b6c20 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b6c20();
    virtual void slot5();  /* derived name; FUN_00b76fd0, not traced */
    virtual void slot6();  /* derived name; FUN_01343880, not traced */
    virtual void slot7();  /* derived name; FUN_00b77320, not traced */
    virtual void slot8();  /* derived name; FUN_00b77340, not traced */
    virtual void slot9();  /* derived name; FUN_00b77040, not traced */
    virtual void slot10(); /* derived name; FUN_00b77050, not traced */
    virtual void slot11(); /* derived name; FUN_00b77080, not traced */
    virtual void slot12(); /* derived name; FUN_00b772a0, not traced */

  private:
    u8 unknown24[0x3c];
    /* +0x60: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held60;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00b76ec0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
// NONMATCHING (the deleting destructor FUN_00b76ec0 only): an inline-cost margin: the build calls this
// destructor where the base inlines it (its vptr store is in FUN_00b76ec0 too)
Object016b6c20::~Object016b6c20() {}
