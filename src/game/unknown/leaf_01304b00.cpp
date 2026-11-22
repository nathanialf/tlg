/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_program01304b00.h"

/* derived names: the class whose vtable is at 0x16c3940
 * (config/vtables.derived.base.txt; built by FUN_01303ee0), over
 * Object0130acb0: its complete destructor (0x1304b00) destroys the object at
 * +0x30 and runs the base's as a tail call; the deleting one (0x1304b90) is
 * the same, then the storage. The other fields are not traced. */
class Object016c3940 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c3940();

  private:
    Program01304b00 program; /* +0x30 */
};

Object016c3940::~Object016c3940() {}
