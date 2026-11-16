/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (leaf_002dc440.cpp's; type 2 a string) */
struct ScriptArgument00a2efa0 {
    void set(int type_, const char *string) /* derived name */
    {
        type = type_;
        value.string = string;
    }

    int type;
    u8 unknown4[4];

    union {
        const char *string;
        void *pointer;
    } value;
};

/* calls the script function its name gives with count arguments, its int
 * result through the last pointer; nonzero on success (FUN_00b10da0). */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: the class whose vtable is at 0x16a8430
 * (config/vtables.derived.base.txt, stored by FUN_002f9860 and
 * FUN_002fed80), derived from Object016b9108; slot 19 (FUN_00301db0) is FUN_003fcfb0 of the class at 0x16a96d0, byte for byte.
 * Slots 5 to 18 are not traced. */
class Object016a8430 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5();              /* derived name; not traced */
    virtual void slot6();              /* derived name; not traced */
    virtual void slot7();              /* derived name; not traced */
    virtual void slot8();              /* derived name; not traced */
    virtual void slot9();              /* derived name; not traced */
    virtual void slot10();             /* derived name; not traced */
    virtual void slot11();             /* derived name; not traced */
    virtual void slot12();             /* derived name; not traced */
    virtual void slot13();             /* derived name; not traced */
    virtual void slot14();             /* derived name; not traced */
    virtual void slot15();             /* derived name; not traced */
    virtual void slot16();             /* derived name; not traced */
    virtual void slot17();             /* derived name; not traced */
    virtual void slot18();             /* derived name; not traced */
    virtual void beforeInterestTick(); /* derived name: slot 19 */

  private:
    u8 unknown24[0x6c];
    int state; /* +0x90: 1 skips the script call (derived name) */
    u8 unknown94[0x7c];
    Owner05943280 *heap; /* +0x110: the thread's heap while the slot runs (derived name) */
};

/* derived names: with the calling thread's heap (set on first use to the
 * table's first) replaced by the object's for the call, calls the script
 * function "Ai2.BeforeInterestTick" with the object's name (type 2) unless
 * its state at +0x90 is 1, then puts the thread's heap back. */
void Object016a8430::beforeInterestTick()
{
    ThreadHeapScope05943280 scope(heap);
    if (state != 1) {
        ScriptArgument00a2efa0 arguments[1];
        arguments[0].set(2, D_17ac870[name.index].string0);
        int result = 0;
        FUN_00a2efa0("Ai2.BeforeInterestTick", 1, arguments, &result);
    }
}
