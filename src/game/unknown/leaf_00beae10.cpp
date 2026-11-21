/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived name: an object the array below refers to: a pointer at +0x30
 * that the holder's destructor clears (`mov qword [rcx+0x30], 0`); the
 * rest is not traced */
class Child00beae10 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0xc];
    Object016b9108 *owner; /* +0x30 */
};

/* derived names: the class whose vtable is at 0x16b7ba0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00bea370
 * and its complete destructor FUN_00beae10), derived from Object016b9108:
 * a Name at +0x28 and an array of counted references at +0x30. The
 * destructor clears the pointer at +0x30 of each object the array refers
 * to, then empties the array to no capacity; then the members are torn
 * down, last first, and the base's destructor is inlined (its vptr store,
 * then the two names). FUN_00beb030, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable.
 * The other fields are not traced. */
class Object016b7ba0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7ba0();

  private:
    u8 unknown24[0x4];
    Name name28;             /* +0x28 */
    Object0134f620 children; /* +0x30 */
};

// NONMATCHING: the base holds the array's emptying inlined (the loop over the references, then the block given
// back with no capacity); the module calls Array05943280<Ref00503fb0<Object016b9108>>::clear(), which has other
// callers, and the deleting destructor then inlines this one (leaf_00ae7530.cpp's residual)
Object016b7ba0::~Object016b7ba0()
{
    for (int i = 0; i < children.size(); ++i)
        static_cast<Child00beae10 *>(children.at(i).get())->owner = 0;
    children.clear();
}
