/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b1a48
 * (config/vtables.derived.base.txt, stored by FUN_009f6ce0 FUN_009f88d0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_009f88d0 tears them
 * down (the counted references at +0x80, +0x48); the rest are not traced. */
class Object016b1a48 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b1a48();
    virtual void slot5(); /* derived name; FUN_009f8a90, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_009f8890, not traced */
    virtual void slot8(); /* derived name; FUN_009f88b0, not traced */

  private:
    u8 unknown24[0x24];
    /* +0x48: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held48;
    u8 unknown50[0x30];
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held80;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_009f8a70, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1a48::~Object016b1a48() {}
