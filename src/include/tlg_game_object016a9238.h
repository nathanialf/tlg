/* src/include/tlg_game_object016a9238.h: the class whose vtable is at 0x16a9238
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9238_H
#define TLG_GAME_OBJECT016A9238_H

#include "tlg_game_name.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016a9238 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16a9238
 * (config/vtables.derived.base.txt, stored by FUN_003e7b30 FUN_003e7ca0), 0xc0 bytes
 * (`mov edi, 0xc0` before operator new in its creator FUN_003e79d0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_003e7b30 is not written. Its complete destructor FUN_003e7ca0 closes
 * the pool its reference at +0xb0 holds and empties the reference, the
 * array at +0x38 is destroyed (0x134f620) and the base's part inlined;
 * FUN_003e7ec0, slot 1, is the deleting one. The rest is not traced. */
class Object016a9238 : public Object016b9108 /* derived name */
{
  public:
    Object016a9238(const Name &name); /* FUN_003e7b30 */
    virtual ~Object016a9238();

  private:
    u8 unknown24[0x14];
    Object0134f620 references38; /* +0x38 */
    u8 unknown50[0x60];
    /* +0xb0: a counted reference to a pool, closed and emptied by the
     * destructor (FUN_003e7ca0) */
    AtomicRef0045c470<Pool016a9238> pool;
    u8 unknownb8[0x8];
};

#endif
