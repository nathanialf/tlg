/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_namebuckets.h"

/* derived names: frees the entry of a name whose last reference is gone
 * (Name::release): under its bucket's lock the entry's hold is dropped and,
 * with the last, its string (when the arena holds it) and the entry are
 * given back, the entry taken out of the bucket's chain and the count of
 * freed entries raised */
/* OPEN (FINISHING rule 6), checked in round 513D: its callers in the tree declare it under this
 * signature, and the link keeps every call (cost 440, over the link's threshold of 175) */
void FUN_00d66e30(unsigned index) /* derived name */
{
    NameTableEntry017ac870 &entry = D_17ac870[index];
    int *bucket = &D_5949980[entry.hash8 & 0xffff];
    const unsigned first = lockBucket(bucket);
    if (__sync_fetch_and_sub(&entry.holds16, 1) == 1) {
        const unsigned next = entry.nextc;
        const char *arena = reinterpret_cast<const char *>(D_17ac870);
        if (entry.string0 >= arena && entry.string0 < arena + 0x4000000)
            FUN_00d67820(const_cast<char *>(entry.string0), entry.length14 + 1);
        FUN_00d67820(&entry, sizeof(entry));
        if (first == index) {
            unlockBucket(bucket, next);
        } else {
            unsigned i = first;
            while (D_17ac870[i].nextc != index)
                i = D_17ac870[i].nextc;
            D_17ac870[i].nextc = next;
            unlockBucket(bucket, first);
        }
        __sync_fetch_and_add(&D_5989988, 1);
    } else {
        unlockBucket(bucket, first);
    }
}
