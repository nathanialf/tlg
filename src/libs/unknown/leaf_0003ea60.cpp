/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the character type, the int at +0xc; the game code at
 * 0xeaa625 calls it with 1 on the context it has just built (0x3e840). */
void hknpCharacterContext::FUN_0003ea60(int type)
{
    characterType = type;
}
