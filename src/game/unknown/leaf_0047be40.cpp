/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived name: an object's locked array field found from its description:
 * where the flags carry 0x10000 the field is at the offset (the callers
 * at 0x4791df and 0x47ad45 pass a record's flags and its word at +0x18 or
 * +0x10), else none; where they carry 0x400 the field's lock is taken and
 * given back, a wait for a writer that holds it. The callers read the count
 * at +0x8 and take the lock at +0x14 again. The object and the element type
 * are not traced. */
// NONMATCHING: greedy's assignment: the result's phi in rax (0 in eax, `mov rax, r13` on each
// arm) where the base keeps it in r13 (`xor r13d, r13d` first, `mov rax, r13` after the guard); 10/87
Array01343a80<u32> *FUN_0047be40(u8 *object, u32 flags, u32 offset) /* derived name */
{
    Array01343a80<u32> *array = nullptr;
    if (flags & 0x10000) {
        array = reinterpret_cast<Array01343a80<u32> *>(object + offset);
        if (flags & 0x400) {
            array->lock.lock();
            array->lock.unlock();
        }
    }
    return array;
}
