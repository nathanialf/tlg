/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a member function that returns false. FUN_00b14040 stores its
 * address at +0x28 of a record with 0 at +0x30 (a pointer to member function,
 * no adjustment), chosen over FUN_00b10e30 by the byte at +0x81; FUN_00b10e30
 * reads the object's +0x74 and returns a bool in al. A free function with a
 * self pointer until the record is typed (round 98A's ruling). Class and
 * method unknown. */
struct Object00b10eb0;

bool FUN_00b10eb0(Object00b10eb0 *self) /* derived name */
{
    return false;
}
