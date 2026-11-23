/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_0096a910: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). Beyond it the base keeps the vptr stores of 0x16cd110 and 0x16b15a0 (0x96aa2b, 0x96aa55) under the later ones and stores the ints after them one by one, where the build drops those vptr stores and merges the zeros around them into vector stores: OPEN (a member the stores cannot pass, not traced). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_multibase.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5821c10]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5821c10;

/* derived names: what FUN_0096a910 adds to Class16b15a0 for the class at
 * 0x16b1640: a base with no virtual function, declared after it, so it is
 * built after it (its stores follow Class16b15a0's vptr stores) and
 * destroyed first; from +0x78 (Class16b15a0 is 0x78 bytes), all set by
 * the constructor but +0x78, +0xe4 and +0x178: from +0xe8 the run of
 * FUN_00953a30's class at +0x78 (16 zero bytes, 0 and 2.0, 16 zero bytes,
 * the floats (1, 1, 0, 0) and four of 1, 0.01, -1, 0.2), and the counted
 * reference at +0x170, null. */
struct State016b1640 /* derived name */
{
    State016b1640()
        : unknown80(0), unknown84(-1.0f), unknown88(0), unknown8c(0), unknown90(0), unknown94(0),
          unknown98(0), unknown9c(1.0f), unknowna0(1.0f), unknowna4(1.0f), unknowna8(1.0f),
          unknownac(0.0f), unknownb0(0.0f), unknownb4(1.0f), unknownb8(1.0f), unknownbc(0.0f),
          unknownc0(0), unknownc4(1.0f), unknownc8(1.0f), unknowncc(0.0f), unknownd0(0.0f),
          unknownd4(1.0f), unknownd8(0), unknowndc(0), unknowne0(1), unknowne8(0), unknownec(0),
          unknownf0(0), unknownf4(0), unknownf8(0), unknownfc(2.0f), unknown100(0), unknown104(0),
          unknown108(0), unknown10c(0), unknown110(0), unknown114(1.0f), unknown118(1.0f),
          unknown11c(0.0f), unknown120(0.0f), unknown124(1.0f), unknown128(1.0f), unknown12c(1.0f),
          unknown130(1.0f), unknown134(0), unknown138(1.0f), unknown13c(0), unknown140(0.01f),
          unknown144(0), unknown148(0), unknown14c(-1), unknown150(0), unknown154(0),
          unknown158(1.0f), unknown15c(0), unknown160(0), unknown164(0), unknown168(1.0f),
          unknown16c(0.2f)
    {
    }

    u8 unknown78[0x8];
    int unknown80;   /* +0x80 */
    float unknown84; /* +0x84: -1.0 */
    int unknown88;   /* +0x88 */
    int unknown8c;   /* +0x8c */
    int unknown90;   /* +0x90 */
    int unknown94;   /* +0x94 */
    int unknown98;   /* +0x98 */
    float unknown9c; /* +0x9c: 1.0 */
    float unknowna0; /* +0xa0: 1.0 */
    float unknowna4; /* +0xa4: 1.0 */
    float unknowna8; /* +0xa8: 1.0 */
    float unknownac; /* +0xac */
    float unknownb0; /* +0xb0 */
    float unknownb4; /* +0xb4: 1.0 */
    float unknownb8; /* +0xb8: 1.0 */
    float unknownbc; /* +0xbc */
    int unknownc0;   /* +0xc0 */
    float unknownc4; /* +0xc4: 1.0 */
    float unknownc8; /* +0xc8: 1.0 */
    float unknowncc; /* +0xcc */
    float unknownd0; /* +0xd0 */
    float unknownd4; /* +0xd4: 1.0 */
    int unknownd8;   /* +0xd8 */
    int unknowndc;   /* +0xdc */
    int unknowne0;   /* +0xe0: 1 */
    u8 unknowne4[0x4];
    int unknowne8;                          /* +0xe8 */
    int unknownec;                          /* +0xec */
    int unknownf0;                          /* +0xf0 */
    int unknownf4;                          /* +0xf4 */
    int unknownf8;                          /* +0xf8 */
    float unknownfc;                        /* +0xfc: 2.0 */
    int unknown100;                         /* +0x100 */
    int unknown104;                         /* +0x104 */
    int unknown108;                         /* +0x108 */
    int unknown10c;                         /* +0x10c */
    int unknown110;                         /* +0x110 */
    float unknown114;                       /* +0x114: 1.0 */
    float unknown118;                       /* +0x118: 1.0 */
    float unknown11c;                       /* +0x11c */
    float unknown120;                       /* +0x120 */
    float unknown124;                       /* +0x124: 1.0 */
    float unknown128;                       /* +0x128: 1.0 */
    float unknown12c;                       /* +0x12c: 1.0 */
    float unknown130;                       /* +0x130: 1.0 */
    int unknown134;                         /* +0x134 */
    float unknown138;                       /* +0x138: 1.0 */
    int unknown13c;                         /* +0x13c */
    float unknown140;                       /* +0x140: 0.01 */
    int unknown144;                         /* +0x144 */
    int unknown148;                         /* +0x148 */
    int unknown14c;                         /* +0x14c: -1 */
    int unknown150;                         /* +0x150 */
    int unknown154;                         /* +0x154 */
    float unknown158;                       /* +0x158: 1.0 */
    int unknown15c;                         /* +0x15c */
    int unknown160;                         /* +0x160 */
    int unknown164;                         /* +0x164 */
    float unknown168;                       /* +0x168: 1.0 */
    float unknown16c;                       /* +0x16c: 0.2 */
    Ref00503fb0<Object016b9108> unknown170; /* +0x170 */
    u8 unknown178[0x8];
};

/* derived names: the class whose vtable is at 0x16b1640
 * (config/vtables.derived.base.txt; stored by FUN_0096a910), slot 6 kept
 * from the class at 0x16b15a0, slot 9 its own (FUN_0096e710; not declared).
 * It declares no destructor: every function of it lies in the stretch of
 * inline functions, so this unit, which constructs it, emits the vtable
 * and the destructors, the implicit destructor hinted (its body costs 315
 * at the unit stage, under the limit of 325, so the deleting one, slot 1
 * at 0x1381a00, holds it as the base does). The complete one, slot 0 at
 * 0x1381860, stores no vptr of its own: the reference at +0x170 is
 * released, then Class137ba70's bases (the base at +0x30's vptr and
 * reference, then the root class's). */
class Object016b1640 : public Class16b15a0, public State016b1640 /* derived name */
{
  public:
    Object016b1640(const Name &name) : Class16b15a0(name) {}
};

/* derived name: the creator of Object016b1640, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x180 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * root's constructor 0xcb6310 a call, the rest inlined after it. */
Object016b9108 *FUN_0096a910(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016b1640));
    D_59458a4.lock();
    D_59458a8 = D_5821c10;
    return new (memory) Object016b1640(name);
}
