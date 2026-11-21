/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: nine ints of the object, then 1.0 and two zeros, set
 * together at +0x1c0 of the record at +0x5b0 of the record at +0x10 of its
 * argument (as leaf_01395e40.cpp reaches it), and the int at +0x20c of that
 * record set to 1; returns 1. The same body as FUN_01399fd0 over other
 * fields. The classes and the return type are not traced. */
struct Values01397b50 { /* derived name */
    int values[9];
    float unknown24;
    float unknown28;
    float unknown2c;
};

struct Record01397b50 { /* derived name */
    u8 unknown0[0x1c0];
    Values01397b50 values; /* +0x1c0 */
    u8 unknown1f0[0x1c];
    int unknown20c; /* +0x20c */
};

struct Holder01397b50 { /* derived name */
    u8 unknown0[0x5b0];
    Record01397b50 *unknown5b0;
};

struct Argument01397b50 { /* derived name */
    u8 unknown0[0x10];
    Holder01397b50 *unknown10;
};

struct Object01397b50 { /* derived name */
    u8 unknown0[0x8c];
    int unknown8c; /* +0x8c: the record's fifth value */
    int unknown90; /* +0x90: the record's sixth value */
    u8 unknown94[0x10];
    int unknowna4; /* +0xa4: the record's first value */
    int unknowna8; /* +0xa8: the record's second value */
    u8 unknownac[0x14];
    int unknownc0; /* +0xc0: the record's seventh value */
    int unknownc4; /* +0xc4: the record's eighth value */
    u8 unknownc8[0x10];
    int unknownd8; /* +0xd8: the record's third value */
    int unknowndc; /* +0xdc: the record's fourth value */
    u8 unknowne0[0x20];
    int unknown100; /* +0x100: the record's ninth value */
};

int FUN_01397b50(Object01397b50 *self, Argument01397b50 *argument) /* derived name */
{
    Record01397b50 *record = argument->unknown10->unknown5b0;
    const Values01397b50 values = {{self->unknowna4, self->unknowna8, self->unknownd8,
                                    self->unknowndc, self->unknown8c, self->unknown90,
                                    self->unknownc0, self->unknownc4, self->unknown100},
                                   1.0f,
                                   0.0f,
                                   0.0f};
    record->values = values;
    record->unknown20c = 1;
    return 1;
}
