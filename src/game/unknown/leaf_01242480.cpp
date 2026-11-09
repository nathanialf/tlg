/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* derived names: calls its own slot 8 (FUN_01241ec0 in the vtable 0x16d6b98)
 * with its argument as a tail call; slot 7 counted from the nearest stored
 * vtable, at 0x16ca9a0 (its pointer at 0x16ca9e8), the vtable stored by
 * FUN_0122be10; slot 7 of the vtable at 0x16d6b98 (its pointer at 0x16d6be0),
 * the vtable stored by FUN_0122be10. The load of the slot is not folded into
 * the jump (mov rax, [rax+0x40]; jmp rax), the shape of a call that passes a
 * register argument on (round 112A, 0x8f28f0), so the argument is passed: its
 * type and the return type are not traced. Class and method unknown. */
struct Argument01242480; /* derived name */

class Object01242480 /* derived name */
{
  public:
    virtual void slot0();                                  /* derived name; not traced */
    virtual void slot1();                                  /* derived name; not traced */
    virtual void slot2();                                  /* derived name; not traced */
    virtual void slot3();                                  /* derived name; not traced */
    virtual void slot4();                                  /* derived name; not traced */
    virtual void slot5();                                  /* derived name; not traced */
    virtual void slot6();                                  /* derived name; not traced */
    virtual void slot7();                                  /* derived name; not traced */
    virtual void FUN_01241ec0(Argument01242480 *argument); /* derived name */
};

void FUN_01242480(Object01242480 *self, Argument01242480 *argument) /* derived name */
{
    self->FUN_01241ec0(argument);
}
