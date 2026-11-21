/* src/include/tlg_game_object016a96d0.h: the class whose vtable is at 0x16a96d0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A96D0_H
#define TLG_GAME_OBJECT016A96D0_H

#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_name.h"

/* derived names: an item of FUN_00402f30's list, its kind at +0x28 */
struct Item00402f30 {
    u8 unknown0[0x28];
    int kind; /* +0x28 */
};

/* derived names: what FUN_00402f30's argument holds at +0x10: a list of
 * items, the first one read (none when the count is zero) */
struct List00402f30 {
    Item00402f30 *first() const
    {
        return count ? items[0] : 0;
    }

    u8 unknown0[0xa8];
    Item00402f30 **items; /* +0xa8 */
    int count;            /* +0xb0 */
};

/* derived names: the argument of slot 24 of 0x16a96d0, its list at +0x10 */
struct Source00402f30 {
    u8 unknown0[0x10];
    List00402f30 *list; /* +0x10 */
};

/* derived names: the class whose vtable is at 0x16a96d0
 * (config/vtables.derived.base.txt, stored by FUN_003fbc60 and
 * FUN_003fc620), derived from Object016b9108; slot 19 (FUN_003fcfb0) is FUN_00301db0 of the class at 0x16a8430, byte for byte.
 * Slots 5 to 18 are not traced.
 * The creator FUN_003f70d0 allocates 0x650 bytes (`mov edi, 0x650` before operator new). */
class Object016a96d0 : public Object016b9108 /* derived name */
{
  public:
    Object016a96d0(const Name &name); /* FUN_003fbc60, its row named after it (D15) */
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12();            /* derived name; not traced */
    /* slot 13, FUN_00403530: the script function "Ai2.CallPhysicsBgTick"
     * with the pointer at +0x28, the object and the step */
    virtual void callPhysicsBgTick(float step); /* derived name */
    virtual void slot14();                      /* derived name; not traced */
    virtual void slot15();                      /* derived name; not traced */
    virtual void slot16();                      /* derived name; not traced */
    virtual void slot17();                      /* derived name; not traced */
    virtual void slot18();                      /* derived name; not traced */
    virtual void beforeInterestTick();          /* derived name: slot 19 */
    /* slot 20, FUN_00402080: the base class's slot 20 (FUN_00a8e280) run
     * with the object's heap as the thread's */
    virtual void slot20(float step);  /* derived name */
    virtual void slot21(float value); /* derived name: FUN_00402f20 */
    virtual void slot22();            /* derived name; not traced */
    virtual void slot23();            /* derived name; not traced */
    /* slot 24, FUN_00402f30: the three flags at +0x1b0 to +0x1b8 set from
     * the first item of what the argument holds, then slot 28 */
    virtual void slot24(Source00402f30 *source); /* derived name */
    virtual void slot25();                       /* derived name; not traced */
    virtual void slot26();                       /* derived name; not traced */
    virtual void slot27();                       /* derived name; not traced */
    virtual void slot28();                       /* derived name; an empty body (0x1af750) here */

  private:
    u8 unknown24[4];
    void *unknown28; /* +0x28: the script call's first argument (type 1) */
    u8 unknown30[0x60];
    int state; /* +0x90: 1 skips the script call (derived name) */
    u8 unknown94[0x7c];
    Owner05943280 *heap; /* +0x110: the thread's heap while the slot runs (derived name) */
    u8 unknown118[0x98];
    int unknown1b0; /* +0x1b0: the first item's kind is 0x24 to 0x26 (FUN_00402f30) */
    int unknown1b4; /* +0x1b4: +0x1b0 was set and no longer is */
    int unknown1b8; /* +0x1b8: the first item's kind is 1 */
    u8 unknown1bc[0x494];
};

#endif
