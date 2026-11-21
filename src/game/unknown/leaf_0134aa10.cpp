/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_element0134aa10.h"
#include "tlg_game_object016b9108.h"

/* derived names: the destructor (0x134aa10) and clear(unsigned) (0x134a8c0)
 * of an array of 0xd0-byte elements aligned on 16 bytes, each holding a
 * counted reference at +0xa8 and nothing else that needs destruction
 * (tlg_game_array.h), out of line: the array's own members, instantiated
 * here, with the holder of the array below. The element's other members
 * and the referenced class are not traced. */
template Array05943280<Element0134aa10>::~Array05943280();
template void Array05943280<Element0134aa10>::clear(unsigned);

/* derived names: the class whose vtable is at 0x16a7c90
 * (config/vtables.derived.base.txt, stored by its constructor FUN_002a63d0
 * and its destructors), derived from Object016b9108: its slots 2 to 4 are
 * the base's, slot 5 FUN_000058a0. Its own fields from +0x24 are traced
 * only where its destructor tears them down (the array at +0x78,
 * whose destructor above is its member's); the rest are not traced. */
class Object016a7c90 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a7c90();

  private:
    u8 unknown24[0x54];
    Array05943280<Element0134aa10> elements78; /* +0x78 */
};

/* derived names: the complete destructor: the array's destructor
 * FUN_0134aa10 runs out of line, then the base's destructor is inlined (its
 * vptr store, then the two names). FUN_002a7960, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
Object016a7c90::~Object016a7c90() {}
