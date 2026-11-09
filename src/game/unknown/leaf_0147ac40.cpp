/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the pointer at +0x17a8, a pointer to a
 * record with a reference count at +0x8. FUN_01228180 passes its address (lea
 * at 0x122bd51) as the getter beside the setter FUN_0147aed0, which swaps the
 * pointer in with lock cmpxchg, increments the new record's count and
 * decrements the old one's (both after testing for 0xdeadc0de); the getter's
 * parameter is the record the setter adjusts. Owner and meaning unknown. */
struct Counted01476130 { /* derived name */
    u8 unknown0[8];
    int count; /* the setters test it against 0xdeadc0de, the released mark, before they change it */
};

struct Object01476130 { /* derived name */
    u8 unknown0[0x1788];
    Counted01476130 *unknown1788; /* its address returned by FUN_01476130, stored by FUN_01476070 */
    Counted01476130 *unknown1790; /* its address returned by FUN_01476200, stored by FUN_01476140 */
    Counted01476130 *unknown1798; /* its address returned by FUN_014762d0, stored by FUN_01476210 */
    Counted01476130 *unknown17a0; /* its address returned by FUN_014763a0, stored by FUN_014762e0 */
    Counted01476130 *unknown17a8; /* its address returned by FUN_0147ac40, stored by FUN_0147aed0 */
    Counted01476130 *unknown17b0; /* its address returned by FUN_0147ac50, stored by FUN_0147af90 */
    Counted01476130 *unknown17b8; /* its address returned by FUN_0147ac60, stored by FUN_0147b050 */
    Counted01476130 *unknown17c0; /* its address returned by FUN_0147ac70, stored by FUN_0147b110 */
};

Counted01476130 **FUN_0147ac40(Object01476130 *self) /* derived name */
{
    return &self->unknown17a8;
}
