/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "stdlib.h"

#include "tlg_game_program01304b00.h"

/* derived names: the class whose vtable is at 0x16c3b18
 * (config/vtables.derived.base.txt; built by FUN_0131e9d0), over
 * Object0130acb0: its complete destructor (0x131f080) erases the object from
 * the array at +0x28 of the object 0x5adaaa8 points at (found from the
 * start, its slot cleared, the rest moved down), then destroys the object at
 * +0x30 and runs the base's as a tail call; the deleting one (0x131f150)
 * calls it, then frees the storage. The other fields are not traced. */
class Object016c3b18 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c3b18();

  private:
    Program01304b00 program; /* +0x30 */
};

// NONMATCHING: the pointer at 0x5adaaa8 the erase reads is kept in r14 and reused for the entry at +0xb8 in the base (no reload after the cleared slot and the memmove); here it is read again (`mov r14, [rip]`, 211 bytes against 204), the store of a null pointer and the memmove may alias it; the loop, the erase and the rest are the base's
Object016c3b18::~Object016c3b18()
{
    Object05adaaa8 *owner = D_5adaaa8;
    void **object = owner->objects28;
    while (object != owner->objects28End && *object != this) {
        ++object;
    }
    if (object != owner->objects28End) {
        *object = 0;
        memmove(object, object + 1, (owner->objects28End - (object + 1)) * sizeof(void *));
        --owner->objects28End;
    }
}
