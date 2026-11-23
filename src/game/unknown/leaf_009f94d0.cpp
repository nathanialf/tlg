/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the 16-byte entries of the two arrays below, an int and a
 * counted reference to an object of the root class (leaf_00a00900.cpp,
 * leaf_00a009d0.cpp) */
struct Entry00a00900 {
    int value;                          /* +0x0 */
    Ref00503fb0<Object016b9108> object; /* +0x8 */
};

struct Entry00a009d0 {
    int value;                          /* +0x0 */
    Ref00503fb0<Object016b9108> object; /* +0x8 */
};

void FUN_00a00900(Array05943280<Entry00a00900> *array,
                  const Entry00a00900 &entry); /* derived name */
void FUN_00a009d0(Array05943280<Entry00a009d0> *array,
                  const Entry00a009d0 &entry); /* derived name */

/* derived names: the record the pointer at +0x18 of the record at +0x58 of
 * the object at 0x57c9390 names (leaf_009f6ca0.cpp, leaf_009f8890.cpp): two
 * arrays of entries, each with its own lock (the lock word at +0x9c and
 * +0xb4); the rest is not traced */
struct Member057c9390_58_18 { /* derived name */
    u8 unknown0[0x88];
    Array01343a80<Entry00a00900> entries88; /* +0x88 */
    Array01343a80<Entry00a009d0> entriesA0; /* +0xa0 */
};

/* derived names: each appends an entry naming the object, 1 or 0, to one of
 * the arrays under the array's lock: FUN_009f94d0 and FUN_009f96b0 to the
 * array at +0x88 (called by FUN_009f8890 and from 0x9f88c5), FUN_009f9890 and
 * FUN_009f9a70 to the one at +0xa0 (called by FUN_009f6ca0 and from
 * 0x9f6cd5). The entry is a temporary the out-of-line append copies, released before
 * the lock is given back. */
// NONMATCHING: 115 of 120 equal in the whole module (466 bytes, the entry's reload forwarded across
// the append): the release compares the count at `[r14+8]` where the base reuses the raise's
// address (`cmp [rbx], 0xdeadc0de`), then the near `je`s; leaf_009f5a00.cpp's open class.
void FUN_009f94d0(Member057c9390_58_18 *member, Object016b9108 *object) /* derived name */
{
    member->entries88.lock.lock();
    FUN_00a00900(&member->entries88, Entry00a00900{1, Ref00503fb0<Object016b9108>(object)});
    member->entries88.lock.unlock();
}

// NONMATCHING: 115 of 120 equal in the whole module (466 bytes, the entry's reload forwarded across
// the append): the release compares the count at `[r14+8]` where the base reuses the raise's
// address (`cmp [rbx], 0xdeadc0de`), then the near `je`s; leaf_009f5a00.cpp's open class.
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 420 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_009f96b0(Member057c9390_58_18 *member, Object016b9108 *object) /* derived name */
{
    member->entries88.lock.lock();
    FUN_00a00900(&member->entries88, Entry00a00900{0, Ref00503fb0<Object016b9108>(object)});
    member->entries88.lock.unlock();
}

// NONMATCHING: 115 of 120 equal in the whole module (466 bytes, the entry's reload forwarded across
// the append): the release compares the count at `[r14+8]` where the base reuses the raise's
// address (`cmp [rbx], 0xdeadc0de`), then the near `je`s; leaf_009f5a00.cpp's open class.
void FUN_009f9890(Member057c9390_58_18 *member, Object016b9108 *object) /* derived name */
{
    member->entriesA0.lock.lock();
    FUN_00a009d0(&member->entriesA0, Entry00a009d0{1, Ref00503fb0<Object016b9108>(object)});
    member->entriesA0.lock.unlock();
}

// NONMATCHING: 115 of 120 equal in the whole module (466 bytes, the entry's reload forwarded across
// the append): the release compares the count at `[r14+8]` where the base reuses the raise's
// address (`cmp [rbx], 0xdeadc0de`), then the near `je`s; leaf_009f5a00.cpp's open class.
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 420 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_009f9a70(Member057c9390_58_18 *member, Object016b9108 *object) /* derived name */
{
    member->entriesA0.lock.lock();
    FUN_00a009d0(&member->entriesA0, Entry00a009d0{0, Ref00503fb0<Object016b9108>(object)});
    member->entriesA0.lock.unlock();
}
