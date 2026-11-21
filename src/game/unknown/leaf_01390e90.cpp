/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived name: the entries walked from the first to the end (`shl rcx, 3`
 * on the count, then `add rdx, 8; add rcx, -8; jne`) */
// NONMATCHING: the result's copies: the base gives each exit of the exchange's release its own
// `mov rax, rbx; jmp` and the last found's exit its own block (314 bytes); the build joins them
// in one block (290 bytes). The loop and the exchange are the base's. Seven forms tried.
Entry016b4ce0 *Object016b4ce0::find(const int &id)
{
    Entry016b4ce0 *found = static_cast<Entry016b4ce0 *>(found10.get());
    if (found == 0 || found->id310 != id) {
        found = 0;
        for (const Ref00503fb0<Object016b9108> *at = entries.begin(); at != entries.end(); ++at) {
            Entry016b4ce0 *entry = static_cast<Entry016b4ce0 *>(at->get());
            if (entry->id310 == id) {
                found10.set(entry);
                found = entry;
                break;
            }
        }
    }
    return found;
}
