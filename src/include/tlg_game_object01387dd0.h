/* src/include/tlg_game_object01387dd0.h: an object holding three counted
 * references, whose destructor is 0x1387dd0 (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT01387DD0_H
#define TLG_GAME_OBJECT01387DD0_H

#include "tlg_game_node.h"

/* derived names: the destructor of an object that holds counted references
 * at +0x0, +0x8, +0x10: each dropped, the last declared first. A function of its own in
 * the executable (no vtable pointer is stored: not a virtual destructor).
 * The object is 0x60 bytes (the element of FUN_009f5720's array: `lea rdi,
 * [rax+rax*2]; shl rdi, 5`); its other members and the referenced class are
 * not traced. */
class Value01387dd0 : public Object016b9108 /* derived name */
{
};

struct Object01387dd0 { /* derived name */
    ~Object01387dd0();

    Ref00503fb0<Value01387dd0> unknown0;  /* +0x0 */
    Ref00503fb0<Value01387dd0> unknown8;  /* +0x8 */
    Ref00503fb0<Value01387dd0> unknown10; /* +0x10 */
    u8 unknown18[0x48];
};

#endif
