/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the script C function "ClearEGLog" (FUN_001db8b0 registers
 * it through FUN_00c87e30, lea at 0x1de13b, signature string "ClearEGLog()"):
 * passes each pointer of the array at +0x1d0 of the object the pointer at
 * 0x581f4b8 holds, counted by the int at +0x1d8, to FUN_008d9110, the last
 * first (the array reloaded each pass), and returns 0 (no results). The state
 * is not read. The C function's own name is unknown. */
struct lua_State;
struct Entry008d9110; /* derived name */

struct Object0581f4b8 /* derived name */
{
    u8 unknown0[0x1d0];
    Entry008d9110 **unknown1d0; /* +0x1d0 */
    int unknown1d8;             /* +0x1d8: their count */
};

extern Object0581f4b8 *D_581f4b8;

void FUN_008d9110(Entry008d9110 *entry); /* derived name */

int FUN_008d7c30(lua_State *) /* derived name */
{
    Object0581f4b8 *log = D_581f4b8;
    for (int i = log->unknown1d8 - 1; i >= 0; i--)
        FUN_008d9110(log->unknown1d0[i]);
    return 0;
}
