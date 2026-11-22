/* src/include/tlg_game_object016ac7c8.h: the class whose vtable is at 0x16ac7c8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AC7C8_H
#define TLG_GAME_OBJECT016AC7C8_H

#include "tlg_game_array.h"
#include "tlg_game_object00ced570.h"
#include "tlg_types.h"

/* derived names: the class whose vtable is at 0x16ac7c8
 * (config/vtables.derived.base.txt, stored by FUN_00704230 FUN_00712f40),
 * over Object00ced570 (slot 7, 0x719ab0, runs that class's slot 7,
 * 0xcebe40, first).
 * Its constructor and its destructor (slot 0, 23,170 bytes) are not
 * written; of its fields only the one slot 10 reads is traced. */
class Object016ac7c8 : public Object00ced570 /* derived name */
{
  public:
    virtual ~Object016ac7c8();

    unsigned FUN_00724a90(Array05943280<Object016b9108 *> &objects) const;

    /* the object at +0xb38, by value (slot 10 reads it before the array
     * grows) */
    Object016b9108 *object() const /* derived name */
    {
        return unknownb38;
    }

  private:
    u8 unknown60[0xad8];
    Object016b9108 *unknownb38; /* +0xb38: what slot 10 hands out; not traced */
};

#endif
