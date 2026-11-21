/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_commandbuffer.h"
#include "tlg_types.h"

struct Object01499e20 { /* derived name */
    u8 unknown0[0x47c0];
    CommandBuffer01496a80 commands; /* +0x47c0 */
};

extern "C" int sceGnmInsertPushMarker(u32 *commands, u32 words, const char *marker);

/* derived name: a push marker written into the buffer when there is room for
 * it: its size in words from the string's length; the same body as
 * FUN_01496a00 with its buffer at +0x47c0 */
void FUN_01499e20(Object01499e20 *self, const char *marker) /* derived name */
{
    const u32 length = strlen(marker);
    const u32 words = 2 * ((length + 12) / 8) + (length + 8) / 4 + 2;
    CommandBuffer01496a80 &commands = self->commands;
    if (commands.remaining() < words && !commands.reserve(&commands, words, commands.userData))
        return;
    if (sceGnmInsertPushMarker(commands.cursor, words, marker) == 0)
        commands.cursor += words;
}
