/* src/include/tlg_game_object016aeed0.h: the class whose vtable is at 0x16aeed0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEED0_H
#define TLG_GAME_OBJECT016AEED0_H

#include "tlg_game_array.h"
#include "tlg_game_list0138c3b0.h"
#include "tlg_game_name.h"
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16aeed0
 * (config/vtables.derived.base.txt, stored by FUN_00844410 FUN_00844590), 0x120 bytes
 * (`mov edi, 0x120` before operator new in its creator FUN_00840e30),
 * derived from Object016c81c0 (its constructor 0x844410 first calls 0xd68470, that
 * class's constructor). Its constructor is not written; its fields are
 * traced where its destructor FUN_00844590, the key function
 * (leaf_00844590.cpp), tears them down. */
class Object016aeed0 : public Object016c81c0 /* derived name */
{
  public:
    Object016aeed0(const Name &name); /* 0x844410, its row named after it (D15) */
    virtual ~Object016aeed0();

  private:
    List0138c3b0 list98; /* +0x98: emptied first by the destructor */
    Array05943280<void *>
        arrayd0; /* +0xd0: emptied to no block by the destructor; its elements not traced */
    u8 unknowne8[0x8];
    Name names[8];  /* +0xf0 to +0x10c: released last first; not traced */
    int unknown110; /* +0x110: not traced */
    Name name114;   /* +0x114: not traced */
    u8 unknown118[0x8];
};

#endif
