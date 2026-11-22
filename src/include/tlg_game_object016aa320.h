/* src/include/tlg_game_object016aa320.h: the class whose vtable is at 0x16aa320
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA320_H
#define TLG_GAME_OBJECT016AA320_H

#include "tlg_game_name.h"
#include "tlg_game_object016aa0d0.h"

/* derived names: the class whose vtable is at 0x16aa320
 * (config/vtables.derived.base.txt, stored by FUN_004b7d80 FUN_004b8390), 0x5f0 bytes
 * (`mov edi, 0x5f0` before operator new in its creator FUN_004b7c20),
 * derived from Object016aa0d0 (its constructor stores that class's vtable
 * first); slots 6, 9 and 11 are its own too (0x40b0, 0x4b8c60, 0x4ba5f0), not declared here. Its constructor
 * FUN_004b7d80 is not written, and its fields are not traced. */
class Object016aa320 : public Object016aa0d0 /* derived name */
{
  public:
    Object016aa320(const Name &name); /* FUN_004b7d80 */
    virtual ~Object016aa320();
    int slot7() const;             /* FUN_004ba620: one point */
    Float4 slot8(int index) const; /* FUN_004ba630: the point at +0xa0 */

  private:
    u8 unknown60[0xa0 - 0x60];
    Float4 unknowna0; /* +0xa0: the point slot 8 hands back */
    u8 unknownb0[0x5f0 - 0xb0];
};

#endif
