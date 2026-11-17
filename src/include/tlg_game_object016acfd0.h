/* src/include/tlg_game_object016acfd0.h: the class whose vtable is at 0x16acfd0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACFD0_H
#define TLG_GAME_OBJECT016ACFD0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16acfd0
 * (config/vtables.derived.base.txt, stored by its creator FUN_007781c0, where
 * its constructor is inlined after Object00774560's, 0x774370, called out of
 * line), derived from Object00774560. 0x110 bytes (`mov edi, 0x110`
 * before operator new in the creator). Its fields are traced only where the
 * creator sets them; its destructor is not written. */
class Object016acfd0 : public Object00774560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, 0.95 at +0xfc, (0, 1, 0, 0) at +0x100,
     * and the body's 0.2 at the base's +0x7c */
    Object016acfd0(const Name &name) : Object00774560(name), unknown100(0.0f, 1.0f, 0.0f, 0.0f)
    {
        unknown7c = 0.2f;
        unknownfc = 0.95f;
    }

    virtual ~Object016acfd0();

  private:
    float unknownfc;    /* +0xfc: 0.95 from the constructor */
    Float4A unknown100; /* +0x100: (0, 1, 0, 0) from the constructor; not traced */
};

#endif
