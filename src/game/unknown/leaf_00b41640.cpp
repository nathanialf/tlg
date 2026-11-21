/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: clears bits 4 and 5 of the object's flags at +0x20, then
 * calls slot 5 of the three objects at +0x58, +0x60 and +0x80 (each where
 * it is set) and of each child (the counted references at +0x68, their count
 * at +0x70 read once), each child held by a reference of its own during its
 * call. The classes and the slot's meaning are not traced. */
class Part00b41640 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5(); /* derived name */
};

struct Object00b41640 { /* derived name */
    u8 unknown0[0x20];
    u8 flags20; /* +0x20 */
    u8 unknown21[0x37];
    Part00b41640 *unknown58;             /* +0x58 */
    Part00b41640 *unknown60;             /* +0x60 */
    Ref00503fb0<Part00b41640> *children; /* +0x68 */
    unsigned childCount;                 /* +0x70 */
    u8 unknown74[0xc];
    Part00b41640 *unknown80; /* +0x80 */

    const Ref00503fb0<Part00b41640> &childAt(int index) const /* derived name */
    {
        return children[index];
    }
};

void FUN_00b41640(Object00b41640 *self) /* derived name */
{
    self->flags20 &= 0xcf;
    if (self->unknown58)
        self->unknown58->slot5();
    if (self->unknown60)
        self->unknown60->slot5();
    if (self->unknown80)
        self->unknown80->slot5();
    unsigned count = self->childCount;
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Part00b41640> child(self->childAt(i));
        if (child.get())
            child.get()->slot5();
    }
}
