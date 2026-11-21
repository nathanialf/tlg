/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: the class of the vtable at 0x16d0298
 * (config/vtables.derived.base.txt; stored by FUN_00bf9780 and
 * FUN_013a05f0), a handler of arrays of 12-byte elements, as the class at
 * 0x16caee0 (leaf_01354780.cpp) is of 4-byte ones: slot 4 (FUN_0139ed10)
 * makes one array a copy of another (the count set as slot 6 sets it, then
 * the elements copied with one memcpy, a tail call), slot 6
 * (FUN_0139ee40) sets an array's count (the capacity made the count
 * exactly). Slot 5 is the shared emptying FUN_0139edd0. The object itself is
 * not read; the other slots are not traced. */
struct Element016d0298 { /* derived name: what the 12 bytes hold is not traced */
    u32 unknown0;
    u32 unknown4;
    u32 unknown8;
};

class Object016d0298 /* derived name */
{
  public:
    virtual ~Object016d0298();
    virtual void slot2(); /* derived name: 0x139ece0; not traced */
    virtual void slot3(); /* derived name: 0x139ecf0; not traced */
    virtual void
    FUN_0139ed10(Array05943280<Element016d0298> &array,
                 const Array05943280<Element016d0298> &other); /* derived name: slot 4 */
    virtual void slot5(); /* derived name: 0x139edd0; not traced */
    virtual void FUN_0139ee40(Array05943280<Element016d0298> &array,
                              unsigned size); /* derived name: slot 6 */
};

void Object016d0298::FUN_0139ed10(Array05943280<Element016d0298> &array,
                                  const Array05943280<Element016d0298> &other) /* derived name */
{
    if (&array == &other)
        return;
    unsigned size = other.size();
    array.resize(size);
    if (size) {
        const Element016d0298 *values = other.begin();
        memcpy(&array[0], values, size * unsigned(sizeof(Element016d0298)));
    }
}

void Object016d0298::FUN_0139ee40(Array05943280<Element016d0298> &array,
                                  unsigned size) /* derived name */
{
    array.resize(size);
}
