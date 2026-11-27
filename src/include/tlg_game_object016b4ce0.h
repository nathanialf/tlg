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
struct Handler016b4ce0 { /* derived name */
    u8 unknown0[0x20];
};

struct Entry016b4ce0 : Counted00c14bc0 /* derived name */
{
    u8 unknownC[0x4];
    int state10; /* +0x10: 2 and up shown, 4 faded, 5 fading, 7 not changed */
    u8 shown14;  /* +0x14: 1 while the entry is in its list (`movzx eax, byte [r14+0x14];
                     cmp eax, 1` at 0x1390cd7) */
    u8 unknown15;
    u8 waiting16; /* +0x16: set where the state is not 4 */
    bool full17;  /* +0x17: the fade goes to 255 whatever the count */
    /* the object the handlers run on and the handlers run when the entry is
     * shown (+0x38) and hidden (+0x48), member pointers (`test al, 1` for a
     * virtual one, `lea rdi, [r14+rcx+0x18]` at 0x1390d00) */
    Handler016b4ce0 handler18;            /* +0x18 */
    void (Handler016b4ce0::*onEnter38)(); /* +0x38 */
    void (Handler016b4ce0::*onExit48)();  /* +0x48 */
    u8 unknown58[0x2a];
    bool callEnter82; /* +0x82: "GuideSystem.CallEnter" called when shown */
    bool callExit83;  /* +0x83: "GuideSystem.CallExit" called when hidden */
    u8 unknown84[0x4];
    int unknown88;       /* +0x88: cleared when shown or hidden */
    int id8C;            /* +0x8c: the argument of the two script calls (type 3) */
    Fade016b4ce0 fade90; /* +0x90 */
    u8 unknownA8[0x1c];
    int listC4;   /* +0xc4: set for the entries of the list at +0x68 of the guide */
    int countC8;  /* +0xc8 */
    int totalCC;  /* +0xcc */
    bool shownD0; /* +0xd0 */
    u8 changedD1; /* +0xd1: cleared when the entry is shown or hidden */
    u8 unknownD2[0x2];
    int levelD4; /* +0xd4: the guide's level (+0x110) it is shown from (`cmp ecx, [rax+0xd4]; jl`
                     at 0x875360) */
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

    /* the entry as the arrays hold it, of()'s converse */
    Object016b9108 *object() /* derived name */
    {
        return static_cast<Object016b9108 *>(static_cast<Counted00c14bc0 *>(this));
    }
};

/* derived names: a change held back while the guide holds its changes: the
 * entry and whether it is shown, 16 bytes (`shl rbx, 4` at 0x1390984) */
struct Change016b4ce0 {   /* derived name */
    Entry016b4ce0 *entry; /* +0x0 */
    bool shown;           /* +0x8 */
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
 * and its destructor 0xb129d0, its row named for it, D15), 0x120 bytes (a
 * member at +0x98 of Object00875120, leaf_00875120.cpp, which its creator
 * FUN_00872a80 makes with 0x1b8: `mov edi, 0x1b8` at 0x872a98); the fields
 * after +0x110 are not traced. Its fields are
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
     * pointer at 0x581e3a8, FUN_00b16780 its own argument: `mov rsi` kept),
     * returned as the arrays hold it (the callers cast it to the entry);
     * not written equal, so it keeps its address's name */
    friend Object016b9108 *FUN_01390e90(Object016b4ce0 *self, const Name &name);

    /* 0xb16780: the entry of the name counted down and shown again */
    void countDown(const Name &name); /* derived name */

    /* 0xb16a90: the name taken out of the names at +0xc0 (every copy, or the
     * last one only), unless it is held at +0xd8 */
    void remove(const Name &name, bool every); /* derived name */

    /* 0xb16bd0: Guide_SetIgnoreFade(keycode, isIgnore): the name added to
     * the names at +0xd8 and taken out of the names at +0xc0, or taken out
     * of the names at +0xd8 */
    void setIgnoreFade(lua_State *state); /* derived name */

    /* 0xb16940: the entry the script's string names finished, its level
     * raised when the second argument is true (leaf_00b16940.cpp) */
    friend void FUN_00b16940(Object016b4ce0 *self, lua_State *state);

    /* 0xb16110: the entry the script's string names given the second
     * argument's number as its count (leaf_00b16110.cpp) */
    friend void FUN_00b16110(Object016b4ce0 *self, lua_State *state);

    /* 0xb16380: the entry the script's string names counted again from its
     * total (leaf_00b16380.cpp) */
    friend void FUN_00b16380(Object016b4ce0 *self, lua_State *state);

    /* the entry given a count and shown when marked and the count is not
     * 0 (FUN_013907f0), then faded when shown with its count changed
     * (below; held in line by FUN_00b16110 and twice by FUN_00b16380; the
     * old count read before the mark's test with the count: `mov ecx,
     * [r12+0xc8]` before `setg dl` at 0xb161e5) */
    void setCount(Entry016b4ce0 *entry, int count, bool marked); /* derived name */

    /* the level entries are shown from (+0x110) */
    int level() const /* derived name */
    {
        return level110;
    }

    /* 0x13907f0: an entry shown or hidden (leaf_013907f0.cpp) */
    friend void FUN_013907f0(Object016b4ce0 *self, Entry016b4ce0 *entry, bool shown);

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
    bool holdingF0;              /* +0xf0: the changes are held in the array at +0xf8 */
    u8 unknownF1[0x7];
    Array05943280<Change016b4ce0> changesF8; /* +0xf8: its block given back by FUN_00ebf3f0,
                                                 the release of an array of elements with no
                                                 destructor (tlg_game_array.h) */
    int level110; /* +0x110: compared with an entry's level at +0xd4 before it is shown */
    u8 unknown114[0xc];
};

/* derived name: an entry shown or not after its count changed
 * (FUN_00b16780; leaf_013907f0.cpp) */
void FUN_013907f0(Object016b4ce0 *self, Entry016b4ce0 *entry, bool shown);

/* derived names: the append of a reference to one of the guide's arrays,
 * a function of its own (leaf_00b16e40.cpp): its seven call sites push to
 * the arrays at +0x38 (an element of it: `lea rdi, [rcx+rax*8]` over the
 * index times 3 at 0xb150b4), +0x50, +0x68 and +0x80 (`sub rdi, -0x80` at
 * 0x13906e9), whose destructor is the one over the root class's references
 * (0x134f620) */
void FUN_00b16e40(Array05943280<Ref00503fb0<Object016b9108>> *array,
                  const Ref00503fb0<Object016b9108> &value); /* derived name */

/* derived names: the guide's list sorted, its begin and end (not written) */
void FUN_01390fd0(Ref00503fb0<Object016b9108> *begin, Ref00503fb0<Object016b9108> *end);

/* derived names: the guide while it lives (the script functions of
 * FUN_00874ec0 read it) */
extern Object016b4ce0 *D_581e3a8;

/* derived names: the script's Guide_SetNorma, Guide_ResetNorma and
 * Guide_ClearNorma (FUN_008753d0, FUN_008753f0, FUN_008754d0 pass the
 * guide and their state) */
void FUN_00b16110(Object016b4ce0 *self, lua_State *state);
void FUN_00b16380(Object016b4ce0 *self, lua_State *state);
void FUN_00b16940(Object016b4ce0 *self, lua_State *state);

/* derived names: an entry faded out over the time (not written) */
void FUN_00b1aad0(Entry016b4ce0 *entry, bool out, float time);

/* the tests and the fade of countDown() (leaf_00b16780.cpp), written in
 * its order (the base tests state 7 first, `cmp eax, 7` at 0xb16205, as
 * countDown's build does): from the alpha to 255, to 0 with no count left, or
 * to 155 and up by the share of the count left */
inline void Object016b4ce0::setCount(Entry016b4ce0 *entry, int count, bool marked)
{
    const int previous = entry->countC8;
    const bool shown = marked && count > 0;
    entry->countC8 = count;
    FUN_013907f0(this, entry, shown);
    if (!shown || entry->state10 < 2 || previous == count || entry->state10 == 7)
        return;
    if (entry->state10 != 4) {
        entry->waiting16 = 1;
        return;
    }
    entry->waiting16 = 0;
    const float from = entry->alphaEF;
    u8 to;
    if (entry->full17)
        to = 255;
    else if (entry->countC8 <= 0)
        to = 0;
    else if (entry->totalCC < 2)
        to = 255;
    else
        to = u8(float(entry->countC8 - 1) / float(entry->totalCC - 1) * 100.0f + 155.0f);
    entry->fade90.start(from, to);
    if (entry->fade90.active)
        entry->state10 = 5;
}

/* derived name: called with 1 by stop(); not traced */
void FUN_00b127e0(Object016b4ce0 *self, int unknown);

/* derived name: a counted reference another thread may replace, emptied by
 * stop(); its readers are not traced */
extern AtomicRef0045c470<Object016b9108> D_5832910;

#endif
