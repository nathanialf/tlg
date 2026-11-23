/* src/include/tlg_game_object016b8fd0.h: the classes whose vtables are at
 * 0x16b8fd0 and 0x16b8828 (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT016B8FD0_H
#define TLG_GAME_OBJECT016B8FD0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_node.h"
#include "tlg_game_object00ca38f0.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_array.h"
#include "tlg_game_mutex.h"

/* derived names: the class whose vtable is at 0x16b8fd0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00cb2fb0),
 * derived from Object00ca38f0. Its destructor (its key function) calls
 * FUN_00cb33a0 on the object, then the counted reference at +0xb8 is
 * released and the base's destructor tail-called (FUN_00cb32e0; FUN_00cb3500
 * the deleting one). The other fields are not traced. */
class Object016b8fd0 : public Object00ca38f0 /* derived name */
{
  public:
    virtual ~Object016b8fd0();
    /* slots 2 to 9 of 0x16b8fd0, not traced: 0xcb66f0, the empty body
     * 0x1af750 twice, 0x58a0, 0x1343880, 0x1af750 twice, 0xcb35c0 */
    virtual void slot2(); /* derived name */
    virtual void slot3(); /* derived name */
    virtual void slot4(); /* derived name */
    virtual void slot5(); /* derived name */
    virtual void slot6(); /* derived name */
    virtual void slot7(); /* derived name */
    virtual void slot8(); /* derived name */
    virtual void slot9(); /* derived name */
    /* slot 10, FUN_00cb3b00 (leaf_00cb32e0.cpp): with the grid on (+0x50),
     * its pairs cleared, its cells set to 0xff80ff80 and the four floats
     * at +0xa8 set; 1, else 0 */
    virtual int slot10(); /* derived name */

    void FUN_00cb33a0(); /* derived name; slot 11, called directly by the destructor; not traced */

  private:
    u8 unknown8[0x48];
    int unknown50; /* +0x50: slot 10 does nothing while it is clear */
    u8 unknown54[0x2c];
    float unknown80; /* +0x80: the w slot 10 gives +0xa8 (copied through a general register) */
    u8 unknown84[0x4];
    unsigned width;  /* +0x88 (derived name) */
    unsigned height; /* +0x8c (derived name) */
    float *pairs;    /* +0x90: two floats a cell, cleared by slot 10 */
    u8 unknown98[0x8];
    u32 *cells;                            /* +0xa0: a word a cell, 0xff80ff80 from slot 10 */
    Float4 unknowna8;                      /* +0xa8: (0, 1, 0, the float at +0x80) from slot 10 */
    Ref00503fb0<Object016b9108> unknownb8; /* +0xb8 */
};

class Object016b8828;

/* derived names: the object at 0x593a938 that FUN_00c822d0 is called on with
 * an Object016b8828 being destroyed: under its recursive mutex at +0x28, the
 * objects it holds (+0x40) and two lists of them, each list's count after
 * the two (+0x58 to +0x6c, indexed by the list: `[r15+rcx*8+0x58]`,
 * `[r15+rcx*4+0x68]`); the other fields are not traced */
struct Registry0593a938 { /* derived name */
    u8 unknown0[0x28];
    Mutex013847e0 mutex;                     /* +0x28 */
    Array05943280<Object016b8828 *> objects; /* +0x40 */
    Object016b8828 **lists[2];               /* +0x58 */
    unsigned listCounts[2];                  /* +0x68 */
};

extern Registry0593a938 *D_593a938; /* derived name */

void FUN_00c822d0(Registry0593a938 *registry, Object016b8828 *object); /* derived name */

/* derived names: the class whose vtable is at 0x16b8828
 * (config/vtables.derived.base.txt, stored by its creator FUN_00c81f90),
 * derived from Object016b85e0. Its destructor (its key function) hands the
 * object to FUN_00c822d0 when the object at 0x593a938 exists, then the
 * counted reference at +0x280 is released and the base's destructor
 * tail-called (FUN_00c82210; FUN_00c82430 the deleting one). The other fields
 * are not traced. */
class Object016b8828 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b8828();

  private:
    friend void FUN_00c822d0(Registry0593a938 *registry, Object016b8828 *object);

    u8 unknown238[0x48];
    Ref00503fb0<Object016b9108> unknown280; /* +0x280 */
    u8 unknown288[0x48];
    /* +0x2d0: its place in the registry's list that holds it, -1 when in
     * none (FUN_00c822d0) */
    int slot;
};

#endif
