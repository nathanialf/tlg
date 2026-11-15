/* src/include/tlg_game_object016a7db8.h: the class whose vtable is at
 * 0x16a7db8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7DB8_H
#define TLG_GAME_OBJECT016A7DB8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_math.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7db8
 * (config/vtables.derived.base.txt, stored by FUN_002a94b0 FUN_002a9720 FUN_002a9970), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_002a9720 tears them down
 * (the blocks at +0x138, +0x120, +0xc8, +0xb0, +0x98, +0x80, +0x68); the rest are not traced. */
class Object016a7db8 : public Object016b9108 /* derived name */
{
  public:
    Object016a7db8(const Name &name); /* FUN_002a94b0 */
    virtual ~Object016a7db8();

  private:
    u8 unknown24[0xc];
    Float4A unknown30; /* +0x30: (0, 0, 0, 1) from the constructor; not traced */
    Float4A unknown40; /* +0x40: (0, 0, 0, 1) from the constructor; not traced */
    Float4A unknown50; /* +0x50: (0, 0, 0, 1) from the constructor; not traced */
    int unknown60;     /* +0x60: zero from the constructor; not traced */
    u8 unknown64[0x4];
    Array01343a80<u32>
        array68; /* +0x68: an array whose elements need no destructor, emptied by the constructor */
    Array01343a80<u32>
        array80; /* +0x80: an array whose elements need no destructor, emptied by the constructor */
    Array01343a80<u32>
        array98; /* +0x98: an array whose elements need no destructor, emptied by the constructor */
    Array01343a80<u32>
        arrayb0; /* +0xb0: an array whose elements need no destructor, emptied by the constructor */
    Array01343a80<u32>
        arrayc8; /* +0xc8: an array whose elements need no destructor, emptied by the constructor */
    int unknowne0; /* +0xe0: zero from the constructor; not traced */
    u8 unknowne4[0xc];
    Float4A unknownf0; /* +0xf0: (0, 0, 0, 1) from the constructor; not traced */
    int unknown100;    /* +0x100: zero from the constructor; not traced */
    float unknown104;  /* +0x104: zero from the constructor; not traced */
    float unknown108;  /* +0x108: zero from the constructor; not traced */
    float unknown10c;  /* +0x10c: 1.0 from the constructor; not traced */
    float unknown110;  /* +0x110: zero from the constructor; not traced */
    int unknown114;    /* +0x114: zero from the constructor; not traced */
    int unknown118;    /* +0x118: zero from the constructor; not traced */
    float unknown11c;  /* +0x11c: 1.0 from the constructor; not traced */
    Array01343a80<u32>
        array120; /* +0x120: an array whose elements need no destructor, emptied by the constructor */
    Array01343a80<u32>
        array138; /* +0x138: an array whose elements need no destructor, emptied by the constructor */
};

#endif
