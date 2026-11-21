/* src/include/tlg_game_element013742e0.h: the 16-byte element of the
 * arrays whose destructor is FUN_013742e0 (leaf_013742e0.cpp) (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_ELEMENT013742E0_H
#define TLG_GAME_ELEMENT013742E0_H

#include "tlg_game_node.h"

/* derived names: a counted reference at +0x0 and 8 bytes that need no
 * destruction. The element's other members and the referenced class are not
 * traced. */
class Value013742e0 : public Object016b9108 /* derived name */
{
};

struct Element013742e0 {                 /* derived name */
    Ref00503fb0<Value013742e0> unknown0; /* +0x0 */
    u8 unknown8[8];
};

#endif
