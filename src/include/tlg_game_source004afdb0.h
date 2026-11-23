/* src/include/tlg_game_source004afdb0.h: the counted object Object016aa0d0
 * (tlg_game_object016aa0d0.h) takes on at +0x30 and the object it holds,
 * which Object016aa0d0 holds at +0x28 (FUN_004afdb0). Every name here is
 * derived. */
#ifndef TLG_GAME_SOURCE004AFDB0_H
#define TLG_GAME_SOURCE004AFDB0_H

#include "tlg_game_node.h"

/* derived names: the object the source below holds at +0x28: its flags at
 * +0x24 (slot 5 of Object016aa0d0 wants bit 0 without bit 7, and with bit 6
 * a non-zero int at +0x48) */
struct Value004afdb0 : Object016b9108 /* derived name */
{
    int flags24; /* +0x24 */
    u8 unknown28[0x20];
    int unknown48; /* +0x48 */
};

/* derived names: the counted object FUN_004afdb0 takes on: the object it
 * holds at +0x28 and its kind at +0x58; slot 5 of Object016aa0d0 wants bit 0
 * of the byte at +0x5c clear and a non-zero int at +0x30 */
struct Source004afdb0 : Object016b9108 /* derived name */
{
    u8 unknown24[0x4];
    AtomicRef0045c470<Value004afdb0> held28; /* +0x28 */
    int unknown30;                           /* +0x30 */
    u8 unknown34[0x24];
    int kind58; /* +0x58 */
    u8 flags5c; /* +0x5c */
};

#endif
