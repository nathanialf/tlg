/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bd3b0.h"

/* FUN_00df1030: the held references at +0xc0, +0x30 and +0x60, the
 * entries' and the sets' references, then the rest in the base's order (the
 * two sets of six side by side) */
void Object016bd3b0::releaseResources()
{
    sharedc0.reset();
    shared30.reset();
    shared60.reset();
    for (int i = 0; i < 16; ++i) {
        Entry016bd3b0 &entry = entries[i];
        releaseAndClear(entry.shared8);
        releaseAndClear(entry.shared10);
        releaseAndClear(entry.shared18);
    }
    for (int i = 0; i < 5; ++i) {
        Set016bd3b0 &set = sets[i];
        releaseAndClear(set.counted);
        releaseAndClear(set.shared8);
        releaseAndClear(set.shared10);
        releaseAndClear(set.shared18);
        releaseAndClear(set.shared20);
        releaseAndClear(set.shared28);
        releaseAndClear(set.shared30);
        releaseAndClear(set.shared38);
        releaseAndClear(set.shared40);
        releaseAndClear(set.shared48);
        releaseAndClear(set.shared50);
        releaseAndClear(set.shared58);
        releaseAndClear(set.shared60);
        releaseAndClear(set.shared68);
        releaseAndClear(set.shared70);
        releaseAndClear(set.shared78);
        releaseAndClear(set.shared80);
    }
    releaseAndClear(shared600);
    releaseAndClear(shared618);
    releaseAndClear(shared608);
    releaseAndClear(shared610);
    shared630.reset();
    releaseAndClear(sharedA[0]);
    releaseAndClear(sharedB[0]);
    releaseAndClear(sharedA[1]);
    releaseAndClear(sharedB[1]);
    releaseAndClear(sharedA[2]);
    releaseAndClear(sharedB[2]);
    releaseAndClear(sharedA[3]);
    releaseAndClear(sharedB[3]);
    releaseAndClear(sharedA[4]);
    releaseAndClear(sharedB[4]);
    releaseAndClear(sharedA[5]);
    releaseAndClear(sharedB[5]);
    releaseAndClear(shared658);
    releaseAndClear(shared650);
}
