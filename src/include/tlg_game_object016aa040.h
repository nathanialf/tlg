/* src/include/tlg_game_object016aa040.h: the class whose vtable is at
 * 0x16aa040 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA040_H
#define TLG_GAME_OBJECT016AA040_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16aa040
 * (config/vtables.derived.base.txt, stored by its creator FUN_004ad800, where
 * its constructor is inlined after Object01343880's), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's).
 * 0x60 bytes (`mov edi, 0x60` before operator new in the creator). Its own
 * fields are traced only where the creator sets them. The destructor is the
 * class's key function (leaf_004ad980.cpp). */
class Object016aa040 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 1.0
     * at +0x54, then the eight floats from +0x34 set in the body, one store
     * after it (`mov dword [r15+0x54], 1.0; vmovups [r15+0x34], ymm0` of a
     * 32-byte constant) */
    Object016aa040(const Name &name) : Object01343880(name), unknown54(1.0f)
    {
        unknown34 = 0.0f;
        unknown38 = 0.1f;
        unknown3c = 1.0f;
        unknown40 = 0.25f;
        unknown44 = 1.0f;
        unknown48 = 1.0f;
        unknown4c = 3.0f;
        unknown50 = 0.0f;
    }

    virtual ~Object016aa040();

  private:
    float unknown34; /* +0x34: 0.0 from the constructor; not traced */
    float unknown38; /* +0x38: 0.1 from the constructor; not traced */
    float unknown3c; /* +0x3c: 1.0 from the constructor; not traced */
    float unknown40; /* +0x40: 0.25 from the constructor; not traced */
    float unknown44; /* +0x44: 1.0 from the constructor; not traced */
    float unknown48; /* +0x48: 1.0 from the constructor; not traced */
    float unknown4c; /* +0x4c: 3.0 from the constructor; not traced */
    float unknown50; /* +0x50: 0.0 from the constructor; not traced */
    float unknown54; /* +0x54: 1.0 from the constructor; not traced */
    u8 unknown58[0x8];
};

#endif
