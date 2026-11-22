/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_assert.h"

/* derived names: the assertion handler CreateDevice stores at 0x5ace510
 * (lea at 0xb8c33a; tlg_game_assert.h): when the game's thread-local pointer
 * at 0x16dc080 (tp offset -80) holds an object, calls its slot 2 with the
 * report and its kind ("ASSERT"), as a tail call. The object's class is not
 * traced. */
class Handler016dc080 /* derived name */
{
  public:
    virtual void slot0();                                      /* derived name; not traced */
    virtual void slot1();                                      /* derived name; not traced */
    virtual void slot2(const char *message, const char *kind); /* derived name */
};

extern __thread Handler016dc080 *D_16dc080;

void FUN_00b8a440(const char *message, const char *kind)
{
    if (D_16dc080)
        D_16dc080->slot2(message, kind);
}
