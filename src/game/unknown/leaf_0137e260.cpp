/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16c7b78 (tlg_game_multibase.h's
 * Object0095b960), its destructor the one at 0x137e6e0 (its row named for it,
 * D15), as leaf_0137e230.cpp declares it. */
class Object0137e6e0 /* derived name */
{
  public:
    virtual ~Object0137e6e0();
};

/* derived names: the fields of the class at 0x16b0fb0 that FUN_00958460
 * sets before it builds the base at 0x16c7b78 (+0x204 to +0x2a4, and the
 * counted reference at +0x2a8 cleared): a base with no virtual function,
 * declared first, so it is built first and destroyed last. Its other fields
 * are not traced. */
struct State016b0fb0 /* derived name */
{
    u8 unknown8[0x2a8 - 0x8];
    Ref00503fb0<Object016b9108> unknown2a8; /* +0x2a8 */
};

/* derived names: the class whose vtable is at 0x16b0fb0 (stored by
 * FUN_00958460; tlg_game_multibase.h's Object016b0fb0), 0x2b0 bytes (the
 * size FUN_00958460 allocates). Its destructor (slot 0, 0x137e260) stores no
 * vptr: its own body and fields are empty, the counted reference is the
 * first base's, released after the base at 0x16c7b78's destructor;
 * slot 1 (0x137e300) the deleting destructor. */
class Object0137e260 : public State016b0fb0, public Object0137e6e0 /* derived name */
{
  public:
    virtual ~Object0137e260();
};

Object0137e260::~Object0137e260() {}
