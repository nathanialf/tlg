/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: the object at +0x128 of the game's record: the name of
 * the background's fade at +0x74 and an int at +0x78 cleared with it */
struct Fade0020e440 /* derived name */
{
    u8 unknown0[0x74];
    Name name74;   /* +0x74 */
    int unknown78; /* +0x78 */
};

struct Game0020e440 /* derived name */
{
    u8 unknown0[0x128];
    Fade0020e440 *fade; /* +0x128 */
};

extern Game0020e440 *D_57c9390;

/* derived name: a script C function: with one argument naming "bgFadeOut"
 * or "bgClear" (each interned as a copy), that name is set at +0x74 of the
 * game's fade object and its int at +0x78 cleared. Returns 0. */
int FUN_0020e440(lua_State *state) /* derived name */
{
    const int count = argumentCount(state);
    Name name = nameArgument(state, 1);
    if (count == 1) {
        if (name == Name("bgFadeOut", false)) {
            D_57c9390->fade->name74 = name;
            D_57c9390->fade->unknown78 = 0;
        } else if (name == Name("bgClear", false)) {
            D_57c9390->fade->name74 = name;
            D_57c9390->fade->unknown78 = 0;
        }
    }
    return 0;
}
