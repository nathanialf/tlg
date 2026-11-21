/* src/include/tlg_game_object016c77b8.h: the class whose vtable is at
 * 0x16c77b8 and the class at 0x16abea0 derived from it (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C77B8_H
#define TLG_GAME_OBJECT016C77B8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016c77b8 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16c77b8
 * (config/vtables.derived.base.txt, stored by its complete destructor
 * 0x6180c0 and by the constructor of the class at 0x16abea0, 0x6187d0),
 * derived from Object016b9108 (its destructor ends in that class's: the
 * vptr 0x16b9118). 0x30 bytes of data: a counted reference to a pool at
 * +0x28, which the destructor gives up (PoolRef01343090::shutdown()) before
 * the reference itself is released (leaf_006180c0.cpp). Slot 5,
 * FUN_006182f0, is its own (both vtables hold it). */
class Object016c77b8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c77b8();   /* 0x6180c0 */
    virtual void FUN_006182f0(); /* derived name; slot 5 */

  private:
    u8 unknown24[0x4];
    PoolRef01343090<Pool016c77b8> pool; /* +0x28 */
};

/* derived names: the class whose vtable is at 0x16abea0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_006187d0
 * and its complete destructor 0x618980): a name at +0x30 (slot 6,
 * FUN_00618b00, reads its record) and two counted references at +0x38 and
 * +0x40, not traced further. */
class Object016abea0 : public Object016c77b8 /* derived name */
{
  public:
    virtual ~Object016abea0();

  private:
    Name name30;                        /* +0x30 */
    Ref00503fb0<Object016b9108> held38; /* +0x38 */
    Ref00503fb0<Object016b9108> held40; /* +0x40: the first member released */
};

#endif
