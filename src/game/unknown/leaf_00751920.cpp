/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: a 16-byte entry: a pointer, then a counted reference to an
 * object; two entries are equal when both are, the reference compared first
 * (`cmp [rcx], rsi; jne` on +0x8, then `cmp [rcx-8], rdx` on +0x0). Neither
 * is traced further. */
struct Entry00751920 { /* derived name */

    bool operator==(const Entry00751920 &other) const
    {
        return object == other.object && key == other.key;
    }

    void *key;                          /* +0x0 */
    Ref00503fb0<Object016b9108> object; /* +0x8 */
};

/* FUN_00751920: tlg_game_array.h's addUnique over the entries, out of line
 * until its caller FUN_00733dc0 is written */
template void Array05943280<Entry00751920>::addUnique(const Entry00751920 &);
