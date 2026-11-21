/* The class whose vtable is at 0x16b5c48 (config/vtables.derived.base.txt;
 * stored by FUN_00b404d0 and its destructor 0x1397620) and its derived class
 * at 0x16b5ce8, over Class137ba70 (tlg_game_multibase.h; all names
 * derived). */
#ifndef TLG_GAME_OBJECT01397620_H
#define TLG_GAME_OBJECT01397620_H

#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_multibase.h"

/* 0x68 bytes: Class137ba70's slots and slot 9 of its own (0x42d0's `return
 * 0`), two counted references at +0x58 and +0x60. Its destructor is
 * 0x1397620 (its row named for it, D15): the vptrs stored, the references
 * released last to first, then Class137ba70's bases'; slot 0 of the vtable
 * (0x1397a90) runs it as a tail call. */
class Object01397620 /* derived name */ : public Class137ba70
{
  public:
    virtual ~Object01397620();
    virtual int slot9();              /* derived name; 0x42d0, not traced */
    int FUN_00004340(int mask) const; /* slot 6, 0xb406d0 */

  protected:
    Class137ba70 *child40; /* +0x40, derived name: asked when bit 0 is set */
    Class137ba70 *child48; /* +0x48, derived name: asked when bit 2 is set */
    u8 unknown50[0x8];
    Ref00503fb0<Class137ba70> unknown58; /* +0x58 */
    Ref00503fb0<Class137ba70> unknown60; /* +0x60 */
};

/* The class whose vtable is at 0x16b5ce8 (config/vtables.derived.base.txt;
 * stored by FUN_00b40d10): slots 5, 6 and 9 its own (FUN_00b41640,
 * FUN_00b414a0, FUN_00b40f10), an array of counted references at +0x68 and
 * a counted reference at +0x80. Its destructor (0x139b1f0, slot 0) stores
 * the vptrs (+0x28 and +0x30 in one store), releases the reference, calls
 * the array's destructor, then the base's. */
class Object016b5ce8 /* derived name */ : public Object01397620
{
  public:
    virtual ~Object016b5ce8();
    int FUN_00004340(int mask) const; /* slot 6, 0xb414a0 */

  private:
    Object0134f620 unknown68;            /* +0x68 */
    Ref00503fb0<Class137ba70> unknown80; /* +0x80 */
};

#endif
