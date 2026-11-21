/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d1a40.h"

/* derived names: the class whose vtable is at 0x16d3248
 * (config/vtables.derived.base.txt), derived from Object016d1a40: its
 * creator FUN_00e93310 allocates 0x68 bytes, calls Object00ccfd00's
 * constructor with 7, then stores the vptr and clears the reference at +0x58
 * and the int at +0x60. Its own destructor is empty and stores no vptr (the
 * base's stores 0x16d1a40's). The class at 0x16d3280 (creator FUN_00e93a70) shares its two
 * destructors (slots 0 and 1 of both vtables). */
class Object016d3248 : public Object016d1a40 /* derived name */
{
  public:
    virtual ~Object016d3248();

  private:
    int unknown60; /* +0x60: zero from the creator; not traced */
};

Object016d3248::~Object016d3248() {}
