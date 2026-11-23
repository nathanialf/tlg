/* src/include/tlg_game_task00ce9460.h: the work FUN_00ce5af0, FUN_00ce16f0
 * and FUN_00ce5e60 split across jobs when their list holds more than 19
 * objects (FUN_00d680b0's job, its task at +0x30 of the job with the vtable
 * 0x16b9698): a range of the list, each object's virtual handed the caller's
 * argument, and the count of finished parts raised at the end. Every name
 * here is derived. */
#ifndef TLG_GAME_TASK00CE9460_H
#define TLG_GAME_TASK00CE9460_H

#include "tlg_types.h"
#include <xmmintrin.h>

/* derived names: an object of the list: slots 6 to 8 are the three
 * passes; their parameters not traced past the pointer each takes */
class Element00ce9460 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual void slot1();             /* derived name; not traced */
    virtual void slot2();             /* derived name; not traced */
    virtual void slot3();             /* derived name; not traced */
    virtual void slot4();             /* derived name; not traced */
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6(void *value);  /* derived name; FUN_00ce9460's pass */
    virtual void slot7(void *member); /* derived name; FUN_00ce94d0's pass */
    virtual void slot8(void *member); /* derived name; FUN_00ce61d0's pass */
};

/* derived names: the list's array: its block first; an element read at a
 * signed index (`movsxd` at each use under the unsigned counter) */
struct List00ce9460 { /* derived name */

    Element00ce9460 *at(int index) const
    {
        return elements[index];
    }

    Element00ce9460 **elements; /* +0x0 */
};

/* derived names: the caller's argument: a pointer at +0 and a member at
 * +0x8 (not traced) */
struct Argument00ce9460 { /* derived name */
    void *value;          /* +0x0 */
    u8 member8[1];        /* +0x8: not traced */
};

/* derived names: the task at +0x30 of the job (the creators' stores from
 * +0x30: the vptr, a zero, the argument, the list, the range, the count) */
struct Task00ce9460 { /* derived name */
    u8 unknown0[0x10];
    Argument00ce9460 *argument; /* +0x10 */
    List00ce9460 *list;         /* +0x18 */
    unsigned begin;             /* +0x20 */
    unsigned end;               /* +0x24 */
    int *finished;              /* +0x28 */
};

#endif
