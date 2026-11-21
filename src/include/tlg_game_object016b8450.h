/* src/include/tlg_game_object016b8450.h: the class whose destructor is
 * 0xc298a0, a base of other game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8450_H
#define TLG_GAME_OBJECT016B8450_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b8450
 * (config/vtables.derived.base.txt; stored by FUN_00c296e0), whose complete
 * destructor is 0xc298a0 (its row named for it, D15), derived from
 * Object016b9108 (the derived classes' vtables hold its slots 2 to 4 and no
 * others). The classes derived from it tail-call that destructor from their
 * own (the files that include this header). The destructor
 * (leaf_00c298a0.cpp, the key function) empties the counted reference at
 * +0x28 by compare-and-swap before the members' and the base's destructors
 * run. Its constructor, inlined in the creator of a derived class
 * (FUN_00b0c790), sets its fields BEFORE the derived class's vptr store
 * (0xb0c8a9 to 0xb0c8fc); the fields are not traced further. */
class Object016b8450 : public Object016b9108 /* derived name */
{
  public:
    /* the reference empty, 31 at +0x30, the 24 bytes from +0x34 cleared
     * (`vmovdqu [rbx+0x34], xmm0; mov qword [rbx+0x44], 0`: six ints, a run of
     * zero stores made one memset), the four floats at +0x4c, +0x60 and +0x80
     * from the constants at 0x15405c0, 0x15405d0 and 0x15405e0 in one store
     * each, 0.5 at +0x70, 1 at +0x90 */
    Object016b8450(const Name &name)
        : Object016b9108(name), unknown30(0x1f), unknown34(0), unknown38(0), unknown3c(0),
          unknown40(0), unknown44(0), unknown48(0), unknown4c(1.0f), unknown50(0.125f),
          unknown54(1.0f), unknown58(60.0f), unknown60(0.4f), unknown64(1.0f), unknown68(1.0f),
          unknown6c(1.0f), unknown70(0.5f), unknown80(1.0f), unknown84(1.0f), unknown88(1.0f),
          unknown8c(1.0f), unknown90(1)
    {
    }

    virtual ~Object016b8450();

  private:
    AtomicRef0045c470<Object016b9108> held28; /* +0x28: empty from the constructor */
    int unknown30;                            /* +0x30: 31 from the constructor; not traced */
    int unknown34;                            /* +0x34: zero from the constructor; not traced */
    int unknown38;                            /* +0x38: zero from the constructor; not traced */
    int unknown3c;                            /* +0x3c: zero from the constructor; not traced */
    int unknown40;                            /* +0x40: zero from the constructor; not traced */
    int unknown44;                            /* +0x44: zero from the constructor; not traced */
    int unknown48;                            /* +0x48: zero from the constructor; not traced */
    float unknown4c;                          /* +0x4c: 1.0 from the constructor; not traced */
    float unknown50;                          /* +0x50: 0.125 from the constructor; not traced */
    float unknown54;                          /* +0x54: 1.0 from the constructor; not traced */
    float unknown58;                          /* +0x58: 60.0 from the constructor; not traced */
    u8 unknown5c[0x4];
    float unknown60; /* +0x60: 0.4 from the constructor; not traced */
    float unknown64; /* +0x64: 1.0 from the constructor; not traced */
    float unknown68; /* +0x68: 1.0 from the constructor; not traced */
    float unknown6c; /* +0x6c: 1.0 from the constructor; not traced */
    float unknown70; /* +0x70: 0.5 from the constructor; not traced */
    u8 unknown74[0xc];
    float unknown80; /* +0x80: 1.0 from the constructor; not traced */
    float unknown84; /* +0x84: 1.0 from the constructor; not traced */
    float unknown88; /* +0x88: 1.0 from the constructor; not traced */
    float unknown8c; /* +0x8c: 1.0 from the constructor; not traced */
    int unknown90;   /* +0x90: 1 from the constructor; not traced */
};

#endif
