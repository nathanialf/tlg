/* src/include/tlg_game_object016b6dc8.h: the class whose vtable is at
 * 0x16b6dc8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B6DC8_H
#define TLG_GAME_OBJECT016B6DC8_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived name: the record slot 9 returns through the hidden pointer
 * (FUN_0139d9e0, which clears its first byte); its size is not traced */
struct Result016b6dc8_9 { /* derived name */
    bool valid;
    u8 unknown1[0x17];
};

/* derived names: the class whose vtable is at 0x16b6dc8
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b7dea0,
 * its complete destructor FUN_00b7f5f0 and the deleting ones of it and of
 * the three classes over it, vtables 0x16b6e28, 0x16b6e88, 0x16b6ee8, whose
 * slot 0 is FUN_00b7f5f0 too: their destructors are this one's), derived
 * from Object01343880. 0xc0 bytes (`mov edi, 0xc0` before operator new in
 * the creator); its fields as the creator sets them after the base's
 * constructor (FUN_00cb6310). Slot 7 (FUN_00b7fec0) is the first virtual
 * defined out of line, so its unit emits the vtable and both destructors. */
class Object016b6dc8 : public Object01343880 /* derived name */
{
  public:
    /* the complete destructor FUN_00b7f5f0: the body is empty; the
     * reference is released, then the base's destructor is inlined.
     * FUN_00b7f710, slot 1, is the deleting one and holds this one inlined.
     * Defined in the class, so slot 7 is the class's first virtual defined
     * out of line. */
    virtual ~Object016b6dc8() {}

    /* slot 7, FUN_00b7fec0: named as the base's slot is (an override
     * carries the base's name); defined in leaf_00b7fec0.cpp */
    virtual void FUN_001af750();
    /* slot 5, FUN_00b7f820: not traced */
    virtual int FUN_000058a0();
    /* slot 8, FUN_00b7fee0: not traced */
    virtual void slot8();
    /* slot 9, the record FUN_0139d9e0 returns; overridden by the three
     * classes over this one (FUN_00b807c0, FUN_00b818a0, FUN_00b823a0) */
    virtual Result016b6dc8_9 slot9();

  private:
    u32 unknown34;   /* +0x34: zero from the creator (one 8-byte store with +0x38) */
    u32 unknown38;   /* +0x38: zero from the creator */
    void *unknown40; /* +0x40: null from the creator */
    void *unknown48; /* +0x48: null from the creator */
    /* +0x50: a counted reference, empty from the creator, released by the
     * destructor */
    Ref00503fb0<Object016b9108> held50;
    u8 unknown58[0x8];
    void *unknown60;    /* +0x60: null from the creator */
    int unknown68;      /* +0x68: zero from the creator */
    float unknown6c;    /* +0x6c: 1.0 from the creator */
    u8 unknown70[0x10]; /* +0x70: zero from the creator */
    float unknown80;    /* +0x80: 1.0 from the creator */
    u8 unknown84[0xc];
    u8 unknown90[0x10]; /* +0x90: the 16 bytes at 0x1541b90 from the creator */
    u8 unknowna0[0x10]; /* +0xa0: zero from the creator */
    float unknownb0;    /* +0xb0: 1.0 from the creator */
    float unknownb4;    /* +0xb4: 1.0 from the creator */
    float unknownb8;    /* +0xb8: 0.95 from the creator */
    u8 unknownbc[0x4];
};

#endif
