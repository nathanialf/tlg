/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the constructor of the class whose vtable is at 0x16d0698
 * (config/vtables.derived.base.txt; its destructors FUN_013a2910 and
 * FUN_013a2a00 store it too): its base Object016b9108 is built from the
 * name passed on, an int at +0x24 cleared and the Name at +0x28 set to
 * "_black_texture". The class's other members and functions are not
 * traced. */
class Object016d0698 : public Object016b9108 /* derived name */
{
  public:
    Object016d0698(const Name &name);
    virtual ~Object016d0698();

  private:
    int unknown24;  /* +0x24 */
    Name texture28; /* +0x28: derived name, after its string */
};

// NONMATCHING: the vtable is reached through the GOT in both builds (`mov rax, [rip]; add rax,
// 0x10`) where the base folds 0x16d06a8 into a `lea`: the class's key function, its destructor
// (FUN_013a2910, slot 0), is not written, so no unit of the module emits the vtable (D50)
Object016d0698::Object016d0698(const Name &name) : Object016b9108(name), unknown24(0)
{
    texture28 = Name("_black_texture");
}
