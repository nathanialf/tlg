/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_namebuckets.h"
#include "tlg_libc.h"

/* derived names: the index of a string's entry in the name table, made when
 * there is none (0 for a null or empty string). Under the bucket's lock
 * (the low 16 bits of the hash) the chain is walked from the bucket's first
 * index for an entry of the same hash whose string starts with the length's
 * bytes of this one; found, its count is raised (and its hold, when the
 * count was 0: an entry whose last reference is being dropped) and its
 * index returned. Otherwise a 32-byte entry is taken from the arena, the
 * string kept as it is (literal: the caller's array lives as long as the
 * program) or copied into a block of its own with its terminator, the
 * entry made the chain's first and the count of entries made raised. The
 * count compared is the length as 32 bits (`mov eax, eax` before the walk),
 * and the copy's terminator is stored through strncpy's result (`mov byte
 * [rax+r14], 0`). */
// NONMATCHING: 153/159 at the base's 690 bytes: only the bucket address's spill (`mov [rbp-0x90], r15`) is
// before the first exchange where the base has it after (0x13bab42). The DAG scheduler of the line is the source
// list scheduler (SelectionDAGISel.cpp:296-299 of 3.7.1: x86 enables the machine scheduler), which emits the lea of
// the address the later blocks use at the GEP's place, before the load, and the spill follows it; list-ilp,
// list-burr and list-hybrid over the same link-stage IR give the base's bytes (c570 notes; D6's fourth addendum)
unsigned FUN_013baad0(const char *string, unsigned hash, size_t length,
                      bool literal) /* derived name */
{
    if (string == 0 || *string == 0)
        return 0;
    int *bucket = &D_5949980[hash & 0xffff];
    unsigned first = lockBucket(bucket);
    unsigned index;
    for (index = *bucket & 0x7fffffff; index != 0; index = D_17ac870[index].nextc) {
        const NameTableEntry017ac870 &entry = D_17ac870[index];
        if (entry.hash8 == hash && strncmp(entry.string0, string, unsigned(length)) == 0)
            break;
    }
    if (index != 0) {
        if (__sync_fetch_and_add(&D_17ac870[index].references10, 1) == 0)
            __sync_fetch_and_add(&D_17ac870[index].holds16, 1);
    } else {
        NameTableEntry017ac870 *entry =
            static_cast<NameTableEntry017ac870 *>(FUN_00d67350(sizeof(NameTableEntry017ac870)));
        if (literal) {
            entry->string0 = string;
        } else {
            char *copy = static_cast<char *>(FUN_00d67350(length + 1));
            entry->string0 = copy;
            strncpy(copy, string, length)[length] = 0;
        }
        entry->nextc = first;
        entry->hash8 = hash;
        entry->references10 = 1;
        entry->length14 = length;
        entry->holds16 = 1;
        entry->record18 = 0;
        index = entry - D_17ac870;
        __sync_fetch_and_add(&D_5989980, 1);
        first = index;
    }
    unlockBucket(bucket, first);
    return index;
}
