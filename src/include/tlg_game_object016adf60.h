/* src/include/tlg_game_object016adf60.h: the class whose vtable is at 0x16adf60
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADF60_H
#define TLG_GAME_OBJECT016ADF60_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object013671a0.h"

/* derived names: the class whose vtable is at 0x16adf60
 * (config/vtables.derived.base.txt, stored by FUN_007b2850 FUN_007b2a80 FUN_007b2b40), 0x130 bytes
 * (`mov edi, 0x130` before operator new in its creator FUN_007b26f0),
 * derived from Object013671a0 (its destructor 0x7b2a80 tail-calls 0x13671a0,
 * which tail-calls 0xced570: the chain Object013671a0, Object00ced570,
 * Object01343880, Object016b9108; the constructor 0x7b2850 calls 0xcb6310,
 * the root's constructor, with the bases' constructors inlined). Its
 * constructor is not written; its fields are traced only where its
 * destructor tears them down (the counted reference at +0xe8). */
class Object016adf60 : public Object013671a0 /* derived name */
{
  public:
    Object016adf60(const Name &name); /* 0x7b2850, its row named after it (D15) */
    virtual ~Object016adf60();

  private:
    u8 unknown60[0x88];
    Ref00503fb0<Object016b9108> unknowne8; /* +0xe8 */
    u8 unknownf0[0x40];
};

#endif
