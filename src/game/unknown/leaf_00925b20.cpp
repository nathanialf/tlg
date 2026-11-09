/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a deleter. FUN_00925b30 passes its address (lea at 0x929f9a)
 * to the type registry FUN_00cbb0e0 as the 8th argument, beside the factory
 * FUN_00925b10 (the 7th, lea at 0x929fc2). It deletes the object through its
 * virtual destructor (slot 1, the deleting one), null skipped. The parameter
 * is the root of the registered classes: the factory returns null, and the
 * objects of the registry's other factories are built on constructor chains
 * that end in FUN_00cb6310, which stores the vtable 0x16b9108 (slot 0 the
 * destructor 0xcb65f0, which stores it again); the registry's own pointer type
 * is not traced. */
class Object00cb65f0 /* derived name */
{
  public:
    virtual ~Object00cb65f0();
};

void FUN_00925b20(Object00cb65f0 *object) /* derived name */
{
    delete object;
}
