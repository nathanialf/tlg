/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3d88.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16bfc28
 * (config/vtables.derived.base.txt), derived from Object016d3d88: slot 2 is
 * its own (FUN_013d9130: the base's slot 2, then +0x70 cleared), slot 4
 * FUN_00f7d600 (not traced), the rest the base's. The class of 0x16bfcb8
 * (slot 4 FUN_00f83550) holds the same slot 2: two bodies of one form the
 * link folded, claimed from the lower vtable. Its destructor is the implicit one
 * (slots 0 and 1 hold the base's pair): slot 2 is the key function, so this
 * file emits the vtable. */
class Object016bfc28 : public Object016d3d88 /* derived name */
{
  public:
    virtual void slot2(); /* derived name */

  private:
    int unknown70; /* +0x70 */
};

void Object016bfc28::slot2()
{
    Object016d3d88::slot2();
    unknown70 = 0;
}

/* derived names: FUN_013d90d0 is slot 2 of the vtable at 0x16bfc70 (the class
 * Object016bfc70 of leaf_013d9d50.cpp, not yet in a header): it calls
 * FUN_013d9150 too, then resets the members at +0x80 and +0xa0 through
 * FUN_013d8be0, each followed by an int (+0x70, +0x74) set to 0 and an aligned
 * vector (+0xd0, +0xe0) zeroed. The members' type is not traced. */
struct Member013d9130 { /* derived name */
    u8 unknown0[0x20];
};

struct Object013d9130 { /* derived name */
    u8 unknown0[0x70];
    int unknown70;
    int unknown74;
    u8 unknown78[8];
    Member013d9130 unknown80;
    Member013d9130 unknowna0;
    u8 unknownc0[0x10];
    Float4A unknownd0;
    Float4A unknowne0;
};

void FUN_013d9150(Object013d9130 *self);   /* derived name */
void FUN_013d8be0(Member013d9130 *member); /* derived name */

void FUN_013d90d0(Object013d9130 *self) /* derived name */
{
    FUN_013d9150(self);
    FUN_013d8be0(&self->unknown80);
    self->unknown70 = 0;
    self->unknownd0.set(0.0f, 0.0f, 0.0f, 0.0f);
    FUN_013d8be0(&self->unknowna0);
    self->unknown74 = 0;
    self->unknowne0.set(0.0f, 0.0f, 0.0f, 0.0f);
}
