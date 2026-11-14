/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16cee58 (config/vtables.derived.base.txt), slot 1: slot 0 is a method
 * declared before it (FUN_013936a0, which reads the record the pointer at +0x8
 * holds), slot 2 the deleting destructor, 0x21a00, the shared `jmp operator
 * delete` body (its stores dead before the delete). It stores the vtable (its
 * body is not empty) and nulls the pointer at +0x8. The vtable is also stored
 * by FUN_00b32dd0. */
/* The record the pointer at +0x8 holds: slot 0 hands out the addresses of
 * its areas at +0x28, +0x1828, +0x1c28, +0x1d28, +0x1e28 and +0x2028 and the
 * int at +0x2428 (their contents not traced; each extent runs to the next). */
struct Record01393730 { /* derived name */
    u8 unknown0[0x28];
    u8 unknown28[0x1828 - 0x28];
    u8 unknown1828[0x1c28 - 0x1828];
    u8 unknown1c28[0x1d28 - 0x1c28];
    u8 unknown1d28[0x1e28 - 0x1d28];
    u8 unknown1e28[0x2028 - 0x1e28];
    u8 unknown2028[0x2428 - 0x2028];
    int unknown2428;
};

/* slot 0's second argument: a count at +0x28 (of the 16-bit entries its
 * fourth argument points to, each set to 1) and the addresses it receives. */
struct Target01393730 { /* derived name */
    u8 unknown0[0x28];
    int count; /* +0x28 */
    u8 unknown2c[0x58 - 0x2c];
    void *unknown58; /* +0x58: the record's +0x28 */
    void *unknown60; /* +0x60: +0x1828 */
    void *unknown68; /* +0x68: +0x1e28 */
    void *unknown70; /* +0x70: +0x1d28 */
    void *unknown78; /* +0x78: +0x1c28 */
    void *unknown80; /* +0x80: +0x2028 */
    int unknown88;   /* +0x88: +0x2428 */
};

class Object01393730 /* derived name */
{
  public:
    /* FUN_013936a0; its third parameter is unused */
    virtual void slot0(Target01393730 *target, void *, unsigned short *entries); /* derived name */
    virtual ~Object01393730();

  private:
    Record01393730 *unknown8; /* +0x8 */
};

void Object01393730::slot0(Target01393730 *target, void *, unsigned short *entries)
{
    for (int i = 0; i < target->count; i++)
        entries[i] = 1;
    if (unknown8) {
        target->unknown58 = unknown8->unknown28;
        target->unknown60 = unknown8->unknown1828;
        target->unknown78 = unknown8->unknown1c28;
        target->unknown70 = unknown8->unknown1d28;
        target->unknown68 = unknown8->unknown1e28;
        target->unknown80 = unknown8->unknown2028;
        target->unknown88 = unknown8->unknown2428;
    }
}

Object01393730::~Object01393730()
{
    unknown8 = 0;
}
