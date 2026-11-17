/* src/include/tlg_game_object016accb0.h: the class whose vtable is at
 * 0x16accb0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACCB0_H
#define TLG_GAME_OBJECT016ACCB0_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16accb0
 * (config/vtables.derived.base.txt, stored by FUN_0076e4a0 FUN_0076e620), derived from
 * Object00774560: slots 2 to 22 are the base's or override them.
 * Its own fields are traced only where its destructor FUN_0076e620 tears them
 * down (the counted references at +0x188, +0x180, the Names at +0x14c, +0x148, +0x100), the others where its constructor
 * FUN_0076e4a0 sets them. 0x1a0 bytes (`mov edi, 0x1a0` before operator new
 * in its creator FUN_0076e340). */
class Object016accb0 : public Object00774560 /* derived name */
{
  public:
    Object016accb0(const Name &name); /* FUN_0076e4a0 */
    virtual ~Object016accb0();
    virtual void slot7(Pose0077bac0 *pose);  /* FUN_007701b0 (func_00773e90.cpp) */
    virtual void slot19(Pose0077bac0 *pose); /* FUN_00773d80 (func_00773e90.cpp) */

  private:
    float unknownfc;  /* +0xfc: 0.1 from the constructor; not traced */
    Name name100;     /* +0x100: released by the destructor (`mov eax, [rbx+0x100]; shl 5`) */
    float unknown104; /* +0x104: 0.5 from the constructor; not traced */
    float unknown108; /* +0x108: 0.5 from the constructor; not traced */
    int unknown10c;   /* +0x10c: -1 from the constructor; not traced */
    int unknown110;   /* +0x110: -1 from the constructor; not traced */
    int unknown114;   /* +0x114: zero from the constructor; not traced */
    u8 unknown118[0x8];
    Float4A unknown120;  /* +0x120: VECTOR_W from the constructor; not traced */
    int unknown130;      /* +0x130: -1 from the constructor; not traced */
    float unknown134[4]; /* +0x134: (0, 0, FLT_MAX, FLT_MAX) from the constructor; not traced */
    int unknown144;      /* +0x144: zero from the constructor; not traced */
    Name name148;        /* +0x148: released by the destructor (`mov eax, [rbx+0x148]; shl 5`) */
    Name name14c;        /* +0x14c: released by the destructor (`mov eax, [rbx+0x14c]; shl 5`) */
    int unknown150;      /* +0x150: 1 from the constructor; not traced */
    float unknown154
        [4]; /* +0x154: (-FLT_MAX, -FLT_MAX, -FLT_MAX, FLT_MAX) from the constructor; not traced */
    /* +0x164: (0, 0x72000, -1, -1) from the constructor; [1], at +0x168,
     * the bits slot 7 clears from the body's int at +0xb08 */
    int unknown164[4];
    int unknown174; /* +0x174: -1 from the constructor; not traced */
    int unknown178; /* +0x178: 1 from the constructor; not traced */
    u8 unknown17c[0x4];
    /* +0x180: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held180;
    /* +0x188: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held188;
    u8 unknown190[0x10]; /* the rest of the 0x1a0 bytes the creator allocates; not traced */
};

#endif
