/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: with a nonzero first value, returns 1 at once; else by kind
 * (0 to 3, the jump table 0x1559c68): kinds 0 to 2 pass the class the pointer
 * at 0x5939080, 0x5946600 or 0x5948b00 holds (0x5948b00 is a class
 * isKindOf takes, FUN_001bbc00) with the callback FUN_00d8ff10, FUN_00d8ff30
 * or FUN_00d8ff50 and 0 to FUN_00cb8490 and return 0; kind 3 passes the object
 * to FUN_00d8d490, the member at +0xb0 of the object the pointer at 0x5938c40
 * holds to FUN_00ce1fd0, then calls slot 9 of each object of that member's
 * array (pointers at +0x3c8, count at +0x3d0) and returns 1; any other kind
 * returns 0. FUN_00cb8490 is taken to visit each object of the class with the
 * callback; its third parameter and the slot's return type are not traced. */
class Object00d8f280;    /* derived name */
struct Class00cb8490;    /* derived name */
struct Object00d8ff10;   /* derived name */
class Object00d8ff30;    /* derived name */
struct Object00d8ff50;   /* derived name */
struct Instance00cb8490; /* derived name */

typedef int (*Visitor00cb8490)(Instance00cb8490 *object); /* derived name */

class Item00d8f280 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
};

struct Member05938c40_b0 { /* derived name */
    u8 unknown0[0x3c8];
    Item00d8f280 **unknown3c8;
    u32 unknown3d0;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    Member05938c40_b0 *unknownb0;
};

extern Object05938c40 *D_5938c40;
extern Class00cb8490 *D_5939080;
extern Class00cb8490 *D_5946600;
extern Class00cb8490 *D_5948b00;

void FUN_00cb8490(Class00cb8490 *type, Visitor00cb8490 visit, int flags); /* derived name */
void FUN_00d8d490(Object00d8f280 *self);                                  /* derived name */
void FUN_00ce1fd0(Member05938c40_b0 *member);                             /* derived name */
int FUN_00d8ff10(Object00d8ff10 *self);                                   /* derived name */
int FUN_00d8ff30(Object00d8ff30 *self);                                   /* derived name */
int FUN_00d8ff50(Object00d8ff50 *self);                                   /* derived name */

int FUN_00d8f280(Object00d8f280 *self, int busy, int kind) /* derived name */
{
    if (busy != 0)
        return 1;
    switch (kind) {
    case 0:
        FUN_00cb8490(D_5939080, reinterpret_cast<Visitor00cb8490>(FUN_00d8ff10), 0);
        return 0;
    case 1:
        FUN_00cb8490(D_5946600, reinterpret_cast<Visitor00cb8490>(FUN_00d8ff30), 0);
        return 0;
    case 2:
        FUN_00cb8490(D_5948b00, reinterpret_cast<Visitor00cb8490>(FUN_00d8ff50), 0);
        return 0;
    case 3: {
        FUN_00d8d490(self);
        FUN_00ce1fd0(D_5938c40->unknownb0);
        Member05938c40_b0 *member = D_5938c40->unknownb0;
        Item00d8f280 **end = member->unknown3c8 + member->unknown3d0;
        for (Item00d8f280 **item = member->unknown3c8; item != end; ++item)
            (*item)->slot9();
        return 1;
    }
    default:
        return 0;
    }
}
