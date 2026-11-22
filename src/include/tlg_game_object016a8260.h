/* src/include/tlg_game_object016a8260.h: the class whose vtable is at 0x16a8260
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8260_H
#define TLG_GAME_OBJECT016A8260_H

#include "tlg_game_name.h"
#include "tlg_game_object016aed28.h"

/* derived names: the class whose vtable is at 0x16a8260
 * (config/vtables.derived.base.txt, stored by FUN_002eec50), 0x5a0 bytes
 * (`mov edi, 0x5a0` before operator new in its creator FUN_002eeaf0),
 * derived from Object016aed28 (tlg_game_object016aed28.h). Its constructor
 * FUN_002eec50 is not written, and its own fields are not traced. */
class Object016a8260 : public Object016aed28 /* derived name */
{
  public:
    Object016a8260(const Name &name); /* FUN_002eec50 */
    virtual ~Object016a8260();
    /* slot 48, FUN_002eed30: the five words at +0x584 cleared (one 16-byte
     * store and one 4-byte store) */
    virtual void slot48(); /* derived name */

  private:
    u8 unknown580[0x4];

  public:
    int unknown584; /* +0x584 */
    int unknown588; /* +0x588 */
    int unknown58c; /* +0x58c */
    int unknown590; /* +0x590 */
    int unknown594; /* +0x594 */

  private:
    u8 unknown598[0x8];
};

#endif
