/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object00d157e0.h"
#include "tlg_game_object0135e680.h"

/* derived name: an element of the array the class below owns at +0x318:
 * 0xb0 bytes (`imul rax, rax, 0xb0` over the count before the block), a
 * counted reference at +0x98 the only part with a destructor; 16-aligned
 * (the array's cookie is 16 bytes: the count at -0x8, the block from
 * -0x10), as Element00d1e230 (leaf_00d1e230.cpp). The rest is not traced. */
struct alignas(16) Element007af0d0 { /* derived name */
    u8 unknown0[0x98];
    Ref00503fb0<Object016b9108> held; /* +0x98 */
    u8 unknowna0[0x10];
};

/* derived names: the class whose vtable is at 0x16adec8
 * (config/vtables.derived.base.txt, stored by its creator FUN_007aeee0),
 * derived from Object00d157e0. Its complete destructor FUN_007af0d0 (the
 * class's key function, so this file emits the vtable) deletes the array of
 * elements at +0x318 and the block at +0x320, each then cleared; the members
 * then destroy the object at +0x120 (0x135e680) and release the counted
 * reference at +0xf8, and the base's destructor runs as a tail call.
 * FUN_007af2a0, slot 1, is the deleting one, which calls it. The other
 * members are not traced. */
class Object016adec8 : public Object00d157e0 /* derived name */
{
  public:
    virtual ~Object016adec8();

  private:
    u8 unknown8[0xf0];
    Ref00503fb0<Object016b9108> heldf8; /* +0xf8 */
    u8 unknown100[0x20];
    Object0135e680 member120; /* +0x120 */
    u8 unknown128[0x1f0];
    Element007af0d0 *elements; /* +0x318 */
    int *block320;             /* +0x320: deleted with delete[]; its contents not traced */
};

Object016adec8::~Object016adec8()
{
    if (elements) {
        delete[] elements;
        elements = 0;
    }
    if (block320) {
        delete[] block320;
        block320 = 0;
    }
}
