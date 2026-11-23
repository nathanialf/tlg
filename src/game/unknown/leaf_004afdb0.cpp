/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_source004afdb0.h"

/* derived names: the table at 0x57d6b00 of a value for each kind, ended by
 * kind 0 (0x4aff2b: the first kind read at +0x4, the next at +0xc) */
struct KindValue004afdb0 /* derived name */
{
    int value;
    int kind;
};

extern KindValue004afdb0 D_57d6b00[];

/* derived name: the table's value for a kind, -1 for a kind it lacks */
static inline int valueOfKind(int kind)
{
    for (const KindValue004afdb0 *entry = D_57d6b00; entry->kind != 0; ++entry)
        if (entry->kind == kind)
            return entry->value;
    return -1;
}

/* derived names: the object FUN_004b7xxx (0x4b78d6) hands a source to:
 * the source's object and the source held at +0x28 and +0x30, and an int
 * at +0x38 */
struct Object004afdb0 /* derived name */
{
    /* 0x4afdb0: the source's object and the source held; a negative value
     * is the table's value for the source's kind, when the table has one */
    void take(Source004afdb0 *source, int value); /* derived name */

    u8 unknown0[0x28];
    AtomicRef0045c470<Object016b9108> held28; /* +0x28 */
    AtomicRef0045c470<Object016b9108> held30; /* +0x30 */
    int unknown38;                            /* +0x38 */
};

void Object004afdb0::take(Source004afdb0 *source, int value)
{
    held28.set(source->held28.get());
    held30.set(source);
    if (value < 0)
        value = valueOfKind(source->kind58);
    unknown38 = value;
}
