/* src/include/tlg_game_object016b1cc0.h: the class whose vtable is at
 * 0x16b1cc0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1CC0_H
#define TLG_GAME_OBJECT016B1CC0_H

#include "tlg_game_object016c7c78.h"

/* derived names: the class whose vtable is at 0x16b1cc0
 * (config/vtables.derived.base.txt, stored by FUN_00a29d80 FUN_00a2a670), derived from Object016c7c78 (tlg_game_object016c7c78.h; itself derived from
 * Object016b9108): slot 5 is its own (declared; their bodies are not written here), the others the base's. Its own fields
 * from +0x50 are traced where its destructor FUN_00a2a670 tears them down
 * (the Names at +0x68, +0x64, +0x58, +0x50) and where the creator
 * FUN_00a29d80 inlines its constructor; their meaning is not traced. 0x70
 * bytes (the creator's `mov edi, 0x70`). */
class Object016b1cc0 : public Object016c7c78 /* derived name */
{
  public:
    /* inlined in the creator FUN_00a29d80: the Names empty (the members),
     * then 2 at +0x54 and the floats at +0x5c and +0x60 zero (the body: the
     * base's stores +0x58, +0x64, +0x68 alone, no run of zeros for a clear,
     * no four stores of one type for the vectoriser) */
    Object016b1cc0(const Name &name) : Object016c7c78(name)
    {
        unknown54 = 2;
        unknown5c = 0.0f;
        unknown60 = 0.0f;
    }

    virtual ~Object016b1cc0();
    virtual void slot5(); /* derived name; FUN_00a2a820, not traced */

  private:
    Name name50;     /* +0x50: released by the destructor (`mov eax, [rbx+0x50]; shl 5`) */
    int unknown54;   /* +0x54: 2 from the constructor; not traced */
    Name name58;     /* +0x58: released by the destructor (`mov eax, [rbx+0x58]; shl 5`) */
    float unknown5c; /* +0x5c: zero from the constructor; not traced */
    float unknown60; /* +0x60: zero from the constructor; not traced */
    Name name64;     /* +0x64: released by the destructor (`mov eax, [rbx+0x64]; shl 5`) */
    Name name68;     /* +0x68: released by the destructor (`mov eax, [rbx+0x68]; shl 5`) */
    u8 unknown6c[0x4];
};

#endif
