/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00ca8e80: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array01343a80.h"

/* derived names: under the lock of the array of elements at +0x138 (its
 * lock at +0x14c), every element whose word at +0x74 is the id given gets
 * the two other arguments through its slot 6 (`call [rax+0x30]`); called
 * at 0xb9b282, 0xb9b2a4 and 0xbaa1f1. The classes, the slot and its
 * arguments are not traced. */
struct Argument00ca8e80; /* derived name */

class Element00ca8e80 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void unknown4();
    virtual void unknown5();
    virtual void unknown6(Argument00ca8e80 *first, Argument00ca8e80 *second);

    u8 unknown8[0x6c];
    int id; /* +0x74 */
};

struct Object00ca8e80 { /* derived name */
    u8 unknown0[0x138];
    Array01343a80<Element00ca8e80 *> elements; /* +0x138 */
};

void FUN_00ca8e80(Object00ca8e80 *self, int id, Argument00ca8e80 *first,
                  Argument00ca8e80 *second) /* derived name */
{
    self->elements.lock.lock();
    for (Element00ca8e80 *element : self->elements) {
        if (element->id == id)
            element->unknown6(first, second);
    }
    self->elements.lock.unlock();
}
