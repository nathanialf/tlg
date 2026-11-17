/* src/include/tlg_game_object01367090.h: a pair of counted references (16
 * bytes, no vtable), whose destructor FUN_01367090 is called on each element
 * of the arrays that hold it (game region; docs/TARGETS.md). Every name here
 * is derived. */
#ifndef TLG_GAME_OBJECT01367090_H
#define TLG_GAME_OBJECT01367090_H

#include "tlg_game_node.h"

/* derived names: the destructor of a pair of counted references, 16 bytes,
 * without a vtable: the reference at +0x8 dropped, then the one at +0x0,
 * each pointer cleared first. The callers show a destructor (56 sites:
 * 0x2bbbea runs it on each 16-byte element of an array, `shl rdi, 4; add
 * rdi, [r14+0x60]`, before the count is cleared). The referenced objects'
 * classes are not traced. */
struct Object01367090 /* derived name */
{
    ~Object01367090();

    Ref00503fb0<Object016b9108> unknown0; /* +0x0 */
    Ref00503fb0<Object016b9108> unknown8; /* +0x8 */
};

#endif
