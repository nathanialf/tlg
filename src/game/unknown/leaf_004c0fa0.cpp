/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: what the object at 0x16aa3c8's class holds at +0x1a0: a
 * scale at +0x100 (three equal lanes and 1), a flag byte at +0x20 whose bit
 * 0 says the scale changed, and a value read through slot 15 and set through
 * slot 25 */
class Shape004c0fa0 /* derived name */
{
  public:
    virtual void slot0();                  /* derived name; not traced */
    virtual void slot1();                  /* derived name; not traced */
    virtual void slot2();                  /* derived name; not traced */
    virtual void slot3();                  /* derived name; not traced */
    virtual void slot4();                  /* derived name; not traced */
    virtual void slot5();                  /* derived name; not traced */
    virtual void slot6();                  /* derived name; not traced */
    virtual void slot7();                  /* derived name; not traced */
    virtual void slot8();                  /* derived name; not traced */
    virtual void slot9();                  /* derived name; not traced */
    virtual void slot10();                 /* derived name; not traced */
    virtual void slot11();                 /* derived name; not traced */
    virtual void slot12();                 /* derived name; not traced */
    virtual void slot13();                 /* derived name; not traced */
    virtual void slot14();                 /* derived name; not traced */
    virtual int *slot15();                 /* derived name; not traced */
    virtual void slot16();                 /* derived name; not traced */
    virtual void slot17();                 /* derived name; not traced */
    virtual void slot18();                 /* derived name; not traced */
    virtual void slot19();                 /* derived name; not traced */
    virtual void slot20();                 /* derived name; not traced */
    virtual void slot21();                 /* derived name; not traced */
    virtual void slot22();                 /* derived name; not traced */
    virtual void slot23();                 /* derived name; not traced */
    virtual void slot24();                 /* derived name; not traced */
    virtual void slot25(const int *value); /* derived name; not traced */

    /* the scale's three lanes and 1, the change flagged */
    void setScale(float value) /* derived name */
    {
        scale[0] = value;
        scale[1] = value;
        scale[2] = value;
        scale[3] = 1.0f;
        flags |= 1;
    }

    u8 unknown8[0x18];
    u8 flags; /* +0x20 */
    u8 unknown21[0xdf];
    float scale[4]; /* +0x100 */
};

/* derived names: the class whose vtable is at 0x16aa3c8 (stored by
 * FUN_004bf730 FUN_004bfb50) as slot 26 sees it: its slots 29 and 30 take
 * the step */
class Object004c0fa0 /* derived name */
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
    virtual void slot26(float step); /* derived name: FUN_004c0fa0 */
    virtual void slot27();           /* derived name; not traced */
    virtual void slot28();           /* derived name; not traced */
    virtual void slot29(float step); /* derived name; not traced */
    virtual void slot30(float step); /* derived name; not traced */

    u8 unknown8[0x17c];
    int unknown184;   /* +0x184: the value the shape is given through its slot 25 */
    float unknown188; /* +0x188: the shape's scale */
    u8 unknown18c[0x14];
    Shape004c0fa0 *shape; /* +0x1a0 */
};

/* derived names: slot 26 of the vtable at 0x16aa3c8: with a shape, its scale
 * set from +0x188 (and flag 1 raised) when its first lane differs, and its
 * value set from +0x184 when it differs; then slots 29 and 30 with the
 * step. */
void Object004c0fa0::slot26(float step)
{
    if (shape) {
        const float scale = unknown188;
        if (shape->scale[0] != scale)
            shape->setScale(scale);
        if (*shape->slot15() != unknown184)
            shape->slot25(&unknown184);
    }
    slot29(step);
    slot30(step);
}
