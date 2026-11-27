/* src/include/tlg_game_recordlayout.h: a record's layout as a list of typed
 * fields, which FUN_00d0cc60 prints a record by (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_RECORDLAYOUT_H
#define TLG_GAME_RECORDLAYOUT_H

#include "tlg_types.h"
#include "tlg_game_string01331840.h"

/* derived names: one field of a record, 12 bytes: its type at +0x4 (0 to 3
 * the 8- and 16-bit integers unsigned and signed, 4 and 5 the 32-bit, 6 and
 * 7 the 64-bit, 8 to 10 one to three floats, 11 and 12 four floats, 13 four
 * bytes and a float), how many at +0x5, the distance between them at +0x6
 * and the first's offset in the record at +0x8 */
struct RecordField { /* derived name */
    u32 unknown0;
    u8 type;    /* +0x4 */
    u8 count;   /* +0x5 */
    u16 stride; /* +0x6 */
    u32 offset; /* +0x8 */
};

/* derived names: the classes of the vtables at 0x16caf08, 0x16d02c0 and
 * 0x16d1c38, whose slot 3 prints one of their records through FUN_00d0cc60:
 * the number of fields at +0x10, the fields from slot 9 */
class RecordLayout /* derived name */
{
  public:
    virtual void slot0();                /* derived name; not traced */
    virtual void slot1();                /* derived name; not traced */
    virtual void slot2();                /* derived name; not traced */
    virtual void slot3();                /* derived name; not traced */
    virtual void slot4();                /* derived name; not traced */
    virtual void slot5();                /* derived name; not traced */
    virtual void slot6();                /* derived name; not traced */
    virtual void slot7();                /* derived name; not traced */
    virtual void slot8();                /* derived name; not traced */
    virtual const RecordField *fields(); /* derived name; slot 9 */

    u8 unknown8[0x8];
    u32 fieldCount; /* +0x10 */
};

/* the record's fields as text, each value followed by a comma, the last of a
 * field by a semicolon (leaf_00d0cc60.cpp) */
void FUN_00d0cc60(RecordLayout *layout, const void *record,
                  String01331840 *text); /* derived name */

#endif
