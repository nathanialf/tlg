/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: the position an object (a soldier, by FUN_00ac0fe0's
 * mode) keeps at +0x280: its node's while the node at +0x40 of its record
 * at +0x350 is shown, its own at +0x50 otherwise. A node is not shown when
 * its model (+0x50) answers slot 5 and holds a part (+0x30) that is hidden
 * (the model's byte at +0x3c, or bit 0 of the part's flags at +0x5c); else
 * by its flags: bit 0 of +0x58 when bit 3 of +0x5c is set, otherwise bit 0
 * of +0x58 with neither bit 8 of it nor bits 0 and 1 of +0x5c. A node's
 * position is its own at +0x30 when bit 7 of +0x58 is set, its model's at
 * +0x40 otherwise. Called by FUN_00ac0fe0 and FUN_00ac8170. */
struct Part00430580 { /* derived name */
    u8 unknown0[0x5c];
    u32 flags; /* +0x5c */
};

class Model00430580 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual bool slot5(); /* derived name */

    u8 unknown8[0x28];
    Part00430580 *part; /* +0x30 */
    u8 unknown38[0x4];
    bool hidden; /* +0x3c */
    u8 unknown3d[0x3];
    Float4A position; /* +0x40 */
};

struct Node00430580 { /* derived name */
    u8 unknown0[0x30];
    Float4A position; /* +0x30 */
    u8 unknown40[0x10];
    Model00430580 *model; /* +0x50 */
    u32 flags58;          /* +0x58 */
    u32 flags5c;          /* +0x5c */

    bool shown() const
    {
        Model00430580 *shown = model;
        if (shown->slot5() && shown->part && (shown->hidden || (shown->part->flags & 1)))
            return false;
        bool enabled = flags58 & 1;
        if (flags5c & 8)
            return enabled;
        return enabled && !(flags58 & 0x100) && !(flags5c & 3);
    }

    const Float4A &worldPosition() const
    {
        if (flags58 & 0x80)
            return position;
        return model->position;
    }
};

struct Record00430580 { /* derived name */
    u8 unknown0[0x40];
    Node00430580 *node; /* +0x40 */
};

struct Object00430580 { /* derived name */
    u8 unknown0[0x50];
    Float4A position; /* +0x50 */
    u8 unknown60[0x220];
    Float4A shownPosition; /* +0x280 */
    u8 unknown290[0xc0];
    Record00430580 *record; /* +0x350 */
};

// NONMATCHING: the flag tests. The base reads +0x5c before +0x58, tests
// bit 0 of +0x58 in a block of its own and the rest as one value,
// `(flags58 & 0x100) | (flags5c & 3)` (too many instructions for SimplifyCFG
// to fold into the bit 0 test's branch); this build folds bit 0 and bit 8
// into one test (`and 0x101; cmp 1`). The copy's target is formed once
// (`lea rax, [r14+0x280]`) in the base; 176 bytes against 175.
void FUN_00430580(Object00430580 *object) /* derived name */
{
    Record00430580 *record = object->record;
    if (record->node && record->node->shown() && record->node)
        object->shownPosition = record->node->worldPosition();
    else
        object->shownPosition = object->position;
}
