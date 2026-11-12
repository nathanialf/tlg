/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (cookbook: FUN_00b10da0's form; here a pointer,
 * the object itself and a float). */
struct ScriptArgument00a2efa0 {
    int type;
    u8 unknown4[4];

    union {
        void *pointer;
        float number;
    } value;
};

/* calls the script function its name gives with count arguments, its int
 * result through the last pointer; nonzero on success (FUN_00b10da0). */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: slot 19 of the vtable at 0x16a8178 (no row; the method
 * stores no vptr; the vtable is stored by FUN_002dba90 and FUN_002dbc50):
 * calls the script function "Ai2.CondorUtils.CondorLightPrepareTick" with
 * the pointer at +0x28 and the object (both type 1) and its float argument
 * (type 4), then its own slot 16. The class is not traced. */
class Object016a8178 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual void slot1();             /* derived name; not traced */
    virtual void slot2();             /* derived name; not traced */
    virtual void slot3();             /* derived name; not traced */
    virtual void slot4();             /* derived name; not traced */
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12();            /* derived name; not traced */
    virtual void slot13();            /* derived name; not traced */
    virtual void slot14();            /* derived name; not traced */
    virtual void slot15();            /* derived name; not traced */
    virtual void slot16();            /* derived name; not traced */
    virtual void slot17();            /* derived name; not traced */
    virtual void slot18();            /* derived name; not traced */
    virtual void slot19(float value); /* derived name: FUN_002dc440 */

  private:
    u8 unknown8[0x20];
    void *unknown28; /* +0x28 */
};

// NONMATCHING: instruction order (list-ilp): the base loads +0x28 before the first argument's type and stores the result's 0 after it, the build stores the 0 first (FUN_00b10da0's class)
void Object016a8178::slot19(float value)
{
    int result = 0;
    ScriptArgument00a2efa0 arguments[3];
    arguments[0].type = 1;
    arguments[0].value.pointer = unknown28;
    arguments[1].type = 1;
    arguments[1].value.pointer = this;
    arguments[2].type = 4;
    arguments[2].value.number = value;
    FUN_00a2efa0("Ai2.CondorUtils.CondorLightPrepareTick", 3, arguments, &result);
    slot16();
}
