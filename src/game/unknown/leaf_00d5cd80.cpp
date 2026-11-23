/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: FUN_00a48710 calls this on each object of a list whose
 * flags at +0xd4 lack 0x20000, with the object's pointer at +0x28 (tested
 * not null there). The object takes that one's name (+0xc) as its own at
 * +0x170. Neither class is traced further. */
struct Source00d5cd80 { /* derived name */
    u8 unknown0[0xc];
    Name name; /* +0xc */
};

class Object00d5cd80 /* derived name */
{
  public:
    void setName(const Source00d5cd80 *source);

  private:
    u8 unknown0[0x170];
    Name name170; /* +0x170 */
};

/* FUN_00d5cd80: the source's name, the empty name without a source */
void Object00d5cd80::setName(const Source00d5cd80 *source)
{
    Name name;
    if (source)
        name = source->name;
    name170 = name;
}
