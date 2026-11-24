/* src/include/tlg_game_object016b4ce0.h: the class whose vtable is at
 * 0x16b4ce0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4CE0_H
#define TLG_GAME_OBJECT016B4CE0_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

struct lua_State; /* tlg_hks.h */

/* derived names: a fade of a value from one end to the other, 24 bytes:
 * started on a difference, it runs 0.3 from the start (time 0); with none
 * it stands finished (time and length 1). Stored in that order (0xb168ed to
 * 0xb16919). */
struct Fade016b4ce0 /* derived name */
{
    bool active;    /* +0x0 */
    float time;     /* +0x4 */
    float length;   /* +0x8 */
    float distance; /* +0xc */
    float from;     /* +0x10 */
    float to;       /* +0x14 */

    void start(float start, float end)
    {
        const float difference = end - start;
        const bool moving = difference != 0.0f;
        const float begun = moving ? 0.0f : 1.0f;
        const float span = moving ? 0.3f : 1.0f;
        const float covered = moving ? difference : 0.0f;
        active = moving;
        time = begun;
        length = span;
        distance = covered;
        from = start;
        to = end;
    }
};

/* derived names: an object Object016b4ce0 holds, found by the name whose
 * index is at +0x310 (FUN_01390e90): a counted object (the arrays hold it as the root class's
 * references, the instantiation 0x134f620 is, but its own fields start at
 * +0x10: an int state where the root class has its second name, bytes at
 * +0x16 and +0x17, FUN_00b16780). A guide's count down at +0xc8 out of
 * +0xcc, a level at +0xd8 raised up to +0xdc each time the count reaches
 * 0, and the alpha at +0xef faded at +0x90. */
struct Entry016b4ce0 : Counted00c14bc0 /* derived name */
{
    u8 unknownC[0x4];
    int state10; /* +0x10: 2 and up shown, 4 faded, 5 fading, 7 not changed */
    u8 unknown14[0x2];
    u8 waiting16; /* +0x16: set where the state is not 4 */
    bool full17;  /* +0x17: the fade goes to 255 whatever the count */
    u8 unknown18[0x78];
    Fade016b4ce0 fade90; /* +0x90 */
    u8 unknownA8[0x20];
    int countC8;  /* +0xc8 */
    int totalCC;  /* +0xcc */
    bool shownD0; /* +0xd0 */
    u8 unknownD1[0x7];
    int levelD8; /* +0xd8 */
    int limitDC; /* +0xdc */
    u8 unknownE0[0xf];
    u8 alphaEF; /* +0xef */
    u8 unknownF0[0x220];
    unsigned name310; /* +0x310: the index of the entry's name */

    /* an entry as the arrays hold it */
    static Entry016b4ce0 *of(Object016b9108 *object)
    {
        return static_cast<Entry016b4ce0 *>(static_cast<Counted00c14bc0 *>(object));
    }
};

/* derived names: a record of the array at +0xa0, 40 bytes (`lea rsi,
 * [rcx + 4*rcx]` over the index, then `[rdx + 8*rsi]`), a name at +0x0
 * the only part with a destructor; the rest is not traced */
struct RecordA0016b4ce0 { /* derived name */
    Name name;            /* +0x0 */
    u8 unknown4[0x24];
};

/* derived names: the class whose vtable is at 0x16b4ce0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b12590
 * and its destructor 0xb129d0, its row named for it, D15), 0x100 bytes (a
 * member at +0x98 of Object00875120, leaf_00875120.cpp). Its fields are
 * traced where FUN_00b12e50 and FUN_01390e90 read them and where the
 * destructor (leaf_00b129d0.cpp) tears them down: the last entry found at
 * +0x10, a counted reference at +0x18, the entries at +0x20 (counted
 * references: their array's destructor is 0x134f620), an array of arrays of
 * counted references at +0x38, three more at +0x50, +0x68 and +0x80, the
 * counted reference at +0x98, the records at +0xa0, two arrays of names at
 * +0xc0 and +0xd8 and a heap block at +0xf8. */
class Object016b4ce0 /* derived name */
{
  public:
    virtual ~Object016b4ce0();

    /* 0xb12e50: FUN_00b127e0 with 1, then the reference at 0x5832910 and
     * the one at +0x98 emptied (the destructor calls it first; so does
     * FUN_001f4f10 for the member at +0x98 of the object at +0xf0 of its
     * own) */
    void stop(); /* derived name */

    /* 0x1390e90: the entry whose name at +0x310 is `name` (its index
     * compared): the last one found when it is, else the first of the array,
     * kept as the last found; null when none is (its callers pass the
     * pointer at 0x581e3a8, FUN_00b16780 its own argument: `mov rsi` kept);
     * not written equal, so it keeps its address's name */
    friend Entry016b4ce0 *FUN_01390e90(Object016b4ce0 *self, const Name &name);

    /* 0xb16780: the entry of the name counted down and shown again */
    void countDown(const Name &name); /* derived name */

    /* 0xb16a90: the name taken out of the names at +0xc0 (every copy, or the
     * last one only), unless it is held at +0xd8 */
    void remove(const Name &name, bool every); /* derived name */

    /* 0xb16bd0: Guide_SetIgnoreFade(keycode, isIgnore): the name added to
     * the names at +0xd8 and taken out of the names at +0xc0, or taken out
     * of the names at +0xd8 */
    void setIgnoreFade(lua_State *state); /* derived name */

  private:
    u8 unknown8[0x8];
    AtomicRef0045c470<Object016b9108> found10;                          /* +0x10 */
    Ref00503fb0<Object016b9108> held18;                                 /* +0x18 */
    Array05943280<Ref00503fb0<Object016b9108>> entries;                 /* +0x20 */
    Array05943280<Array05943280<Ref00503fb0<Object016b9108>>> arrays38; /* +0x38 */
    Array05943280<Ref00503fb0<Object016b9108>> array50;                 /* +0x50 */
    Array05943280<Ref00503fb0<Object016b9108>> array68;                 /* +0x68 */
    Array05943280<Ref00503fb0<Object016b9108>> array80;                 /* +0x80 */
    AtomicRef0045c470<Object016b9108> held98;                           /* +0x98 */
    Array05943280<RecordA0016b4ce0> recordsA0;                          /* +0xa0 */
    int activeB8; /* +0xb8: cleared when the names at +0xc0 are all taken out */
    u8 unknownBC[0x4];
    Array05943280<Name> namesC0; /* +0xc0 */
    Array05943280<Name> namesD8; /* +0xd8 */
    u8 unknownF0[0x8];
    OwnedBlock05943280 blockF8; /* +0xf8 */
};

/* derived name: an entry shown or not after its count changed
 * (FUN_00b16780; 0x696 bytes, not written) */
void FUN_013907f0(Object016b4ce0 *self, Entry016b4ce0 *entry, bool shown);

/* derived name: called with 1 by stop(); not traced */
void FUN_00b127e0(Object016b4ce0 *self, int unknown);

/* derived name: a counted reference another thread may replace, emptied by
 * stop(); its readers are not traced */
extern AtomicRef0045c470<Object016b9108> D_5832910;

#endif
