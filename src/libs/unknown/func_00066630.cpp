/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpModifierManager::FUN_00066630(u32 flags, CacheModifier0017a000 *modifier, int append)
{
    u32 functions = modifier->unknownVirtual2();
    if (!functions) {
        return;
    }
    if (append) {
        for (ModifierSet *set = modifierSets; functions; set++, functions >>= 1) {
            if (functions & 1) {
                if (set->numModifiers == 8) {
                    HK_BREAKPOINT(0);
                }
                ModifierSet::Entry &entry = set->entries[set->numModifiers++];
                set->enabledModifiers |= flags;
                entry.mask = flags;
                entry.modifier = modifier;
            }
        }
    } else {
        for (int i = 0; functions; i++, functions >>= 1) {
            if (functions & 1) {
                ModifierSet &set = modifierSets[i];
                if (set.numModifiers == 8) {
                    HK_BREAKPOINT(0);
                }
                int j = set.numModifiers++;
                ModifierSet::Entry *e = set.entries + j;
                for (; j > 0; j--, e--) {
                    e[0] = e[-1];
                }
                set.enabledModifiers |= flags;
                set.entries[j].mask = flags;
                set.entries[j].modifier = modifier;
            }
        }
    }
}
