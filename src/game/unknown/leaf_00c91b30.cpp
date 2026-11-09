/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a function that returns 0. FUN_00c83870 stores its address at
 * +0x18 of the 0x90-byte state settings record it builds (the allocator
 * FUN_00c91a90 at +0x8, the printf-like FUN_00c91b40 at +0x20, the name
 * "LuaMain" at +0x28) and copies it to +0x580 of the new state; no call
 * through it is traced. Its parameters are not traced: none here; the return
 * type is not traced, int is the 0 in eax. Owner and meaning unknown. */
int FUN_00c91b30() /* derived name */
{
    return 0;
}
