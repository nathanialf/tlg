/* src/include/tlg_game_object0137bcf0.h: a record of two counted references
 * without a vtable (all names derived). */
#ifndef TLG_GAME_OBJECT0137BCF0_H
#define TLG_GAME_OBJECT0137BCF0_H

#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the destructor of a record without a vtable: its members
 * are destroyed from the last to the first, each a counted reference
 * dropped with its pointer cleared first. The callers show a destructor
 * (0x137bcf0 runs where a member, a local or an array's element is
 * destroyed: +0x60 of the class at 0x16b5860, 0x137bac0). The record's other
 * fields and the referenced objects' classes are not traced. */
struct Object0137bcf0 /* derived name */
{
    ~Object0137bcf0();

    u8 unknown0[0x80];
    Ref00503fb0<Object016b9108> unknown80; /* +0x80 */
    Ref00503fb0<Object016b9108> unknown88; /* +0x88 */
};

#endif
