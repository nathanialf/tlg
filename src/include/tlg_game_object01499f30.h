/* src/include/tlg_game_object01499f30.h: the render's object over
 * Object0130acb0 whose vtable is the row _ZTV14Object01499f30 (0x16c3b90,
 * config/vtables.derived.base.txt), and the class over it whose vtable is
 * _ZTV14Object016c3b40 (0x16c3b40), the one the device's creator 0x130a930
 * makes (kind 0x1a). No string names either class; every name here is
 * derived.
 *
 * Object01499f30's slots 3 to 5 (0x131f290, 0x131f2c0, 0x131f300) are read
 * by the description's kind at +0x34 and call the context's slots with the
 * block at +0x40; its slots 6 and 7 are empty (the shared body 0x1af750).
 * Object016c3b40 overrides slots 6 and 7 (0x131f240, 0x131f270) and keeps
 * the rest. Neither declares a destructor: their complete destructors are
 * the base's vptr store and a jump to 0x130acb0 (0x1499f30, 0x1499f40 in the
 * stretch of inline functions), the derived class's folded onto the base's.
 * The context's slots 3, 4 and 5 forward to slots 3, 4 and 5 here
 * (JsDeviceContext's Begin, End and GetData, tlg_game_jsdevicecontext.h). */
#ifndef TLG_GAME_OBJECT01499F30_H
#define TLG_GAME_OBJECT01499F30_H

#include "tlg_types.h"

#include "tlg_game_object0130acb0.h"
#include "tlg_game_object05adaaa8.h"

/* derived names: the description the creator copies whole into +0x34 (8
 * bytes); the kind picks the block the object writes (0x100 bytes for 1
 * and 5, 8 for 2) */
struct QueryDesc01499f30 {
    u32 Query;     /* +0x0 */
    u32 MiscFlags; /* +0x4: not read */
};

/* derived name: the context the slots call (JsDeviceContext's slots 28 to
 * 32 by its vtable; not traced as that class, whose methods the tree
 * declares as plain members) */
class Context01499f30
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
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */
    virtual void slot20(); /* derived name; not traced */
    virtual void slot21(); /* derived name; not traced */
    virtual void slot22(); /* derived name; not traced */
    virtual void slot23(); /* derived name; not traced */
    virtual void slot24(); /* derived name; not traced */
    virtual void slot25(); /* derived name; not traced */
    virtual void slot26(); /* derived name; not traced */
    virtual void slot27(); /* derived name; not traced */
    /* slot 28: JsDeviceContext's end-of-pipe event (writeEvent) */
    virtual void slot28(void *block); /* derived name */
    /* slots 29 and 30: JsDeviceContext's counters written for the first
     * and the second of the two */
    virtual void slot29(void *block);                        /* derived name */
    virtual void slot30(void *block);                        /* derived name */
    virtual void slot31(bool flag, void *block, bool again); /* derived name */
    virtual void slot32();                                   /* derived name */
};

class Object01499f30 : public Object0130acb0 /* derived name */
{
  public:
    /* derived name: inlined by the creator (0x130a930), no block yet */
    explicit Object01499f30(u32 kind) : Object0130acb0(kind)
    {
        block = nullptr;
    }

    /* slot 3 (0x131f290): the context's slot 29 with the block for the
     * kinds 1 and 5 */
    virtual void Begin(Context01499f30 *context); /* derived name */
    /* slot 4 (0x131f2c0): the context's slot 30 for the kinds 1 and 5, its
     * slot 28 for the kind 2, with the block */
    virtual void End(Context01499f30 *context); /* derived name */
    /* slot 5 (0x131f300): the result read from the block by the kind, -2
     * for an unknown one; not written */
    virtual int FUN_0131f300(Context01499f30 *context, void *data, u32 size, u32 flags);

    /* slots 6 and 7: empty here (0x1af750), Object016c3b40's */
    virtual void slot6(Context01499f30 *context, bool flag) /* derived name */ {}

    virtual void slot7(Context01499f30 *context) /* derived name */ {}

  protected:
    u32 unknown30;          /* +0x30: not written by the creator */
    QueryDesc01499f30 desc; /* +0x34 (derived name) */
    void *block;            /* +0x40: the device's onion memory (derived name) */
};

class Object016c3b40 : public Object01499f30 /* derived name */
{
  public:
    /* derived name: the kind 0x1a */
    Object016c3b40() : Object01499f30(0x1a) {}

    /* derived name: the description copied and the block its kind writes
     * taken from the device's onion memory (the label 6); false for the
     * kinds 6 to 15 */
    bool Initialize(const QueryDesc01499f30 &queryDesc)
    {
        desc = queryDesc;
        switch (desc.Query) {
        case 1:
        case 5:
            block = D_5adaaa8->AllocateOnionMemory(256, 8, 6);
            break;
        case 2:
            block = D_5adaaa8->AllocateOnionMemory(8, 8, 6);
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            return false;
        }
        return true;
    }

    /* slot 6 (0x131f240): the context's slot 31 with the flag and the block
     * when +0x48 is 5 */
    void slot6(Context01499f30 *context, bool flag); /* derived name */
    /* slot 7 (0x131f270): the context's slot 32 when +0x48 is 5 */
    void slot7(Context01499f30 *context); /* derived name */

  private:
    int unknown48; /* +0x48 */
};

#endif
