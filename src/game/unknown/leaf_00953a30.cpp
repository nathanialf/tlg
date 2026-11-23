/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00953a30: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). Beyond it the base keeps the vptr stores of 0x16ccce8 (0x953b4b) under the later ones and stores the ints after them one by one, where the build drops those vptr stores and merges the zeros around them into vector stores: OPEN (a member the stores cannot pass, not traced). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_multibase.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5821210]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5821210;

/* derived names: what FUN_00953a30 adds to Class16b10c8 for the class at
 * 0x16b1168: a base with no virtual function, declared after it, so it
 * is built after it (its stores follow the members of Object016ccce8) and
 * destroyed first; from +0x78 (Class16b10c8 is 0x78 bytes), all set by
 * the constructor: 16 zero bytes, 0 and 2.0 at +0x88, 16 zero bytes, then
 * from +0xa0 the run FUN_0096a910's class holds at +0x110 (four floats
 * (1, 1, 0, 0) at +0xa4 and four of 1 at +0xb4, unaligned, 0.01 at +0xd0,
 * -1 at +0xdc, 0.2 at +0xfc) and the counted reference at +0x100, null. */
struct State016b1168 /* derived name */
{
    State016b1168()
        : unknown78(0), unknown7c(0), unknown80(0), unknown84(0), unknown88(0), unknown8c(2.0f),
          unknown90(0), unknown94(0), unknown98(0), unknown9c(0), unknowna0(0), unknowna4(1.0f),
          unknowna8(1.0f), unknownac(0.0f), unknownb0(0.0f), unknownb4(1.0f), unknownb8(1.0f),
          unknownbc(1.0f), unknownc0(1.0f), unknownc4(0), unknownc8(1.0f), unknowncc(0),
          unknownd0(0.01f), unknownd4(0), unknownd8(0), unknowndc(-1), unknowne0(0), unknowne4(0),
          unknowne8(1.0f), unknownec(0), unknownf0(0), unknownf4(0), unknownf8(1.0f),
          unknownfc(0.2f)
    {
    }

    int unknown78;                          /* +0x78 */
    int unknown7c;                          /* +0x7c */
    int unknown80;                          /* +0x80 */
    int unknown84;                          /* +0x84 */
    int unknown88;                          /* +0x88 */
    float unknown8c;                        /* +0x8c: 2.0 */
    int unknown90;                          /* +0x90 */
    int unknown94;                          /* +0x94 */
    int unknown98;                          /* +0x98 */
    int unknown9c;                          /* +0x9c */
    int unknowna0;                          /* +0xa0 */
    float unknowna4;                        /* +0xa4 */
    float unknowna8;                        /* +0xa8 */
    float unknownac;                        /* +0xac */
    float unknownb0;                        /* +0xb0 */
    float unknownb4;                        /* +0xb4 */
    float unknownb8;                        /* +0xb8 */
    float unknownbc;                        /* +0xbc */
    float unknownc0;                        /* +0xc0 */
    int unknownc4;                          /* +0xc4 */
    float unknownc8;                        /* +0xc8: 1.0 */
    int unknowncc;                          /* +0xcc */
    float unknownd0;                        /* +0xd0: 0.01 */
    int unknownd4;                          /* +0xd4 */
    int unknownd8;                          /* +0xd8 */
    int unknowndc;                          /* +0xdc: -1 */
    int unknowne0;                          /* +0xe0 */
    int unknowne4;                          /* +0xe4 */
    float unknowne8;                        /* +0xe8: 1.0 */
    int unknownec;                          /* +0xec */
    int unknownf0;                          /* +0xf0 */
    int unknownf4;                          /* +0xf4 */
    float unknownf8;                        /* +0xf8: 1.0 */
    float unknownfc;                        /* +0xfc: 0.2 */
    Ref00503fb0<Object016b9108> unknown100; /* +0x100 */
};

/* derived names: the class whose vtable is at 0x16b1168
 * (config/vtables.derived.base.txt; stored by FUN_00953a30), slot 6 kept
 * from the class at 0x16b10c8, slot 9 its own (FUN_009611a0, the function
 * that follows FUN_00961140; not declared). It declares no destructor:
 * every function of it lies in the stretch of inline functions, so this
 * unit, which constructs it, emits the vtable and the destructors, the
 * implicit destructor hinted (its body costs 315 at the unit stage, under
 * the limit of 325, so the deleting one, slot 1 at 0x137e550, holds it as
 * the base does). The complete one, slot 0 at 0x137e3b0, stores no vptr of
 * its own: the reference at +0x100 is released, then Class137ba70's bases
 * (the base at +0x30's vptr and reference, then the root class's). The
 * shape of the class at 0x16b1640 (leaf_0096a910.cpp). */
class Object016b1168 : public Class16b10c8, public State016b1168 /* derived name */
{
  public:
    Object016b1168(const Name &name) : Class16b10c8(name) {}
};

/* derived name: the creator of Object016b1168, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x108 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * root's constructor 0xcb6310 a call, the rest inlined after it. */
Object016b9108 *FUN_00953a30(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016b1168));
    D_59458a4.lock();
    D_59458a8 = D_5821210;
    return new (memory) Object016b1168(name);
}
