/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived names: the entry of a name (the script's Guide_CountUpNorma,
 * FUN_00875410) counted down: on reaching 0 its level is raised, up to its
 * limit (1 where it has none); FUN_013907f0 then shows it or not, and a
 * shown entry whose count changed is faded from its alpha to 255, to 0 with
 * no count left, or to 155 and up by the share of the count left. */
void Object016b4ce0::countDown(const Name &name)
{
    Entry016b4ce0 *entry = Entry016b4ce0::of(FUN_01390e90(this, name));
    if (!entry)
        return;
    const int previous = entry->countC8;
    int count = 0;
    if (previous > 0) {
        count = previous - 1;
        if (count == 0) {
            if (entry->limitDC == 0)
                entry->levelD8 = 1;
            else
                entry->levelD8 =
                    entry->levelD8 < entry->limitDC ? entry->levelD8 + 1 : entry->limitDC;
        }
    }
    const bool shown = entry->shownD0 && count > 0;
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
