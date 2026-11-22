/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_004acae0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then the empty name at 0x57d74b4, then the
 * table of 15 names, each with the function a name stands for, at 0x57d74c0,
 * destroyed by the array destructor the compiler writes for it (0x4ad120).
 * FUN_004ac3d0 enters each name of the table that its object's table of 16
 * buckets (+0x48) lacks, with its function (FUN_004acf60). */

struct Object004ad600; /* derived name */
struct Target004ad600; /* derived name */

typedef void (*Handler004acae0)(Object004ad600 *self, Target004ad600 *target); /* derived name */

/* leaf_004ad5f0.cpp types this handler from its own body (it reads only its
 * second argument), so the table takes it through the handler type */
struct Object004ad5f0;                            /* derived name */
void FUN_004ad5f0(void *, Object004ad5f0 *owner); /* derived name */

void FUN_004ad190(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad230(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad2f0(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad3b0(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad470(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad530(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad600(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad610(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad630(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad650(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad670(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad690(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad6b0(Object004ad600 *self, Target004ad600 *target); /* derived name */
void FUN_004ad750(Object004ad600 *self, Target004ad600 *target); /* derived name */

extern const char D_156e8eb[18];
extern const char D_156e8fd[19];
extern const char D_156e910[19];
extern const char D_156e923[19];
extern const char D_156e936[19];
extern const char D_156e949[23];
extern const char D_156e960[23];
extern const char D_156e977[20];
extern const char D_156e98b[21];
extern const char D_156e9a0[21];
extern const char D_156e9b5[21];
extern const char D_156e9ca[21];
extern const char D_156e9df[26];
extern const char D_156e9f9[25];
extern const char D_156ea12[21];

/* a name and the function it stands for, 16 bytes */
struct Entry004acae0 {       /* derived name */
    Name name;               /* +0x0 */
    Handler004acae0 handler; /* +0x8 */
};

static Name D_57d74b4;

static Entry004acae0 D_57d74c0[] = {
    {Name(D_156e8eb, false), FUN_004ad190},
    {Name(D_156e8fd, false), FUN_004ad230},
    {Name(D_156e910, false), FUN_004ad2f0},
    {Name(D_156e923, false), FUN_004ad3b0},
    {Name(D_156e936, false), FUN_004ad470},
    {Name(D_156e949, false), FUN_004ad530},
    {Name(D_156e960, false), reinterpret_cast<Handler004acae0>(FUN_004ad5f0)},
    {Name(D_156e977, false), FUN_004ad600},
    {Name(D_156e98b, false), FUN_004ad610},
    {Name(D_156e9a0, false), FUN_004ad630},
    {Name(D_156e9b5, false), FUN_004ad650},
    {Name(D_156e9ca, false), FUN_004ad670},
    {Name(D_156e9df, false), FUN_004ad690},
    {Name(D_156e9f9, false), FUN_004ad6b0},
    {Name(D_156ea12, false), FUN_004ad750},
};
