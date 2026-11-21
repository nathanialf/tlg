/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: a script call's argument, 16 bytes: a 32-bit type code at
 * +0x0 and its value at +0x8 (leaf_00b10e30.cpp's and leaf_00301db0.cpp's;
 * type 2 a string, 3 an int) */
struct ScriptArgument00a2efa0 {
    void set(int type_, int value_) /* derived name */
    {
        type = type_;
        value.integer = value_;
    }

    void set(int type_, const char *string) /* derived name */
    {
        type = type_;
        value.string = string;
    }

    int type;
    u8 unknown4[4];

    union {
        int integer;
        const char *string;
    } value;
};

/* calls the script function its name gives with count arguments, its int
 * result through the last pointer; nonzero on success (FUN_00b10da0). */
int FUN_00a2efa0(const char *name, int count, const ScriptArgument00a2efa0 *arguments, int *result);

/* derived names: a string of at most 255 characters and its length at
 * +0x100; FUN_01342e50 formats into it (vsnprintf with 0x100, the length
 * the result or 255 when it is negative) */
struct String01342e50 { /* derived name */
    void FUN_01342e50(const char *format, ...);

    char text[0x100];
    int length; /* +0x100 */
};

/* derived names: an entry of the list the pointer at 0x581bd00 holds: its
 * state at +0x24, its name at +0x2c and at +0x118 the object it belongs to */
struct Region0082f550 { /* derived name */
    u8 unknown0[0x24];
    /* +0x24: the state (3 connected, the callback's test); volatile: the
     * region functions' reads compared with a nonzero constant are never
     * folded into the compare (`mov eax, [r+0x24]; cmp eax, 3` at 0x82e319,
     * 0x82ec5d, 0x82ef6a, 0x82f0af, 0x82f371 and here, eleven such reads
     * from 0x82e319 to 0x82f56c); stores at 0x82e3bc and 0x82e5c8 */
    volatile int unknown24;
    u8 unknown28[0x4];
    Name name; /* +0x2c */
    u8 unknown30[0xe8];
    Object016b9108 *unknown118; /* +0x118 */
};

/* derived names: a callback FUN_00202800 hands FUN_00cb8490 for each entry
 * of the list the pointer at 0x581bd00 holds (lea at 0x202f17, the context
 * null): an entry in state 3 calls the script function
 * "RegionSetting.<its name>.OnConnect" with the int 1, the name of the
 * object at +0x118 and its own name; returns 1 */
int FUN_0082f550(Region0082f550 *region, void *) /* derived name */
{
    if (region->unknown24 == 3) {
        ScriptArgument00a2efa0 arguments[3];
        arguments[0].set(3, 1);
        arguments[1].set(2, D_17ac870[region->unknown118->name.index].string0);
        arguments[2].set(2, D_17ac870[region->name.index].string0);
        String01342e50 function;
        function.FUN_01342e50("RegionSetting.%s.OnConnect", D_17ac870[region->name.index].string0);
        FUN_00a2efa0(function.text, 3, arguments, 0);
    }
    return 1;
}
