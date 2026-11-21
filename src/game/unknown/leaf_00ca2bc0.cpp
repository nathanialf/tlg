/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"

/* derived names: the class whose complete destructor is 0xd476f0 (its row
 * named for it, D15), the base of the class below, its destructor run as a
 * tail call. The destructor is not written, so nothing here emits its
 * vtable; its slots and fields are not traced. */
class Object00d476f0 /* derived name */
{
  public:
    virtual ~Object00d476f0();
};

/* derived name: an element of the array at +0x288 of the class below,
 * 0x20 bytes (`shl rax, 5` over the index), an owned block at +0x8 the only
 * part with a destructor. The rest is not traced. */
struct Element00ca2bc0 { /* derived name */
    u8 unknown0[0x8];
    OwnedBlock05943280 block; /* +0x8 */
    u8 unknown10[0x10];
};

/* derived names: the class whose vtable is at 0x16b8c98
 * (config/vtables.derived.base.txt, stored by its creator FUN_00ca2960),
 * derived from Object00d476f0. Its complete destructor FUN_00ca2bc0 (the
 * class's key function, so this file emits the vtable) is the members': the
 * counted references at +0x2a8 and +0x2a0, the array at +0x288 (each
 * element's block, then the array's own) and the counted reference at
 * +0x280, then the base's destructor as a tail call. FUN_00ca2e20, slot 1,
 * is the deleting one, which calls it. The other members are not traced. */
class Object016b8c98 : public Object00d476f0 /* derived name */
{
  public:
    virtual ~Object016b8c98();

  private:
    u8 unknown8[0x278];
    Ref00503fb0<Object016b9108> held280;     /* +0x280 */
    Array05943280<Element00ca2bc0> array288; /* +0x288 */
    Ref00503fb0<Object016b9108> held2a0;     /* +0x2a0 */
    Ref00503fb0<Object016b9108> held2a8;     /* +0x2a8 */
};

Object016b8c98::~Object016b8c98() {}
