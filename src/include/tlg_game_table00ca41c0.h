/* src/include/tlg_game_table00ca41c0.h: the table of counted objects by
 * name the object at 0x5938c40 holds at +0xf8 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_TABLE00CA41C0_H
#define TLG_GAME_TABLE00CA41C0_H

#include "tlg_game_node.h"

/* derived names: a node of the table below: two ids, the counted object
 * and the next node of its bucket */
struct Node00ca41c0 /* derived name */
{
    unsigned id0;                             /* +0x0 */
    unsigned id4;                             /* +0x4 */
    AtomicRef0045c470<Object016b9108> value8; /* +0x8 */
    Node00ca41c0 *next10;                     /* +0x10 */
};

/* derived names: a table of 32 buckets of nodes chained at +0x10, by the
 * id's low five bits (the index of a type's name: Object016b8d40's
 * constructor and destructor look their type's name up in it) */
struct Table00ca41c0 /* derived name */
{
    /* 0xca41c0 (leaf_00ca41c0.cpp): the object of the node whose two ids
     * are `id`, or null; the found object is copied into a reference of its
     * own, whose pointer is answered as the reference is dropped */
    Object016b9108 *find(unsigned id) const; /* derived name */

    Node00ca41c0 *buckets[32];
};

#endif
