/* src/include/tlg_game_object016ab4e8.h: the class whose vtable is at 0x16ab4e8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB4E8_H
#define TLG_GAME_OBJECT016AB4E8_H

#include "tlg_game_object01343880.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16ab4e8
 * (config/vtables.derived.base.txt, stored by FUN_005322e0 FUN_00532840), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's).
 * Its own fields are traced only where its destructor FUN_00532840 tears them
 * down (the counted references at +0x1b0, +0x1a8, +0x1a0, +0x198, +0x190, the block at +0xd0, the records at +0x1b8, +0x178, +0x160, +0x60, +0x38); the rest are not traced.
 * The creator FUN_0052e010 allocates 0x1e0 bytes (`mov edi, 0x1e0` before operator new). */
class Object016ab4e8 : public Object01343880 /* derived name */
{
  public:
    Object016ab4e8(const Name &name); /* FUN_005322e0, its row named after it (D15) */
    virtual ~Object016ab4e8();

  private:
    u8 unknown34[0x4];
    /* +0x38: torn down by the destructor (`lea rdi, [rbx+0x38]; call 0x134f620`) */
    Object0134f620 record38;
    u8 unknown50[0x10];
    /* +0x60: torn down by the destructor (`lea rdi, [rbx+0x60]; call 0x134f620`) */
    Object0134f620 record60;
    u8 unknown78[0x58];
    /* +0xd0: an owned block, released by the destructor (`mov rax, [rbx+0xd0]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 blockd0;
    u8 unknownd8[0x88];
    /* +0x160: torn down by the destructor (`lea rdi, [rbx+0x160]; call 0x134f620`) */
    Object0134f620 record160;
    /* +0x178: torn down by the destructor (`lea rdi, [rbx+0x178]; call 0x134f620`) */
    Object0134f620 record178;
    /* +0x190: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held190;
    /* +0x198: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held198;
    /* +0x1a0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held1a0;
    /* +0x1a8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held1a8;
    /* +0x1b0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held1b0;
    /* +0x1b8: torn down by the destructor (`lea rdi, [rbx+0x1b8]; call 0x134f620`) */
    Object0134f620 record1b8;
    u8 unknown1d0[0x10];
};

#endif
