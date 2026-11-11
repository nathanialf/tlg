/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slots 2 to 4 of the vtable at 0x16ce750 (stored by
 * FUN_0069d690; slots 0 and 1 the shared empty and deleting bodies 0x1af750
 * and 0x21a00, an inline empty virtual destructor), each forwarding to slots
 * 3 to 5 of the table FUN_00a65190 returns. The accessor's return is the
 * constant address of its static (IPSCCP over the module), so the call is
 * kept and the table is reached at 0x58286a8 directly. */
class Object016ce750 /* derived name */
{
  public:
    virtual ~Object016ce750() {}

    virtual const NamedValue *FUN_0138dbf0(int index) const;
    virtual int FUN_0138dc20(int index) const;
    virtual const char *FUN_0138dc50(int index, const char *fallback) const;
};

const NamedValue *Object016ce750::FUN_0138dbf0(int index) const
{
    return FUN_00a65190().entry(index);
}

int Object016ce750::FUN_0138dc20(int index) const
{
    return FUN_00a65190().value(index);
}

const char *Object016ce750::FUN_0138dc50(int index, const char *fallback) const
{
    return FUN_00a65190().name(index, fallback);
}
