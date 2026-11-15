/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of an object that holds 192 0xb0-byte elements at +0x20 and
 * two more at +0x8430 and +0x84e0, each with a counted reference at +0x98:
 * each reference dropped, the last declared first. A function of its own in
 * the executable (no vtable pointer is stored). The other members and the
 * referenced class are not traced. */
class Value0134d7b0 : public Node00503fb0 /* derived name */
{
};

struct Element0134d7b0 { /* derived name: 0xb0 bytes */
    u8 unknown0[0x98];
    Ref00503fb0<Value0134d7b0> unknown98; /* +0x98 */
    u8 unknowna0[0x10];
};

struct Object0134d7b0 { /* derived name */
    ~Object0134d7b0();

    u8 unknown0[0x20];
    Element0134d7b0 unknown20[192]; /* +0x20 */
    u8 unknown8420[0x10];
    Element0134d7b0 unknown8430; /* +0x8430: its reference at +0x84c8 */
    Element0134d7b0 unknown84e0; /* +0x84e0: its reference at +0x8578 */
};

Object0134d7b0::~Object0134d7b0() {}
