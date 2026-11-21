/* src/include/tlg_game_object016a9ba8.h: the class whose vtable is at 0x16a9ba8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9BA8_H
#define TLG_GAME_OBJECT016A9BA8_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

struct Owner00c57870; /* derived name: leaf_002c4210.cpp's */
class Object016a9ba8;

/* derived names: the state at +0x28 of the object's controller: slot 11
 * reads +0x30 and +0x40 and sets +0x40 */
struct ControllerState00471a40 {
    u8 unknown0[0x30];
    int unknown30; /* +0x30 */
    u8 unknown34[0xc];
    int active; /* +0x40: 1 once slot 11 starts the controller, else 0 */
};

/* derived names: the object at +0x310: its slots 6 and 9 are given the
 * object (FUN_00471a40), the others are not traced */
class Controller00471a40
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3();                       /* derived name; not traced */
    virtual void slot4();                       /* derived name; not traced */
    virtual void slot5();                       /* derived name; not traced */
    virtual void slot6(Object016a9ba8 *object); /* derived name; not traced */
    virtual void slot7();                       /* derived name; not traced */
    virtual void slot8();                       /* derived name; not traced */
    virtual void slot9(Object016a9ba8 *object); /* derived name; not traced */

    u8 unknown8[0x20];
    ControllerState00471a40 *state; /* +0x28 */
    u8 unknown30[0x3c];
    int unknown6c; /* +0x6c: set to 1 when the state's +0x30 or +0x40 is clear */
};

/* derived names: the class whose vtable is at 0x16a9ba8
 * (config/vtables.derived.base.txt, stored by FUN_00471620 FUN_00471830), 0x530 bytes
 * (`mov edi, 0x530` before operator new in its creator FUN_004714c0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00471620 is not written, and its fields are not traced. */
class Object016a9ba8 : public Object016b9108 /* derived name */
{
  public:
    Object016a9ba8(const Name &name); /* FUN_00471620 */
    virtual ~Object016a9ba8();
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    /* slot 11, FUN_00471a40: the controller started or stopped, then the
     * base class's slot 11 */
    virtual void slot11(); /* derived name */
    virtual void slot12(); /* derived name; not traced */
    /* slot 13, FUN_00471ae0: slot 29, then the script function
     * "Ai2.CallPhysicsBgTick" with the pointer at +0x28, the object and the
     * step */
    virtual void callPhysicsBgTick(float step); /* derived name */
    virtual void slot14();                      /* derived name; not traced */
    virtual void slot15();                      /* derived name; not traced */
    virtual void slot16();                      /* derived name; not traced */
    virtual void slot17();                      /* derived name; not traced */
    virtual void slot18();                      /* derived name; not traced */
    virtual void slot19();                      /* derived name; not traced */
    virtual void slot20();                      /* derived name; not traced */
    virtual void slot21(float step);            /* derived name; not traced */
    virtual void slot22();                      /* derived name; not traced */
    virtual void slot23();                      /* derived name; not traced */
    virtual void slot24();                      /* derived name; not traced */
    virtual void slot25();                      /* derived name; not traced */
    virtual void slot26();                      /* derived name; not traced */
    virtual void slot27();                      /* derived name; not traced */
    virtual void slot28();                      /* derived name; not traced */
    /* slot 29, FUN_00471b70: slot 21 between two calls on the record the
     * owner at +0x28 gives */
    virtual void slot29(float step); /* derived name */

  private:
    u8 unknown24[4];
    /* +0x28: the script call's first argument (type 1), and what slot 29
     * looks a record up in (FUN_00c57870) */
    Owner00c57870 *unknown28;
    int unknown30; /* +0x30: slot 11 starts the controller only when set */
    u8 unknown34[0x5c];
    int unknown90; /* +0x90: slot 11 starts the controller only when clear */
    u8 unknown94[0x274];
    void *unknown308;               /* +0x308: slot 29 hands it to the record's two calls, set */
    Controller00471a40 *controller; /* +0x310 (derived name) */
    u8 unknown318[0x134];
    u8 flags44c; /* +0x44c: slot 11 does nothing while bit 0 is set */
    u8 unknown44d[0xe3];
};

#endif
