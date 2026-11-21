/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the 0x38-byte history record of the command callback
 * FUN_002049f0: flags in its first byte, the rings' entry count at +0x4, the
 * object it records held counted at +0x8, two rings of 16-byte entries at
 * +0x20 and +0x28 (allocated with new[]), the filled count at +0x30 and the
 * next index at +0x34. Command 2 frees both rings, runs this destructor and
 * deletes the record. */
struct Record00204260 /* derived name */
{
    ~Record00204260();

    /* both rings freed and forgotten (0x204a51, inlined in command 2) */
    void clear() /* derived name */
    {
        if (ring20) {
            delete[] ring20;
            ring20 = 0;
        }
        if (ring28) {
            delete[] ring28;
            ring28 = 0;
        }
    }

    u32 flags;                         /* +0x0 */
    u32 capacity;                      /* +0x4 */
    Ref00503fb0<Object016b9108> held8; /* +0x8 */
    u8 unknown10[0x10];
    u8 *ring20;   /* +0x20 */
    u8 *ring28;   /* +0x28 */
    u32 filled30; /* +0x30 */
    u32 next34;   /* +0x34 */
};

Record00204260::~Record00204260()
{
    clear();
}
