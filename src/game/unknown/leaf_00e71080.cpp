/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_hks.h"

/* derived names: the script C functions "GUI_DrawTexture" and
 * "GUI_DrawScaledTexture" (the names FUN_00e71b00's registration gives them,
 * lea at 0xe71cd8 and 0xe71d67): the arguments' numbers (0 for an absent
 * one) are a position, and for the scaled one a size, and the last
 * argument's string a colour in hexadecimal (the format at 0x15c03d8, read
 * by sscanf_s; ~0 without one: GUI_DrawSubTextureEx makes the same word of
 * four byte arguments); FUN_00c67ff0 draws with the current GUI (the
 * pointer at +0x78 indexed by the int at +0x90 of the object the pointer at
 * 0x5938c40 holds), the size -1 unless given, and the texture's
 * coordinates from (0, 0) to (1, 1). All return 0 (no results). The
 * classes are not traced. */
class Gui00c67ff0; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x78];
    Gui00c67ff0 *guis[3]; /* +0x78; its extent not traced */
    unsigned currentGui;  /* +0x90 */
};

extern Object05938c40 *D_5938c40;

extern const char D_15c03d8[3]; /* derived name: the format of a hexadecimal number */

void FUN_00c67ff0(Gui00c67ff0 *gui, unsigned colour, float x, float y, float width, float height,
                  float u0, float v0, float u1, float v1); /* derived name */

/* derived name: an argument's string, null past the frame's top */
static inline const char *toString(lua_State *state, int argument)
{
    HksObject *value = state->base + (argument - 1);
    return value < state->top ? FUN_00db6b20(state, value, 0) : 0;
}

/* derived name: the colour an argument gives in hexadecimal, ~0 for none */
static inline unsigned colourArgument(lua_State *state, int argument)
{
    const char *text = toString(state, argument);
    unsigned colour = ~0u;
    if (text)
        sscanf_s(text, D_15c03d8, &colour);
    return colour;
}

static inline Gui00c67ff0 *currentGui()
{
    return D_5938c40->guis[D_5938c40->currentGui];
}

int FUN_00e71080(lua_State *state) /* derived name */
{
    float x = toNumber(state, 1);
    float y = toNumber(state, 2);
    unsigned colour = colourArgument(state, 3);
    FUN_00c67ff0(currentGui(), colour, x, y, -1, -1, 0, 0, 1, 1);
    return 0;
}

int FUN_00e711a0(lua_State *state) /* derived name */
{
    float x = toNumber(state, 1);
    float y = toNumber(state, 2);
    float width = toNumber(state, 3);
    float height = toNumber(state, 4);
    unsigned colour = colourArgument(state, 5);
    FUN_00c67ff0(currentGui(), colour, x, y, width, height, 0, 0, 1, 1);
    return 0;
}

/* derived name: "GUI_DrawSubTexture" (lea at 0xe71df6, the same
 * registration): the position, the size and the texture's coordinates
 * from the first eight arguments, the colour from the ninth */
int FUN_00e71310(lua_State *state) /* derived name */
{
    float x = toNumber(state, 1);
    float y = toNumber(state, 2);
    float width = toNumber(state, 3);
    float height = toNumber(state, 4);
    float u0 = toNumber(state, 5);
    float v0 = toNumber(state, 6);
    float u1 = toNumber(state, 7);
    float v1 = toNumber(state, 8);
    unsigned colour = colourArgument(state, 9);
    FUN_00c67ff0(currentGui(), colour, x, y, width, height, u0, v0, u1, v1);
    return 0;
}

/* derived name: "GUI_DrawSubTextureEx" (lea at 0xe71fa3, the same
 * registration): as GUI_DrawSubTexture, the colour made of the bytes of
 * the ninth to twelfth arguments, the ninth the highest */
int FUN_00e71520(lua_State *state) /* derived name */
{
    float x = toNumber(state, 1);
    float y = toNumber(state, 2);
    float width = toNumber(state, 3);
    float height = toNumber(state, 4);
    float u0 = toNumber(state, 5);
    float v0 = toNumber(state, 6);
    float u1 = toNumber(state, 7);
    float v1 = toNumber(state, 8);
    u8 a = toNumber(state, 9);
    u8 b = toNumber(state, 10);
    u8 c = toNumber(state, 11);
    u8 d = toNumber(state, 12);
    unsigned colour = a << 24 | b << 16 | c << 8 | d;
    FUN_00c67ff0(currentGui(), colour, x, y, width, height, u0, v0, u1, v1);
    return 0;
}
