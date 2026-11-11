/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the script compiler's register check (the message "Function
 * or expression requires too many registers (too complex)." is a fact): the
 * function state the pointer at +0x7dc8 holds takes at +0xf60 its count at
 * +0xe88 less bit 0 of the byte at +0xf58, then the registers in use at
 * +0xc44 grow by that count; a new high mark at +0xc48 is kept, the message
 * handed first to slot 3 of the reporter at +0x18 when the total reaches
 * 200. The fields' meaning beyond that is not traced. */
struct FunctionState00dac050 { /* derived name */
    u8 unknown0[0xc44];
    unsigned used;     /* +0xc44: derived name */
    unsigned highMark; /* +0xc48: derived name */
    u8 unknown_c4c[0xe88 - 0xc4c];
    unsigned count; /* +0xe88: derived name */
    u8 unknown_e8c[0xf58 - 0xe8c];
    u8 flags; /* +0xf58: bit 0 read */
    u8 unknown_f59[7];
    unsigned unknownf60;
};

class Reporter00dac050 /* derived name */
{
  public:
    virtual void slot0();                    /* derived name; not traced */
    virtual void slot1();                    /* derived name; not traced */
    virtual void slot2();                    /* derived name; not traced */
    virtual void slot3(const char *message); /* derived name */
};

struct Compiler00dac050 { /* derived name */
    u8 unknown0[0x18];
    Reporter00dac050 *reporter; /* +0x18 */
    u8 unknown20[0x7dc8 - 0x20];
    FunctionState00dac050 *state; /* +0x7dc8 */
};

void FUN_00dac050(Compiler00dac050 *compiler) /* derived name */
{
    compiler->state->unknownf60 = compiler->state->count - (compiler->state->flags & 1);
    unsigned used = compiler->state->count + compiler->state->used;
    if (used > compiler->state->highMark) {
        if (used >= 200)
            compiler->reporter->slot3(
                "Function or expression requires too many registers (too complex).");
        compiler->state->highMark = used;
    }
    compiler->state->used = used;
}
