/* src/include/tlg_game_namelist.h: the entry of the classes that hold a
 * fixed list of names with an int each (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_NAMELIST_H
#define TLG_GAME_NAMELIST_H

#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: one entry of such a list, 8 bytes: the list starts at
 * +0x14 of its class, after the count at +0x10 (FUN_013883d0 appends one;
 * the classes' destructors, FUN_01346b90 and on, release the names from the
 * last entry down, stepping 8 bytes). */
struct NamedValue013883d0 /* derived name */
{
    Name name;
    unsigned value;
};

/* derived names: the list itself, a count and N entries, a member at +0x10
 * of each class that holds one; its implicit destructor releases the names
 * from the last entry down, inlined into the class's destructors (the
 * loop's form in the base is the inlined copy's: `cmp rbx, 0xc` against
 * the offset). Every such class's slot 2 is the same append,
 * FUN_013883d0. */
template <unsigned N>
struct NamedValueList013883d0 /* derived name */
{
    unsigned count;                /* +0x0 */
    NamedValue013883d0 entries[N]; /* +0x4 */
};

#endif
