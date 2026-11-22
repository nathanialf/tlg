/* src/include/tlg_game_object016b64f8.h: the class whose vtable is at
 * 0x16b64f8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B64F8_H
#define TLG_GAME_OBJECT016B64F8_H

#include "tlg_game_name.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016ba7f8.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b64f8 : public Pool01343090
{
};

/* derived names: the class whose vtable is at 0x16b64f8
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b4aed0, a
 * 0x1c0-byte object, and its destructor FUN_00b4b060), derived from
 * Object016ba7f8 (the destructor tail-calls 0xd5c340). Slot 8 is
 * FUN_00b4b950 (leaf_00b4b950.cpp), which the destructor runs first; then
 * the pool at +0x190 is given up and the five Names from +0x1a0 released.
 * The rest is not traced. */
class Object016b64f8 : public Object016ba7f8 /* derived name */
{
  public:
    virtual ~Object016b64f8();

    u8 unknown174[0xc];
    int unknown180; /* +0x180 */
    int unknown184; /* +0x184 */
    u8 unknown188[0x8];
    PoolRef01343090<Pool016b64f8> pool; /* +0x190 */
    u8 unknown198[0x8];
    Name name1a0; /* +0x1a0 */
    Name name1a4; /* +0x1a4 */
    Name name1a8; /* +0x1a8 */
    Name name1ac; /* +0x1ac */
    Name name1b0; /* +0x1b0 */
    u8 unknown1b4[0xc];
};

/* slot 8 (leaf_00b4b950.cpp) */
void FUN_00b4b950(Object016b64f8 *self); /* derived name */

#endif
