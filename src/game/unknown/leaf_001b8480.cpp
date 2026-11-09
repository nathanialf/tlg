/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a deleter. FUN_001db8b0 passes its address (lea at 0x1ed5d8)
 * to the type registry FUN_00cbb0e0 as the 8th argument, beside the factory
 * FUN_001b8310 (the 7th, lea at 0x1ed601), which allocates a 0x98-byte object,
 * builds it on the base constructor FUN_00d68470 and stores the vtable at
 * 0x16c6580. It deletes the object through its virtual destructor (slot 1, the
 * deleting one), null skipped. The parameter is the base whose destructor is
 * 0xd687e0 (the vtable 0x16c81c0, stored by FUN_00d68470 and FUN_00d687e0),
 * the class the factory's object derives from; the registry's own pointer type
 * is not traced. */
class Object00d687e0 /* derived name */
{
  public:
    virtual ~Object00d687e0();
};

void FUN_001b8480(Object00d687e0 *object) /* derived name */
{
    delete object;
}
