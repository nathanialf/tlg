/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 13 of the vtable at 0x16b06b0 (stored by FUN_008ef8a0
 * FUN_008efe80) calls slot 5 (FUN_008f1140, 6,057 bytes) on the object as a
 * tail call through the vtable. Slots 0 and 1 are FUN_008efe80 and
 * FUN_008f0160 (the destructors' shape), slot 2 FUN_00cb66f0, slots 3 and 4
 * the empty FUN_001af750. The argument's target and the return types are not traced.
 * Class and method unknown. */
struct Target008f28f0; /* derived name */

class Object008f28f0 /* derived name */
{
  public:
    virtual ~Object008f28f0();
    virtual void FUN_00cb66f0();                         /* derived name; not traced */
    virtual void slot3();                                /* derived name: the empty FUN_001af750 */
    virtual void slot4();                                /* derived name: the empty FUN_001af750 */
    virtual void FUN_008f1140(Target008f28f0 *argument); /* derived name */
};

void FUN_008f28f0(Object008f28f0 *self, Target008f28f0 *argument) /* derived name */
{
    self->FUN_008f1140(argument);
}
