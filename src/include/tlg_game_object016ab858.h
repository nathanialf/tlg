/* src/include/tlg_game_object016ab858.h: the class whose vtable is at
 * 0x16ab858 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB858_H
#define TLG_GAME_OBJECT016AB858_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16ab858
 * (config/vtables.derived.base.txt, stored by its creator FUN_0057efb0, where
 * its constructor is inlined after Object016b9108Kind's), derived from Object016b9108Kind. 0x78 bytes
 * (`mov edi, 0x78` before operator new in the creator). Its fields are traced only where the creator sets them; its destructor is not written, so nothing here emits the vtable. */
class Object016ab858 : public Object016b9108Kind /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name (0 at +0x24), the vptr,
     * the arrays at +0x48 and +0x60 (each owner index from the thread's
     * heap, each lock free); then the body: 0x6b at +0x24 and the zeros
     * after it in one store, 1.0 at +0x34 and +0x3c, 1 at +0x40 (every field
     * before the arrays is stored after them) */
    Object016ab858(const Name &name) : Object016b9108Kind(name)
    {
        kind = 0x6b;
        unknown28 = 0;
        unknown2c = 0;
        unknown30 = 0;
        unknown34 = 1.0f;
        unknown38 = 0.0f;
        unknown3c = 1.0f;
        unknown40 = 1;
        unknown44 = 0;
    }

    virtual ~Object016ab858();

  private:
    int unknown28;                 /* +0x28: 0 from the constructor */
    int unknown2c;                 /* +0x2c: 0 from the constructor */
    int unknown30;                 /* +0x30: 0 from the constructor */
    float unknown34;               /* +0x34: 1.0 from the constructor */
    float unknown38;               /* +0x38: 0.0 from the constructor */
    float unknown3c;               /* +0x3c: 1.0 from the constructor */
    int unknown40;                 /* +0x40: 1 from the constructor */
    int unknown44;                 /* +0x44: 0 from the constructor */
    Array01343a80<void *> array48; /* +0x48: empty from the constructor; its elements not traced */
    Array01343a80<void *> array60; /* +0x60: empty from the constructor; its elements not traced */
};

#endif
