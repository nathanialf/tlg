/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The member type table (derived name), one row per hkClassMember::Type
 * including TYPE_MAX. The base reaches it with a direct `lea`, so it is local
 * to this TU (docs/DECISIONS.md D17); its rows are written at build time from
 * the user's executable (D18, config/data_schema.base.txt). */
static const hkClassMember::TypeProperties D_16dc150[36] = {
#include "gen/D_16dc150.inc"
};

/* derived name: the properties of a member type, its row of the table at
 * 0x16dc150 (0x4768 reads the size of an enum's or a flags member's
 * storage type through it). The type is the enum, indexed unsigned. */
const hkClassMember::TypeProperties &hkClassMember::FUN_00007d40(Type type) /* derived name */
{
    return D_16dc150[type];
}
