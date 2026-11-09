/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a deleter. FUN_00e744c0 picks its address (lea at 0xe75275)
 * with the factory FUN_00e828c0 when the type it looks up equals the one at
 * 0x5949954 (object size 0x240), and passes the pair to the type registry
 * FUN_00cbb0e0 (at 0xe755ea) as the 8th and 7th arguments. It deletes the
 * object through its virtual destructor (slot 1, the deleting one), null
 * skipped. The parameter is the root of the registered classes: the factory
 * builds its object on FUN_00c55320 (at 0xe829d8), which first calls
 * FUN_00cb6310, which stores the vtable 0x16b9108 (slot 0 the destructor
 * 0xcb65f0, which stores it again); the registry's own pointer type is not
 * traced. */
class Object00cb65f0 /* derived name */
{
  public:
    virtual ~Object00cb65f0();
};

void FUN_00e82a20(Object00cb65f0 *object) /* derived name */
{
    delete object;
}
