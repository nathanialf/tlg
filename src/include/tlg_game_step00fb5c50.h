#ifndef TLG_GAME_STEP00FB5C50_H
#define TLG_GAME_STEP00FB5C50_H

#include "tlg_types.h"

/* The step of a state object, slot 7 of four vtables (0x16ca660,
 * 0x16ca6b8, 0x16ca710, 0x16caaf0: FUN_00fb5c50, FUN_00fb5cf0, FUN_00fb5d90,
 * FUN_01246fd0), and what it reads: the context's input holds two records
 * of 0x140 bytes, each with a count at +0x10 and a value at +0x90. The
 * classes are not traced beyond these members. derived names. */
struct StepRecord00fb5c50 {
    u8 unknown0[0x10];
    int count; /* +0x10 */
    u8 unknown14[0x7c];
    float value; /* +0x90 */
    u8 unknown94[0xac];
};

struct StepInput00fb5c50 {
    StepRecord00fb5c50 records[2]; /* +0x0, +0x140 */
};

struct StepContext00fb5c50 {
    u8 unknown0[8];
    StepInput00fb5c50 *input; /* +0x8 */
};

class Stepper00fb5c50
{
  public:
    virtual void slot0();                           /* derived name; not traced */
    virtual void slot1();                           /* derived name; not traced */
    virtual void slot2();                           /* derived name; not traced */
    virtual void slot3();                           /* derived name; not traced */
    virtual void slot4();                           /* derived name; not traced */
    virtual void slot5();                           /* derived name; not traced */
    virtual void slot6();                           /* derived name; not traced */
    virtual int step(StepContext00fb5c50 *context); /* derived name; slot 7 */
    virtual float
    level(StepContext00fb5c50 *context); /* derived name; slot 8: FUN_013e2080 and its copies */

    /* the state follows the input: 0 or 3 becomes 1 while either record
     * holds a count, 1 or 2 becomes 3 when neither does. derived name */
    void follow(const StepInput00fb5c50 *input)
    {
        if (input->records[0].count != 0 || input->records[1].count != 0) {
            if (state == 0 || state == 3)
                state = 1;
        } else {
            if (state == 1 || state == 2)
                state = 3;
        }
    }

    u8 unknown8[0x50];
    int state; /* +0x58 */
    u8 unknown5c[4];
    float unknown60; /* +0x60: the level at the last step */
};

#endif
