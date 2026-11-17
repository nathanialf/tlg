/* src/include/tlg_game_fadeparam013f9ca0.h: the parameter records FUN_013f9ca0
 * and its three copies (FUN_01489b20, FUN_0148aaf0, FUN_0148b5b0) write into
 * an object or into one of its owner's elements, read from their bytes. Every
 * name here is derived. */
#ifndef TLG_GAME_FADEPARAM013F9CA0_H
#define TLG_GAME_FADEPARAM013F9CA0_H

#include "tlg_types.h"

/* derived name: four floats copied as one block (an unaligned 16-byte copy
 * both ways) */
struct ParamValue4 { /* derived name */
    float v[4];
};

/* derived names: one record of 0x70 bytes. A record whose +0x0 is not zero
 * is skipped; its kind picks the value written, its destination type where:
 * 0 the object itself, 1 the owner's element whose id it names. The value
 * lands at the byte offset at +0x20. */
struct ParamRecord013f9ca0 { /* derived name */
    int disabled;            /* +0x0: the record is skipped unless zero */
    unsigned kind;           /* +0x4: 0 to 4: which value below is written */
    int destination;         /* +0x8: 0 the object, 1 an element of the owner */
    u8 unknownc[0x4];
    const int *elementId; /* +0x10: the element's id (destination 1) */
    u8 unknown18[0x8];
    int offset; /* +0x20: the byte offset written */
    u8 unknown24[0xc];
    ParamValue4 value30; /* +0x30: kind 0 */
    ParamValue4 value40; /* +0x40: kind 1 */
    int value50;         /* +0x50: kind 2 */
    int value54;         /* +0x54: kind 3 */
    int value58;         /* +0x58: kind 4 */
    u8 unknown5c[0x14];
};

/* derived names: the records of one group (16 bytes) */
struct ParamGroup013f9ca0 {       /* derived name */
    ParamRecord013f9ca0 *records; /* +0x0 */
    int count;                    /* +0x8 */
    u8 unknownc[0x4];
};

/* derived names: the object the records are written into: its groups at
 * +0x58, chosen by an index the callers read from its +0x134 */
struct ParamTarget013f9ca0 { /* derived name */
    u8 unknown0[0x58];
    ParamGroup013f9ca0 *groups; /* +0x58 */
};

/* derived names: an element a record can name, by its id at +0x1c */
struct ParamElement013f9ca0 { /* derived name */
    u8 unknown0[0x1c];
    int id; /* +0x1c */
};

/* derived names: the elements an owner holds at its +0x28 */
struct ParamElementSet013f9ca0 { /* derived name */
    u8 unknown0[0x170];
    ParamElement013f9ca0 **elements; /* +0x170 */
    int count;                       /* +0x178 */
};

/* derived name: the object whose +0x28 holds the elements */
struct ParamOwner013f9ca0 { /* derived name */
    u8 unknown0[0x28];
    ParamElementSet013f9ca0 *set; /* +0x28 */
};

/* derived name: the record's value written at its offset from `base` */
inline void writeParam(const ParamRecord013f9ca0 &record, char *base)
{
    switch (record.kind) {
    case 0:
        *reinterpret_cast<ParamValue4 *>(base + record.offset) = record.value30;
        break;
    case 1:
        *reinterpret_cast<ParamValue4 *>(base + record.offset) = record.value40;
        break;
    case 2:
        *reinterpret_cast<int *>(base + record.offset) = record.value50;
        break;
    case 3:
        *reinterpret_cast<int *>(base + record.offset) = record.value54;
        break;
    case 4:
        *reinterpret_cast<int *>(base + record.offset) = record.value58;
        break;
    }
}

/* derived name: the owner's element with the id, or null (the id read through
 * its pointer, as Object016d7b30::findElement takes it) */
inline ParamElement013f9ca0 *findParamElement(ParamOwner013f9ca0 *owner, const int *id)
{
    ParamElementSet013f9ca0 *set = owner->set;
    for (int i = 0; i < set->count; ++i) {
        if (set->elements[i]->id == *id)
            return set->elements[i];
    }
    return 0;
}

#endif
