/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: nine ints of the object, then 1.0 and two zeros, set
 * together at +0x1c0 of the record at +0x5b0 of the record at +0x10 of its
 * argument (as leaf_01395e40.cpp reaches it), and the int at +0x20c of that
 * record set to 1; returns 1. The same body as FUN_01397b50 over other
 * fields. The classes and the return type are not traced. */
struct Values01399fd0 { /* derived name */
    int values[9];
    float unknown24;
    float unknown28;
    float unknown2c;
};

struct Record01399fd0 { /* derived name */
    u8 unknown0[0x1c0];
    Values01399fd0 values; /* +0x1c0 */
    u8 unknown1f0[0x1c];
    int unknown20c; /* +0x20c */
};

struct Holder01399fd0 { /* derived name */
    u8 unknown0[0x5b0];
    Record01399fd0 *unknown5b0;
};

struct Argument01399fd0 { /* derived name */
    u8 unknown0[0x10];
    Holder01399fd0 *unknown10;
};

struct Object01399fd0 { /* derived name */
    u8 unknown0[0xc4];
    int unknownc4; /* +0xc4: the record's fifth value */
    int unknownc8; /* +0xc8: the record's sixth value */
    u8 unknowncc[0x10];
    int unknowndc; /* +0xdc: the record's first value */
    int unknowne0; /* +0xe0: the record's second value */
    u8 unknowne4[0x14];
    int unknownf8; /* +0xf8: the record's seventh value */
    int unknownfc; /* +0xfc: the record's eighth value */
    u8 unknown100[0x10];
    int unknown110; /* +0x110: the record's third value */
    int unknown114; /* +0x114: the record's fourth value */
    u8 unknown118[0x20];
    int unknown138; /* +0x138: the record's ninth value */
};

int FUN_01399fd0(Object01399fd0 *self, Argument01399fd0 *argument) /* derived name */
{
    Record01399fd0 *record = argument->unknown10->unknown5b0;
    const Values01399fd0 values = {{self->unknowndc, self->unknowne0, self->unknown110,
                                    self->unknown114, self->unknownc4, self->unknownc8,
                                    self->unknownf8, self->unknownfc, self->unknown138},
                                   1.0f,
                                   0.0f,
                                   0.0f};
    record->values = values;
    record->unknown20c = 1;
    return 1;
}
