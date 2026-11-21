/* src/include/tlg_game_object016b0468.h: the class whose vtable is at 0x16b0468
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0468_H
#define TLG_GAME_OBJECT016B0468_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_target004ad600.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b0468
 * (config/vtables.derived.base.txt, stored by its creator FUN_008edda0, where
 * its constructor is inlined, and by its complete destructor 0x8edf10),
 * derived from Object01343880. 0x60 bytes (`mov edi, 0x60` before operator
 * new in the creator). Its complete destructor (leaf_008edf10.cpp, the
 * class's key function): while the object is registered (the int at +0x3c)
 * and the record at +0x80 of the object at 0x57c9390 exists, it hands the
 * object to that record (FUN_008e1020) and clears +0x3c and +0x5c; while
 * registered it stores 1 to +0x58 either way; then the five Names from +0x44
 * are released last first and the base's destructor runs; the deleting one
 * 0x8ee0d0 calls it. The other fields are not traced. */
class Object016b0468 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: Object01343880's, the vptr, then zero from
     * +0x34 to the end (two overlapping 32-byte stores) */
    Object016b0468(const Name &name)
        : Object01343880(name), unknown34(0), unknown38(0), registered(0), unknown40(0),
          unknown58(0), unknown5c(0)
    {
    }

    virtual ~Object016b0468();

  private:
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    int unknown38;   /* +0x38: zero from the constructor; not traced */
    int registered;  /* +0x3c: handed to FUN_008e1020 by the destructor when set */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    Name names44[5]; /* +0x44: zero from the constructor */
    int unknown58;   /* +0x58: 1 from the destructor while registered */
    int unknown5c;   /* +0x5c: cleared with +0x3c */
};

#endif
