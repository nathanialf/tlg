/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c7880.h"

/* derived names: the classes whose vtables are at 0x16add68 and 0x16ade08
 * (config/vtables.derived.base.txt, stored by their constructors
 * FUN_007a6a00 and FUN_007a6d40): over 0x16c7880, nothing of their own
 * traced. Each destructor is its class's key function, so this file emits
 * the vtables; the deleting ones (0x7a9bc0, 0x7abe30) call it out of line. */
class Object016add68 : public Object016c7880 /* derived name */
{
  public:
    virtual ~Object016add68();
};

class Object016ade08 : public Object016c7880 /* derived name */
{
  public:
    virtual ~Object016ade08();
};

/* 0x7a9a40: lets the node at +0xb0 go, then the base's destructor 0x7a7960
 * as a tail call */
Object016add68::~Object016add68()
{
    unknownb0->clearUnknown68();
    unknownb0->clearUnknown70();
    if (unknownb0->unknown28)
        FUN_00c5a160(unknownb0);
}

/* 0x7abcb0: the same body */
Object016ade08::~Object016ade08()
{
    unknownb0->clearUnknown68();
    unknownb0->clearUnknown70();
    if (unknownb0->unknown28)
        FUN_00c5a160(unknownb0);
}
