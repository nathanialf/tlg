/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the destructor of a pair of counted references, 16 bytes,
 * without a vtable: the reference at +0x8 dropped, then the one at +0x0,
 * each pointer cleared first. The callers show a destructor (56 sites:
 * 0x2bbbea runs it on each 16-byte element of an array, `shl rdi, 4; add
 * rdi, [r14+0x60]`, before the count is cleared). The referenced objects'
 * classes are not traced. */
struct Object01367090 /* derived name */
{
    ~Object01367090();

    Ref00503fb0<Node00503fb0> unknown0; /* +0x0 */
    Ref00503fb0<Node00503fb0> unknown8; /* +0x8 */
};

Object01367090::~Object01367090() {}
