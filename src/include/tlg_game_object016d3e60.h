/* src/include/tlg_game_object016d3e60.h: the class whose vtable is at
 * 0x16d3e60 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D3E60_H
#define TLG_GAME_OBJECT016D3E60_H

#include "tlg_game_block.h"
#include "tlg_game_object0139b6b0.h"

/* derived names: the object at +0x48 of the class at 0x16d3e60, told by
 * its slot 10 (`call [rax+0x50]`) when its holder goes; nothing else of it
 * is traced */
class Link016d3e60 /* derived name */
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
    virtual void detach(); /* derived name: slot 10 */
};

/* derived name: the object at +0x50 of the class at 0x16d3e60, deleted
 * through its slot 1 (`call [rax+8]`) when its holder goes */
class Owned016d3e60 /* derived name */
{
  public:
    virtual ~Owned016d3e60();
};

/* derived names: the records of the class at 0x16d3e60 with the block at
 * +0x18 and an int at +0x20, cleared together: the int zeroed through the
 * table's own address (the complete destructor computes +0x8 before it
 * stores +0x28, `lea rdx, [r15+8]` ahead of `mov dword [r15+0x28], 0`),
 * then every record dropped */
struct RecordTable016d3e60 /* derived name */
{
    void clear() /* derived name */
    {
        unknown20 = 0;
        entries.removeAll();
    }

    Array05943280<Entry0139b6b0> entries; /* +0x0 */
    OwnedBlock05943280 block18;           /* +0x18 */
    int unknown20;                        /* +0x20: zero before the entries go */
};

/* derived names: the class whose vtable is at 0x16d3e60 (two slots: the
 * complete destructor 0x13d7400 and the deleting one 0x13d9390). Its fields
 * are traced only where the destructor reads them: a table of 16-byte
 * records with a counted reference each at +0x8 (its destructor
 * 0x139b6b0 out of line), with a block at +0x20 and an int at +0x28, an
 * object told at +0x48 and one owned at +0x50. */
class Object016d3e60 /* derived name */
{
  public:
    virtual ~Object016d3e60();

  private:
    RecordTable016d3e60 records; /* +0x8 */
    u8 unknown30[0x18];
    Link016d3e60 *link48;   /* +0x48 */
    Owned016d3e60 *owned50; /* +0x50 */
};

#endif
