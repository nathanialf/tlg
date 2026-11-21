/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16caee0
 * (config/vtables.derived.base.txt; made by FUN_005114e0): three Names at
 * +0x14, +0x20 and +0x2c. Its complete destructor 0x1354780 releases +0x2c, then +0x20, then +0x14,
 * and calls no base; the deleting one 0x1354f30 is the compiler's. Slot 5
 * (FUN_0139edd0) empties an array of 4-byte elements it is given and frees
 * its block (the array's clear with 0; the object itself is not read). The
 * other members are not traced. */
/* derived name: a 28-byte element of the arrays slot 6 sizes, zeroed when
 * made (FUN_01354a60: two overlapping 16-byte stores of zero at +0 and +0xc);
 * what it holds is not traced */
struct Element01354a60 {
    Element01354a60()
        : unknown0(0), unknown4(0), unknown8(0), unknownc(0), unknown10(0), unknown14(0),
          unknown18(0)
    {
    }

    u32 unknown0;
    u32 unknown4;
    u32 unknown8;
    u32 unknownc;
    u32 unknown10;
    u32 unknown14;
    u32 unknown18;
};

class Object016caee0 /* derived name */
{
  public:
    virtual ~Object016caee0();
    virtual void slot2();                                 /* derived name: 0x139ece0; not traced */
    virtual void slot3();                                 /* derived name: 0x1354940; not traced */
    virtual void slot4();                                 /* derived name: 0x1354960; not traced */
    virtual void FUN_0139edd0(Array05943280<int> &array); /* derived name: slot 5 */
    /* derived name: slot 6, the count of an array of its elements set (the
     * capacity made the count exactly, each element zeroed) */
    virtual void FUN_01354a60(Array05943280<Element01354a60> &array, unsigned size);

  private:
    u8 unknown8[0xc];
    Name unknown14; /* +0x14 */
    u8 unknown18[0x8];
    Name unknown20; /* +0x20 */
    u8 unknown24[0x8];
    Name unknown2c; /* +0x2c */
};

Object016caee0::~Object016caee0() {}

void Object016caee0::FUN_0139edd0(Array05943280<int> &array) /* derived name */
{
    array.clear(0);
}

void Object016caee0::FUN_01354a60(Array05943280<Element01354a60> &array,
                                  unsigned size) /* derived name */
{
    array.resize(size);
}
