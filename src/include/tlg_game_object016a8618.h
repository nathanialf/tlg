/* src/include/tlg_game_object016a8618.h: the class whose vtable is at 0x16a8618
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8618_H
#define TLG_GAME_OBJECT016A8618_H

#include "tlg_game_name.h"
#include "tlg_game_block.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8618
 * (config/vtables.derived.base.txt, stored by FUN_00325a50 FUN_00325ed0), 0x100 bytes
 * (`mov edi, 0x100` before operator new in its creator FUN_003258f0),
 * derived from Object016b9108 (its creator leaves the type's record for
 * that constructor); the classes between are not traced. Its constructor
 * FUN_00325a50 is not written; its members are the ones its destructor
 * 0x325ed0 releases (leaf_00325ed0.cpp), in the reverse of their order. */
/* derived name: the kind of pool it refers to; nothing of it is traced but
 * its base */
class Pool016a8618 : public Pool01343090
{
};

class Object016a8618 : public Object016b9108 /* derived name */
{
  public:
    Object016a8618(const Name &name); /* FUN_00325a50 */
    virtual ~Object016a8618();

  private:
    u8 unknown24[0x4c];
    Ref00503fb0<Object016b9108> held70; /* +0x70 */
    Object0134f620 array78;             /* +0x78 */
    Object0134f620 array90;             /* +0x90 */
    Object0134f620 arraya8;             /* +0xa8 */
    Object0134f620 arrayc0;             /* +0xc0 */
    OwnedBlock05943280 blockd8;         /* +0xd8 */
    u8 unknowne0[0x18];
    PoolRef01343090<Pool016a8618> pool; /* +0xf8 */
};

#endif
