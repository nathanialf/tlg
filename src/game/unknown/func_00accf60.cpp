/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00accf60 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800), then the table of
 * subtypes, destroyed by the array destructor the compiler writes for it
 * (0xacd370, registered last). Slot 5 of the soldier mode at 0x16b38c0
 * (FUN_00acc450) reads the table. */

extern const char D_15a7f36[18];
extern const char D_15a7f48[15];
extern const char D_15a7f57[9];
extern const char D_15a7f60[8];
extern const char D_15a7f68[13];
extern const char D_15a7f75[13];
extern const char D_15a7f82[13];
extern const char D_15a7f8f[13];
extern const char D_15a7f9c[13];
extern const char D_15a7fa9[13];
extern const char D_15a7fb6[13];
extern const char D_15a7fc3[13];

Name D_582c250(D_15a7f36, false);
Name D_582c1f4(D_15a7f48, false);
Name D_582c1f0(D_15a7f57, false);
Name D_582c1f8(D_15a7f60, false);

/* an entry of 12 bytes: a soldier subtype and the two angles slot 5 copies
 * to +0x15f0 and +0x15f4 of the soldier (derived names) */
struct Subtype00accf60 { /* derived name */

    Name subtype; /* +0x0 */
    float first;  /* +0x4 */
    float second; /* +0x8 */
};

// NONMATCHING: the file's initializer (FUN_00accf60): each entry's two angles are stored
// as one 8-byte constant (MergeConsecutiveStores) where the base keeps two 4-byte stores
// (cookbook 2142's open {name, a, b} case).
static Subtype00accf60 D_582c190[] = {
    {Name(D_15a7f68, false), -175.0f, -60.0f}, {Name(D_15a7f75, false), 180.0f, -180.0f},
    {Name(D_15a7f82, false), -150.0f, -65.0f}, {Name(D_15a7f8f, false), 180.0f, -180.0f},
    {Name(D_15a7f9c, false), -170.0f, -65.0f}, {Name(D_15a7fa9, false), 180.0f, -180.0f},
    {Name(D_15a7fb6, false), -170.0f, -65.0f}, {Name(D_15a7fc3, false), 10.0f, 100.0f},
};

struct Entity00accf60; /* derived name */

/* the soldier's object at +0x348: an int and a 16-byte vector slot 7 clears */
struct Motion00accf60 { /* derived name */
    u8 unknown0[0x68];
    int unknown68; /* +0x68 */
    u8 unknown6c[0x4];
    Vector4 unknown70; /* +0x70 */
};

/* the object at +0x50 of the soldier's target: slot 5 asks whether it is
 * set, its object at +0x30 holds a flag word at +0x5c */
struct Flags00accf60 { /* derived name */
    u8 unknown0[0x5c];
    u32 unknown5c; /* +0x5c */
};

class Part00accf60 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual bool slot5(); /* derived name */

    /* whether the part holds the target: set by slot 5 and either the bool
     * at +0x3c or bit 0 of its object's flags */
    bool holds() /* derived name */
    {
        return slot5() && unknown30 && (unknown3c || (unknown30->unknown5c & 1));
    }

    u8 unknown8[0x28];
    Flags00accf60 *unknown30; /* +0x30 */
    u8 unknown38[0x4];
    bool unknown3c; /* +0x3c */
};

/* the target at +0x40 of the soldier's object at +0x350 */
struct Target00accf60 { /* derived name */

    /* bit 0 of the flags at +0x58; unless bit 3 of +0x5c is set, also
     * neither bit 8 of +0x58 nor bits 0 and 1 of +0x5c */
    bool ready() const /* derived name */
    {
        if (!(unknown5c & 8) && ((unknown58 & 0x100) || (unknown5c & 3)))
            return false;
        return unknown58 & 1;
    }

    u8 unknown0[0x50];
    Part00accf60 *unknown50; /* +0x50 */
    u32 unknown58;           /* +0x58 */
    u32 unknown5c;           /* +0x5c */
};

struct Holder00accf60 { /* derived name */
    u8 unknown0[0x40];
    Target00accf60 *unknown40; /* +0x40 */
};

struct Record002a45c0 { /* derived name */
    u8 unknown0[0x58];
    Name name; /* +0x58 */
};

/* the soldier a mode's owner points to (as leaf_0046d150.cpp's) */
struct Soldier00accf60 { /* derived name */
    u8 unknown0[0x28];
    Entity00accf60 *entity; /* +0x28 */
    u8 unknown30[0x318];
    Motion00accf60 *unknown348; /* +0x348 */
    Holder00accf60 *unknown350; /* +0x350 */
    u8 unknown358[0x44];
    Name subtype; /* +0x39c */
    u8 unknown3a0[0xec];
    bool unknown48c; /* +0x48c */
    u8 unknown48d[0x43];
    float unknown4d0; /* +0x4d0 */
    u8 unknown4d4[0x111c];
    float unknown15f0; /* +0x15f0 */
    float unknown15f4; /* +0x15f4 */
};

/* the mode before this one (slot 5's argument): its int at +0x10 */
struct PreviousMode00accf60 { /* derived name */
    u8 unknown0[0x10];
    int unknown10; /* +0x10 */
};

/* the soldier mode whose vtable is at 0x16b38c0 (stored by FUN_00abf490), as
 * slot 5 sees it (leaf_00accd20.cpp's fields) */
struct Mode00accf60 { /* derived name */
    u8 unknown0[0x8];
    Soldier00accf60 **unknown8; /* +0x8: the owner */
    u8 unknown10[0x8];
    int unknown18;  /* +0x18 */
    int unknown1c;  /* +0x1c */
    bool unknown20; /* +0x20 */
    u8 unknown21[0x1f];
    bool unknown40; /* +0x40 */
    u8 unknown41[0x3];
    int unknown44; /* +0x44 */
    u8 unknown48[0x4];
    bool unknown4c; /* +0x4c */
    bool unknown4d; /* +0x4d */
    bool unknown4e; /* +0x4e */
    bool unknown4f; /* +0x4f: the angles taken from the table */
};

extern const Name D_57d5304; /* derived name: the key of a soldier's subtype record */
extern const Name D_57d4f60; /* derived name: the subtype of a soldier without one */

Record002a45c0 *FUN_002a45c0(Entity00accf60 *entity, const Name *key,
                             int unknown2);                      /* derived name */
void FUN_0048af30(Entity00accf60 *entity, bool on, int unknown); /* derived name */

/* derived name: the soldier's subtype (leaf_0046d150.cpp) */
static inline const Name &subtypeOf(const Soldier00accf60 *soldier)
{
    if (soldier->subtype.index != 0)
        return soldier->subtype;
    const Record002a45c0 *record = FUN_002a45c0(soldier->entity, &D_57d5304, 1);
    return record ? record->name : D_57d4f60;
}

/* derived names: slot 5 of the mode: resets its state; after a mode whose
 * int at +0x10 is 0, sets +0x18 to 1, hands the soldier's entity to
 * FUN_0048af30 (on, 1) and sets +0x44 to 2 and +0x4c; the first time, copies
 * the two angles of the soldier's subtype from the table to the soldier. */
void FUN_00acc450(Mode00accf60 *self, const PreviousMode00accf60 *previous) /* derived name */
{
    self->unknown18 = 0;
    self->unknown1c = -1;
    self->unknown20 = false;
    self->unknown40 = false;
    self->unknown44 = 0;
    self->unknown4c = false;
    self->unknown4d = false;
    if (previous) {
        self->unknown4e = previous->unknown10 == 0;
        if (self->unknown4e) {
            self->unknown18 = 1;
            FUN_0048af30((*self->unknown8)->entity, true, 1);
            self->unknown44 = 2;
            self->unknown4c = true;
        }
    } else {
        self->unknown4e = false;
    }
    if (!self->unknown4f) {
        const Name &subtype = subtypeOf(*self->unknown8);
        for (const Subtype00accf60 &entry : D_582c190) {
            if (entry.subtype == subtype) {
                Soldier00accf60 *soldier = *self->unknown8;
                soldier->unknown15f0 = entry.first;
                soldier->unknown15f4 = entry.second;
                break;
            }
        }
        self->unknown4f = true;
    }
}

struct Mission00accf60 { /* derived name */
    u8 unknown0[0x44];
    float unknown44; /* +0x44 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Mission00accf60 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;
extern const Name D_57d6d38; /* derived name: the key looked up (leaf_00accd20.cpp) */
extern const Name D_57d6d4c; /* derived name */
extern const Name D_57d6b70; /* derived name */

void FUN_00accd20(Mode00accf60 *self);                                       /* derived name */
void FUN_0048fc20(Entity00accf60 *entity);                                   /* derived name */
void FUN_004a6bf0(const Name &first, const Name &second, const Name &third); /* derived name */

/* derived names: slot 7 of the mode: clears the soldier's motion record,
 * leaves through FUN_00accd20, sets the soldier's float at +0x4d0 to the
 * mission's +0x44 plus 20 when +0x40 is set, hands the entity to
 * FUN_0048af30 (off, 0) when +0x4c is set, then to FUN_0048fc20; marks the
 * soldier's byte at +0x48c when its target is ready and not held; then as
 * FUN_00accd20 for the record of the key at 0x57d6d38 when +0x4d is set. */
void FUN_00accde0(Mode00accf60 *self) /* derived name */
{
    Motion00accf60 *motion = (*self->unknown8)->unknown348;
    motion->unknown68 = 0;
    motion->unknown70 = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    FUN_00accd20(self);
    if (self->unknown40) {
        Soldier00accf60 *soldier = *self->unknown8;
        soldier->unknown4d0 = D_57c9390->unknown38->unknown900->unknown44 + 20.0f;
    }
    if (self->unknown4c) {
        FUN_0048af30((*self->unknown8)->entity, false, 0);
        self->unknown4c = false;
    }
    FUN_0048fc20((*self->unknown8)->entity);
    Holder00accf60 *holder = (*self->unknown8)->unknown350;
    if (Target00accf60 *target = holder->unknown40) {
        if (!target->unknown50->holds() && target->ready() && holder->unknown40)
            (*self->unknown8)->unknown48c = true;
    }
    if (self->unknown4d) {
        if (Entity00accf60 *entity = (*self->unknown8)->entity) {
            if (Record002a45c0 *record = FUN_002a45c0(entity, &D_57d6d38, 1))
                FUN_004a6bf0(D_57d6d4c, record->name, D_57d6b70);
        }
        self->unknown4d = false;
    }
}
