/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object016b9108.h"
#include "tlg_types.h"

/* derived names: slots 27 and 28 of the vtable at 0x16b1208 (its pointers
 * at 0x16b12f0 and 0x16b12f8), Object016b1208's (leaf_00967d40.cpp), written
 * over the fields they read: each 0x100-byte entry of the array at +0x50
 * (its count at +0x58 read again after each entry) holds an array of
 * objects at +0x48, each with a polymorphic second base at +0x10 (its slot 1 told
 * by slot 27, its slot 2 by slot 28 with the argument), the count read once
 * per entry; slot 27 then tells the entry's object at +0x40 (its slot 11).
 * What the calls mean is not traced. */
class Part00968ef0 /* derived name */
{
  public:
    virtual void slot0();          /* derived name; not traced */
    virtual void slot1();          /* derived name; not traced */
    virtual void slot2(int value); /* derived name; not traced */
};

/* derived names: the object's first base, polymorphic, 0x10 bytes */
class Head00968ef0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
};

/* derived names: an object of an entry's array, its part the second base */
class Item00968ef0 : public Head00968ef0, public Part00968ef0 /* derived name */
{
};

class Target00968ef0 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
};

struct Entry00968ef0 { /* derived name */
    u8 unknown0[0x40];
    Target00968ef0 *target;              /* +0x40 */
    Array05943280<Item00968ef0 *> items; /* +0x48 */
    u8 unknown60[0x84];
    u8 flagse4; /* +0xe4: bit 0 has slot 19 hand the entry to FUN_0092d7e0 */
    u8 unknowne5[0x1b];
};

/* derived names: the object at +0x28, of the root class: an int at +0x4c8
 * cleared by slot 19 */
class Node00968ef0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x4a4];
    int unknown4c8; /* +0x4c8 */
};

struct Object00968ef0 { /* derived name */
    u8 unknown0[0x28];
    Node00968ef0 *node; /* +0x28 */
    u8 unknown30[0x20];
    Entry00968ef0 *entries; /* +0x50 */
    u32 count;              /* +0x58 */
    int unknown5c;          /* +0x5c: while it is set slot 19 leaves the entries alone */
};

void FUN_00968ef0(Object00968ef0 *self) /* derived name */
{
    for (u32 i = 0; i < self->count; ++i) {
        Entry00968ef0 &entry = self->entries[i];
        const unsigned n = entry.items.size();
        for (unsigned j = 0; j < n; ++j)
            entry.items.at(j)->slot1();
        entry.target->slot11();
    }
}

void FUN_00968f90(Object00968ef0 *self, int value) /* derived name */
{
    for (u32 i = 0; i < self->count; ++i) {
        Entry00968ef0 &entry = self->entries[i];
        const unsigned n = entry.items.size();
        for (unsigned j = 0; j < n; ++j)
            entry.items.at(j)->slot2(value);
    }
}

extern const Type00503fb0 *D_58208d8; /* derived name: the node's type */

void FUN_0092d7e0(Entry00968ef0 *entry, Node00968ef0 *node,
                  float value); /* derived name: not traced */

/* derived names: slot 19 (its pointer at 0x16b12b0): when the node at +0x28
 * is of the type D_58208d8 points to, its int at +0x4c8 is cleared and,
 * unless +0x5c is set, each entry whose flag bit 0 is set is handed to
 * FUN_0092d7e0 with the node and the value; returns 1 */
int FUN_009686b0(Object00968ef0 *self, float value) /* derived name */
{
    Node00968ef0 *node = self->node;
    if (node && node->isKindOf(D_58208d8)) {
        node->unknown4c8 = 0;
        if (!self->unknown5c)
            for (u32 i = 0; i < self->count; ++i)
                if (self->entries[i].flagse4 & 1)
                    FUN_0092d7e0(&self->entries[i], node, value);
    }
    return 1;
}

int FUN_0092d4f0(Entry00968ef0 *entry, Node00968ef0 *node,
                 u32 remaining); /* derived name: not traced */

/* derived names: slot 10 (its pointer at 0x16b1268): with no entries 0;
 * else each entry in turn is handed to FUN_0092d4f0 with the node at +0x28
 * (null unless it is of the type D_58208d8 points to) and the number of
 * entries from it on, 0 at the first that answers 0; after the last +0x5c
 * is cleared and 1 returned */
// NONMATCHING: the type walk as a value (round 365B, whole module, 14/60, 161 bytes against
// 177): the base keeps a flag for "not of the type" (`mov dil, 1` in the loop, two `xor edi,
// edi` arms for the two hits) and selects null on it (`test dil, dil; cmovne rax, 0`); the
// build merges the hits (`mov dl, 1` before the walk, `xor edx, edx` at its end) and selects the
// node; `target ? ... : 0` and the reset form give the same
int FUN_00968120(Object00968ef0 *self) /* derived name */
{
    if (!self->count)
        return 0;
    Node00968ef0 *target = self->node;
    if (target && !target->isKindOf(D_58208d8))
        target = 0;
    for (u32 i = 0; i < self->count; ++i)
        if (!FUN_0092d4f0(&self->entries[i], target, self->count - i))
            return 0;
    self->unknown5c = 0;
    return 1;
}
