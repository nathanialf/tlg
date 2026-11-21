/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the first 16 bytes of the 64-byte records FUN_00885840
 * and FUN_00886300 assign one to another (0x885d5d, 0x88681d: the record's
 * address `lea rdi, [r15+rbx]` after `shl rbx, 6`): a name, an int and a
 * counted reference another thread may replace. The rest of the record is
 * not traced. */
struct Binding008a9640 /* derived name */
{
    /* 0x8a9640: the name, the int and the reference assigned in turn */
    void operator=(const Binding008a9640 &other);

    Name name;                               /* +0x0 */
    int unknown4;                            /* +0x4 */
    AtomicRef0045c470<Object016b9108> held8; /* +0x8 */
};

void Binding008a9640::operator=(const Binding008a9640 &other)
{
    name = other.name;
    unknown4 = other.unknown4;
    held8 = other.held8;
}
