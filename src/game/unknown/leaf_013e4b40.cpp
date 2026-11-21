/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d4b78 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00f96270): it stores the vtable and destroys its members in reverse
 * order, the Object013e4510 at +0x30 (its destructor 0x13e4510, the row named
 * for it, D15) and then the heap block it owns at +0x18 (tlg_game_block.h).
 * It has no base. FUN_013e4bb0, slot 1, is the deleting one. The destructor
 * is the class's key function, so this file emits the vtable. The block at
 * +0x18 is an array's (slot 2, FUN_013dc9a0, resizes it to 184 cleared
 * words). The other members are not traced. */
class Object013e4510 /* derived name */
{
  public:
    virtual ~Object013e4510();

    void FUN_013dca50(); /* derived name; not traced */
};

/* derived name: an element of the array at +0x18: a word its constructor
 * clears (FUN_013dc9a0's loop: `mov dword [rdx+rcx*4], 0`); not traced
 * further */
struct Word013dc9a0 {
    Word013dc9a0() : value(0) {}

    u32 value;
};

class Object016d4b78 /* derived name */
{
  public:
    virtual ~Object016d4b78();

    /* slot 2 (its pointer at 0x16d4b98): the array made 184 cleared words,
     * then FUN_013dca50 for the member at +0x30, as a tail call */
    void FUN_013dc9a0(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<Word013dc9a0> words18; /* +0x18 */
    Object013e4510 unknown30;            /* +0x30 */
};

Object016d4b78::~Object016d4b78() {}

void Object016d4b78::FUN_013dc9a0()
{
    words18.resize(184);
    unknown30.FUN_013dca50();
}
