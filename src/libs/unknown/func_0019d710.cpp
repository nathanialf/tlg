/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int FUN_0019d710(char *dst, const char *src)
{
    char *out = dst;
    while (*src != 0) {
        const char c = *src++;
        if (c == '&') {
            /* An entity runs from the ampersand to its semicolon. */
            const char *name = src;
            const char *end = name;
            for (;;) {
                if (*end == 0) {
                    return -1;
                }
                if (*end == ';') {
                    break;
                }
                end++;
            }
            src = end + 1;

            if (*name == '#') {
                /* A character by its number, at most nine digits. */
                const int numDigits = int(src - name) - 2;
                if (numDigits > 9) {
                    return -1;
                }
                char digits[10];
                FUN_00017fd0(digits, name + 1, numDigits);
                digits[numDigits] = 0;
                *out = char(FUN_00018010(digits, 0));
            } else {
                /* A character by its name: each entry the character, then
                 * the name. */
                const char *entities[] = {"<lt", ">gt", "&amp", "\"quot", "'apos", HK_NULL};
                int i = 0;
                for (; entities[i] != HK_NULL; i++) {
                    const char decoded = entities[i][0];
                    const char *entity = entities[i] + 1;
                    if (FUN_00017f50(name, entity, FUN_00017fe0(entity)) == 0) {
                        *out = decoded;
                        break;
                    }
                }
                if (entities[i] == HK_NULL) {
                    return -1;
                }
            }
        } else {
            *out = c;
        }
        out++;
    }
    *out = 0;
    return int(out - dst);
}
