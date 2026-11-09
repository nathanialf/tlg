/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a deleter. FUN_001db8b0 passes its address (lea at 0x1efb88)
 * to the type registry FUN_00cbb0e0 as the 8th argument, beside the factory
 * FUN_001bab90 (the 7th, lea at 0x1efbb1, which allocates a 0x98-byte object).
 * The factory builds its object on the base constructor FUN_00d68470. It
 * deletes the object through its virtual destructor (slot 1, the deleting
 * one), null skipped. The parameter is the root of the registered classes, as
 * for every deleter the registry takes: the factory's object derives from the
 * base whose destructor is 0xd687e0 (the vtable 0x16c81c0, stored by
 * FUN_00d68470 and FUN_00d687e0), and FUN_00d68470 first calls FUN_00cb6310
 * (at 0xd68491), which stores the vtable 0x16b9108 (slot 0 the destructor
 * 0xcb65f0, which stores it again); the registry's own pointer type is not
 * traced. */
class Object00cb65f0 /* derived name */
{
  public:
    virtual ~Object00cb65f0();
};

void FUN_001bad00(Object00cb65f0 *object) /* derived name */
{
    delete object;
}
