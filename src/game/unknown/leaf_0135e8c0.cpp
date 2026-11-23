/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: a record of 0x90 bytes, four of them at +0x738 to +0x8e8
 * of FUN_00608580's object: a name, two lists of names and three names
 * more, destroyed by its own destructor, the last member first */
struct Record0135e8c0 { /* derived name */
    ~Record0135e8c0();

    Name name;                  /* +0x0 */
    Array01343a80<Name> first;  /* +0x8 */
    Array01343a80<Name> second; /* +0x20 */
    u8 unknown38[0x1c];
    Name name54; /* +0x54 */
    Name name58; /* +0x58 */
    u8 unknown5c[0x4];
    Name name60; /* +0x60 */
    u8 unknown64[0x2c];
};

/* FUN_0135e8c0 */
Record0135e8c0::~Record0135e8c0() {}
