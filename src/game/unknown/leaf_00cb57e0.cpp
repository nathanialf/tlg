/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: opens a module of the list at 0x5945880 by its name: a new
 * 16-byte handle holding the module, after the module's function named
 * "ModuleInitialize" (its table of names and functions at +0x18, the count
 * at +0x20) is called when it has one; null for an empty name or a name no
 * module has. */
struct ModuleFunction00cb57e0 { /* derived name */
    const char *name;
    void (*function)();
};

struct Module00cb57e0 {   /* derived name */
    Module00cb57e0 *next; /* +0x0 */
    u8 unknown8[8];
    const char *name;                  /* +0x10 */
    ModuleFunction00cb57e0 *functions; /* +0x18 */
    u32 functionCount;                 /* +0x20 */
};

struct ModuleHandle00cb57e0 { /* derived name */
    Module00cb57e0 *module;   /* +0x0 */
    int unknown8;             /* +0x8 */
};

extern Module00cb57e0 *D_5945880; /* derived name: the first module */

// NONMATCHING: greedy's assignment in the function loop (the base's index in rbx, the entry
// in r13 and the string in r12; the build rbx, r12, r13 the other way round) and the
// order of the two increments (list-ilp); every other instruction equal
ModuleHandle00cb57e0 *FUN_00cb57e0(const char *name) /* derived name */
{
    if (!name || !*name)
        return 0;
    for (Module00cb57e0 *module = D_5945880; module; module = module->next) {
        if (strcmp(name, module->name) == 0) {
            ModuleHandle00cb57e0 *handle = new ModuleHandle00cb57e0;
            handle->module = module;
            handle->unknown8 = 0;
            for (size_t i = 0; i < module->functionCount; i++) {
                if (strcmp("ModuleInitialize", module->functions[i].name) == 0) {
                    if (module->functions[i].function)
                        module->functions[i].function();
                    break;
                }
            }
            return handle;
        }
    }
    return 0;
}
