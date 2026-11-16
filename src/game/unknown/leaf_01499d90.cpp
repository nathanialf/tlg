/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a target record whose kind 5 (+0x48) carries a value at
 * +0x40 */
struct Target01499d90 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40; /* +0x40 */
    int kind;        /* +0x48 */
};

/* derived names: an object with a current target at +0x270, told through
 * slot 32 when a target of kind 5 is let go and through slot 31 when one is
 * taken; the other slots and fields are not traced */
class Object01499d90 /* derived name */
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void take(bool flag, void *value); /* derived name */
    virtual void release();                    /* derived name */

    void setTarget(Target01499d90 *target, bool flag); /* derived name */

  private:
    u8 unknown8[0x268];
    Target01499d90 *target; /* +0x270 */
};

/* derived name: the current target replaced */
void Object01499d90::setTarget(Target01499d90 *next, bool flag)
{
    if (target) {
        if (target->kind == 5)
            release();
        target = 0;
    }
    if (next) {
        if (next->kind == 5)
            take(flag, next->unknown40);
        target = next;
    }
}
