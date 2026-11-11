/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16b8c00 (slot 0, FUN_00ca24c0; slot 1, FUN_00ca24e0, the deleting one;
 * stored by FUN_001bd010, FUN_002212a0, FUN_00c32940, FUN_00c4fdb0,
 * FUN_00cd7ee0 and FUN_00eb3c90), derived from Object00c9cf90
 * (leaf_00c9cf90.cpp): its own body is empty, so its vtable store is skipped,
 * and the base destructor, defined in the other file, is inlined in the game
 * module: the base's vtable stored and the pointer at +0x10 freed, the bytes
 * of FUN_00c9cf90. The class's vtable is not referenced by this code and is
 * not named. */
#include "stdlib.h"

class Object00c9cf90 /* derived name */
{
  public:
    virtual ~Object00c9cf90();

  private:
    u8 unknown8[8];
    void *unknown10;
};

class Object00ca24c0 : public Object00c9cf90 /* derived name */
{
  public:
    virtual ~Object00ca24c0();
};

Object00ca24c0::~Object00ca24c0() {}
