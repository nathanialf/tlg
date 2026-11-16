/* src/include/tlg_game_object012ada80.h: the objects whose four arrays of
 * counted references the seven functions FUN_012ada80, FUN_012f95a0,
 * FUN_0129dda0, FUN_00f27820, FUN_010749f0, FUN_011f4cb0 and FUN_012b83c0
 * empty. derived names throughout. */
#ifndef TLG_GAME_OBJECT012ADA80_H
#define TLG_GAME_OBJECT012ADA80_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_registry00cb8240.h"

/* the class the arrays refer to; not traced (FUN_00f2b550 is the arrays'
 * clear) */
class Value00f2b550 : public Object016b9108 /* derived name */
{
};

struct Object012ada80 : Object00cb8240 { /* derived name */
    u8 unknown20[0x10];
    Array05943280<Ref00503fb0<Value00f2b550>> array30; /* +0x30 */
    Array05943280<Ref00503fb0<Value00f2b550>> array48; /* +0x48 */
    Array05943280<Ref00503fb0<Value00f2b550>> array60; /* +0x60 */
    Array05943280<Ref00503fb0<Value00f2b550>> array78; /* +0x78 */
};

/* two tables kept side by side (0x5ad8f08 and 0x5ad8f10) */
struct Tables00c1ac70 {       /* derived name */
    Registry00cb8240 *first;  /* +0x0 */
    Registry00cb8240 *second; /* +0x8 */
};

/* both tables emptied, the second first, then their ids given back
 * (0x12adb58 to 0x12adb9c) */
inline void empty(const Tables00c1ac70 &tables) /* derived name */
{
    FUN_00c1ac70(tables.second);
    FUN_00c1ac70(tables.first);
    FUN_00cbb8d0(D_5945a38, tables.second->id);
    FUN_00cbb8d0(D_5945a38, tables.first->id);
}

#endif
