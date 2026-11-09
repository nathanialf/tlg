/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include "tlg_sce_system_service.h"

/* derived names: a virtual method that hides the system splash screen, passing
 * on the import's result as a tail call; slot 13 of the vtable at 0x16b9cb0
 * (stored by FUN_001afd70). Class and method unknown. */
struct Object00cff700; /* derived name */

int FUN_00cff700(Object00cff700 *self) /* derived name */
{
    return sceSystemServiceHideSplashScreen();
}
