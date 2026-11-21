/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: a volume that contains the viewer and its alpha, 16 bytes */
struct ContainingVolume008453f0 { /* derived name */
    Object016b9108 *volume;       /* +0x0: its name at +0xc */
    float alpha;                  /* +0x8: "bool, alpha = HasContainingVolume('volume_name')" */
    u8 unknownc[4];
};

struct Member057c9390_60 /* derived name */
{
    u8 unknown0[0xd0];
    Array05943280<ContainingVolume008453f0> containing; /* +0xd0 */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0x60];
    Member057c9390_60 *unknown60; /* +0x60 */
};

extern Object057c9390 *D_57c9390;

/* derived name: whether a name is the string's: the entry's hash compared
 * with the string's, then the strings */
static inline bool isNamed(const Name &name, const HashedString &string)
{
    const NameTableEntry017ac870 &entry = D_17ac870[name.index];
    return entry.hash8 == string.hash && strcmp(entry.string0, string.string) == 0;
}

/* derived names: the script C function FUN_001db8b0 registers (lea at
 * 0x1ddc4e, script name "HasContainingVolume", its description "bool,
 * alpha = HasContainingVolume('volume_name')"): whether a volume containing
 * the viewer has the name of the first argument's string, and its alpha (0
 * for none), pushed as a boolean and a number; returns 2. The C function's
 * own name is unknown. */
int FUN_008453f0(lua_State *state) /* derived name */
{
    HashedString string;
    FUN_00e81bd0(&string, state, 1);
    const Member057c9390_60 *member = D_57c9390->unknown60;
    bool found = false;
    float alpha = 0;
    for (unsigned i = 0; i < member->containing.size(); ++i) {
        const ContainingVolume008453f0 &volume = member->containing.at(i);
        if (isNamed(volume.volume->name, string)) {
            found = true;
            alpha = volume.alpha;
            break;
        }
    }
    pushBoolean(state, found);
    pushNumber(state, alpha);
    return 2;
}
