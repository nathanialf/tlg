/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object0134f620.h"

void FUN_00c57220(Object016b9108 *object); /* derived name; not traced */

/* derived names: the class whose vtable is at 0x16b3a88
 * (config/vtables.derived.base.txt, stored by its creator FUN_00ad6850),
 * derived from Object016b85e0, with an array of counted references at
 * +0x238 and a counted reference at +0x288. Its destructor (its key
 * function) calls FUN_00ad6b20 on the object, hands each referenced object
 * to FUN_00c57220 (the count read once, `mov r15d, [r14+0x240]; test r15d,
 * r15d; jle`), empties the array to no capacity (FUN_0138c8d0 with 0), then
 * the members are released, last first, and the base's destructor
 * tail-called (0xad6a00; FUN_00ad6b00 the deleting one). The other fields
 * are not traced. */
class Object016b3a88 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b3a88();

    void FUN_00ad6b20(); /* derived name; not traced */

  private:
    Object0134f620 unknown238; /* +0x238 */
    u8 unknown250[0x38];
    Ref00503fb0<Object016b9108> unknown288; /* +0x288 */
};

Object016b3a88::~Object016b3a88()
{
    FUN_00ad6b20();
    const int count = unknown238.size();
    for (int i = 0; i < count; ++i)
        if (unknown238[i].get())
            FUN_00c57220(unknown238[i].get());
    unknown238.clear(0);
}
