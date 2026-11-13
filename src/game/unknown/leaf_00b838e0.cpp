/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b6f48
 * (config/vtables.derived.base.txt, stored by FUN_00b828e0 FUN_00b838e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00b838e0 tears them
 * down (the counted references at +0x58, +0x50); the rest are not traced. */
class Object016b6f48 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b6f48();
    virtual void slot5(); /* derived name; FUN_00b83aa0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_00b83d10, not traced */
    virtual void slot8(); /* derived name; FUN_00b83d30, not traced */

  private:
    u8 unknown24[0x2c];
    /* +0x50: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held50;
    /* +0x58: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held58;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00b83a80, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b6f48::~Object016b6f48() {}
