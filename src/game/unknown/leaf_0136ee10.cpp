/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: an 8-byte element with a Name at +0x4 (`mov ecx, [r12+rbx*8+4]`
 * in the destructor's loop); its first word is not traced */
struct Element0136ee10 { /* derived name */
    u32 unknown0;
    Name name4; /* +0x4 */
};

/* derived names: the class whose vtable is at 0x16cbed0
 * (config/vtables.derived.base.txt), with an array of Element0136ee10 at
 * +0x18. Its complete destructor FUN_0136ee10 is the array's destructor
 * inlined (each element's name released first to last, then the block);
 * FUN_0136eee0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. The other members are not
 * traced. */
class Object016cbed0 /* derived name */
{
  public:
    virtual ~Object016cbed0();

  private:
    u8 unknown8[0x10];
    Array05943280<Element0136ee10> elements18; /* +0x18 */
};

Object016cbed0::~Object016cbed0() {}
