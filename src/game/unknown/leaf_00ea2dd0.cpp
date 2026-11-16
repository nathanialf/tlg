/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_log.h"
#include "tlg_libc.h"

/* derived names: a line of text written to the game's output on channel 0
 * (nothing for a null text), then a newline unless the text ends with one;
 * no direct caller. */
void FUN_00ea2dd0(const char *text) /* derived name */
{
    if (text)
        debugOutput().write(0, text, strlen(text));
    if (text[strlen(text) - 1] != '\n')
        debugOutput().write(0, "\n", 1);
}
