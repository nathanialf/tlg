/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* An ASCII upper-case letter in lower case (derived name). */
static inline char toLower(char c) /* derived name */
{
    return (c >= 'A' && c <= 'Z') ? char(c + ('a' - 'A')) : c;
}

int hkString::strCasecmp(const char *s1, const char *s2) /* derived name */
{
    int i = 0;
    while (s1[i] != 0 || s2[i] != 0) {
        char c1 = toLower(s1[i]);
        char c2 = toLower(s2[i]);
        if (c1 < c2) {
            return -1;
        } else if (c1 > c2) {
            return 1;
        }
        ++i;
    }
    return 0;
}
