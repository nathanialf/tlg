/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the copy of a record of two exchanged references, written
 * member by member: the references at +0x0 and +0x8 assigned, then the int
 * at +0x18 and the eight bytes at +0x10, in that order (`mov eax, [r14+0x18];
 * mov [r15+0x18], eax; mov rax, [r14+0x10]; mov [r15+0x10], rax` at
 * 0x5a49b6). The record's class is not traced. */
struct Record005a4840 { /* derived name */
    void operator=(const Record005a4840 &other);

    AtomicRef0045c470<Node00503fb0> first;  /* +0x0 */
    AtomicRef0045c470<Node00503fb0> second; /* +0x8 */
    u64 unknown10;                          /* +0x10 */
    int unknown18;                          /* +0x18 */
};

void Record005a4840::operator=(const Record005a4840 &other)
{
    first = other.first;
    second = other.second;
    unknown18 = other.unknown18;
    unknown10 = other.unknown10;
}
