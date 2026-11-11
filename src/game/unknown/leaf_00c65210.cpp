/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: three callbacks stored side by side at +0x1e28 of an owner
 * by FUN_00be6da0 (0xbe795d), as the other triples before them (+0x1628,
 * +0x1a28): each walks one list of a holder (+0x30 with its count at +0x38
 * for the first and third, +0x50 and +0x58 for the second) and, for every
 * element whose object at +0x38 has a non-zero kind (+0x24), calls the
 * visitor's handler of that kind (the table at +0x48) when one is set, with
 * the visitor and the object. Each returns 0. Classes and methods unknown. */
struct Target00c65210 { /* derived name */
    u8 unknown0[0x24];
    int kind; /* +0x24 */
};

struct Element00c65210 { /* derived name */
    u8 unknown0[0x38];
    Target00c65210 *target; /* +0x38 */
};

struct Visitor00c65210; /* derived name */

typedef void (*Handler00c65210)(Visitor00c65210 *visitor,
                                Target00c65210 *target); /* derived name */

struct Visitor00c65210 { /* derived name */
    u8 unknown0[0x48];
    Handler00c65210 *handlers; /* +0x48 */
};

struct Holder00c65210 { /* derived name */
    u8 unknown0[0x30];
    Element00c65210 **first; /* +0x30 */
    unsigned firstCount;     /* +0x38 */
    u8 unknown3c[0x14];
    Element00c65210 **second; /* +0x50 */
    unsigned secondCount;     /* +0x58 */
};

static inline void visitAll(Visitor00c65210 *visitor, Element00c65210 **elements,
                            unsigned count) /* derived name */
{
    Element00c65210 **end = elements + count;
    for (Element00c65210 **element = elements; element != end; ++element) {
        Target00c65210 *target = (*element)->target;
        if (target && target->kind) {
            if (Handler00c65210 handler = visitor->handlers[target->kind])
                handler(visitor, target);
        }
    }
}

int FUN_00c65210(Visitor00c65210 *visitor, Holder00c65210 *holder) /* derived name */
{
    visitAll(visitor, holder->first, holder->firstCount);
    return 0;
}

int FUN_00c65270(Visitor00c65210 *visitor, Holder00c65210 *holder) /* derived name */
{
    visitAll(visitor, holder->second, holder->secondCount);
    return 0;
}

int FUN_00c652d0(Visitor00c65210 *visitor, Holder00c65210 *holder) /* derived name */
{
    visitAll(visitor, holder->first, holder->firstCount);
    return 0;
}
