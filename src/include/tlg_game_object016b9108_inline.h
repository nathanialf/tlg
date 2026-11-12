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

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7700
 * (config/vtables.derived.base.txt, stored by FUN_0036ac20): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016c7700 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c7700(); /* FUN_01386090; leaf_01386090.cpp */
};

/* derived names: the class whose vtable is at 0x16c7738
 * (config/vtables.derived.base.txt, stored by FUN_00371bc0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016c7738 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c7738() {}
};

/* derived names: the class whose vtable is at 0x16cada8
 * (config/vtables.derived.base.txt, stored by FUN_00474ae0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cada8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cada8() {}
};

/* derived names: the class whose vtable is at 0x16cb5b8
 * (config/vtables.derived.base.txt, stored by FUN_00690560): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cb5b8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cb5b8() {}
};

/* derived names: the class whose vtable is at 0x16cb920
 * (config/vtables.derived.base.txt, stored by FUN_007a1fb0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cb920 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cb920() {}
};

/* derived names: the class whose vtable is at 0x16cba38
 * (config/vtables.derived.base.txt, stored by FUN_007a28d0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cba38 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cba38() {}
};

/* derived names: the class whose vtable is at 0x16cbbc0
 * (config/vtables.derived.base.txt, stored by FUN_007ad930): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cbbc0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cbbc0() {}
};

/* derived names: the class whose vtable is at 0x16cbfe8
 * (config/vtables.derived.base.txt, stored by FUN_0082fc00): its slots 2 to
 * 4 are the base's, slots 5 to 8 its own (declared; not written). Its own
 * fields are not traced. */
class Object016cbfe8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cbfe8() {}

    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
};

/* derived names: the class whose vtable is at 0x16cc1f0
 * (config/vtables.derived.base.txt, stored by FUN_00872910): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cc1f0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cc1f0() {}
};

/* derived names: the class whose vtable is at 0x16cd3f8
 * (config/vtables.derived.base.txt, stored by FUN_00991bf0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cd3f8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cd3f8() {}
};

/* derived names: the class whose vtable is at 0x16cd4d8
 * (config/vtables.derived.base.txt, stored by FUN_009957e0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cd4d8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cd4d8() {}
};

/* derived names: the class whose vtable is at 0x16cd510
 * (config/vtables.derived.base.txt, stored by FUN_009959a0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cd510 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cd510() {}
};

/* derived names: the class whose vtable is at 0x16cd6e0
 * (config/vtables.derived.base.txt, stored by FUN_009b3ef0): its slots 2 to
 * 4 are the base's, slots 5 to 6 its own (declared; not written). Its own
 * fields are not traced. */
class Object016cd6e0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cd6e0() {}

    virtual void slot5(); /* derived name; FUN_01384830, not traced */
    virtual void slot6(); /* derived name; FUN_01383ec0, not traced */
};

/* derived names: the class whose vtable is at 0x16cda90
 * (config/vtables.derived.base.txt, stored by FUN_009b4ac0): its slots 2 to
 * 4 are the base's, slots 5 to 8 its own (declared; not written). Its own
 * fields are not traced. */
class Object016cda90 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cda90() {}

    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
};

/* derived names: the class whose vtable is at 0x16cdae8
 * (config/vtables.derived.base.txt, stored by FUN_009b4c40): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cdae8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cdae8() {}
};

/* derived names: the class whose vtable is at 0x16cdd18
 * (config/vtables.derived.base.txt, stored by FUN_009b62f0): its slots 2 to
 * 4 are the base's. Its own fields are not traced. */
class Object016cdd18 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cdd18() {}
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
 * (config/vtables.derived.base.txt, stored by FUN_00c5a000): its slots 2 to
 * 4 are the base's, slots 5 to 8 its own (declared; not written). Its own
 * fields are not traced. */
class Object016d1448 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d1448() {}

    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
};

/* derived names: the class whose vtable is at 0x16d19b0
 * (config/vtables.derived.base.txt, stored by FUN_00cccbd0): its slots 2 to
 * 4 are the base's, slots 5 to 8 its own (declared; not written). Its own
 * fields are not traced. */
class Object016d19b0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d19b0() {}

    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
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
 * (config/vtables.derived.base.txt, stored by FUN_00e63af0): its slots 2 to
 * 4 are the base's, slots 5 to 8 its own (declared; not written). Its own
 * fields are not traced. */
class Object016d2de0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2de0() {}

    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
};

/* derived names: the class whose vtable is at 0x16d2f28
 * (config/vtables.derived.base.txt, stored by FUN_00e87bb0): its slots 2 to
 * 4 are the base's, slots 5 to 8 its own (declared; not written). Its own
 * fields are not traced. */
class Object016d2f28 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d2f28() {}

    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; FUN_001af750, not traced */
    virtual void slot8(); /* derived name; FUN_001af750, not traced */
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

#endif
