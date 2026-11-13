/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16a8b90
 * (config/vtables.derived.base.txt, stored by FUN_0036af00 FUN_0036b650), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_0036b650 tears them
 * down (the counted references at +0xa8, +0xa0, +0x98, +0x90, +0x88, +0x68, the record at +0x70); the rest are not traced. */
class Object016a8b90 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a8b90();

  private:
    u8 unknown24[0x44];
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held68;
    /* +0x70: torn down by the destructor (`lea rdi, [rbx+0x70]; call 0x134f620`) */
    Object0134f620 record70;
    u8 unknown80[0x8];
    /* +0x88: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held88;
    /* +0x90: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held90;
    /* +0x98: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held98;
    /* +0xa0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> helda0;
    /* +0xa8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> helda8;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0036b9f0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a8b90::~Object016a8b90() {}
