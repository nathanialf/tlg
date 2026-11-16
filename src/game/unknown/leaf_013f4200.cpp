/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of an object that holds a counted reference at +0x18 and six
 * 0xb0-byte elements at +0x30, each with a counted reference at +0x98:
 * each reference dropped, the last declared first. A function of its own in
 * the executable (no vtable pointer is stored). The other members and the
 * referenced class are not traced. */
class Value013f4200 : public Object016b9108 /* derived name */
{
};

struct Element013f4200 { /* derived name: 0xb0 bytes */
    u8 unknown0[0x98];
    Ref00503fb0<Value013f4200> unknown98; /* +0x98 */
    u8 unknowna0[0x10];
};

struct Object013f4200 { /* derived name */
    ~Object013f4200();

    u8 unknown0[0x18];
    Ref00503fb0<Value013f4200> unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Element013f4200 unknown30[6]; /* +0x30 */
};

Object013f4200::~Object013f4200() {}
