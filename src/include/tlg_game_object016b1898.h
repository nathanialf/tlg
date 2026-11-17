/* src/include/tlg_game_object016b1898.h: the class whose vtable is at 0x16b1898
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1898_H
#define TLG_GAME_OBJECT016B1898_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108kind.h"

/* derived names: the class whose vtable is at 0x16b1898
 * (config/vtables.derived.base.txt, stored by its creator FUN_009b4360, where its
 * constructor is inlined), derived from Object016b9108Kind: the creator
 * stores 0 at +0x24 before the vptr, the kind its derived classes leave as
 * it is. 0x40 bytes (`mov edi, 0x40` before operator new in the creator).
 * Its fields are traced only where the creator sets them; its destructor is
 * not written. */
class Object016b1898 : public Object016b9108Kind /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name (0 at +0x24),
     * the vptr, zero from +0x28 (one 16-byte store) and at +0x38 */
    Object016b1898(const Name &name)
        : Object016b9108Kind(name), unknown28(0), unknown2c(0), unknown30(0), unknown34(0),
          unknown38(0)
    {
    }

    virtual ~Object016b1898();

  private:
    int unknown28; /* +0x28: 0 from the constructor */
    int unknown2c; /* +0x2c: 0 from the constructor */
    int unknown30; /* +0x30: 0 from the constructor */
    int unknown34; /* +0x34: 0 from the constructor */
    int unknown38; /* +0x38: 0 from the constructor */
};

#endif
