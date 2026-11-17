/* src/include/tlg_game_object016b9108_inline.h: the classes derived from
 * Object016b9108 whose vtables share slots 0 and 1, the destructor pair
 * 0x1386090/0x1386110 (game region; docs/TARGETS.md). Every name here is
 * derived. The pair is byte for byte Object016b9108's own pair modulo
 * addresses: an empty destructor that inlines the base's. Read as the
 * inline destructor of each class, the copies folded by the linker into one
 * body (docs/DECISIONS.md D15: one name per address), the pair is claimed
 * once, from the class whose storer has the lowest address,
 * Object016c7700 (leaf_01386090.cpp, where its destructor is defined out
 * of line); the others' destructors are inline, so no unit of the tree
 * emits them until their constructors are written. */
#ifndef TLG_GAME_OBJECT016B9108_INLINE_H
#define TLG_GAME_OBJECT016B9108_INLINE_H

#include "tlg_game_base016cbbf8.h"
#include "tlg_game_object01343880.h"
#include "tlg_math.h"
#include "tlg_game_value004af700.h"

/* derived name: the value every Object016c7738 starts with, four ints its
 * creator FUN_00371bc0 copies member by member (`mov dword; shr rax, 0x20;
 * mov dword` from 0x57d0000) */
extern Value004af700 D_57d0000;

/* derived name: the value Object016cd4d8, Object016cd510 and Object016cdd18
 * start with, copied member by member by their creators FUN_009957e0,
 * FUN_009959a0 and FUN_009b62f0 (from 0x5822b10) */
extern Value004af700 D_5822b10;

/* derived name: the value Object016cd3f8 starts with, copied member by
 * member by its creator FUN_00991bf0 (from 0x58224c0) */
extern Value004af700 D_58224c0;

/* derived names: the class whose vtable is at 0x16c7700
 * (config/vtables.derived.base.txt, stored by FUN_0036ac20): its slots 2 to
 * 4 are the base's. 0x40 bytes (`mov edi, 0x40` before operator new in its
 * creator). Its fields are traced only where the creator sets them. */
class Object016c7700 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_0036ac20: the base built from the name, then
     * zero at +0x24, then six floats (one 16-byte constant and one eight-byte immediate) */
    Object016c7700(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0.0f), unknown2c(1.0f), unknown30(0.1f),
          unknown34(0.1f), unknown38(0.1f), unknown3c(0.1f)
    {
    }

    virtual ~Object016c7700(); /* FUN_01386090; leaf_01386090.cpp */

  private:
    int unknown24;   /* +0x24: 0 from the constructor */
    float unknown28; /* +0x28: 0.0 from the constructor */
    float unknown2c; /* +0x2c: 1.0 from the constructor */
    float unknown30; /* +0x30: 0.1 from the constructor */
    float unknown34; /* +0x34: 0.1 from the constructor */
    float unknown38; /* +0x38: 0.1 from the constructor */
    float unknown3c; /* +0x3c: 0.1 from the constructor */
};

/* derived names: the class whose vtable is at 0x16c7738
 * (config/vtables.derived.base.txt, stored by FUN_00371bc0): its slots 2 to
 * 4 are the base's. 0xa0 bytes (`mov edi, 0xa0` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016c7738 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_00371bc0: the base built from the name, then
     * the body: the fields in their order, the value at +0x40 copied member by member from D_57d0000 (`mov dword; shr rax, 0x20; mov dword`) */
    Object016c7738(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0;
        unknown30 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        unknown40.set(D_57d0000);
        unknown50 = 0;
        unknown54 = 0;
        unknown58 = 0;
        unknown60 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        unknown70 = 0;
        unknown80 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
        unknown90 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
    }

    virtual ~Object016c7738() {}

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    u8 unknown28[0x8];
    Float4A unknown30;       /* +0x30: zero from the constructor; not traced */
    Value004af700 unknown40; /* +0x40: D_57d0000 from the constructor */
    int unknown50;           /* +0x50: 0 from the constructor */
    int unknown54;           /* +0x54: 0 from the constructor */
    int unknown58;           /* +0x58: 0 from the constructor */
    u8 unknown5c[0x4];
    Float4A unknown60; /* +0x60: zero from the constructor; not traced */
    int unknown70;     /* +0x70: 0 from the constructor */
    u8 unknown74[0xc];
    Float4A unknown80; /* +0x80: zero from the constructor; not traced */
    Float4A unknown90; /* +0x90: zero from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16cada8
 * (config/vtables.derived.base.txt, stored by FUN_00474ae0): its slots 2 to
 * 4 are the base's. 0x60 bytes (`mov edi, 0x60` before operator new in its
 * creator). Its fields are traced only where the creator sets them. */
class Object016cada8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_00474ae0: the base built from the name, then
     * (0, 0, 0, 1) at +0x30 and +0x40 (one 32-byte constant), zero at +0x50 */
    Object016cada8(const Name &name)
        : Object016b9108(name), unknown30(0.0f, 0.0f, 0.0f, 1.0f),
          unknown40(0.0f, 0.0f, 0.0f, 1.0f), unknown50(0.0f, 0.0f, 0.0f, 0.0f)
    {
    }

    virtual ~Object016cada8() {}

  private:
    u8 unknown24[0xc];
    Float4A unknown30; /* +0x30: (0, 0, 0, 1) from the constructor; not traced */
    Float4A unknown40; /* +0x40: (0, 0, 0, 1) from the constructor; not traced */
    Float4 unknown50;  /* +0x50: zero from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16cb5b8
 * (config/vtables.derived.base.txt, stored by FUN_00690560): its slots 2 to
 * 4 are the base's. 0x2e0 bytes (`mov edi, 0x2e0` before operator new in its
 * creator FUN_00685d90). Its own fields are not traced. */
class Object016cb5b8 : public Object016b9108 /* derived name */
{
  public:
    Object016cb5b8(const Name &name); /* 0x690560, its row named after it (D15) */

    virtual ~Object016cb5b8() {}

  private:
    u8 unknown24[0x2bc];
};

/* derived names: the class whose vtable is at 0x16cb920
 * (config/vtables.derived.base.txt, stored by FUN_007a1fb0): its slots 2 to
 * 4 are the base's. 0x80 bytes (`mov edi, 0x80` before operator new in its
 * creator): the fields of Base016cb958 (tlg_game_base016cbbf8.h) as a member
 * at +0x24, stored after the vptr. */
class Object016cb920 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_007a1fb0: the base built from the name, the
     * vptr, then the member's fields */
    Object016cb920(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cb920() {}

  private:
    Base016cb958 unknown24; /* +0x24: not traced */
    u8 unknown74[0xc];
};

/* derived names: the class whose vtable is at 0x16cba38
 * (config/vtables.derived.base.txt, stored by FUN_007a28d0): its slots 2 to
 * 4 are the base's. 0xa0 bytes (`mov edi, 0xa0` before operator new in its
 * creator): the fields of Base016cba70 (tlg_game_base016cbbf8.h) as a member
 * at +0x24, stored after the vptr. */
class Object016cba38 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_007a28d0: the base built from the name, the
     * vptr, then the member's fields */
    Object016cba38(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cba38() {}

  private:
    Base016cba70 unknown24; /* +0x24: not traced */
};

/* derived names: the class whose vtable is at 0x16cbbc0
 * (config/vtables.derived.base.txt, stored by FUN_007ad930): its slots 2 to
 * 4 are the base's. 0x40 bytes (`mov edi, 0x40` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cbbc0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_007ad930: the base built from the name, then
     * zero at +0x24 and +0x28, then 1.0 four times from +0x30 (one 16-byte constant) */
    Object016cbbc0(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown30(1.0f, 1.0f, 1.0f, 1.0f)
    {
    }

    virtual ~Object016cbbc0() {}

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    int unknown28; /* +0x28: 0 from the constructor */
    u8 unknown2c[0x4];
    Float4 unknown30; /* +0x30: 1.0 in every lane from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16cbfe8
 * (config/vtables.derived.base.txt, stored by FUN_0082fc00), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). 0x38 bytes (`mov edi, 0x38`
 * before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cbfe8 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator FUN_0082fc00: the base built from the name, then
     * zero at +0x34 */
    Object016cbfe8(const Name &name) : Object01343880(name), unknown34(0) {}

    virtual ~Object016cbfe8() {}

  private:
    int unknown34; /* +0x34: 0 from the constructor */
};

/* derived names: the class whose vtable is at 0x16cc1f0
 * (config/vtables.derived.base.txt, stored by FUN_00872910): its slots 2 to
 * 4 are the base's. 0x68 bytes (`mov edi, 0x68` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cc1f0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_00872910: the base built from the name, then
     * zero from +0x24 to the end (two 32-byte stores and one four-byte store) */
    Object016cc1f0(const Name &name) : Object016b9108(name), unknown24() {}

    virtual ~Object016cc1f0() {}

  private:
    int unknown24[0x11]; /* +0x24: zero from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16cd3f8
 * (config/vtables.derived.base.txt, stored by FUN_00991bf0): its slots 2 to
 * 4 are the base's. 0xb0 bytes (`mov edi, 0xb0` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cd3f8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_00991bf0: the base built from the name, then
     * the body: the fields in their order, the value at +0x60 copied member by member from D_58224c0, then bit 0 of the flags at +0x16 set */
    Object016cd3f8(const Name &name) : Object016b9108(name)
    {
        unknown24 = 1;
        unknown28 = 0;
        unknown2c = 1;
        unknown30 = 0;
        unknown34 = 0;
        unknown38 = 0;
        unknown3c = 1.0f;
        unknown40 = 0;
        unknown44 = 2;
        unknown48 = 1.0f;
        unknown4c = 2.0f;
        unknown50 = Float4(0.0f, 0.0f, 0.0f, 0.0f);
        unknown60.set(D_58224c0);
        unknown70 = 1.0f;
        unknown74 = 0;
        unknowna0 = 0;
        flags16 |= 1;
    }

    virtual ~Object016cd3f8() {}

  private:
    int unknown24;           /* +0x24: 1 from the constructor */
    int unknown28;           /* +0x28: 0 from the constructor */
    int unknown2c;           /* +0x2c: 1 from the constructor */
    int unknown30;           /* +0x30: 0 from the constructor */
    int unknown34;           /* +0x34: 0 from the constructor */
    int unknown38;           /* +0x38: 0 from the constructor */
    float unknown3c;         /* +0x3c: 1.0 from the constructor */
    int unknown40;           /* +0x40: 0 from the constructor */
    int unknown44;           /* +0x44: 2 from the constructor */
    float unknown48;         /* +0x48: 1.0 from the constructor */
    float unknown4c;         /* +0x4c: 2.0 from the constructor */
    Float4 unknown50;        /* +0x50: zero from the constructor; not traced */
    Value004af700 unknown60; /* +0x60: D_58224c0 from the constructor */
    float unknown70;         /* +0x70: 1.0 from the constructor */
    int unknown74;           /* +0x74: 0 from the constructor */
    u8 unknown78[0x28];
    void *unknowna0; /* +0xa0: null from the constructor */
    u8 unknowna8[0x8];
};

/* derived names: the class whose vtable is at 0x16cd4d8
 * (config/vtables.derived.base.txt, stored by FUN_009957e0): its slots 2 to
 * 4 are the base's. 0x90 bytes (`mov edi, 0x90` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cd4d8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009957e0: the base built from the name, then
     * the body: the fields in their order, the value at +0x30 copied member by member from D_5822b10 */
    Object016cd4d8(const Name &name) : Object016b9108(name)
    {
        unknown30.set(D_5822b10);
        unknown40 = 0;
        unknown50 = Float4(-45.0f, 45.0f, 0.0f, 1.0f);
        unknown60 = 0;
        unknown70 = Float4(-45.0f, 45.0f, 0.0f, 1.0f);
        unknown80 = 0.0f;
        unknown84 = 45.0f;
        unknown88 = 0;
    }

    virtual ~Object016cd4d8() {}

  private:
    u8 unknown24[0xc];
    Value004af700 unknown30; /* +0x30: D_5822b10 from the constructor */
    int unknown40;           /* +0x40: 0 from the constructor */
    u8 unknown44[0xc];
    Float4 unknown50; /* +0x50: (-45, 45, 0, 1) from the constructor; not traced */
    int unknown60;    /* +0x60: 0 from the constructor */
    u8 unknown64[0xc];
    Float4 unknown70; /* +0x70: (-45, 45, 0, 1) from the constructor; not traced */
    float unknown80;  /* +0x80: 0.0 from the constructor */
    float unknown84;  /* +0x84: 45.0 from the constructor */
    int unknown88;    /* +0x88: 0 from the constructor */
    u8 unknown8c[0x4];
};

/* derived names: the class whose vtable is at 0x16cd510
 * (config/vtables.derived.base.txt, stored by FUN_009959a0): its slots 2 to
 * 4 are the base's. 0x70 bytes (`mov edi, 0x70` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cd510 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009959a0: the base built from the name, then
     * the body: the fields in their order, the value at +0x30 copied member by member from D_5822b10 */
    Object016cd510(const Name &name) : Object016b9108(name)
    {
        unknown30.set(D_5822b10);
        unknown40 = 0;
        unknown50 = Float4(-45.0f, 45.0f, 0.0f, 1.0f);
        unknown60 = 0;
    }

    virtual ~Object016cd510() {}

  private:
    u8 unknown24[0xc];
    Value004af700 unknown30; /* +0x30: D_5822b10 from the constructor */
    int unknown40;           /* +0x40: 0 from the constructor */
    u8 unknown44[0xc];
    Float4 unknown50; /* +0x50: (-45, 45, 0, 1) from the constructor; not traced */
    int unknown60;    /* +0x60: 0 from the constructor */
    u8 unknown64[0xc];
};

/* derived names: the class whose vtable is at 0x16cd6e0
 * (config/vtables.derived.base.txt, stored by FUN_009b3ef0): its slots 2 to
 * 4 are the base's, slots 5 to 6 its own (declared; not written). 0x28 bytes (`mov edi, 0x28`
 * before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cd6e0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009b3ef0: the base built from the name, then
     * zero at +0x24 */
    Object016cd6e0(const Name &name) : Object016b9108(name), unknown24(0) {}

    virtual ~Object016cd6e0() {}

    virtual void slot5(); /* derived name; FUN_01384830, not traced */
    virtual void slot6(); /* derived name; FUN_01383ec0, not traced */

  private:
    int unknown24; /* +0x24: 0 from the constructor */
};

/* derived names: the class whose vtable is at 0x16cda90
 * (config/vtables.derived.base.txt, stored by FUN_009b4ac0), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). 0x48 bytes (`mov edi, 0x48`
 * before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cda90 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator FUN_009b4ac0: the base built from the name, then
     * (14, 45, 1, 0.02) at +0x34 (one 16-byte constant), zero at +0x44 */
    Object016cda90(const Name &name)
        : Object01343880(name), unknown34(14.0f, 45.0f, 1.0f, 0.02f), unknown44(0)
    {
    }

    virtual ~Object016cda90() {}

  private:
    Float4 unknown34; /* +0x34: (14, 45, 1, 0.02) from the constructor; not traced */
    int unknown44;    /* +0x44: 0 from the constructor */
};

/* derived names: the class whose vtable is at 0x16cdae8
 * (config/vtables.derived.base.txt, stored by FUN_009b4c40): its slots 2 to
 * 4 are the base's. 0x50 bytes (`mov edi, 0x50` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cdae8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009b4c40: the base built from the name, then
     * 1 at +0x24, zero from +0x30 (one 32-byte store) */
    Object016cdae8(const Name &name)
        : Object016b9108(name), unknown24(1), unknown30(0.0f, 0.0f, 0.0f, 0.0f),
          unknown40(0.0f, 0.0f, 0.0f, 0.0f)
    {
    }

    virtual ~Object016cdae8() {}

  private:
    int unknown24; /* +0x24: 1 from the constructor */
    u8 unknown28[0x8];
    Float4A unknown30; /* +0x30: zero from the constructor; not traced */
    Float4A unknown40; /* +0x40: zero from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16cdd18
 * (config/vtables.derived.base.txt, stored by FUN_009b62f0): its slots 2 to
 * 4 are the base's. 0x90 bytes (`mov edi, 0x90` before operator new in its creator). Its fields are traced only where the creator sets them. */
class Object016cdd18 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009b62f0: the base built from the name, then
     * the body: the fields in their order, the values at +0x30 and +0x40 copied member by member from D_5822b10 */
    Object016cdd18(const Name &name) : Object016b9108(name)
    {
        unknown30.set(D_5822b10);
        unknown40.set(D_5822b10);
        unknown50 = Float4(0.0f, 0.0f, 0.0f, 90.0f);
        unknown60 = 180.0f;
        unknown64 = 45.0f;
        unknown68 = 45.0f;
        unknown6c = Float4(90.0f, 90.0f, 10.0f, 10.0f);
        unknown7c = 0;
        unknown80 = 0;
    }

    virtual ~Object016cdd18() {}

  private:
    u8 unknown24[0xc];
    Value004af700 unknown30; /* +0x30: D_5822b10 from the constructor */
    Value004af700 unknown40; /* +0x40: D_5822b10 from the constructor */
    Float4 unknown50;        /* +0x50: (0, 0, 0, 90) from the constructor; not traced */
    float unknown60;         /* +0x60: 180.0 from the constructor */
    float unknown64;         /* +0x64: 45.0 from the constructor */
    float unknown68;         /* +0x68: 45.0 from the constructor */
    Float4 unknown6c;        /* +0x6c: (90, 90, 10, 10) from the constructor; not traced */
    int unknown7c;           /* +0x7c: 0 from the constructor */
    int unknown80;           /* +0x80: 0 from the constructor */
    u8 unknown84[0xc];
};

/* derived names: the class whose vtable is at 0x16cdd88
 * (config/vtables.derived.base.txt, stored by FUN_009bbab0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cdd88 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cdd88() {}
};

/* derived names: the class whose vtable is at 0x16ce3b0
 * (config/vtables.derived.base.txt, stored by FUN_00a54580): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016ce3b0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ce3b0() {}
};

/* derived names: the class whose vtable is at 0x16ceea0
 * (config/vtables.derived.base.txt, stored by FUN_00b37ce0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016ceea0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ceea0() {}
};

/* derived names: the class whose vtable is at 0x16ceed8
 * (config/vtables.derived.base.txt, stored by FUN_00b37e40): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016ceed8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ceed8() {}
};

/* derived names: the class whose vtable is at 0x16cffe8
 * (config/vtables.derived.base.txt, stored by FUN_00b45ce0): its slots 2 to
 * 4 are the base's, slots 5 to 8 its own (declared; not written). Its own
 * fields are not traced. */
class Object016cffe8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cffe8() {}

    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_0139b7f0, not traced */
    virtual void slot8(); /* derived name; FUN_0139ba00, not traced */
};

/* derived names: the class whose vtable is at 0x16b80d0
 * (config/vtables.derived.base.txt, stored by FUN_00c1b0e0): its slots 2 to
 * 4 are the base's, slots 5 to 6 its own (declared; not written). Its own
 * fields are not traced. */
class Object016b80d0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b80d0() {}

    virtual void slot5(); /* derived name; FUN_00c1b400, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */
};

/* derived names: the class whose vtable is at 0x16d1448
 * (config/vtables.derived.base.txt, stored by FUN_00c5a000), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own
 * fields are not traced. */
class Object016d1448 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016d1448() {}
};

/* derived names: the class whose vtable is at 0x16d19b0
 * (config/vtables.derived.base.txt, stored by FUN_00cccbd0), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own
 * fields are not traced. */
class Object016d19b0 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016d19b0() {}
};

/* derived names: the class whose vtable is at 0x16d2068
 * (config/vtables.derived.base.txt, stored by FUN_00cfced0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d2068 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2068() {}
};

/* derived names: the class whose vtable is at 0x16d2370
 * (config/vtables.derived.base.txt, stored by FUN_00d51fd0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d2370 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2370() {}
};

/* derived names: the class whose vtable is at 0x16d2418
 * (config/vtables.derived.base.txt, stored by FUN_00d637b0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d2418 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2418() {}
};

/* derived names: the class whose vtable is at 0x16d2668
 * (config/vtables.derived.base.txt, stored by FUN_00d76e10): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d2668 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2668() {}
};

/* derived names: the class whose vtable is at 0x16d26a0
 * (config/vtables.derived.base.txt, stored by FUN_00d77fc0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d26a0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d26a0() {}
};

/* derived names: the class whose vtable is at 0x16d26d8
 * (config/vtables.derived.base.txt, stored by FUN_00d79f30): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d26d8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d26d8() {}
};

/* derived names: the class whose vtable is at 0x16d27b8
 * (config/vtables.derived.base.txt, stored by FUN_00d881a0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d27b8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d27b8() {}
};

/* derived names: the class whose vtable is at 0x16d2de0
 * (config/vtables.derived.base.txt, stored by FUN_00e63af0), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own
 * fields are not traced. */
class Object016d2de0 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016d2de0() {}
};

/* derived names: the class whose vtable is at 0x16d2f28
 * (config/vtables.derived.base.txt, stored by FUN_00e87bb0), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own
 * fields are not traced. */
class Object016d2f28 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016d2f28() {}
};

/* derived names: the class whose vtable is at 0x16d2f80
 * (config/vtables.derived.base.txt, stored by FUN_00e8d980): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d2f80 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2f80() {}
};

/* derived names: the class whose vtable is at 0x16d2fb8
 * (config/vtables.derived.base.txt, stored by FUN_00e8dd60): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d2fb8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2fb8() {}
};

/* derived names: the class whose vtable is at 0x16d3018
 * (config/vtables.derived.base.txt, stored by FUN_00e8ded0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d3018 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d3018() {}
};

/* derived names: the class whose vtable is at 0x16d3050
 * (config/vtables.derived.base.txt, stored by FUN_00e8e080): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d3050 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d3050() {}
};

/* derived names: the class whose vtable is at 0x16d3088
 * (config/vtables.derived.base.txt, stored by FUN_00e8e230): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d3088 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d3088() {}
};

/* derived names: the class whose vtable is at 0x16d30c0
 * (config/vtables.derived.base.txt, stored by FUN_00e8e3e0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d30c0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d30c0() {}
};

/* derived names: the class whose vtable is at 0x16d30f8
 * (config/vtables.derived.base.txt, stored by FUN_00e8e590): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d30f8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d30f8() {}
};

/* derived names: the class whose vtable is at 0x16d3130
 * (config/vtables.derived.base.txt, stored by FUN_00e8e740): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d3130 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d3130() {}
};

/* derived names: the class whose vtable is at 0x16d3168
 * (config/vtables.derived.base.txt, stored by FUN_00e8ec20): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016d3168 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d3168() {}
};

/* derived names: the class whose vtable is at 0x16cc228
 * (config/vtables.derived.base.txt, stored by FUN_008778c0): its slots 2 to
 * 4 are the base's. 0x38 bytes (`mov edi, 0x38` before operator new in its
 * creator). Its fields are not traced. */
class Object016cc228 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_008778c0: the base built from the name, then
     * nothing of its own */
    Object016cc228(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cc228() {}

  private:
    u8 unknown24[0x14];
};

/* derived names: the class whose vtable is at 0x16cd698
 * (config/vtables.derived.base.txt, stored by FUN_009b3d80): its slots 2 to
 * 4 are the base's. 0x28 bytes (`mov edi, 0x28` before operator new in its
 * creator). Its fields are not traced. */
class Object016cd698 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009b3d80: the base built from the name, then
     * nothing of its own */
    Object016cd698(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cd698() {}

  private:
    u8 unknown24[0x4];
};

/* derived names: the class whose vtable is at 0x16cdc38
 * (config/vtables.derived.base.txt, stored by FUN_009b59a0): its slots 2 to
 * 4 are the base's. 0x28 bytes (`mov edi, 0x28` before operator new in its
 * creator). Its fields are not traced. */
class Object016cdc38 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009b59a0: the base built from the name, then
     * nothing of its own */
    Object016cdc38(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cdc38() {}

  private:
    u8 unknown24[0x4];
};

#endif
