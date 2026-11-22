/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* derived names: forwards its five first arguments to slot 19 (FUN_0131a010)
 * with 0 inserted as the sixth and its own sixth passed on as the seventh
 * (on the stack). The arguments' types and the return type are not traced. */
void FUN_0131a010(JsDeviceContext *self, void *a, void *b, void *c, void *d, void *e,
                  void *f); /* derived name */

void JsDeviceContext::slot18(void *a, void *b, void *c, void *d, void *f)
{
    FUN_0131a010(this, a, b, c, d, 0, f);
}
