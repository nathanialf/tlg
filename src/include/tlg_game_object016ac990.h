/* src/include/tlg_game_object016ac990.h: the class whose vtable is at
 * 0x16ac990 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AC990_H
#define TLG_GAME_OBJECT016AC990_H

#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ac990
 * (config/vtables.derived.base.txt, stored by FUN_00763020 FUN_007631b0
 * FUN_007633d0), derived from Object00774560. 0x160 bytes (`mov edi,
 * 0x160` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00763020 sets them and its destructor FUN_007631b0
 * tears them down. The destructor is the class's key function
 * (leaf_007631b0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016ac990 : public Object00774560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0xfc], 0`
     * (the two names), the three references cleared (`vmovdqu [r15+0x110];
     * mov qword [r15+0x120], 0`: a run of zero stores made one memset), 1 at
     * +0x154, then the body's `mov dword [r15+0x7c], 0` (the base's field) */
    Object016ac990(const Name &name) : Object00774560(name), unknown154(1)
    {
        unknown7c = 0;
    }

    virtual ~Object016ac990();

  private:
    u8 unknowne8[0x14];
    Name namefc;  /* +0xfc: empty from the constructor, released by the destructor */
    Name name100; /* +0x100: empty from the constructor, released by the destructor */
    u8 unknown104[0xc];
    /* +0x110: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held110;
    /* +0x118: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held118;
    /* +0x120: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held120;
    u8 unknown128[0x2c];
    int unknown154; /* +0x154: 1 from the constructor; not traced */
    u8 unknown158[0x8];
};

#endif
