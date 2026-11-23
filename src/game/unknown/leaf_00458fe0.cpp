/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: FUN_00481c10 gives an object a record (+0x3a8), whose name
 * (+0x0) becomes the object's at +0x3e4, the name at 0x57d4f60 without a
 * record (leaf_00ac5eb0.cpp's fallback subtype). Neither class is traced
 * further. */
struct Record00458fe0 { /* derived name */
    Name name;          /* +0x0 */
};

extern const Name D_57d4f60; /* derived name: the subtype of a soldier without one */

class Object00458fe0 /* derived name */
{
  public:
    void setRecord(Record00458fe0 *record);

  private:
    u8 unknown0[0x3a8];
    Record00458fe0 *record; /* +0x3a8 */
    u8 unknown3b0[0x34];
    Name name3e4; /* +0x3e4 */
};

/* FUN_00458fe0 */
void Object00458fe0::setRecord(Record00458fe0 *record)
{
    this->record = record;
    if (record)
        name3e4 = record->name;
    else
        name3e4 = D_57d4f60;
}
