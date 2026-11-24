/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"

/* derived names: the script lexer's text of the token it holds, as the
 * function below reads them: the state at +0x8 and the buffer of the
 * token's text at +0x10, its characters at +0x10 and their count at +0x20 */
struct LexBuffer00db37f0 { /* derived name */
    u8 unknown0[0x10];
    char *buffer; /* +0x10 */
    u8 unknown18[0x8];
    size_t length; /* +0x20 */
};

struct Lexer00db37f0 { /* derived name */
    u8 unknown0[0x8];
    lua_State *state;          /* +0x8 */
    LexBuffer00db37f0 *buffer; /* +0x10 */
};

/* derived name: the reserved words' names from token 0x400001 ("and",
 * "break", "do", ...: Lua's luaX_tokens) */
extern const char *const D_16baf70[];

int FUN_00d95b60(char *buffer, size_t size, const char *format, ...);

/* derived names: pushes the text of a token, Lua's txtToken and
 * luaX_token2str: a name, a string or a number (0x40001f, 0x400022,
 * 0x400023) its text in the buffer; a single character "char(%u)" for a
 * control character, else the character; a reserved word its name, at most
 * 128 bytes of it copied and the 128th cleared. The buffer is 144 bytes (the
 * frame's 0x90 from rbp-0xc0 to the guard); the formatter's size argument is
 * dropped by the link (leaf_00d95b60.cpp) */
void FUN_00db37f0(Lexer00db37f0 *lexer, const int *token) /* derived name */
{
    switch (*token) {
    case 0x40001f:
    case 0x400022:
    case 0x400023:
        FUN_013aacc0(lexer->state, lexer->buffer->buffer, lexer->buffer->length);
        return;
    }
    char text[144];
    const int value = *token;
    if (value < 0x400001) {
        const char c = char(value);
        if (_Getpctype()[u8(c)] & 0x80)
            FUN_00d95b60(text, sizeof(text), "char(%u)", *token);
        else
            FUN_00d95b60(text, sizeof(text), "%c", c);
    } else {
        const char *name = D_16baf70[value - 0x400001];
        const size_t size = strlen(name) + 1;
        memcpy(text, name, size > 128 ? 128 : size);
        text[127] = 0;
    }
    FUN_013aacc0(lexer->state, text, strlen(text));
}
