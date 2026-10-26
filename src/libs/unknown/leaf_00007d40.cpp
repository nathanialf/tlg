/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the properties of a member type, its row of the table at
 * 0x16dc150 (0x4768 reads the size of an enum's or a flags member's
 * storage type through it). The type is the enum, indexed unsigned. */
// NONMATCHING: the base reaches the table with `lea rcx, [rip+0x16dc150]`, so
// the table is defined in this TU with internal linkage (a namespace-scope
// const array); declared extern it is read through the GOT (`addq
// D@GOTPCREL(%rip)`, not relaxed, D10). Defining it here needs its 35 rows
// (type names among them) as a claimed data object and the gate's
// resolution of a relocation against a file-local object: docs/NOTES.md,
// Round 19.
const hkClassMember::TypeProperties &hkClassMember::FUN_00007d40(Type type) /* derived name */
{
    return D_16dc150[type];
}
