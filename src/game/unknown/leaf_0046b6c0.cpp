/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived name: FUN_00470ed0 pushes the text from `begin` up to `end` (its
 * body not written) */
void FUN_00470ed0(lua_State *state, const char *begin, const char *end);

/* derived name: a blank character: a control character, the space or DEL */
static inline bool isBlank(unsigned char c)
{
    return c < 0x21 || c == 0x7f;
}

/* derived name: the first character of a string that is not blank, null
 * when there is none */
static inline const char *skipBlanks(const char *text)
{
    for (; *text; ++text) {
        if (!isBlank(*text))
            return text;
    }
    return 0;
}

/* derived names: the script C function "Soldier_ParseEntityGeneratorSubType"
 * (FUN_002212a0 registers it through FUN_00c89b70, lea at 0x2232a4): splits
 * its first argument, a string `type(a,b)` or `type(a)`: with no string,
 * nothing but blanks or no `(`, pushes nothing and returns 0; pushes the
 * type (FUN_00470ed0) and, when a `)` closes the list with only blanks
 * after it, each entry of the list, returning how many were pushed. */
// NONMATCHING: the unrotated loop class: the two blank-skipping loops stay unrotated in the base
// (`dec rbx; mov al, [rbx+1]; test al, al; je; inc rbx` at 0x46b6fb, the second from
// `lea rax, [r15+1]`); the build rotates both, the first character's load peeled (350 bytes
// as the base, every call, test and branch arm in the base's order)
int FUN_0046b6c0(lua_State *state) /* derived name */
{
    HksObject *value = state->base;
    const char *text = value < state->top ? FUN_00db6b20(state, value, 0) : 0;
    if (!text)
        return 0;
    const char *type = skipBlanks(text);
    if (!type)
        return 0;
    const char *open = strchr(type, '(');
    if (!open)
        return 0;
    const char *first = open + 1;
    const char *comma = strchr(first, ',');
    const char *close;
    if (comma)
        close = strchr(comma + 1, ')');
    else
        close = strchr(first, ')');
    if (!close || skipBlanks(close + 1)) {
        FUN_00470ed0(state, type, open);
        return 1;
    }
    FUN_00470ed0(state, type, open);
    if (comma) {
        FUN_00470ed0(state, first, comma);
        FUN_00470ed0(state, comma + 1, close);
        return 3;
    }
    FUN_00470ed0(state, first, close);
    return 2;
}
