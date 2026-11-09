/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: deletes the object through its virtual destructor (slot 1,
 * the deleting one), null skipped, as delete of the object itself; slot 2 of
 * the vtable at 0x16c3968 (its pointer at 0x16c3988, slots 0 and 1 the
 * destructors 0x1305420 and 0x1305cc0), stored by FUN_00b8a480 FUN_01305420,
 * and of the vtable at 0x16c3c58 (its pointer at 0x16c3c78, destructors
 * 0x13246a0 and 0x1324770), stored by FUN_00b8a480 and 13 more: a method of
 * their common base. Class and method unknown. */
class Object01324850 /* derived name */
{
  public:
    virtual ~Object01324850();
};

void FUN_01324850(Object01324850 *self) /* derived name */
{
    delete self;
}
