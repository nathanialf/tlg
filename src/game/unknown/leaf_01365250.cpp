/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of an object that holds counted references
 * at +0x20, +0x58, +0x60, +0x68: each dropped, the last declared first. A function of its own in
 * the executable (no vtable pointer is stored: not a virtual destructor).
 * The object's other members and the referenced class are not traced. */
class Value01365250 : public Node00503fb0 /* derived name */
{
};

struct Object01365250 { /* derived name */
    ~Object01365250();

    u8 unknown0[0x20];
    Ref00503fb0<Value01365250> unknown20; /* +0x20 */
    u8 unknown28[0x30];
    Ref00503fb0<Value01365250> unknown58; /* +0x58 */
    Ref00503fb0<Value01365250> unknown60; /* +0x60 */
    Ref00503fb0<Value01365250> unknown68; /* +0x68 */
};

Object01365250::~Object01365250() {}
