/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016c1128.h"
#include "tlg_game_vector.h"
#include "tlg_game_fadeparam013f9ca0.h"

/* derived names: FUN_01067d40 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 11 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15ca27a[9];
extern const char D_15ca283[10];
extern const char D_15ca28d[10];
extern const char D_15ca367[8];
extern const char D_15caff8[15];
extern const char D_15cb04a[15];
extern const char D_15cb21f[8];
extern const char D_15cb254[8];
extern const char D_15cb266[10];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad0a40(D_15cb5dd, false);
Name D_5ad0a44(D_15cb5e6, false);
Name D_5ad08e0(D_15ca367, false);
Name D_5ad08e4(D_15ca27a, false);
Name D_5ad08e8(D_15ca283, false);
Name D_5ad08ec(D_15ca28d, false);
Name D_5ad08f0(D_15cb266, false);
Name D_5ad08f4(D_15cb04a, false);
Name D_5ad08f8(D_15caff8, false);
Name D_5ad08fc(D_15cb254, false);
Name D_5ad0900(D_15cb21f, false);

/* derived name: the name the object is made under (15 characters) */
extern const char D_15c6b1d[16];

/* derived name: the complete constructor (called by the factory
 * FUN_01064370): Object00c1b7f0's and the part's constructors inlined, the
 * vptr, the fields after the part, then the name set and the pointers
 * after it cleared */
// NONMATCHING: 140/143: MemCpyOpt's clear of +0x194 to +0x1c7 is inserted where its scan
// stops, at the load of VECTOR_W after the zero stored at +0x250; the base has the clear
// before that store (something ends the scan between the stores at +0x230 and +0x250).
Object016c1128::Object016c1128(const Name &name) : Object00c1b7f0(name), unknown194(), unknown1c0(0)
{
    unknown1c8 = false;
    unknown1cc = -1;
    unknown1d0 = -1;
    active1d4 = 0;
    unknown1d8 = 0;
    name1c4 = Name(D_15c6b1d, false);
    registry = 0;
    unknown1f8 = 0;
    unknown200 = 0;
}

// NONMATCHING: 44/99, 340 bytes against 372: the type-0 cases 2 to 4 share
// their offset load and store in the build (`mov eax, [rcx+0x50]; jmp`), each
// keeps its own in the base, and the type-1 cases share only the store there;
// first difference greedy's (rcx/rax swapped for the group and its index)
/* derived name: the records of one of the target's groups applied in order,
 * each into the target itself or into the owner's element it names */
void FUN_013f9ca0(ParamOwner013f9ca0 *owner, ParamTarget013f9ca0 *target,
                  int group) /* derived name */
{
    const ParamGroup013f9ca0 &records = target->groups[group];
    const int count = records.count;
    const ParamRecord013f9ca0 *next = records.records;
    for (int i = 0; i < count; ++i, ++next) {
        const ParamRecord013f9ca0 &record = *next;
        if (record.disabled != 0)
            continue;
        if (record.destination == 0) {
            writeParam(record, reinterpret_cast<char *>(target));
        } else if (record.destination == 1) {
            if (record.elementId) {
                ParamElement013f9ca0 *element = findParamElement(owner, record.elementId);
                if (element)
                    writeParam(record, reinterpret_cast<char *>(element));
            }
        }
    }
}

/* derived name: the applier this file's copy of FUN_013fa6f0 calls (not
 * written): the owner, a mode (1 here), a key, the clip's position, the
 * weight */
void FUN_013f9e20(ParamOwner013f9ca0 *owner, const int &mode, u64 key,
                  const ClipPosition013fa6f0 &position, float weight);

// NONMATCHING: 40/120: the build reads the entry's time pointer inside the length test's
// block (InstCombine sinks it with the float read; the call reloads it) and indexes the
// entries from +8; the base reads it at the arm's top, after the frame fields, with the
// null arm's copy for the call (a partially redundant load), entries indexed from +0
/* derived name: each clip of the list at its time, the time brought into
 * the clip's span (wrapped when it loops, else held at its ends), handed to
 * the applier with the weight; a clip without frames is handed as all zero */
void FUN_013fa6f0(ParamOwner013f9ca0 *owner, const ClipList013fa6f0 *clips,
                  float weight) /* derived name */
{
    const int count = clips->count;
    for (int i = 0; i < count; ++i) {
        ClipPosition013fa6f0 position;
        const ClipEntry013fa6f0 &entry = clips->entries[i];
        Clip013fa6f0 *clip = entry.clip;
        if (clip && clip->frames) {
            ClipFrames013fa6f0 *frames = clip->frames;
            const int firstSet = clip->first;
            const int lastFrame = frames->count - 1;
            const int lastSet = clip->last;
            const float *at = entry.time;
            unsigned first = firstSet < 0 ? 0 : firstSet;
            unsigned last = lastSet < 0 ? lastFrame : lastSet;
            float length = ((float)last - (float)first) * (1.0f / 30.0f);
            float time = 0.0f;
            if (length != 0.0f) {
                const unsigned loops = clip->flags & 1;
                const float now = *at;
                float begin = (float)first * (1.0f / 30.0f);
                float end = (float)last * (1.0f / 30.0f);
                if (now < end) {
                    if (now < begin) {
                        float before = begin - now;
                        float cycles = loops ? before / length : 1.0f;
                        float wrapped = end + (floorf(cycles) * length - before);
                        time = loops ? wrapped : begin;
                    } else {
                        time = now;
                    }
                } else {
                    float after = now - begin;
                    float cycles = loops ? after / length : 1.0f;
                    float wrapped = (after - floorf(cycles) * length) + begin;
                    time = loops ? wrapped : end;
                }
            }
            position.frames = frames;
            position.unknown8 = clip->unknown120;
            position.time = time;
            position.frame = time * 30.0f;
        } else {
            position.frames = 0;
            position.unknown8 = 0;
            position.time = 0.0f;
            position.frame = 0.0f;
        }
        FUN_013f9e20(owner, 1, (u64)entry.time + (u64)entry.clip, position, weight);
    }
}
