/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* derived names: the destructor of an object that holds an array of counted
 * references at +0x88 (its destructor called, 0x134f620) and counted
 * references at +0x0, +0x8, +0x40 and +0x48: each dropped, the last declared
 * first. A function of its own in the executable (no vtable pointer is
 * stored). The object's other members are not traced. */
struct Object01347c00 { /* derived name */
    ~Object01347c00();

    Ref00503fb0<Node00503fb0> unknown0; /* +0x0 */
    Ref00503fb0<Node00503fb0> unknown8; /* +0x8 */
    u8 unknown10[0x30];
    Ref00503fb0<Node00503fb0> unknown40; /* +0x40 */
    Ref00503fb0<Node00503fb0> unknown48; /* +0x48 */
    u8 unknown50[0x38];
    Object0134f620 unknown88; /* +0x88 */
};

Object01347c00::~Object01347c00() {}
