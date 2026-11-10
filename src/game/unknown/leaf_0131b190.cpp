/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: forwards its five first arguments to FUN_0131a010 with 0
 * inserted as the sixth and its own sixth passed on as the seventh (on the
 * stack); slot 18 of the vtable at 0x16c39b8 (its pointer at 0x16c3a58). The
 * arguments' types and the return type are not traced. Class and method
 * unknown. */
struct Object0131b190; /* derived name */

void FUN_0131a010(Object0131b190 *self, void *a, void *b, void *c, void *d, void *e,
                  void *f); /* derived name */

void FUN_0131b190(Object0131b190 *self, void *a, void *b, void *c, void *d,
                  void *f) /* derived name */
{
    FUN_0131a010(self, a, b, c, d, 0, f);
}
