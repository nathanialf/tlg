/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b2060 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b2060
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a52b70
 * and its complete destructor FUN_00a52ce0), derived from Object016b85e0:
 * a counted reference to a pool at +0x250. Slots 2 to 7 are the base's;
 * this class's slots 8 and 9 (the empty body at 0x1af750 in the base) are
 * FUN_00a52f40 and FUN_00a53160, and it adds slots 10 and 11. The destructor gives the pool up
 * (PoolRef01343090::shutdown()) and calls slot 9 through the vtable; then
 * the reference is released and the base's destructor 0xc55550 runs as a
 * tail call. FUN_00a52ea0, slot 1, is the deleting one. The destructor is
 * the class's key function, so this file emits the vtable. The other
 * members are not traced. */
class Object016b2060 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b2060();
    virtual void slot8();  /* derived name; FUN_00a52f40, not traced */
    virtual void slot9();  /* derived name; FUN_00a53160, not traced */
    virtual void slot10(); /* derived name; FUN_00a52f30 (an empty body), not traced */
    virtual void slot11(); /* derived name; FUN_00a52ec0 */

  private:
    u8 unknown238[0x18];
    PoolRef01343090<Pool016b2060> pool; /* +0x250 */
};

Object016b2060::~Object016b2060()
{
    pool.shutdown();
    slot9();
}

/* derived names: the record at +0x78 of the object at 0x57c9390, as slot 11
 * reads it */
struct Mode00a52ec0 { /* derived name */
    u8 unknown0[0x9c];
    int unknown9c; /* +0x9c */
};

struct Game00a52ec0 { /* derived name */
    u8 unknown0[0x78];
    Mode00a52ec0 *unknown78; /* +0x78 */
};

extern Game00a52ec0 *D_57c9390;

/* Slot 11: for an object with bit 0 of +0x24 set and a parent, when the
 * pool is held and the record at +0x78 of 0x57c9390 has its +0x9c set, the
 * pool's word at +0x48 reset */
// NONMATCHING: the base then walks the parent's type chain to the type at
// 0x5827d10 (::isKindOf inlined, its result unused: 0xa52f0a to 0xa52f2b),
// the open class of a list walk whose result is unused; not written
void Object016b2060::slot11()
{
    if ((unknown24 & 1) == 0 || !parent)
        return;
    Pool016b2060 *held = pool.get();
    if (!held)
        return;
    Mode00a52ec0 *mode = D_57c9390->unknown78;
    if (!mode || !mode->unknown9c)
        return;
    held->resetUnknown48();
}
