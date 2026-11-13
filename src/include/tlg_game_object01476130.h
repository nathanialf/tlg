/* src/include/tlg_game_object01476130.h: the object whose eight counted references at
 * +0x1788 to +0x17c0 each have a getter and a setter (game region;
 * docs/TARGETS.md). Every name here is derived: the owner is named by the
 * first getter's file (leaf_01476130.cpp, which sees the references as
 * plain pointers to a counted record); the referenced objects' classes are
 * not traced beyond the count and slot 2. */
#ifndef TLG_GAME_OBJECT01476130_H
#define TLG_GAME_OBJECT01476130_H

#include "tlg_game_node.h"

struct Object01476130 { /* derived name */
    u8 unknown0[0x1788];
    AtomicRef0045c470<Node00503fb0>
        unknown1788; /* +0x1788: set by FUN_01476070, its address returned by FUN_01476130 */
    AtomicRef0045c470<Node00503fb0>
        unknown1790; /* +0x1790: set by FUN_01476140, its address returned by FUN_01476200 */
    AtomicRef0045c470<Node00503fb0>
        unknown1798; /* +0x1798: set by FUN_01476210, its address returned by FUN_014762d0 */
    AtomicRef0045c470<Node00503fb0>
        unknown17a0; /* +0x17a0: set by FUN_014762e0, its address returned by FUN_014763a0 */
    AtomicRef0045c470<Node00503fb0>
        unknown17a8; /* +0x17a8: set by FUN_0147aed0, its address returned by FUN_0147ac40 */
    AtomicRef0045c470<Node00503fb0>
        unknown17b0; /* +0x17b0: set by FUN_0147af90, its address returned by FUN_0147ac50 */
    AtomicRef0045c470<Node00503fb0>
        unknown17b8; /* +0x17b8: set by FUN_0147b050, its address returned by FUN_0147ac60 */
    AtomicRef0045c470<Node00503fb0>
        unknown17c0; /* +0x17c0: set by FUN_0147b110, its address returned by FUN_0147ac70 */
};

#endif
