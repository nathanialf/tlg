/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a function that returns 0. Its address is the first function
 * of the "CATE" entry of the 24-byte table at 0x57ad9a0 (a four-character tag,
 * an initialize and a shutdown function per entry); the shutdown loop (lea at
 * 0xeb5ecd) calls the third field with no arguments; the initialize call is
 * not traced (the other entries' initialize functions read their first and
 * third arguments). Its parameters are not traced: none here; the return type
 * is not traced, int is the 0 in eax. Owner and meaning unknown. */
int FUN_00ec4520() /* derived name */
{
    return 0;
}
