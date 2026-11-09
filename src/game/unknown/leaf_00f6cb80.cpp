/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: calls its own slot 7 (FUN_00f6c270) with the argument 1 as a
 * tail call; slot 4 of the vtable at 0x16bfa88 (its pointer at 0x16bfab8), the
 * vtable stored by FUN_00f59e00. The 32-bit 1 (mov esi, 1) is an int or a
 * bool; int is written, as for FUN_00f6cb50 and FUN_00f6cb60, which pass 0 to
 * the same slots. The return type is not traced. Class and method unknown. */
class Object00f6cb80 /* derived name */
{
  public:
    virtual void slot0();           /* derived name; not traced */
    virtual void slot1();           /* derived name; not traced */
    virtual void slot2();           /* derived name; not traced */
    virtual void slot3();           /* derived name; not traced */
    virtual void slot4();           /* derived name; not traced */
    virtual void slot5();           /* derived name; not traced */
    virtual void slot6();           /* derived name; not traced */
    virtual void FUN_00f6c270(int); /* derived name */
};

void FUN_00f6cb80(Object00f6cb80 *self) /* derived name */
{
    self->FUN_00f6c270(1);
}
