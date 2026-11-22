/* The class whose vtable is at 0x16b5ae8 (stored by FUN_00b3f8e0;
 * config/vtables.derived.base.txt names it), laid out as
 * tlg_game_object016cf9f8.h's: secondary vtables at offsets to top -0x10
 * (the thunk 0x1396cb0 of FUN_01397400, FUN_01396d00, FUN_01396d20), -0x28
 * (FUN_00953720, FUN_00953820), -0x38 (FUN_01396d40), -0x40 (FUN_01396e80),
 * -0x48 (the thunk 0xb3f410 of the primary slot 8, FUN_00b3ee00), -0x50 (the
 * thunk 0xb3f4e0 of the primary slot 9, FUN_00b3f420, the body inlined) and
 * -0x58 (the thunks 0xb3f650 and 0xb3f8d0 of the primary slots 13 and 12,
 * FUN_00b3f5a0 and FUN_00b3f660). The bases' sizes between their vptrs are
 * those offsets. All names derived. */
#ifndef TLG_GAME_OBJECT016B5AE8_H
#define TLG_GAME_OBJECT016B5AE8_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_object016cf9f8.h"
#include "tlg_math.h"

/* Three floats copied one by one (FUN_00b3f420: `mov edx, [rbx+rax+0x18]`
 * to `+0x20` between the block moves of the words around them). */
struct Vector016b5ae8 { /* derived name */
    float x;
    float y;
    float z;

    Vector016b5ae8 &operator=(const Vector016b5ae8 &other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

/* A 44-byte entry of the table at +0x30 (FUN_013984d0, slot 4, returns 44):
 * FUN_00b3f420 copies the words before the vector and after it as blocks
 * (`vmovups` of +0x0, the quad at +0x10, the quad at +0x24), the vector
 * member by member; FUN_00b3f5a0 reads the short at +0x0 sign-extended.
 * The fields' meaning is not traced. */
struct Entry016b5ae8 /* derived name */
{
    short unknown0;
    int unknown4;
    int unknown8;
    int unknownc;
    int unknown10;
    int unknown14;
    Vector016b5ae8 position; /* +0x18: a point, w 0 in the vertex */
    int unknown24;
    int unknown28;
};

/* The object at +0x30 (the base at +0x28's +0x8). */
struct Table016b5ae8 /* derived name */
{
    u8 unknown0[0x10];
    const Entry016b5ae8 *source; /* +0x10: the entries FUN_00b3f420 copies from */
    Entry016b5ae8 *entries;      /* +0x18 */
};

/* A 48-byte element of the output's array at +0x18 (FUN_00b3f5a0). */
struct Vertex016b5ae8 /* derived name */
{
    Float4 position; /* +0x0: the entry's point, w 0 */
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    int unknown20;
    int unknown24;
    int unknown28;
    u8 unknown2c[4];
};

/* The first argument of slot 0 of the base at +0x58. */
struct Output016b5ae8 /* derived name */
{
    u8 unknown0[0x18];
    Vertex016b5ae8 *vertices; /* +0x18 */
};

class Base016b5ae8_0 /* derived name */
{
  public:
    /* Slots 0 and 1: FUN_01397490, FUN_013974a0. */
    virtual ~Base016b5ae8_0();

    u8 unknown8[8];
};

class Base016b5ae8_10 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; the thunk of FUN_01397400 (leaf_01397400.cpp) */
    virtual void slot1(); /* derived name; FUN_01396d00, not traced */
    virtual void slot2(); /* derived name; FUN_01396d20, not traced */

    u8 unknown8[8];
    Records016cf9f8 *records; /* +0x10 (+0x20 of the class) */
};

class Base016b5ae8_28 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_00953720, not traced */
    virtual void slot1(); /* derived name; FUN_00953820, not traced */

    Table016b5ae8 *table; /* +0x8 (+0x30 of the class) */
};

class Base016b5ae8_38 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_01396d40, not traced */
};

class Base016b5ae8_40 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_01396e80, not traced */
};

class Base016b5ae8_48 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; the thunk of FUN_00b3ee00, not traced */
};

class Base016b5ae8_50 /* derived name */
{
  public:
    virtual void FUN_00b3f420() = 0; /* derived name */
};

class Base016b5ae8_58 /* derived name */
{
  public:
    /* the second argument is not read */
    virtual void FUN_00b3f5a0(Output016b5ae8 *output, int, int record) = 0; /* derived name */
    virtual void slot1(); /* derived name; the thunk of FUN_00b3f660, not traced */
};

class Object016b5ae8 /* derived name */
    : public Base016b5ae8_0,
      public Base016b5ae8_10,
      public Base016b5ae8_28,
      public Base016b5ae8_38,
      public Base016b5ae8_40,
      public Base016b5ae8_48,
      public Base016b5ae8_50,
      public Base016b5ae8_58
{
  public:
    /* Slot 9 of the primary vtable (its pointer at 0x16b5b40). */
    void FUN_00b3f420();
    /* Slot 13 of the primary vtable (its pointer at 0x16b5b60). */
    void FUN_00b3f5a0(Output016b5ae8 *output, int, int record);
};

#endif
