/* src/include/tlg_game_object016b7938.h: the class whose vtable is at 0x16b7938
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7938_H
#define TLG_GAME_OBJECT016B7938_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16b7938
 * (config/vtables.derived.base.txt, stored by FUN_0057cf50 FUN_00bde630 FUN_00bdfe70), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 11 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00bdfe70 tears them
 * down (the counted references at +0x68, +0x60, +0x58, the Names at +0x2c, +0x28, the block at +0x88, the record at +0x70); the rest are not traced. */
class Object016b7938 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7938();
    virtual void slot5();              /* derived name; FUN_00c1b340, not traced */
    virtual void slot6();              /* derived name; FUN_00c1b350, not traced */
    virtual void slot7();              /* derived name; FUN_00be0150, not traced */
    virtual void slot8();              /* derived name; FUN_00be09c0, not traced */
    virtual int slot9(void *argument); /* derived name; FUN_00be0c40, not traced */
    virtual void slot10();             /* derived name; FUN_00be0e20, not traced */
    virtual void slot11();             /* derived name; FUN_00be0c30, not traced */

  protected:
    u8 unknown24[0x4];
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    Name name2c; /* +0x2c: released by the destructor (`mov eax, [rbx+0x2c]; shl 5`) */
    u8 unknown30[0x28];
    /* +0x58: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held58;
    /* +0x60: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held60;
    /* +0x68: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held68;
    /* +0x70: torn down by the destructor (`lea rdi, [rbx+0x70]; call 0x134f620`) */
    Object0134f620 record70;
    /* +0x88: an owned block, released by the destructor (`mov rax, [rbx+0x88]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block88;
};

/* the class's slot 9, called by the derived classes' own (FUN_0057de00) */
int FUN_00be0c40(Object016b7938 *self, void *argument); /* derived name */

#endif
