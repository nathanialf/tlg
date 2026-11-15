/* src/include/tlg_game_object016a7d48.h: the class whose vtable is at
 * 0x16a7d48 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7D48_H
#define TLG_GAME_OBJECT016A7D48_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16a7d48
 * (config/vtables.derived.base.txt, stored by FUN_002a89e0 FUN_002a8ab0 FUN_002a8b80), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_002a8ab0 tears them down
 * (the block at +0x28), the others where its constructor FUN_002a89e0 sets
 * them. 0x60 bytes (`mov edi, 0x60` before operator new in its creator
 * FUN_002a8880). */
class Object016a7d48 : public Object016b9108 /* derived name */
{
  public:
    Object016a7d48(const Name &name); /* FUN_002a89e0 */
    virtual ~Object016a7d48();

  private:
    u8 unknown24[0x4];
    /* +0x28: a growable array of aligned four-float values: emptied by the
     * constructor with a capacity of 0 (the reallocation passes the alignment
     * 0x10: `mov ecx, 0x10` / `mov edx, 0x10`), its block released by the
     * destructor (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    Array01343a80<Float4A> array28;
    /* +0x40: (0, 0, 0, 1.0) from the constructor, one aligned store
     * (`vmovaps [rbx+0x40]`); not traced */
    Float4A unknown40;
    float unknown50; /* +0x50: 0.1 from the constructor; not traced */
};

/* derived name: the complete destructor: the body is empty; the array's
 * block is released, then the base's destructor is inlined (its vptr store,
 * then the two names). Defined inline after the class, it is still the key
 * function: the units that include this header emit the vtable and both
 * destructors; FUN_002a8b80, slot 1, the deleting one, holds the whole body
 * (198 bytes, as round 294D's 0xa3- to 0xec-byte pairs). */
inline Object016a7d48::~Object016a7d48() {}

#endif
