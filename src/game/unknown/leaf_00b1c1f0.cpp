/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a deleter. FUN_008c25c0 passes its address (lea at 0x8cf790)
 * to the type registry FUN_00cbb0e0 as the 8th argument, beside the factory
 * FUN_00b1bff0 (the 7th, lea at 0x8cf7b8, which allocates a 0xb8-byte object).
 * It deletes the object through its virtual destructor (slot 1, the deleting
 * one), null skipped. The parameter is the root of the registered classes: the
 * constructor chain of the factory's object (FUN_00cb6310) ends in
 * FUN_00cb6310, which stores the vtable 0x16b9108 (slot 0 the destructor
 * 0xcb65f0, which stores it again); the registry's own pointer type is not
 * traced. */
class Object00cb65f0 /* derived name */
{
  public:
    virtual ~Object00cb65f0();
};

void FUN_00b1c1f0(Object00cb65f0 *object) /* derived name */
{
    delete object;
}
