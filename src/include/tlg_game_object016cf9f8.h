/* The class whose vtable is at 0x16cf9f8 (stored by FUN_00b40f10;
 * config/vtables.derived.base.txt names it): secondary vtables at offsets to
 * top -0x10 (three slots: the thunk 0x1397ac0 of FUN_01398710, FUN_01397b10,
 * FUN_01397b30), -0x28 (FUN_00953720, FUN_00953820), -0x38, -0x40, -0x48,
 * -0x50 (one slot each) and -0x58 (the thunks 0x1398150 and 0x13981d0 of
 * the primary slots 15 and 16, FUN_01399e90 and FUN_01399f10). The bases'
 * sizes between their vptrs are those offsets. All names derived. */
#ifndef TLG_GAME_OBJECT016CF9F8_H
#define TLG_GAME_OBJECT016CF9F8_H

#include "tlg_types.h"
#include "tlg_game_array.h"

/* One of the 64-byte records the object at +0x20 keeps: the index lists of
 * its variants, the one at the holder's +0x10 chosen (FUN_01399e90: `lea
 * r8, [rcx+rcx*2]; mov ecx, [rdi+r8*8+8]`); how many and the rest not
 * traced. */
struct Record016cf9f8 /* derived name */
{
    Array05943280<unsigned> lists[2]; /* +0x0 */
    u8 unknown30[0x10];
};

/* The object at +0x20 (the base at +0x10's +0x10). */
struct Records016cf9f8 /* derived name */
{
    u8 unknown0[0x10];
    unsigned variant; /* +0x10: the list each record gives */
    u8 unknown14[0xc];
    Record016cf9f8 *records; /* +0x20 */
};

/* An element of the table at +0x18 of the object at +0x30: 28 bytes, the
 * four floats from +0xc copied (moved as ints, `mov eax, [r9+rdi+0xc]`). */
struct Entry016cf9f8 /* derived name */
{
    u8 unknown0[0xc];
    float unknownc;
    float unknown10;
    float unknown14;
    float unknown18;
};

/* The object at +0x30 (the base at +0x28's +0x8). */
struct Table016cf9f8 /* derived name */
{
    u8 unknown0[0x18];
    Entry016cf9f8 *entries; /* +0x18 */
};

/* A 64-byte element of the output's array at +0x28. */
struct Vertex016cf9f8 /* derived name */
{
    float unknown0;
    float unknown4;
    u8 unknown8[8];
    float unknown10;
    float unknown14;
    u8 unknown18[0x28];
};

/* The first argument of slot 0 of the base at +0x58. */
struct Output016cf9f8 /* derived name */
{
    u8 unknown0[0x28];
    Vertex016cf9f8 *vertices; /* +0x28 */
};

class Base016cf9f8_0 /* derived name */
{
  public:
    /* Slots 0 and 1: FUN_0139b3a0, FUN_0139b3b0. */
    virtual ~Base016cf9f8_0();

    u8 unknown8[8];
};

class Base016cf9f8_10 /* derived name */
{
  public:
    virtual int FUN_01398710() = 0; /* derived name */
    virtual void slot1();           /* derived name; FUN_01397b10, not traced */
    virtual void slot2();           /* derived name; FUN_01397b30, not traced */

    u8 unknown8[8];
    Records016cf9f8 *records; /* +0x10 (+0x20 of the class) */
};

class Base016cf9f8_28 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_00953720, not traced */
    virtual void slot1(); /* derived name; FUN_00953820, not traced */

    Table016cf9f8 *table; /* +0x8 (+0x30 of the class) */
};

class Base016cf9f8_38 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_01397f30, not traced */
};

class Base016cf9f8_40 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_01398030, not traced */
};

class Base016cf9f8_48 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_01398040, not traced */
};

class Base016cf9f8_50 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_01398090, not traced */
};

class Base016cf9f8_58 /* derived name */
{
  public:
    /* the third argument is not read */
    virtual void FUN_01398150(Output016cf9f8 *output, int, int record) = 0; /* derived name */
    virtual void FUN_013981d0() = 0; /* derived name; parameters not traced */
};

class Object016cf9f8 /* derived name */
    : public Base016cf9f8_0,
      public Base016cf9f8_10,
      public Base016cf9f8_28,
      public Base016cf9f8_38,
      public Base016cf9f8_40,
      public Base016cf9f8_48,
      public Base016cf9f8_50,
      public Base016cf9f8_58
{
  public:
    /* Slot 15 of the primary vtable (its pointer at 0x16cfa80). */
    void FUN_01398150(Output016cf9f8 *output, int, int record);
};

#endif
