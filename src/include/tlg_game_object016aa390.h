/* src/include/tlg_game_object016aa390.h: the class whose vtable is at 0x16aa390
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA390_H
#define TLG_GAME_OBJECT016AA390_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aa390
 * (config/vtables.derived.base.txt, stored by FUN_004bbfd0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. 0x40 bytes (`mov edi, 0x40` before operator new in its creator
 * FUN_004bbfd0); its fields are traced only where the creator sets them. */
class Object016aa390 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_004bbfd0: the base built from the name, then
     * zero at +0x24, then six floats (one 16-byte constant and one eight-byte immediate) */
    Object016aa390(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0.65f), unknown2c(0.75f), unknown30(0.6f),
          unknown34(-0.1f), unknown38(0.1f), unknown3c(0.8f)
    {
    }

    virtual ~Object016aa390();

  private:
    int unknown24;   /* +0x24: 0 from the constructor */
    float unknown28; /* +0x28: 0.65 from the constructor */
    float unknown2c; /* +0x2c: 0.75 from the constructor */
    float unknown30; /* +0x30: 0.6 from the constructor */
    float unknown34; /* +0x34: -0.1 from the constructor */
    float unknown38; /* +0x38: 0.1 from the constructor */
    float unknown3c; /* +0x3c: 0.8 from the constructor */
};

#endif
