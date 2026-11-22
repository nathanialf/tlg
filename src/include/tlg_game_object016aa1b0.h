/* src/include/tlg_game_object016aa1b0.h: the class whose vtable is at 0x16aa1b0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA1B0_H
#define TLG_GAME_OBJECT016AA1B0_H

#include "tlg_game_name.h"
#include "tlg_game_object016aa0d0.h"

/* derived names: the class whose vtable is at 0x16aa1b0
 * (config/vtables.derived.base.txt, stored by FUN_004b16e0 FUN_004b1df0), 0x700 bytes
 * (`mov edi, 0x700` before operator new in its creator FUN_004b1580),
 * derived from Object016aa0d0 (its constructor stores that class's vtable
 * first); slots 9 and 11 are its own too (0x4b2270, 0x4b32c0), not declared here. Its constructor
 * FUN_004b16e0 is not written, and its fields are not traced. */
class Object016aa1b0 : public Object016aa0d0 /* derived name */
{
  public:
    Object016aa1b0(const Name &name); /* FUN_004b16e0 */
    virtual ~Object016aa1b0();
    int slot7() const;             /* FUN_004b3bd0: four points */
    Float4 slot8(int index) const; /* FUN_004b3be0 */
    void slot10();                 /* FUN_004b32b0, empty */

  private:
    /* the points slot 8 hands back: 32-byte entries from +0x2d0, the first
     * 16 bytes the point (`vmovups`); the rest is not traced */
    struct Entry004b3be0 { /* derived name */
        Float4 point;
        u8 unknown10[0x10];
    };

    u8 unknown60[0x2d0 - 0x60];
    Entry004b3be0 entries[0x10]; /* +0x2d0; how many is not traced */
    u8 unknown4d0[0x700 - 0x4d0];
};

#endif
