/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 13 of the vtable at 0x16bf260 (the class of
 * FUN_013d1d60, leaf_013d1d50.cpp): returns a new 0x30-byte object of the
 * class whose vtable is at 0x16d3778 (config/vtables.derived.base.txt; stored
 * also by FUN_00f3fb20), its constructor inlined: the int at +0x8 and the 32
 * bytes at +0x10 cleared. The object itself is not read. The members' types
 * are not traced. The destructor is empty and inline: the vtable's slot 0 is
 * the shared empty body 0x1af750 and slot 1 the shared deleting body 0x21a00
 * (identical code folded by the linker), so the class has no key function and
 * the vtable is emitted where it is used. */
struct Object013d1d60; /* derived name */

class Object013d2460 /* derived name */
{
  public:
    Object013d2460() : unknown8(0), unknown10(0), unknown18(0), unknown20(0), unknown28(0) {}

    virtual ~Object013d2460() {}

  private:
    int unknown8;  /* +0x8 */
    u64 unknown10; /* +0x10 */
    u64 unknown18; /* +0x18 */
    u64 unknown20; /* +0x20 */
    u64 unknown28; /* +0x28 */
};

Object013d2460 *FUN_013d2460(Object013d1d60 *) /* derived name */
{
    return new Object013d2460;
}
