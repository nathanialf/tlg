/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01439e30.h"
#include "tlg_game_object016d4d28.h"
#include "tlg_game_object016d7eb0.h"

/* derived names: the class whose vtable is at 0x16d5760 (eight slots),
 * over Object016d56e8, laid out as Object016d5eb8 (tlg_game_object01439e30.h). Its
 * destructor FUN_013fb5f0 is not virtual (no slot holds it). The slots are not
 * traced. */
class Object016d5760 : public Object016d56e8 /* derived name */
{
  public:
    ~Object016d5760();

    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

  private:
    u8 unknowna0[0x28];
    OwnedBlock05943280 blockc8; /* +0xc8 */
    u8 unknownd0[0x20];
    Array05943280<int> arrayf0; /* +0xf0 */
    u8 unknown108[0x48];
};

/* derived names: the class whose vtable is at 0x16d5710 (eight slots),
 * over Object016d56e8, laid out as Object016d5eb8 (tlg_game_object01439e30.h). Its
 * destructor FUN_013fb820 is not virtual (no slot holds it). The slots are not
 * traced. */
class Object016d5710 : public Object016d56e8 /* derived name */
{
  public:
    ~Object016d5710();

    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

  private:
    u8 unknowna0[0x28];
    OwnedBlock05943280 blockc8; /* +0xc8 */
    u8 unknownd0[0x20];
    Array05943280<int> arrayf0; /* +0xf0 */
    u8 unknown108[0x48];
};

/* FUN_013fb5f0: nothing of its own; the members' blocks are released last
 * first, the vtable of each part stored before its members go */
Object016d5760::~Object016d5760() {}

/* FUN_013fb820: the same over the other class */
Object016d5710::~Object016d5710() {}
