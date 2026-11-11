/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_type.h"

/* derived names: two flags of the first component of the object at +0x38 of
 * the object the pointer at 0x57c9390 holds: when it has a component (the
 * array at +0x858, its count at +0x860) and the first is of the type
 * D_57d35a8 points to (or derives from it), bit 0 or bit 1 of the byte at
 * +0x28c of the record its pointer at +0x570 holds; false otherwise. */
struct Flags00644eb0 { /* derived name */
    u8 unknown0[0x28c];
    bool flag0 : 1; /* +0x28c bit 0 */
    bool flag1 : 1; /* +0x28c bit 1 */
};

struct Component00644eb0 { /* derived name */
    u8 unknown0[0x18];
    Type00503fb0 *type; /* +0x18 */
    u8 unknown20[0x550];
    Flags00644eb0 *flags; /* +0x570 */
};

struct Object00644eb0 { /* derived name */
    u8 unknown0[0x858];
    Component00644eb0 **components; /* +0x858 */
    int componentCount;             /* +0x860 */
};

struct Owner057c9390 { /* derived name */
    u8 unknown0[0x38];
    Object00644eb0 *unknown38; /* +0x38 */
};

extern Owner057c9390 *D_57c9390;
extern Type00503fb0 *D_57d35a8; /* derived name: the component's type */

/* derived name: the first component, when it is of that type */
static inline Component00644eb0 *firstComponent()
{
    Object00644eb0 *object = D_57c9390->unknown38;
    if (object->componentCount == 0)
        return 0;
    Component00644eb0 *component = object->components[0];
    return isKindOf(component->type, D_57d35a8) ? component : 0;
}

// NONMATCHING: loop layout: the base tests the first type before the loop
// and enters the loop at the parent's load (`mov rdx, [rdx]; cmp; je; test;
// jne`), the build at the compare
bool FUN_00644eb0() /* derived name */
{
    Component00644eb0 *component = firstComponent();
    if (component)
        return component->flags->flag0;
    return false;
}

// NONMATCHING: loop layout: the base tests the first type before the loop
// and enters the loop at the parent's load (`mov rdx, [rdx]; cmp; je; test;
// jne`), the build at the compare
bool FUN_00644f10() /* derived name */
{
    Component00644eb0 *component = firstComponent();
    if (component)
        return component->flags->flag1;
    return false;
}
