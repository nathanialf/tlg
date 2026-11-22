/* src/include/tlg_game_object016b8fd0.h: the classes whose vtables are at
 * 0x16b8fd0 and 0x16b8828 (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT016B8FD0_H
#define TLG_GAME_OBJECT016B8FD0_H

#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object00ca38f0.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16b8fd0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00cb2fb0),
 * derived from Object00ca38f0. Its destructor (its key function) calls
 * FUN_00cb33a0 on the object, then the counted reference at +0xb8 is
 * released and the base's destructor tail-called (FUN_00cb32e0; FUN_00cb3500
 * the deleting one). The other fields are not traced. */
class Object016b8fd0 : public Object00ca38f0 /* derived name */
{
  public:
    virtual ~Object016b8fd0();

    void FUN_00cb33a0(); /* derived name; not traced */

  private:
    u8 unknown8[0xb0];
    Ref00503fb0<Object016b9108> unknownb8; /* +0xb8 */
};

/* derived name: the object at 0x593a938 that FUN_00c822d0 is called on with
 * an Object016b8828 being destroyed; not traced */
struct Registry0593a938; /* derived name */

extern Registry0593a938 *D_593a938; /* derived name */

class Object016b8828;
void FUN_00c822d0(Registry0593a938 *registry, Object016b8828 *object); /* derived name */

/* derived names: the class whose vtable is at 0x16b8828
 * (config/vtables.derived.base.txt, stored by its creator FUN_00c81f90),
 * derived from Object016b85e0. Its destructor (its key function) hands the
 * object to FUN_00c822d0 when the object at 0x593a938 exists, then the
 * counted reference at +0x280 is released and the base's destructor
 * tail-called (FUN_00c82210; FUN_00c82430 the deleting one). The other fields
 * are not traced. */
class Object016b8828 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b8828();

  private:
    u8 unknown238[0x48];
    Ref00503fb0<Object016b9108> unknown280; /* +0x280 */
};

#endif
