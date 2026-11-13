/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16ab4e8
 * (config/vtables.derived.base.txt, stored by FUN_005322e0 FUN_00532840), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 8 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_00532840 tears them
 * down (the counted references at +0x1b0, +0x1a8, +0x1a0, +0x198, +0x190, the block at +0xd0, the records at +0x1b8, +0x178, +0x160, +0x60, +0x38); the rest are not traced. */
class Object016ab4e8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ab4e8();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown24[0x14];
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
    Ref00503fb0<Node00503fb0> held190;
    /* +0x198: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held198;
    /* +0x1a0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held1a0;
    /* +0x1a8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held1a8;
    /* +0x1b0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held1b0;
    /* +0x1b8: torn down by the destructor (`lea rdi, [rbx+0x1b8]; call 0x134f620`) */
    Object0134f620 record1b8;
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00532bd0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ab4e8::~Object016ab4e8() {}
