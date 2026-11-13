/* src/include/tlg_game_object013cfb60.h: the object whose eight counted references at
 * +0x1d18 to +0x1d50 each have a getter and a setter (game region;
 * docs/TARGETS.md). Every name here is derived: the owner is named by the
 * first getter's file (leaf_013cfb60.cpp, which sees the references as
 * plain pointers to a counted record); the referenced objects' classes are
 * not traced beyond the count and slot 2. */
#ifndef TLG_GAME_OBJECT013CFB60_H
#define TLG_GAME_OBJECT013CFB60_H

#include "tlg_game_node.h"

struct Object013cfb60 { /* derived name */
    u8 unknown0[0x1d18];
    AtomicRef0045c470<Node00503fb0>
        unknown1d18; /* +0x1d18: set by FUN_013cfaa0, its address returned by FUN_013cfb60 */
    AtomicRef0045c470<Node00503fb0>
        unknown1d20; /* +0x1d20: set by FUN_013cfb70, its address returned by FUN_013cfc30 */
    AtomicRef0045c470<Node00503fb0>
        unknown1d28; /* +0x1d28: set by FUN_013cfc40, its address returned by FUN_013cfd00 */
    AtomicRef0045c470<Node00503fb0>
        unknown1d30; /* +0x1d30: set by FUN_013cfd10, its address returned by FUN_013cfdd0 */
    AtomicRef0045c470<Node00503fb0>
        unknown1d38; /* +0x1d38: set by FUN_013df0c0, its address returned by FUN_013dd790 */
    AtomicRef0045c470<Node00503fb0>
        unknown1d40; /* +0x1d40: set by FUN_013df180, its address returned by FUN_013dd7a0 */
    AtomicRef0045c470<Node00503fb0>
        unknown1d48; /* +0x1d48: set by FUN_013df240, its address returned by FUN_013dd7b0 */
    AtomicRef0045c470<Node00503fb0>
        unknown1d50; /* +0x1d50: set by FUN_013df300, its address returned by FUN_013dd7c0 */
};

#endif
