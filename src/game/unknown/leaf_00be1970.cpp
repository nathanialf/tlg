/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: calls slot 7 of the object its second argument points to, as
 * a tail call; slot 1 of the vtable at 0x16b79a8 (its pointer at 0x16b79c0),
 * no storing constructor listed. The first argument (the object) is not used;
 * the target's class and the slot's signature are not traced. Class and method
 * unknown. */
struct Object00be1970; /* derived name */

class Target00be1970 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name */
};

void FUN_00be1970(Object00be1970 *, Target00be1970 *target) /* derived name */
{
    target->slot7();
}
