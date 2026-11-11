/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the accessor of the table of 34 named values: the guarded
 * static array at 0x5828490 (guard 0x5828488; its destructor
 * FUN_00a65f10 registered with __cxa_atexit) and the guarded static table
 * over it at 0x5828630 (guard 0x5828628, vtable 0x16ce490). Called by the
 * three slots of leaf_0138db60.cpp. */
extern const char D_15c7e60[8];  /* "Default" */
extern const char D_15a5590[7];  /* "Gravel" */
extern const char D_15a5597[5];  /* "Sand" */
extern const char D_15a559c[6];  /* "Stone" */
extern const char D_15a55a2[5];  /* "Rock" */
extern const char D_15a55a7[5];  /* "Soil" */
extern const char D_15a55ac[6];  /* "Swamp" */
extern const char D_15a55b2[5];  /* "Leaf" */
extern const char D_15a55b7[6];  /* "Grass" */
extern const char D_15a55bd[10]; /* "LongGrass" */
extern const char D_15a55c7[5];  /* "Wood" */
extern const char D_15a55cc[10]; /* "ThickWood" */
extern const char D_15a55d6[8];  /* "Shallow" */
extern const char D_15b83f0[6];  /* "Water" */
extern const char D_15a55de[6];  /* "Metal" */
extern const char D_15a55e4[11]; /* "ThickMetal" */
extern const char D_15a55ef[7];  /* "Bronze" */
extern const char D_15a55f6[6];  /* "Glass" */
extern const char D_15a55fc[9];  /* "NoEffect" */
extern const char D_15a5605[10]; /* "StoneTile" */
extern const char D_15a560f[6];  /* "River" */
extern const char D_15a5615[4];  /* "Ivy" */
extern const char D_15a5619[4];  /* "Mud" */
extern const char D_15a561d[7];  /* "Branch" */
extern const char D_15a5624[11]; /* "MetalFence" */
extern const char D_15a562f[10]; /* "TreeTrunk" */
extern const char D_15a5639[10]; /* "LimeStone" */
extern const char D_15a5643[14]; /* "LimeStoneTile" */
extern const char D_15a5651[10]; /* "LimeMetal" */
extern const char D_15a565b[15]; /* "LimeMetalFence" */
extern const char D_15a566a[11]; /* "LimeGravel" */
extern const char D_15a5675[19]; /* "StoneTile_NoEffect" */
extern const char D_15a5688[11]; /* "ShortGrass" */
extern const char D_15a5693[18]; /* "NoSecondaryEffect" */

// NONMATCHING: the two residuals of tlg_game_name.h's accessors: the base drops the
// constant return (nothing in rax: IPSCCP zaps the returns of a local-linkage
// function only), and folds the vtable's address point into the `lea` (the
// class's key function, slot 3, is not yet in the module).
Object016ce490 &FUN_00a64740()
{
    static NamedValue D_5828490[] = {
        {D_15c7e60, {0x7f, 0x7f, 0x7f}, 0},  {D_15a5590, {0x96, 0x96, 0x32}, 1},
        {D_15a5597, {0xff, 0xff, 0x7f}, 2},  {D_15a559c, {0xff, 0xff, 0x00}, 3},
        {D_15a55a2, {0xff, 0x7f, 0xff}, 4},  {D_15a55a7, {0xff, 0x00, 0xff}, 5},
        {D_15a55ac, {0x7f, 0xff, 0xff}, 6},  {D_15a55b2, {0x00, 0x7f, 0x00}, 7},
        {D_15a55b7, {0x00, 0xff, 0x00}, 8},  {D_15a55bd, {0x00, 0xff, 0x7f}, 9},
        {D_15a55c7, {0xff, 0x7f, 0x00}, 10}, {D_15a55cc, {0x7f, 0x7f, 0x00}, 11},
        {D_15a55d6, {0x00, 0xff, 0xff}, 12}, {D_15b83f0, {0x00, 0x00, 0xff}, 13},
        {D_15a55de, {0xff, 0x00, 0x00}, 14}, {D_15a55e4, {0x7f, 0x7f, 0xff}, 15},
        {D_15a55ef, {0x7f, 0x00, 0xff}, 16}, {D_15a55f6, {0x7f, 0x3f, 0x7f}, 17},
        {D_15a55fc, {0x7f, 0x00, 0x7f}, 18}, {D_15a5605, {0x7f, 0x3f, 0x3f}, 19},
        {D_15a560f, {0x7f, 0x7f, 0x3f}, 20}, {D_15a5615, {0x3f, 0x7f, 0x7f}, 21},
        {D_15a5619, {0x3f, 0x3f, 0x3f}, 22}, {D_15a561d, {0x3f, 0x3f, 0x7f}, 23},
        {D_15a5624, {0xff, 0xbf, 0x20}, 24}, {D_15a562f, {0x7f, 0x20, 0x20}, 25},
        {D_15a5639, {0x33, 0x66, 0xff}, 26}, {D_15a5643, {0x33, 0xcc, 0xcc}, 27},
        {D_15a5651, {0x00, 0x00, 0x99}, 28}, {D_15a565b, {0x32, 0xcd, 0x32}, 29},
        {D_15a566a, {0xe6, 0x9c, 0x4a}, 30}, {D_15a5675, {0x20, 0x7f, 0x7f}, 31},
        {D_15a5688, {0x00, 0x40, 0x00}, 32}, {D_15a5693, {0x7f, 0x7f, 0xfa}, 33},
    };
    static Object016ce490 D_5828630(D_5828490);
    return D_5828630;
}
