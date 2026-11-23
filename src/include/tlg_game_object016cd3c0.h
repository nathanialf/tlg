/* src/include/tlg_game_object016cd3c0.h: the class whose vtable is at
 * 0x16cd3c0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD3C0_H
#define TLG_GAME_OBJECT016CD3C0_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd3c0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00991920,
 * leaf_00991920.cpp, and its destructor FUN_01382f90), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0xd8 bytes: 0 at +0x24 and +0x28, five locked arrays of counted
 * references from +0x30, an empty Name at +0xa8, 0 at +0xac and +0xb0, 8
 * bytes of zero at +0xb8 and a locked array at +0xc0 (its elements have
 * no destructor; not traced), all from the constructor. The complete
 * destructor, FUN_01382f80, is a jump to the base-object one, FUN_01382f90
 * (the last array's block, the Name, the five arrays last to first through
 * their destructor FUN_0134f620, then the root's destructor in line), and
 * the deleting one, FUN_013830d0, calls it. The base-object destructor
 * costs 300 at the unit stage (the last array's block given back through
 * FUN_00ebf3f0, tlg_game_array.h): implicit, it would carry the inline
 * hint (limit 325) and be inlined into both, so the destructor is declared
 * in the class body, which carries none (limit 225). The class has no key
 * function, so the creator's unit emits the vtable with them. */
class Object016cd3c0 : public Object016b9108 /* derived name */
{
  public:
    Object016cd3c0(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknownac(0), unknownb0(0), unknownb8(0)
    {
    }

    virtual ~Object016cd3c0() {}

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    int unknown28; /* +0x28: 0 from the constructor */
    u8 unknown2c[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> references30; /* +0x30 */
    Array01343a80<Ref00503fb0<Object016b9108>> references48; /* +0x48 */
    Array01343a80<Ref00503fb0<Object016b9108>> references60; /* +0x60 */
    Array01343a80<Ref00503fb0<Object016b9108>> references78; /* +0x78 */
    Array01343a80<Ref00503fb0<Object016b9108>> references90; /* +0x90 */
    Name namea8;                                             /* +0xa8 */
    int unknownac;                                           /* +0xac: 0 from the constructor */
    int unknownb0;                                           /* +0xb0: 0 from the constructor */
    u8 unknownb4[0x4];
    void *unknownb8;              /* +0xb8: null from the constructor */
    Array01343a80<int> unknownc0; /* +0xc0: the element not traced */
};

#endif
