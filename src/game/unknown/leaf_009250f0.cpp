/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the component at +0x258 of the class below, as its slots
 * 20, 24 and 26 call it (leaf_00925210.cpp's Member00925210_258 the same
 * object: slots 15 and 16 take an int); handed to FUN_00c5a160. Slots 5 to 8
 * are Object01343880's. */
class Member009250f0 : public Object01343880 /* derived name */
{
  public:
    virtual void slot9();           /* derived name; not traced */
    virtual void slot10();          /* derived name; not traced */
    virtual void slot11();          /* derived name; not traced */
    virtual void slot12();          /* derived name; not traced */
    virtual void slot13();          /* derived name; not traced */
    virtual void slot14();          /* derived name; not traced */
    virtual void slot15(int value); /* derived name; not traced */
    virtual void slot16(int value); /* derived name; not traced */
    virtual void slot17(int value); /* derived name; not traced */
    virtual void slot18();          /* derived name; not traced */
    virtual void slot19();          /* derived name; not traced */
    virtual void slot20();          /* derived name; not traced */
    virtual void slot21();          /* derived name; not traced */
    virtual void slot22();          /* derived name; not traced */
    virtual void slot23();          /* derived name; not traced */
    virtual void slot24();          /* derived name; not traced */
    virtual void slot25(int value); /* derived name; not traced */
    virtual unsigned slot26();      /* derived name; bits, not traced */
    virtual void slot27();          /* derived name; not traced */
    virtual void slot28(int value); /* derived name; not traced */
    virtual void slot29();          /* derived name; not traced */
};

/* derived names: not traced; members of the class below without a slot,
 * called by its slot 20 */
class Object016b0d90;
void FUN_0092ae10(Object016b0d90 *self); /* derived name */
void FUN_0092c480(Object016b0d90 *self); /* derived name */
int FUN_0092ac70(Object016b0d90 *self);  /* derived name */
void FUN_0092bdf0(Object016b0d90 *self); /* derived name */

/* derived names: the three names posted to the dispatcher of the record at
 * 0x5938c40 (leaf_00948040.cpp) */
void FUN_00948040(const Name &a, const Name &b, const Name &c); /* derived name */

/* derived names: the names a node of the class below posts with its own
 * from slot 20 (D_5821070) and slot 24 (D_5821074): namespace-scope Names
 * another unit defines */
extern Name D_5821070;
extern Name D_5821074;

/* derived names: the class whose vtable is at 0x16b0d90
 * (config/vtables.derived.base.txt, stored by FUN_0137c320), a node: the
 * node at +0x258 it drives, the flags at +0x274 (bits 0 to 3 a state, bit
 * 27 and on flags kept: FUN_00925210, FUN_009251b0, FUN_009253a0), a flag
 * at +0x280 and two values at +0x284 and +0x288. Slots 20, 24 and 26 are
 * written here; the others are declared for their places. */
class Object016b0d90 : public Object016b85e0 /* derived name */
{
  public:
    /* slots 5 to 7 are Object016b85e0's (0xc573b0, 0xc575d0, 0xc59010) */
    virtual void slot8();           /* derived name; FUN_0092ac30 */
    virtual void slot9();           /* derived name; FUN_0092ac50 */
    virtual void slot10();          /* derived name; not traced */
    virtual void slot11();          /* derived name; not traced */
    virtual void slot12();          /* derived name; not traced */
    virtual void slot13();          /* derived name; not traced */
    virtual void slot14();          /* derived name; not traced */
    virtual void slot15();          /* derived name; not traced */
    virtual void slot16();          /* derived name; not traced */
    virtual void slot17();          /* derived name; not traced */
    virtual void slot18();          /* derived name; not traced */
    virtual void slot19();          /* derived name; FUN_00924a10, not traced */
    virtual void slot20();          /* FUN_009250f0 */
    virtual void slot21();          /* derived name; FUN_009251b0 */
    virtual void slot22();          /* derived name; FUN_00925210 */
    virtual void slot23();          /* derived name; FUN_00925260 */
    virtual void slot24(int value); /* FUN_009252b0 */
    virtual void slot25();          /* derived name; FUN_009253a0 */
    virtual void slot26();          /* FUN_009253e0 */

  private:
    u8 unknown238[0x20];
    Member009250f0 *unknown258; /* +0x258 */
    u8 unknown260[0x14];
    unsigned flags274; /* +0x274 */
    u8 unknown278[0x8];
    int unknown280; /* +0x280: bit 0 tested by slot 20 */
    int unknown284; /* +0x284 */
    int unknown288; /* +0x288 */
};

/* derived names: slot 20 of the vtable at 0x16b0d90: after FUN_0092ae10 and
 * FUN_0092c480, when FUN_0092ac70 allows it, state bit 0 is set and the
 * value at +0x288 is there, the value is copied to +0x284, the state set to
 * 3, FUN_0092bdf0 run and the name posted; otherwise slot 24 with 1, and bit
 * 7 of +0x24 set when bit 0 of +0x280 is */
void Object016b0d90::slot20()
{
    FUN_0092ae10(this);
    FUN_0092c480(this);
    if (FUN_0092ac70(this) && (flags274 & 1) && unknown288) {
        unknown284 = unknown288;
        flags274 = (flags274 & 0xf0000000) | 3;
        FUN_0092bdf0(this);
        FUN_00948040(D_5821070, name, Name());
    } else {
        slot24(1);
        if (unknown280 & 1)
            unknown24 |= 0x80;
    }
}

/* derived names: slot 24 of the vtable at 0x16b0d90: when state bit 1 is
 * set, a nonzero value sets the state to 1 and hands the node at +0x258
 * (when there) its slot 12 and FUN_00c5a160; zero sets bits 2 and 3 to 1
 * and calls the node's slots 15 (1), 16, 25 and 17 (0); then the name is
 * posted */
void Object016b0d90::slot24(int value)
{
    if (flags274 & 2) {
        if (value) {
            flags274 = (flags274 & 0xf0000000) | 1;
            if (unknown258) {
                unknown258->slot12();
                FUN_00c5a160(unknown258);
            }
        } else {
            flags274 = (flags274 & ~0xcu) | 4;
            unknown258->slot15(1);
            unknown258->slot16(0);
            unknown258->slot25(0);
            unknown258->slot17(0);
        }
    }
    FUN_00948040(D_5821074, name, Name());
}

/* derived names: slot 26 of the vtable at 0x16b0d90: flag bit 31 set; with
 * the node at +0x258 there, the node's slot 28 with 0x30, then its slot 26's
 * bits with the root's flags at +0x20 (read first): bit 5 calls the node's
 * slot 29 while state bit 1 is set, bit 4 calls this object's slots 24 (1)
 * and 19 */
void Object016b0d90::slot26()
{
    flags274 |= 0x80000000;
    if (unknown258) {
        const int own = flags;
        unknown258->slot28(0x30);
        const unsigned bits = unknown258->slot26() | own;
        if ((flags274 & 2) && (bits & 0x20))
            unknown258->slot29();
        if (bits & 0x10) {
            slot24(1);
            slot19();
        }
    }
}
