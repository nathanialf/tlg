/* src/include/tlg_game_object016aeab0.h: the class whose vtable is at
 * 0x16aeab0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEAB0_H
#define TLG_GAME_OBJECT016AEAB0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16aeab0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00822000, where
 * its constructor is inlined, and by its complete destructor 0x822440, its row
 * named for it, D15), derived from Object016b85e0 (the creator calls that
 * class's constructor 0xc55320 first). It holds three counted references, at
 * +0x238, +0x240 and +0x250, released by the destructor in the other order
 * before the base's destructor, and an int at +0x248, 3 from the constructor:
 * the creator clears 0x238 to 0x258 in one store (`vmovups [r15+0x238],
 * ymm0`), then stores the 3. 0x260 bytes (`mov edi, 0x260` before operator
 * new in the creator): a derived class's first field is at +0x25c. The destructor is not written, so nothing here emits
 * the vtable. */
class Object016aeab0 : public Object016b85e0 /* derived name */
{
  public:
    /* every field cleared, then the int's 3 in the body: the base's
     * one store clears +0x248 with the others before the 3 */
    Object016aeab0(const Name &name) : Object016b85e0(name), unknown248(0), unknown24c(0)
    {
        unknown248 = 3;
    }

    /* the derived classes' constructor: the same, then the int at +0x258
     * after the 3 (0x670560's Object016ac108 and 0x344670's Object016a87b8:
     * `mov dword [r15+0x248], 3; mov dword [r15+0x258], -1` before their
     * vptr; their destructors tail-call 0x822440, so no class lies between) */
    Object016aeab0(const Name &name, int value) : Object016b85e0(name), unknown248(0), unknown24c(0)
    {
        unknown248 = 3;
        unknown258 = value;
    }

    virtual ~Object016aeab0();

  private:
    u8 unknown8[0x68];
    Float4A unknown70; /* +0x70: the base's; not traced */
    u8 unknown80[0x1b8];
    Ref00503fb0<Object016b9108> held238; /* +0x238 */
    Ref00503fb0<Object016b9108> held240; /* +0x240 */
    int unknown248;                      /* +0x248: 3 from the constructor */
    int unknown24c; /* +0x24c: 0 from the constructor; slot 12 (0x822740) tests it */
    Ref00503fb0<Object016b9108> held250; /* +0x250 */
    int unknown258;                      /* +0x258: set only by the derived classes' constructor */
};

#endif
