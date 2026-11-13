/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16b06b0
 * (config/vtables.derived.base.txt, stored by FUN_008ef8a0 FUN_008efe80), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 15 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_008efe80 tears them
 * down (the counted references at +0xf8, +0xf0, +0x48, +0x40, the block at +0xd0); the rest are not traced. */
class Object016b06b0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b06b0();
    virtual void slot5();  /* derived name; FUN_008f1140, not traced */
    virtual void slot6();  /* derived name; FUN_008f08d0, not traced */
    virtual void slot7();  /* derived name; FUN_008f08f0, not traced */
    virtual void slot8();  /* derived name; FUN_01373fc0, not traced */
    virtual void slot9();  /* derived name; FUN_008f0900, not traced */
    virtual void slot10(); /* derived name; FUN_008f09c0, not traced */
    virtual void slot11(); /* derived name; FUN_008f09d0, not traced */
    virtual void slot12(); /* derived name; FUN_008f2a30, not traced */
    virtual void slot13(); /* derived name; FUN_008f28f0, not traced */
    virtual void slot14(); /* derived name; FUN_008f2900, not traced */
    virtual void slot15(); /* derived name; FUN_01373fd0, not traced */

  private:
    u8 unknown24[0x1c];
    /* +0x40: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held40;
    /* +0x48: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held48;
    u8 unknown50[0x80];
    /* +0xd0: an owned block, released by the destructor (`mov rax, [rbx+0xd0]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 blockd0;
    u8 unknownd8[0x18];
    /* +0xf0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> heldf0;
    /* +0xf8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> heldf8;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_008f0160, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b06b0::~Object016b06b0() {}
