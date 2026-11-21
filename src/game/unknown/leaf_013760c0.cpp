/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the counted objects of the arrays FUN_00949e10 (at +0x28
 * of its object, emptied to 0x800) and FUN_01375860 empty; not traced */
struct Value013760c0 : Object016b9108 /* derived name */
{};

/* FUN_013760c0 is the emptying of an array of counted references to them
 * to a given capacity (tlg_game_array.h's clear(size)), out of line: the
 * array's own member, instantiated here until a caller of it is written. */
// NONMATCHING: the capacity is spilled as 64 bits in the base (`mov [rbp - 0x30], rsi`, read
// back whole) and as 32 in the build (`mov [rbp - 0x2c], esi`); 0x1372960's copy spills 32 as
// this build does. The rest is the base's.
template void Array05943280<Ref00503fb0<Value013760c0>>::clear(unsigned);
