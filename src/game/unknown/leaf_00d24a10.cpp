/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a deleter. FUN_00e10cd0 passes its address (lea at 0xe14da1)
 * to the type registry FUN_00cbb0e0 as the 8th argument, beside the factory
 * FUN_00d24840 (the 7th, lea at 0xe14dc9, which allocates a 0x48-byte object).
 * It deletes the object through its virtual destructor (slot 1, the deleting
 * one), null skipped. The parameter is the root of the registered classes: the
 * factory builds its object on FUN_00cb6310 (called at 0xd2496d) before it
 * stores its own vtable 0x16ba240, which stores the vtable 0x16b9108 (slot 0
 * the destructor 0xcb65f0, which stores it again); the registry's own pointer
 * type is not traced. */
class Object00cb65f0 /* derived name */
{
  public:
    virtual ~Object00cb65f0();
};

void FUN_00d24a10(Object00cb65f0 *object) /* derived name */
{
    delete object;
}
