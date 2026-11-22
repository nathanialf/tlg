/* src/include/tlg_game_object016b85e0.h: the class whose vtable is at
 * 0x16b85e0, a base of many game classes (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B85E0_H
#define TLG_GAME_OBJECT016B85E0_H

#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b85e0
 * (config/vtables.derived.base.txt, stored by its constructor 0xc55320 and
 * its complete destructor 0xc55550; both rows named for it, D15), derived
 * from the root class Object016b9108: the constructor first runs the root's
 * (`call 0xcb6310` with the name it was given), the destructor ends in the
 * root's body (the names at +0x10 and +0xc dropped), and slot 2 of the
 * vtable is the root's release 0xcb66f0. Its own fields begin at +0x24, in
 * the root's tail padding, and end at +0x238 (the constructor's last store,
 * a quadword at +0x230). It is the scene node (round 434A): the
 * constructor lays out the members below (the lock at +0x30 the destructor
 * takes as a writer, `lock cmpxchg [rbx+0x30], 0x10000` at 0xc555ba; the
 * children's array at +0x40 and the components' at +0x58, each with its
 * count after it and its allocator's id after that, read from the thread at
 * 0xc55386 and 0xc553b4; the 16-byte rows from +0x70, stored with `vmovaps`,
 * which align the class; the empty Name at +0x210 and the index -1 at
 * +0x218, the vector (0, 0, -1, 1) at 0xc55484). The classes derived from it tail-call
 * the destructor from their own (leaf_0080b1e0.cpp and the files that
 * include this header). The destructor is not written, so nothing here
 * emits the vtable. */
class Object016b85e0 : public Object016b9108 /* derived name */
{
  public:
    Object016b85e0(const Name &name); /* 0xc55320, its row named after it (D15) */
    virtual ~Object016b85e0();
    /* slots 3 and 4 of 0x16b85e0: FUN_0134a390 and FUN_0134a3a0, in place
     * of the root's empty bodies; parameters not traced */
    virtual void slot3(); /* derived name; FUN_0134a390 */
    virtual void slot4(); /* derived name; FUN_0134a3a0 */
    /* slots 5 to 9, the class's own (slots 8 and 9 the empty body at
     * 0x1af750); the parameters of 7 to 9 not traced. Slot 5 adds a child
     * (FUN_00c573b0: one with no parent at its +0x28, under this object's
     * lock at +0x30), slot 6 takes one out (FUN_00c575d0: only a child whose
     * parent is this object); the classes derived from it call both under
     * the world's write lock (FUN_00b44ec0, FUN_00b45280) */
    virtual void addChild(Object016b9108 *child);    /* derived name; FUN_00c573b0 */
    virtual void removeChild(Object016b9108 *child); /* derived name; FUN_00c575d0 */
    virtual void slot7();                            /* derived name; FUN_00c59010 */
    virtual void slot8();                            /* derived name; 0x1af750 */
    virtual void slot9();                            /* derived name; 0x1af750 */

    /* the component at a signed index (`movsxd` at each use under an unsigned
     * counter: 0x9f54b0, 0x5065f0) */
    Component00503fb0 *componentAt(int index) const /* derived name */
    {
        return components[index];
    }

    /* the child at a signed index (`movsxd` under an unsigned counter at
     * 0x83c9c4), read without a reference of its own */
    Object016b85e0 *childAt(int index) const /* derived name */
    {
        return children[index].get();
    }

    /* the first component from `next` on whose type is `type` or derives
     * from it; `next` is left after it */
    Component00503fb0 *findComponent(const Type00503fb0 *type, unsigned &next) /* derived name */
    {
        FUN_01331c10(&readers);
        Component00503fb0 *found = 0;
        for (unsigned i = next; i < componentCount; ++i) {
            if (::isKindOf(componentAt(i)->type, type)) {
                found = componentAt(i);
                next = i + 1;
                break;
            }
        }
        __sync_fetch_and_sub(&readers, 1);
        return found;
    }

    /* the first component whose type is `type` or derives from it */
    Component00503fb0 *findComponent(const Type00503fb0 *type) /* derived name */
    {
        unsigned next = 0;
        return findComponent(type, next);
    }

    int unknown24; /* +0x24: the index of the object's handler in a visitor's table (FUN_00589590) */
    u8 unknown28[0x8];
    /* +0x30: the reader count (FUN_01331c10 takes it, an atomic decrement
     * drops it); a writer holds 0x10000 (slots 5 and 6, the destructor) */
    int readers;
    Object016b85e0 *parent;                /* +0x38 */
    Ref00503fb0<Object016b85e0> *children; /* +0x40 */
    unsigned childCount;                   /* +0x48 */
    u8 unknown4c[0xc];
    Component00503fb0 **components; /* +0x58 */
    unsigned componentCount;        /* +0x60 */
    u8 unknown64[0xc];

    /* the position and the rotation set from a value that differs (the
     * three floats of the position, the four of the rotation, compared in
     * turn), the node marked changed in bit 0 of the root's flags
     * (FUN_00a12990: `vucomiss; jne` three times, `vmovaps`, `or byte
     * [rcx+0x20], 1`) */
    void setPosition(const Float4A &value) /* derived name */
    {
        if (position.x != value.x || position.y != value.y || position.z != value.z) {
            position = value;
            flags |= 1;
        }
    }

    void setRotation(const Float4A &value) /* derived name */
    {
        if (rotation.x != value.x || rotation.y != value.y || rotation.z != value.z ||
            rotation.w != value.w) {
            rotation = value;
            flags |= 1;
        }
    }

    Float4A unknown70; /* +0x70: the first of the rows; not traced */
    u8 unknown80[0x70];
    Float4A position; /* +0xf0 (derived name) */
    u8 unknown100[0x10];
    Float4A rotation;   /* +0x110 (derived name) */
    Float4A unknown120; /* +0x120 */
    u8 unknown130[0x10];
    Float4A unknown140; /* +0x140 */
    u8 unknown150[0xc0];
    Name name210; /* +0x210: empty from the constructor */
    u8 unknown214[0x4];
    int index; /* +0x218: the node's place in its parent's children, -1 from the constructor */
    u8 unknown21c[0x1c];
};

#endif
