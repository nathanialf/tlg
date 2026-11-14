/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the copy of a record of two exchanged references and a
 * 128-byte block, written member by member: the references at +0x0 and +0x8
 * assigned, then the block at +0x10 copied whole and unaligned (four 32-byte
 * moves at 0x8e3686). The record's class is not traced. */
struct Block008e3510 { /* derived name */
    u8 unknown0[0x80];
};

struct Record008e3510 { /* derived name */
    void operator=(const Record008e3510 &other);

    AtomicRef0045c470<Node00503fb0> first;  /* +0x0 */
    AtomicRef0045c470<Node00503fb0> second; /* +0x8 */
    Block008e3510 block;                    /* +0x10 */
};

void Record008e3510::operator=(const Record008e3510 &other)
{
    first = other.first;
    second = other.second;
    block = other.block;
}
