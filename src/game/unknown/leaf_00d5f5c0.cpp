/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ba888
 * (config/vtables.derived.base.txt), derived from Object016b9108, with a
 * pointer at +0x48 and a Name at +0x7c. Its complete destructor (0xd5f5c0;
 * the deleting one 0xd5f690) clears the pointer when it is set (`cmp qword
 * [rbx+0x48], 0; je` around the store), then the name and the base's two
 * are released. The destructor is the class's key function, so this file
 * emits the vtable. The other fields are not traced. */
class Object016ba888 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ba888();

  private:
    u8 unknown24[0x24];
    void *unknown48; /* +0x48 */
    u8 unknown50[0x2c];
    Name name7c; /* +0x7c */
};

Object016ba888::~Object016ba888()
{
    if (unknown48)
        unknown48 = 0;
}
