/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (cookbook: FUN_00b10da0's form; here a pointer,
 * the object itself and a float). */
struct ScriptArgument00a2efa0 {
    /* the value read before the type is stored (`mov eax,
     * [rdi+0x74]` before `mov dword [rbp-0x30], 3` at 0xb10dcb; `mov rax,
     * [rbx+0x28]` before the first type at 0x2dc470): both are the setter's
     * arguments, evaluated before its stores */
    void set(int type_, void *pointer) /* derived name */
    {
        type = type_;
        value.pointer = pointer;
    }

    void set(int type_, float number) /* derived name */
    {
        type = type_;
        value.number = number;
    }

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
 * (type 4), then its own slot 16. Slot 11 (FUN_002dc4d0) calls
 * "Ai2.CondorUtils.CondorLightTick" with the same three and nothing after.
 * The class is not traced. */
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
    virtual void slot11(float value); /* derived name: FUN_002dc4d0 */
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

void Object016a8178::slot19(float value)
{
    ScriptArgument00a2efa0 arguments[3];
    arguments[0].set(1, unknown28);
    arguments[1].set(1, this);
    arguments[2].set(4, value);
    int result = 0;
    FUN_00a2efa0("Ai2.CondorUtils.CondorLightPrepareTick", 3, arguments, &result);
    slot16();
}

void Object016a8178::slot11(float value)
{
    ScriptArgument00a2efa0 arguments[3];
    arguments[0].set(1, unknown28);
    arguments[1].set(1, this);
    arguments[2].set(4, value);
    int result = 0;
    FUN_00a2efa0("Ai2.CondorUtils.CondorLightTick", 3, arguments, &result);
}
