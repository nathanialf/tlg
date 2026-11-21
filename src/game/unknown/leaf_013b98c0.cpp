/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_types.h"

/* derived names: slot 13 of the vtable at 0x16d22f0 (its pointer at
 * 0x16d2368; leaf_013b92b0.cpp's class): the flag 4 at +0x188 of the third
 * argument set when an element of the array at +0x68 of its record at
 * +0x100 has, through its target (the reference at +0x38, else the one at
 * +0x28, the one chosen read again), a record at +0x48 whose bit 0 at +0x30
 * is set, else cleared (the flags read once, the result kept apart); then
 * FUN_00d4db60 for the object when its word at +0x18c is zero. The object
 * and the second argument are not read; the classes and the return type are
 * not traced. */
struct Object013b98c0; /* derived name */

struct State013b98c0 { /* derived name */
    u8 unknown0[0x30];
    u32 flags30; /* +0x30: bit 0 tested */
};

class Target013b98c0 : public Object016b9108 /* derived name; held by counted references */
{
  public:
    u8 unknown24[0x24];
    State013b98c0 *unknown48; /* +0x48 */
};

struct Element013b98c0 { /* derived name */
    u8 unknown0[0x28];
    Ref00503fb0<Target013b98c0> unknown28; /* +0x28: the target when +0x38 is empty */
    u8 unknown30[0x8];
    Ref00503fb0<Target013b98c0> unknown38; /* +0x38 */
};

struct Record013b98c0 { /* derived name */
    u8 unknown0[0x68];
    Array05943280<Element013b98c0 *> elements; /* +0x68 */
};

struct Owner013b98c0 { /* derived name */
    u8 unknown0[0x100];
    Record013b98c0 *unknown100; /* +0x100 */
    u8 unknown108[0x80];
    u32 flags188; /* +0x188: flag 4 */
    int unknown18c;
};

void FUN_00d4db60(Owner013b98c0 *owner); /* derived name */

void FUN_013b98c0(Object013b98c0 *, void *, Owner013b98c0 *owner) /* derived name */
{
    Record013b98c0 *record = owner->unknown100;
    const u32 flags = owner->flags188;
    u32 result = flags & ~4u;
    for (unsigned i = 0; i < record->elements.size(); ++i) {
        Element013b98c0 *element = record->elements.at(i);
        const Ref00503fb0<Target013b98c0> &target =
            element->unknown38.get() ? element->unknown38 : element->unknown28;
        const Target013b98c0 *object = target.get();
        if (object && object->unknown48 && (object->unknown48->flags30 & 1))
            result = flags | 4;
    }
    owner->flags188 = result;
    if (!owner->unknown18c)
        FUN_00d4db60(owner);
}
