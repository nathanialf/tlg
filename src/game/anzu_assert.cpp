/* src/game/anzu_assert.cpp: the engine's report of a failed check
 * (tlg_game_assert.h). It has no address of its own in the base: the link
 * inlines it at each of its 377 sites, where the handler's null test
 * (0x5ace510) and FUN_00b8a440's body sit behind the formatted message. */
#include "tlg_types.h"

#include "tlg_game_assert.h"

void AnzuAssertFailed(const char *file, long line, const char *function, const char *condition)
{
    char message[512];
    snprintf(message, sizeof(message), "%s(%ld): %s() ASSERT(%s)", file, line, function, condition);
    if (D_5ace510)
        D_5ace510(message, "ASSERT");
    else
        puts(message);
}
