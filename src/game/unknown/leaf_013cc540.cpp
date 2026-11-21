/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 5 of the vtable at 0x16d34e0 (its pointer at
 * 0x16d3508; the class of leaf_013cc900.cpp): for the body whose id is at
 * +0xc of its first argument (entries of 0x90 bytes at +0x20 of the world
 * at +0x18) and the body whose id is at +0x20 of the record given, each
 * body's owner (+0x88), asks the first owner's handler (+0x20) through its
 * slot 10 with a query made from the record: its two vectors as x, y and z
 * with a w of one, its int at +0x24, its flag at +0x28 (1 or 0) and the
 * second owner's handler. 0 when an owner or the handler is missing or the
 * answer is -1 or above 1; 1 when it is 0; when it is 1 the query's vectors
 * (w zero), int and flag are copied back into the record first, and 1. The
 * classes are not traced. */
struct alignas(16) Point013cc540 { /* derived name */
    float x, y, z, w;

    void set(const Vec4 &v)
    {
        x = component<0>(v);
        y = component<1>(v);
        z = component<2>(v);
        w = 1.0f;
    }
};

struct Query013cc540 { /* derived name */
    Point013cc540 unknown0;
    Point013cc540 unknown10;
    int unknown20;
    int unknown24;
    void *unknown28;
};

class Handler013cc540 /* derived name */
{
  public:
    virtual void slot0();                     /* derived name; not traced */
    virtual void slot1();                     /* derived name; not traced */
    virtual void slot2();                     /* derived name; not traced */
    virtual void slot3();                     /* derived name; not traced */
    virtual void slot4();                     /* derived name; not traced */
    virtual void slot5();                     /* derived name; not traced */
    virtual void slot6();                     /* derived name; not traced */
    virtual void slot7();                     /* derived name; not traced */
    virtual void slot8();                     /* derived name; not traced */
    virtual void slot9();                     /* derived name; not traced */
    virtual int slot10(Query013cc540 *query); /* derived name */
};

struct Owner013cc540 { /* derived name */
    u8 unknown0[0x20];
    Handler013cc540 *unknown20;
};

struct Body013cc540 { /* derived name */
    u8 unknown0[0x88];
    Owner013cc540 *unknown88;
};

struct World013cc540 { /* derived name */
    u8 unknown0[0x20];
    Body013cc540 *bodies;

    Body013cc540 &getBody(int bodyId) /* derived name */
    {
        return bodies[bodyId];
    }
};

struct Source013cc540 { /* derived name */
    u8 unknown0[0xc];
    int bodyId;
    u8 unknown10[0x8];
    World013cc540 *world;
};

struct Record013cc540 { /* derived name */
    Vec4 unknown0;
    Vec4 unknown10;
    int bodyId;
    int unknown24;
    u8 unknown28;
};

// NONMATCHING: the flag's compares: the base tests 1 then 0 on the widened byte, the build's switch 0 first on the byte (41 of 94 equal); then the answer's -1 case kept apart from the default in the base. Not the load's zero lane: the same with r248784's change
int FUN_013cc540(void *self, const Source013cc540 *source,
                 Record013cc540 *record) /* derived name */
{
    World013cc540 *world = source->world;
    Owner013cc540 *owner = world->getBody(source->bodyId).unknown88;
    if (owner == 0) {
        return 0;
    }
    Handler013cc540 *handler = owner->unknown20;
    if (handler == 0) {
        return 0;
    }
    Owner013cc540 *other = world->getBody(record->bodyId).unknown88;
    if (other == 0) {
        return 0;
    }
    Query013cc540 query;
    query.unknown0.set(record->unknown0);
    query.unknown10.set(record->unknown10);
    query.unknown20 = record->unknown24;
    if (record->unknown28 == 1) {
        query.unknown24 = 1;
    } else if (record->unknown28 == 0) {
        query.unknown24 = 0;
    }
    query.unknown28 = other->unknown20;
    const int answer = handler->slot10(&query);
    if (answer == -1) {
        return 0;
    }
    if (answer == 0) {
        return 1;
    }
    if (answer == 1) {
        record->unknown0 = loadXYZ_0(&query.unknown0.x);
        record->unknown10 = loadXYZ_0(&query.unknown10.x);
        record->unknown24 = query.unknown20;
        if (query.unknown24 == 1) {
            record->unknown28 = 1;
        } else if (query.unknown24 == 0) {
            record->unknown28 = 0;
        }
        return 1;
    }
    return 0;
}
