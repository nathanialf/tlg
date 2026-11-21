/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: the script C function "SoldierMission_LeaveLostVolume"
 * (FUN_002212a0 registers it through FUN_00c89b70): with no argument
 * empties the list of lost volumes at +0x5d0 of the object at +0x18 of the
 * member at +0x50 of the mission's record (the count cleared, the entries
 * left as they are); else reads its first argument as a name
 * (nameArgument) and removes the first entry of that name, the ones after
 * it moved down. Nothing is done when the object is null. Returns 0. */
struct LostVolume0046c9a0 { /* derived name: 32 bytes */
    Name name;              /* +0x0 */
    u8 unknown4[0x1c];
};

/* derived name: the entries and their count (an int: `movsxd rdx, [r15+0x5d8];
 * test rdx, rdx; jle`) */
struct LostVolumes0046c9a0 {
    LostVolume0046c9a0 *data; /* +0x0 */
    int count;                /* +0x8 */

    /* the entry destroyed and the ones after it moved down, the block and
     * the count read again after the destruction (Array05943280::removeAt's
     * form: the index unsigned, so the entry's name is read again for its
     * release, `mov eax, [r13+rbx-0x20]`, where an int index reuses the
     * name just compared) */
    void removeAt(unsigned index)
    {
        data[index].~LostVolume0046c9a0();
        memmove(&data[index], &data[index] + 1,
                (count - index - 1) * unsigned(sizeof(LostVolume0046c9a0)));
        --count;
    }
};

struct Soldier0046c9a0 { /* derived name */
    u8 unknown0[0x5d0];
    LostVolumes0046c9a0 lostVolumes; /* +0x5d0 */
};

struct Member0046c9a0 { /* derived name */
    u8 unknown0[0x18];
    Soldier0046c9a0 *unknown18; /* +0x18 */
};

struct Mission057c9390_38_900 { /* derived name */
    u8 unknown0[0x50];
    Member0046c9a0 *unknown50; /* +0x50 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Mission057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;

int FUN_0046c9a0(lua_State *state) /* derived name */
{
    Soldier0046c9a0 *soldier = D_57c9390->unknown38->unknown900->unknown50->unknown18;
    if (!soldier)
        return 0;
    if (argumentCount(state) == 0) {
        soldier->lostVolumes.count = 0;
        return 0;
    }
    const Name volume = nameArgument(state, 1);
    LostVolumes0046c9a0 &volumes = soldier->lostVolumes;
    for (int i = 0; i < volumes.count; ++i) {
        if (volumes.data[i].name == volume) {
            volumes.removeAt(i);
            break;
        }
    }
    return 0;
}
