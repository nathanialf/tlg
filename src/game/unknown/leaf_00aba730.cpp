/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* the names func_00abc0a0.cpp's static initializer makes ("Helmet" and
 * "B_bhv_SD_2F") */
extern Name D_582ab94;
extern Name D_582ab98;

extern const Type00503fb0 *D_5814678;

/* derived names: the record at +0x38 of the record at +0x108 of the object
 * at 0x57c9390: an int at +0x2d4 */
struct Member057c9390_108_38 { /* derived name */
    u8 unknown0[0x2d4];
    int unknown2d4; /* +0x2d4 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_108_38 *unknown38; /* +0x38 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;

/* the found component's view: two arrays, the names at +0x14e0 indexing
 * the one at +0x14c8 */
struct Component00aba730 { /* derived name */
    u8 unknown0[0x14c8];
    Array05943280<int> unknown14c8; /* +0x14c8 */
    Array05943280<Name> names;      /* +0x14e0 */
};

struct Described00aba730 { /* derived name: the argument's record at +0x30 */
    u8 unknown0[0x58];
    Name name; /* +0x58 */
};

struct Argument00aba730 { /* derived name */
    u8 unknown0[0x30];
    Described00aba730 *described; /* +0x30 */
};

struct Object00aba730 { /* derived name */
    u8 unknown0[0x28];
    Object016b85e0 *node; /* +0x28 */
    u8 unknown30[0x154];
    int unknown184; /* +0x184 */
    u8 unknown188[0x30];
    int unknown1b8; /* +0x1b8 */
};

/* derived names: true when the argument's name is "Helmet", the ints at
 * +0x184 and +0x1b8 are set, the int at +0x2d4 of the shared record is
 * clear, and the node's component of the type at 0x5814678 holds the name
 * "B_bhv_SD_2F" at an index its other array reaches */
// NONMATCHING: 269 against 262 bytes: the return's zero (FUN_0046f3d0's and FUN_00ff0ab0's class): this
// build makes `xor eax, eax` in the entry and again before the search, where the base makes it once in
// the block every false path reaches; the name search's loop is the base's indexOf (round 588D)
int FUN_00aba730(Object00aba730 *self, Argument00aba730 *argument) /* derived name */
{
    if (!(argument->described->name == D_582ab94))
        return 0;
    if (!self->unknown184 || D_57c9390->unknown108->unknown38->unknown2d4 || !self->unknown1b8)
        return 0;
    Object016b85e0 *node = self->node;
    if (!node)
        return 0;
    Component00503fb0 *found = node->component(D_5814678);
    if (!found)
        return 0;
    Component00aba730 *component = reinterpret_cast<Component00aba730 *>(found);
    int index = component->names.indexOf(D_582ab98);
    return index >= 0 && unsigned(index) < component->unknown14c8.size();
}
