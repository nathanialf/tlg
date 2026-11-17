/* src/include/tlg_game_object016aa098.h: the class whose vtable is at 0x16aa098
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA098_H
#define TLG_GAME_OBJECT016AA098_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived name: two floats, eight of them in Object016aa098 */
struct Pair016aa098 { /* derived name */
    float a;          /* 0.75 of the step's value from the constructor */
    float b;          /* 1.25 of the step's value from the constructor */
};

/* derived names: the class whose vtable is at 0x16aa098
 * (config/vtables.derived.base.txt, stored by its creator FUN_004adaf0, where
 * its constructor is inlined, and by its complete destructor FUN_004adce0,
 * leaf_004adce0.cpp), derived from Object016b9108: its slots 2 to 4 are the
 * base's. 0x90 bytes (`mov edi, 0x90` before operator new in the creator).
 * Its fields are traced only where the creator sets them. */
class Object016aa098 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, eleven
     * floats from +0x24 (one 32-byte constant, a four-byte and an eight-byte
     * store), then the body: eight pairs from +0x50 in a loop, each the
     * step's value (5 over (0.75 i + 2) / (i + 1)) by 0.75 and by 1.25 */
    Object016aa098(const Name &name)
        : Object016b9108(name), unknown24(4.0f), unknown28(4.0f), unknown2c(45.0f), unknown30(4.0f),
          unknown34(6.0f), unknown38(20.0f), unknown3c(0.5f), unknown40(2.0f), unknown44(4.0f)
    {
        unknown48 = 1.25f;
        unknown4c = 0.55f;
        for (int i = 0; i < 8; i++) {
            float value = 5.0f / ((i * 6 / 8.0f + 2.0f) / (i + 1));
            unknown50[i].a = value * 0.75f;
            unknown50[i].b = value * 1.25f;
        }
    }

    virtual ~Object016aa098();

  private:
    float unknown24;           /* +0x24: 4.0 from the constructor */
    float unknown28;           /* +0x28: 4.0 from the constructor */
    float unknown2c;           /* +0x2c: 45.0 from the constructor */
    float unknown30;           /* +0x30: 4.0 from the constructor */
    float unknown34;           /* +0x34: 6.0 from the constructor */
    float unknown38;           /* +0x38: 20.0 from the constructor */
    float unknown3c;           /* +0x3c: 0.5 from the constructor */
    float unknown40;           /* +0x40: 2.0 from the constructor */
    float unknown44;           /* +0x44: 4.0 from the constructor */
    float unknown48;           /* +0x48: 1.25 from the constructor */
    float unknown4c;           /* +0x4c: 0.55 from the constructor */
    Pair016aa098 unknown50[8]; /* +0x50: from the constructor's loop */
};

#endif
