/* src/include/tlg_game_object016a8030.h: the class whose vtable is at
 * 0x16a8030 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A8030_H
#define TLG_GAME_OBJECT016A8030_H

#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a8030
 * (config/vtables.derived.base.txt, stored by FUN_002bf920 FUN_002bfaa0 FUN_002bfb60), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_002bfaa0 tears them down
 * (the Name at +0x24); the others where its constructor FUN_002bf920 sets them. 0xa0 bytes
 * (`mov edi, 0xa0` before operator new in its creator FUN_002bcd10). */
class Object016a8030 : public Object016b9108 /* derived name */
{
  public:
    Object016a8030(const Name &name); /* FUN_002bf920 */
    virtual ~Object016a8030();

  private:
    Name name24;     /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    int unknown28;   /* +0x28: 10 from the constructor; not traced */
    float unknown2c; /* +0x2c: 2.6 from the constructor; not traced */
    float unknown30; /* +0x30: 2.4 from the constructor; not traced */
    float unknown34; /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: zero from the constructor; not traced */
    float unknown3c; /* +0x3c: zero from the constructor; not traced */
    float unknown40; /* +0x40: zero from the constructor; not traced */
    float unknown44; /* +0x44: 3.8 from the constructor; not traced */
    float unknown48; /* +0x48: 2.0 from the constructor; not traced */
    int unknown4c;   /* +0x4c: zero from the constructor; not traced */
    int unknown50;   /* +0x50: zero from the constructor; not traced */
    int unknown54;   /* +0x54: 1 from the constructor; not traced */
    float unknown58; /* +0x58: 1.5 from the constructor; not traced */
    float unknown5c; /* +0x5c: 1.25 from the constructor; not traced */
    int unknown60;   /* +0x60: 6 from the constructor; not traced */
    int unknown64;   /* +0x64: -1 from the constructor; not traced */
    int unknown68;   /* +0x68: 1 from the constructor; not traced */
    /* +0x70: (0.3, 0.4, 0.3, 1.0) from the constructor, one aligned store
     * (`vmovaps [rbx+0x70]`); not traced */
    Float4A unknown70;
    float unknown80; /* +0x80: 0.65 from the constructor; not traced */
    float unknown84; /* +0x84: 0.125 from the constructor; not traced */
    int unknown88;   /* +0x88: zero from the constructor; not traced */
    float unknown8c; /* +0x8c: 60.0 from the constructor; not traced */
    int unknown90;   /* +0x90: zero from the constructor; not traced */
    float unknown94; /* +0x94: 3.0 from the constructor; not traced */
    float unknown98; /* +0x98: 3.0 from the constructor; not traced */
};

#endif
