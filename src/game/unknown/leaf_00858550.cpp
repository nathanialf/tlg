/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_name.h"

/* derived names: a callback of the handler table the function at 0x851260
 * fills (each entry a Name's index and a function pointer, 0x581d4c0 and
 * 0x581d4c8 the first): it hands the Name at +0x14 of its second argument,
 * copied, to FUN_00cb8790 with the object the pointer at 0x57ca270 holds and
 * the visitor FUN_00218650, and returns 1. Its first parameter is unused and not
 * traced. */
struct Registry057ca270; /* derived name */

struct Event00858550 { /* derived name */
    u8 unknown0[0x14];
    Name name; /* +0x14 */
};

extern Registry057ca270 *D_57ca270;

struct Object00218650;                                      /* derived name */
int FUN_00218650(Object00218650 *object, const Name &name); /* derived name */
void FUN_00cb8790(Registry057ca270 *registry, int (*visit)(Object00218650 *, const Name &),
                  const Name &name); /* derived name */

int FUN_00858550(void *, const Event00858550 *event) /* derived name */
{
    Name name(event->name);
    FUN_00cb8790(D_57ca270, FUN_00218650, name);
    return 1;
}
