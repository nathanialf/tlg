/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_math.h"

/* derived names: two names of the class's states (no file defines them
 * yet): in the first, the state machine at +0xd8 is moved to the second */
extern Name D_57d9b44;
extern Name D_57d9b48;

/* derived name: a rotation the class keeps twice (no file defines it yet) */
extern Float4A D_57d9ae0;

/* the state machine at +0xd8 set to a state (leaf_00ad1c10.cpp's) */
void FUN_01344a20(void *member, void *value); /* derived name */

/* derived names: the class whose vtable is at 0x16aa8e0 (stored by
 * FUN_004f3ad0 FUN_004f3df0) as slot 26 sees it: its state machine at
 * +0xd8, its state's name at +0x118 and three vectors from +0x280 */
class Object004f4cf0 /* derived name */
{
  public:
    virtual void slot0();            /* derived name; not traced */
    virtual void slot1();            /* derived name; not traced */
    virtual void slot2();            /* derived name; not traced */
    virtual void slot3();            /* derived name; not traced */
    virtual void slot4();            /* derived name; not traced */
    virtual void slot5();            /* derived name; not traced */
    virtual void slot6();            /* derived name; not traced */
    virtual void slot7();            /* derived name; not traced */
    virtual void slot8();            /* derived name; not traced */
    virtual void slot9();            /* derived name; not traced */
    virtual void slot10();           /* derived name; not traced */
    virtual void slot11();           /* derived name; not traced */
    virtual void slot12();           /* derived name; not traced */
    virtual void slot13();           /* derived name; not traced */
    virtual void slot14();           /* derived name; not traced */
    virtual void slot15();           /* derived name; not traced */
    virtual void slot16();           /* derived name; not traced */
    virtual void slot17();           /* derived name; not traced */
    virtual void slot18();           /* derived name; not traced */
    virtual void slot19();           /* derived name; not traced */
    virtual void slot20();           /* derived name; not traced */
    virtual void slot21();           /* derived name; not traced */
    virtual void slot22();           /* derived name; not traced */
    virtual void slot23();           /* derived name; not traced */
    virtual void slot24();           /* derived name; not traced */
    virtual void slot25();           /* derived name; not traced */
    virtual void slot26(float step); /* derived name: FUN_004f4cf0 */
    virtual void slot27();           /* derived name; not traced */
    virtual void slot28();           /* derived name; not traced */
    virtual void slot29();           /* derived name; not traced */
    virtual void slot30();           /* derived name; not traced */
    virtual void slot31(float step); /* derived name; not traced */
    virtual void slot32(float step); /* derived name; not traced */

    u8 unknown8[0xd0];
    u8 machine[0x40]; /* +0xd8 (derived name) */
    Name state;       /* +0x118 (derived name) */
    u8 unknown11c[0x164];
    Float4A unknown280; /* +0x280: cleared by slot 26 */
    Float4A unknown290; /* +0x290: set to 0x57d9ae0 by slot 26 */
    Float4A unknown2a0; /* +0x2a0: the same */
};

/* derived names: slot 26 of the vtable at 0x16aa8e0: out of the state
 * 0x57d9b44 into 0x57d9b48 when in it, the vectors at +0x280 cleared and
 * at +0x290 and +0x2a0 reset, then slot 30 and slots 31 and 32 with the
 * step. */
void Object004f4cf0::slot26(float step)
{
    if (state == D_57d9b44)
        FUN_01344a20(machine, &D_57d9b48);
    unknown280 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
    unknown290 = D_57d9ae0;
    unknown2a0 = D_57d9ae0;
    slot30();
    slot31(step);
    slot32(step);
}
