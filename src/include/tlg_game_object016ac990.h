/* src/include/tlg_game_object016ac990.h: the class whose vtable is at
 * 0x16ac990 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AC990_H
#define TLG_GAME_OBJECT016AC990_H

#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16ac990
 * (config/vtables.derived.base.txt, stored by FUN_00763020 FUN_007631b0
 * FUN_007633d0), derived from Object00774560. 0x160 bytes (`mov edi,
 * 0x160` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00763020 sets them and its destructor FUN_007631b0
 * tears them down. The destructor is the class's key function
 * (leaf_007631b0.cpp), so that unit emits the vtable and the
 * destructors. */
/* derived names: the object held at +0x120: a rotation at +0xb90 and a
 * point at +0xba0, where the body keeps its own; the rest is not traced */
class Held00764ff0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0xb6c];
    Float4A rotation; /* +0xb90 */
    Float4A position; /* +0xba0 */
};

class Object016ac990 : public Object00774560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0xfc], 0`
     * (the two names), the three references cleared (`vmovdqu [r15+0x110];
     * mov qword [r15+0x120], 0`: a run of zero stores made one memset), 1 at
     * +0x154, then the body's `mov dword [r15+0x7c], 0` (the base's field) */
    Object016ac990(const Name &name) : Object00774560(name), unknown154(1)
    {
        unknown7c = 0.0f;
    }

    virtual ~Object016ac990();
    virtual void slot14(Pose0077bac0 *pose);       /* FUN_00764ff0 */
    virtual void slot17(Context0079c700 *context); /* FUN_00765280 */

  private:
    Name namefc;  /* +0xfc: empty from the constructor, released by the destructor */
    Name name100; /* +0x100: empty from the constructor, released by the destructor */
    /* +0x104: slot 17 hands the two references below to the body when it
     * is 1 (FUN_00765280) */
    int unknown104;
    u8 unknown108[0x8];
    /* +0x110: a counted reference to a node, empty from the constructor,
     * released by the destructor; slot 17 copies it into the body's at
     * +0x62e0 */
    AtomicRef0045c470<Object016b85e0> held110;
    /* +0x118: a counted reference, empty from the constructor, released by
     * the destructor; slot 17 copies it into the body's at +0x62e8 */
    AtomicRef0045c470<Object016b85e0> held118;
    /* +0x120: a counted reference, empty from the constructor, released by
     * the destructor; slot 14 turns and moves the body by it */
    Ref00503fb0<Held00764ff0> held120;
    u8 unknown128[0x8];
    /* +0x130, +0x140: a rotation and an offset slot 14 takes off the held
     * object's (FUN_00764ff0); not traced */
    Float4A unknown130;
    Float4A unknown140;
    u8 unknown150[0x4];
    int unknown154; /* +0x154: 1 from the constructor; not traced */
    u8 unknown158[0x8];
};

#endif
