/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkStringBuf &hkStringBuf::FUN_00011bc0(const char *part0, const char *part1, const char *part2)
{
    const char *parts[4] = {part0, part1, part2, HK_NULL};

    /* The terminator dropped; a separator is needed before the first part
     * unless the path is empty or already ends with one. */
    string.popBack();
    bool needSlash = string.getSize() != 0 && string[string.getSize() - 1] != '/';

    for (int i = 0; parts[i] != HK_NULL; i++) {
        const char *part = parts[i];
        if (part[0] != 0) {
            while (part[0] == '/') {
                part++;
            }
            if (int length = FUN_00017fe0(part)) {
                while (length != 0 && part[length - 1] == '/') {
                    length--;
                }
                if (length != 0 && needSlash) {
                    string.pushBack(hkContainerTempAllocator::get(), '/');
                }
                string.append(hkContainerTempAllocator::get(), part, length);
            }
            needSlash = true;
        }
    }

    string.pushBack(hkContainerTempAllocator::get(), 0);
    return *this;
}
