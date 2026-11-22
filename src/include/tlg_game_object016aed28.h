/* src/include/tlg_game_object016aed28.h: the class whose vtable is at
 * 0x16aed28, the base of seventeen game classes (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AED28_H
#define TLG_GAME_OBJECT016AED28_H

#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b85e0.h"

/* derived names: an entry of the table at +0x2d0, 0x18 bytes: a hash, a
 * name (released when the entry is put back), a float that slots 13 and 47
 * test against zero (`vucomiss xmm0, [r15+8]` at 0x83ebf6) and the next
 * entry */
struct Entry016aed28 { /* derived name */
    u32 hash;          /* +0x0 */
    Name name;         /* +0x4 */
    float value;       /* +0x8 */
    u8 unknownC[0x4];
    Entry016aed28 *next; /* +0x10 */
};

/* derived names: 8 bytes copied as one, alignment 4 (FUN_0134a530: `mov
 * rax, [rsi]`); type not traced */
struct Value0134a530 { /* derived name */
    u8 unknown0[8];
};

/* derived names: the class whose vtable is at 0x16aed28
 * (config/vtables.derived.base.txt, stored by its constructor FUN_0083dcb0,
 * which its factory FUN_0083da00 calls on 0x580 bytes, and by its complete
 * destructor FUN_0083df00), over the scene node Object016b85e0: its own
 * fields start at +0x238. Slots 3 to 9 but 8 and 9 are the node's; slots 15
 * to 42 are accessors the link placed with the inline functions at
 * 0x134a3b0 to 0x134a6e0, each slot of the sixteen classes derived from it
 * (0x16a7a50, 0x16a8260, 0x16ac218, 0x16ac3a8 and others). The destructor is
 * the key function: leaf_0083df00.cpp emits the vtable. */
class Object016aed28 : public Object016b85e0 /* derived name */
{
  public:
    Object016aed28(const Name &name); /* FUN_0083dcb0 */
    virtual ~Object016aed28();
    /* slot 8, FUN_0083de30: the contacts cleared, the name at +0x540 and
     * the int at +0x554 taken as current, then, with neither end set, the
     * object handed to the world's list (FUN_00845600) */
    virtual void slot8(); /* derived name */
    /* slot 9, FUN_0083def0: slot 47 with 0 */
    virtual void slot9();  /* derived name */
    virtual void slot10(); /* derived name; FUN_0083ede0, not traced */
    virtual void slot11(); /* derived name; the empty body 0x1af750 */
    /* slot 12, FUN_0083fef0: slot 47 with 0, then the int at +0x2c0 copied
     * to +0x554 and, when it is positive, bit 0 of +0x4f8 cleared */
    virtual void slot12(); /* derived name */
    virtual void slot13(); /* derived name; FUN_00840710, not traced */
    virtual void slot14(); /* derived name; FUN_00840aa0, not traced */
    /* slots 15 to 24: the addresses of fields */
    virtual Name *slot15();          /* derived name; FUN_0134a3b0 */
    virtual Name *slot16();          /* derived name; FUN_0134a3c0 */
    virtual Value0134a530 *slot17(); /* derived name; FUN_0134a3d0 */
    virtual u32 *slot18();           /* derived name; FUN_0134a3e0 */
    virtual float *slot19();         /* derived name; FUN_0134a3f0 */
    virtual float *slot20();         /* derived name; FUN_0134a400 */
    virtual float *slot21();         /* derived name; FUN_0134a410 */
    virtual int *slot22();           /* derived name; FUN_0134a420 */
    virtual Float4A *slot23();       /* derived name; FUN_0134a430 */
    virtual Float4A *slot24();       /* derived name; FUN_0134a440 */
    /* slots 25 to 33: fields set; those that change the shape mark it in
     * bit 4 of the root's flags (`or byte [rdi+0x20], 0x10`) */
    virtual void slot25(const Name &name);           /* derived name; FUN_0134a450 */
    virtual void slot26(const Name &name);           /* derived name; FUN_0134a4c0 */
    virtual void slot27(const Value0134a530 *value); /* derived name; FUN_0134a530 */
    virtual void slot28(const u32 *value);           /* derived name; FUN_0134a540 */
    virtual void slot29(const float *value);         /* derived name; FUN_0134a550 */
    virtual void slot30(const float *value);         /* derived name; FUN_0134a560 */
    virtual void slot31(const float *value);         /* derived name; FUN_0134a570 */
    virtual void slot32(const Name &name);           /* derived name; FUN_0134a580 */
    virtual void slot33(const Name &name);           /* derived name; FUN_0134a5f0 */
    /* slots 34 to 41: the bits at +0x4f8 (marked as above) and at +0x550
     * read, stored, set and cleared */
    virtual u32 slot34() const;                           /* derived name; FUN_0134a660 */
    virtual void slot35(u32 bits);                        /* derived name; FUN_0134a670 */
    virtual void slot36(u32 bits);                        /* derived name; FUN_0134a680 */
    virtual void slot37(u32 bits);                        /* derived name; FUN_0134a690 */
    virtual u32 slot38() const;                           /* derived name; FUN_0134a6a0 */
    virtual void slot39(u32 bits);                        /* derived name; FUN_0134a6b0 */
    virtual void slot40(u32 bits);                        /* derived name; FUN_0134a6c0 */
    virtual void slot41(u32 bits);                        /* derived name; FUN_0134a6d0 */
    virtual float slot42() const;                         /* derived name; FUN_0134a6e0 */
    virtual float slot43(const Float4A &point);           /* derived name; FUN_008400b0 */
    virtual int slot44(const Float4A &point, int radius); /* derived name; FUN_00840460 */
    virtual float slot45(const Float4A &point);           /* derived name; FUN_0083ff30 */
    virtual void slot46(); /* derived name; FUN_0083e370, not traced */
    /* slot 47, FUN_0083ea20: with 0 and entries in the table, each entry
     * handled under the lock at +0x4f0 and the table emptied; then the
     * contacts cleared */
    virtual void slot47(int keep); /* derived name */

    /* the contacts zeroed: 64 bytes at +0x250 (two 32-byte stores, the
     * upper first, 0x83de3d) */
    void clearContacts() /* derived name */
    {
        for (int i = 0; i < 16; ++i)
            contacts[i] = 0;
    }

    void *end238; /* +0x238: one end of the link (FUN_00823d60) */
    void *end240; /* +0x240: the other end */
    u8 unknown248[0x8];
    float contacts[16];                 /* +0x250 */
    Ref00503fb0<Object016b9108> ref290; /* +0x290 */
    Ref00503fb0<Object016b9108> ref298; /* +0x298 */
    Ref00503fb0<Object016b9108> ref2a0; /* +0x2a0 */
    Ref00503fb0<Object016b9108> ref2a8; /* +0x2a8 */
    u8 unknown2b0[0x8];
    int unknown2b8;   /* +0x2b8: zero from the constructor */
    int unknown2bc;   /* +0x2bc: zero from the constructor */
    int unknown2c0;   /* +0x2c0: -1 from the constructor, the value of +0x554 taken by slot 8 */
    float unknown2c4; /* +0x2c4: the distance slot 44 compares with */
    u8 unknown2c8[0x4];
    Name name2cc;                       /* +0x2cc: the name of +0x540 taken by slot 8 */
    NameTable<Entry016aed28, 64> table; /* +0x2d0 */
    int lock;                           /* +0x4f0: 1 while held (slots 13, 14 and 47) */
    u32 unknown4f4;                     /* +0x4f4: the shape, 0 and 3 boxes (slot 43) */
    u32 unknown4f8;                     /* +0x4f8: bits, bit 0 skips slot 45, bit 3 picks slot 43 */
    Value0134a530 unknown4fc;           /* +0x4fc */
    float unknown504;                   /* +0x504 */
    float unknown508;                   /* +0x508: the radius slot 44 tests with */
    float unknown50c;                   /* +0x50c: the scale of slot 45's value */
    float unknown510;                   /* +0x510: 360 from the constructor */
    u8 unknown514[0xc];
    Float4A unknown520; /* +0x520: the half extents (slot 43) */
    Float4A unknown530; /* +0x530: the offset (slot 43) */
    Name name540;       /* +0x540 */
    Name name544;       /* +0x544 */
    Name name548;       /* +0x548 */
    Name name54c;       /* +0x54c */
    u32 unknown550;     /* +0x550: bits */
    int unknown554;     /* +0x554: -1 from the constructor */
    int unknown558;     /* +0x558: zero from the constructor; slot 13 needs it set */
    u8 unknown55c[0x4];
    Object0134f620 refs560; /* +0x560 */
    float unknown578;       /* +0x578: 1 from the constructor */
    int unknown57c;         /* +0x57c: zero from the constructor */
};

/* the world whose list at +0x60 slot 8 hands the object to */
struct World057c9390 { /* derived name */
    u8 unknown0[0x60];
    void *list60; /* +0x60 */
};

extern World057c9390 *D_57c9390;                       /* derived name */
void FUN_00845600(void *list, Object016aed28 *object); /* derived name */

#endif
