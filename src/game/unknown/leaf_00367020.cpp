/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16a8b00
 * (config/vtables.derived.base.txt, stored by FUN_00366b30 FUN_00367020), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00367020 tears them
 * down (the counted references at +0x80, +0x78, +0x40, +0x38); the rest are not traced. */
class Object016a8b00 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a8b00();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_003672e0, not traced */
    virtual void slot8(); /* derived name; FUN_003677b0, not traced */

  private:
    u8 unknown24[0x14];
    /* +0x38: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held38;
    /* +0x40: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held40;
    u8 unknown48[0x30];
    /* +0x78: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held78;
    /* +0x80: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held80;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_003672c0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a8b00::~Object016a8b00() {}
