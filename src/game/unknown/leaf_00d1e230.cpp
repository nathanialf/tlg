/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object00d157e0.h"

/* derived name: an element of the array the class below owns at +0x98:
 * 0xb0 bytes (`imul rax, rax, 0xb0` over the count before the block), a
 * counted reference at +0x98 the only part with a destructor; 16-aligned
 * (the array's cookie is 16 bytes: the count at -0x8, the block from
 * -0x10). The rest is not traced. */
struct alignas(16) Element00d1e230 { /* derived name */
    u8 unknown0[0x98];
    Ref00503fb0<Object016b9108> held; /* +0x98 */
    u8 unknowna0[0x10];
};

/* derived names: the class whose vtable is at 0x16ba0e8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d1dfa0
 * and its complete destructor FUN_00d1e230), derived from Object00d157e0:
 * three arrays at +0x50, +0x68 and +0x80 and an array of elements it owns
 * at +0x98. The destructor deletes the elements (last first, then the
 * block, `call 0x14b03a8`) and clears the pointer; then the arrays are torn
 * down, last first, and the base's destructor 0xd157e0 runs as a tail
 * call. FUN_00d1e420, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The arrays'
 * elements and the other fields are not traced. */
class Object016ba0e8 : public Object00d157e0 /* derived name */
{
  public:
    virtual ~Object016ba0e8();

  private:
    u8 unknown8[0x48];
    Array05943280<int> array50; /* +0x50 */
    Array05943280<int> array68; /* +0x68 */
    Array05943280<int> array80; /* +0x80 */
    Element00d1e230 *elements;  /* +0x98 */
};

Object016ba0e8::~Object016ba0e8()
{
    if (elements) {
        delete[] elements;
        elements = 0;
    }
}
