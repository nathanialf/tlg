/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_string01331840.h"

/* derived names: the camera's owner, its list of the parameter names it
 * is told to overwrite at +0x1050 */
struct Owner0063d130 { /* derived name */
    u8 unknown0[0x1050];
    Array05943280<Name> overwrites; /* +0x1050 */
};

/* derived names: the game camera FUN_0063b710 drives: its owner at +0x28,
 * the object at +0xa8 whose name heads each entry, and at +0x2420 its
 * flags, bit 9 the one each entry is made under */
struct Camera0063d130 { /* derived name */
    u8 unknown0[0x28];
    Owner0063d130 *owner; /* +0x28 */
    u8 unknown30[0x78];
    Object016b9108 *objectA8; /* +0xa8 */
    u8 unknownb0[0x2420 - 0xb0];
    unsigned flags0_8 : 9;
    unsigned overwriting : 1; /* +0x2420 bit 9 (derived name) */
    unsigned flags10 : 22;
};

/* derived name: appends to the owner's list the name
 * "GameCamera.OverwriteParam:<bit 9>:<the object's name>:<first>:<second>",
 * with ":<third>" after when there is a third, then clears bit 9 */
void FUN_0063d130(Camera0063d130 *camera, const char *first, const char *second,
                  const char *third) /* derived name */
{
    const int overwriting = camera->overwriting;
    Array05943280<Name> &overwrites = camera->owner->overwrites;
    String01331840 full;
    String01331840 text;
    if (third) {
        FUN_01331840(&full, "GameCamera.OverwriteParam:%d:%s:%s:%s:%s", overwriting,
                     camera->objectA8->name.string(), first, second, third);
        Name name(full);
        overwrites.push(name);
    } else {
        FUN_01331840(&text, "GameCamera.OverwriteParam:%d:%s:%s:%s", overwriting,
                     camera->objectA8->name.string(), first, second);
        Name name(text);
        overwrites.push(name);
    }
    camera->overwriting = 0;
}
