/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: gives one of an object's values a new amount. A value
 * that is already set is combined with it by its rule's kind in the table
 * at 0x1521f00 (0 multiplies, 1 adds, any other leaves it) and held to the
 * rule's bounds; one not yet set takes the amount as it is. The value's
 * bit is then set in both of the object's bit sets. Callers FUN_00eea9c0's
 * neighbours (0xeea9e6, 0xeeaa2c). The rule's other members and the owner
 * are not traced. */
struct Rule00ef01f0 { /* derived name */
    u8 unknown0[4];
    int kind; /* +0x4 */
    u8 unknown8[4];
    float min; /* +0xc */
    float max; /* +0x10 */
    u8 unknown14[4];
};

struct Bits00ef01f0 { /* derived name */

    bool test(unsigned index) const
    {
        return (words[index >> 5] & (1 << (index & 31))) != 0;
    }

    void set(unsigned index, bool on)
    {
        words[index >> 5] =
            (words[index >> 5] & ~(1 << (index & 31))) | ((unsigned)on << (index & 31));
    }

    unsigned words[2];
};

struct Object00ef01f0 {   /* derived name */
    Bits00ef01f0 changed; /* +0x0 */
    Bits00ef01f0 set;     /* +0x8 */
    float values[1];      /* +0x10: one for each rule */
};

extern const Rule00ef01f0 D_1521f00[];

/* a value held between two bounds. derived name */
static inline float clamp(float value, float low, float high)
{
    return value < low ? low : (high < value ? high : value);
}

// NONMATCHING: 32/34, 139 bytes of 139: the two bounds' loads exchanged in the shared clamp
// block (the base loads the low bound first, as the source reads them); the build's order is
// made by the scheduler after register allocation (the loads are low, high before it)
void FUN_00ef01f0(Object00ef01f0 *self, unsigned index, float amount) /* derived name */
{
    float &value = self->values[index];
    if (self->set.test(index)) {
        const Rule00ef01f0 &rule = D_1521f00[index];
        switch (rule.kind) {
        case 0:
            value = clamp(amount * value, rule.min, rule.max);
            break;
        case 1:
            value = clamp(amount + value, rule.min, rule.max);
            break;
        }
    } else {
        value = amount;
    }
    self->changed.set(index, true);
    self->set.set(index, true);
}
