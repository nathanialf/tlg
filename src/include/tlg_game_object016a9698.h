/* src/include/tlg_game_object016a9698.h: the class whose vtable is at 0x16a9698
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9698_H
#define TLG_GAME_OBJECT016A9698_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9698
 * (config/vtables.derived.base.txt, stored by 0x3f64c0 0x3f6630; its constructor
 * is inlined in its creator FUN_003f64c0), derived from Object016b9108 (the creator calls
 * that class's constructor 0xcb6310 first). 0x90 bytes (`mov edi,
 * 0x90` before operator new in the creator). Its fields are traced only
 * where the creator sets them; its destructor (0x3f6630, slot 0) releases
 * the counted references of the array at +0x58, last to first, then those
 * of the array at +0x28 (two loops: two arrays). */
class Object016a9698 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the 96 bytes from +0x28 cleared (three `vmovups` of ymm0), then -1 at +0x88 */
    Object016a9698(const Name &name) : Object016b9108(name), unknown28(), unknown58(), unknown88(-1)
    {
    }

    virtual ~Object016a9698();

  private:
    u8 unknown24[0x4];
    Ref00503fb0<Object016b9108> unknown28[6]; /* +0x28: empty from the constructor */
    Ref00503fb0<Object016b9108> unknown58[6]; /* +0x58: empty from the constructor */
    int unknown88;                            /* +0x88: -1 from the constructor */
    u8 unknown8c[0x4];
};

#endif
