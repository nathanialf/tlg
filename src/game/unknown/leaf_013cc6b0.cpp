/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 6 of the vtable at 0x16d34e0 (its pointer at
 * 0x16d3510; slot 5 is leaf_013cc540.cpp's): for a body valid on the world
 * at +0x18 of its first argument (its id at +0xc) and in the broad phase,
 * whose owner (the body's user data) has a handler (+0x20), the object's
 * array at +0x10 is emptied and filled by the handler's slot 11, then each
 * of its entries appended to the array given: its two vectors as x, y and z
 * with a w of zero, the body id of its object's body (+0x48 of the object at
 * +0x28; the invalid id 0x7fffffff when it has none), its int at +0x20 and
 * its flag at +0x24 (1 or 0; another value leaves the byte as it was); then
 * the object's array emptied again. The classes are not traced. */
struct alignas(16) Point013cc6b0 { /* derived name */
    float x, y, z, w;
};

struct Body013cc6b0 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
};

struct Object013cc6b0Owner { /* derived name: the object an entry names */
    u8 unknown0[0x48];
    Body013cc6b0 *unknown48;
};

struct Entry013cc6b0 { /* derived name */
    Point013cc6b0 unknown0;
    Point013cc6b0 unknown10;
    int unknown20;
    int unknown24;
    Object013cc6b0Owner *unknown28;
};

struct Record013cc6b0 { /* derived name */
    Vec4 unknown0;
    Vec4 unknown10;
    int bodyId;
    int unknown24;
    u8 unknown28;
};

class Handler013cc6b0 /* derived name */
{
  public:
    virtual void slot0();                                 /* derived name; not traced */
    virtual void slot1();                                 /* derived name; not traced */
    virtual void slot2();                                 /* derived name; not traced */
    virtual void slot3();                                 /* derived name; not traced */
    virtual void slot4();                                 /* derived name; not traced */
    virtual void slot5();                                 /* derived name; not traced */
    virtual void slot6();                                 /* derived name; not traced */
    virtual void slot7();                                 /* derived name; not traced */
    virtual void slot8();                                 /* derived name; not traced */
    virtual void slot9();                                 /* derived name; not traced */
    virtual void slot10();                                /* derived name; not traced */
    virtual void slot11(hkArray<Entry013cc6b0> *entries); /* derived name */
};

struct Owner013cc6b0 { /* derived name */
    u8 unknown0[0x20];
    Handler013cc6b0 *unknown20;
};

struct Source013cc6b0 { /* derived name */
    u8 unknown0[0xc];
    int bodyId;
    u8 unknown10[0x8];
    hknpWorld *world;
};

struct Object013cc6b0 { /* derived name */
    u8 unknown0[0x10];
    hkArray<Entry013cc6b0> entries; /* +0x10 */
};

void FUN_013cc6b0(Object013cc6b0 *self, const Source013cc6b0 *source, void *unused,
                  hkArray<Record013cc6b0> *records) /* derived name */
{
    const int bodyId = source->bodyId;
    hknpWorld *world = source->world;
    if (!world->isBodyValid(bodyId)) {
        return;
    }
    const hknpBody &body = world->bodyManager.bodies[bodyId];
    if (body.broadPhaseId == u32(-1)) {
        return;
    }
    Owner013cc6b0 *owner = reinterpret_cast<Owner013cc6b0 *>(body.userData);
    if (owner == 0) {
        return;
    }
    Handler013cc6b0 *handler = owner->unknown20;
    if (handler == 0) {
        return;
    }
    self->entries.clear();
    handler->slot11(&self->entries);
    const u32 numEntries = self->entries.getSize();
    Record013cc6b0 *added = records->expandBy(numEntries);
    for (u32 i = 0; i < numEntries; i++) {
        const Entry013cc6b0 &entry = self->entries[i];
        Record013cc6b0 &record = added[i];
        record.unknown0 = loadXYZ_0(&entry.unknown0.x);
        record.unknown10 = loadXYZ_0(&entry.unknown10.x);
        Body013cc6b0 *entryBody = entry.unknown28->unknown48;
        record.bodyId = entryBody != 0 ? entryBody->unknown34 : 0x7fffffff;
        record.unknown24 = entry.unknown20;
        if (entry.unknown24 == 0) {
            record.unknown28 = 0;
        } else if (entry.unknown24 == 1) {
            record.unknown28 = 1;
        }
    }
    self->entries.clear();
}
