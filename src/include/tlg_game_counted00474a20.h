/* src/include/tlg_game_counted00474a20.h: the class of the objects the
 * append FUN_00474a20 takes references to, and the holder of the array
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COUNTED00474A20_H
#define TLG_GAME_COUNTED00474A20_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"

/* derived names: one of the root class's, made by FUN_00466970 as an
 * object of the type at 0x5814dc8 under one of the names of
 * func_004730f0.cpp's list. Not traced further. The array of references to
 * it has its append as a function of its own in the executable,
 * FUN_00474a20 (leaf_00474a20.cpp), called from 2 sites in FUN_00466970. */
struct Counted00474a20 : Object016b9108 { /* derived name */
};

typedef Array05943280<Ref00503fb0<Counted00474a20>> Array00474a20; /* derived name */

/* derived names: the object of the type at 0x5814dd0 named by the name at
 * 0x57d5fe0, of the root class, that holds the made objects in the array at
 * +0x238; the rest of it is not traced */
struct Holder00466970 : Object016b9108 { /* derived name */

    /* the index of the object of the name, or -1: the elements counted
     * unsigned and indexed through at(int) (`movsxd rbx, esi`, `inc esi;
     * cmp esi, eax; jb` at 0x466a50) */
    int find(const Name &name) const /* derived name */
    {
        for (unsigned i = 0; i < objects238.size(); ++i)
            if (objects238.at(i).get()->name == name)
                return i;
        return -1;
    }

    u8 unknown24[0x214];
    Array00474a20 objects238; /* +0x238 */
};

/* derived names: the holder's type and the made objects' type
 * (`mov rbx, [0x5814dd0]`, `mov rsi, [0x5814dc8]` in FUN_00466970) */
extern Type00503fb0 *D_5814dd0;
extern Type00503fb0 *D_5814dc8;

#endif
