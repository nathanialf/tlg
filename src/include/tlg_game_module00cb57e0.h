/* src/include/tlg_game_module00cb57e0.h: a script module: a file's named
 * functions entered under the file's name in the list of every module, which
 * FUN_00cb57e0 and FUN_00cb58b0 search by name (game region;
 * docs/TARGETS.md). The function names are the strings of the tables
 * ("ModuleInitialize", "ModuleRelease", ...); every other name here is
 * derived. */
#ifndef TLG_GAME_MODULE00CB57E0_H
#define TLG_GAME_MODULE00CB57E0_H

#include "tlg_types.h"

/* derived name: one entry of a module's table, 16 bytes: the name the
 * function is looked up by and the function (called with no argument by
 * FUN_00cb57e0 for "ModuleInitialize"; the entries' own signatures differ) */
struct ModuleFunction00cb57e0 {
    const char *name;   /* +0x0 */
    void (*function)(); /* +0x8 */
};

/* derived name: a module, 0x28 bytes, made by each file's static initializer
 * (the 11 callers of the constructor, 0xcb5760) and taken out of the list by
 * its destructor (0xcb57b0) at exit. Pushed at the head of the list: the old
 * head's back link points at the module's next field, the module's at the
 * head. */
class Module00cb57e0
{
  public:
    Module00cb57e0(const char *name, const ModuleFunction00cb57e0 *functions, int functionCount);
    ~Module00cb57e0();

    Module00cb57e0 *next;                    /* +0x0 */
    Module00cb57e0 **pprev;                  /* +0x8 */
    const char *name;                        /* +0x10 */
    const ModuleFunction00cb57e0 *functions; /* +0x18 */
    u32 functionCount;                       /* +0x20 */
};

extern Module00cb57e0 *D_5945880; /* derived name: the first module */

#endif
