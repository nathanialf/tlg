/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cf9f8.h"

/* derived names: slot 6 of the vtable at 0x16cc898 (its pointer at 0x16cc8d8 and in the vtable at 0x16cee58 at 0x16cf000) and,
 * through the thunk 0x137bf90 (this - 0x10, the body inlined into it), slot 0 of
 * the base at +0x10 (its pointer at 0x16cc900 and 0x16cf028): when the object at +0x18 is set and
 * its slot 7 returns nonzero, calls the class's slot 3 (its slot 3 the shared empty body 0x1af750) and returns that
 * value; else 0, as FUN_0137ba00 does in the class at 0x16cc478. The
 * constructor is not traced. */
class Base0137c110_0 /* derived name */
{
  public:
    virtual ~Base0137c110_0();
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */

    u8 unknown8[8];
};

class Member0137c110_18 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual int slot7();  /* derived name */
};

class Base0137c110_10 /* derived name */
{
  public:
    virtual int FUN_0137bf90() = 0; /* derived name, after its thunk */

    Member0137c110_18 *member8; /* +0x8 */
    Records016cf9f8 *records;   /* +0x10 (+0x20 of the class) */
};

/* A 32-byte element of the output's array at +0x48. */
struct Element0137c090 /* derived name */
{
    Vec4 unknown0;
    float unknown10;
    float unknown14;
    float unknown18;
    float unknown1c;
};

/* The first argument of slot 4 and of slot 0 of the base at +0x28. */
struct Output0137c090 /* derived name */
{
    u8 unknown0[0x48];
    Element0137c090 *elements; /* +0x48 */
};

class Base0137c110_28 /* derived name */
{
  public:
    virtual void FUN_0137c010(Output0137c090 *output, int,
                              int record) = 0; /* derived name, after its thunk */
};

class Object0137c110 /* derived name */
    : public Base0137c110_0,
      public Base0137c110_10,
      public Base0137c110_28
{
  public:
    virtual ~Object0137c110();

    int FUN_0137bf90();
    void FUN_0137c010(Output0137c090 *output, int, int record);
};

int Object0137c110::FUN_0137bf90()
{
    int result = 0;
    if (member8) {
        int value = member8->slot7();
        if (value) {
            slot3();
            result = value;
        }
    }
    return result;
}

/* derived names: slot 4 of the vtable at 0x16cc898 (FUN_0137c090, its
 * pointer at 0x16cc8c8) and, through the thunk 0x137c010 (this - 0x28, the
 * body inlined into it), slot 0 of the base at +0x28: for each index of the
 * record's chosen list (tlg_game_object016cf9f8.h's records, as
 * FUN_01399e90 reads them), copies the vector at +0x2f0 and the four words at
 * +0x2e0, +0x2e4, +0x2e8 and +0x300 of the entry it names into the output's
 * elements, one element per index. Its slot 4 overrides the base's slot 0, so
 * the base's slot 4 in this file stays declared. */
// NONMATCHING: LSR's offset of the elements' pointer: the base keeps it at the element
// (`vmovaps [rdx]`, the words at +0x10 to +0x1c), the build moves it to the last word
// (`add rdx, 0x1c` before the loop, the vector at -0x1c); the same in the thunk 0x137c010.
// The elements walked by a pointer give the base's offset but load the output's array after
// the indices (the registers of the two swapped); the vector stored last, the same.
void Object0137c110::FUN_0137c010(Output0137c090 *output, int, int record)
{
    const Array05943280<unsigned> &list = records->records.at(record).lists[records->variant];
    unsigned count = list.size();
    if (!count)
        return;
    Entry0137c090 *entries = records->table->entries;
    Element0137c090 *elements = output->elements;
    const unsigned *indices = list.begin();
    for (unsigned i = 0; i < count; ++i) {
        const Entry0137c090 &entry = entries[indices[i]];
        Element0137c090 &element = elements[i];
        element.unknown0 = entry.unknown2f0;
        element.unknown10 = entry.unknown2e0;
        element.unknown14 = entry.unknown2e4;
        element.unknown18 = entry.unknown2e8;
        element.unknown1c = entry.unknown300;
    }
}
