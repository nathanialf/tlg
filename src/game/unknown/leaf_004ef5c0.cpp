/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: a position, four floats 16-byte aligned, copied whole */
struct alignas(16) Position004ef5c0 { /* derived name */
    float x;
    float y;
    float z;
    float w;
};

/* derived names: the body the object at 0x16aa7d8's class holds at +0x28:
 * a flag word at +0x24 (0x200 set while the state is FISH_boot's) and its
 * position at +0x120, set through FUN_00c57c10 */
struct Body004ef5c0 { /* derived name */
    u8 unknown0[0x24];
    int flags; /* +0x24 */
    u8 unknown28[0xf8];
    Position004ef5c0 position; /* +0x120 */
};

void FUN_00c57c10(Body004ef5c0 *body, const Position004ef5c0 *position); /* derived name */

/* the name "FISH_boot" (func_004f3010.cpp) */
extern Name D_57d9924;

/* derived names: the class whose vtable is at 0x16aa7d8 (stored by
 * FUN_004ee410 FUN_004ee8f0) as slot 26 sees it: its body at +0x28 and the
 * name of its state at +0x118 */
class Object004ef5c0 /* derived name */
{
  public:
    virtual void slot0();            /* derived name; not traced */
    virtual void slot1();            /* derived name; not traced */
    virtual void slot2();            /* derived name; not traced */
    virtual void slot3();            /* derived name; not traced */
    virtual void slot4();            /* derived name; not traced */
    virtual void slot5();            /* derived name; not traced */
    virtual void slot6();            /* derived name; not traced */
    virtual void slot7();            /* derived name; not traced */
    virtual void slot8();            /* derived name; not traced */
    virtual void slot9();            /* derived name; not traced */
    virtual void slot10();           /* derived name; not traced */
    virtual void slot11();           /* derived name; not traced */
    virtual void slot12();           /* derived name; not traced */
    virtual void slot13();           /* derived name; not traced */
    virtual void slot14();           /* derived name; not traced */
    virtual void slot15();           /* derived name; not traced */
    virtual void slot16();           /* derived name; not traced */
    virtual void slot17();           /* derived name; not traced */
    virtual void slot18();           /* derived name; not traced */
    virtual void slot19();           /* derived name; not traced */
    virtual void slot20();           /* derived name; not traced */
    virtual void slot21();           /* derived name; not traced */
    virtual void slot22();           /* derived name; not traced */
    virtual void slot23();           /* derived name; not traced */
    virtual void slot24();           /* derived name; not traced */
    virtual void slot25();           /* derived name; not traced */
    virtual void slot26(float step); /* derived name: FUN_004ef5c0 */
    virtual void slot27();           /* derived name; not traced */
    virtual void slot28();           /* derived name; not traced */
    virtual void slot29(float step); /* derived name; not traced */

    u8 unknown8[0x20];
    Body004ef5c0 *body; /* +0x28 */
    u8 unknown30[0xe8];
    Name state; /* +0x118 (derived name) */
};

/* derived names: slot 26 of the vtable at 0x16aa7d8: in the state
 * "FISH_boot" the body is flagged 0x200 and moved up or down by a random
 * amount under 0.3; in any other the flag is cleared. Then slot 29 with the
 * step. */
void Object004ef5c0::slot26(float step)
{
    if (state == D_57d9924) {
        body->flags |= 0x200;
        Position004ef5c0 position = body->position;
        position.y = position.y + (0.3f - 0.6f * (rand() / (float)RAND_MAX));
        FUN_00c57c10(body, &position);
    } else {
        body->flags &= ~0x200;
    }
    slot29(step);
}
