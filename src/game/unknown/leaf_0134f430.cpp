/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a9018
 * (config/vtables.derived.base.txt): its complete destructor 0x134f430 stores
 * the vtable and destroys the Name at +0x14 (the reference released, the index
 * cleared); the deleting one 0x134f480 is the compiler's (the cleared index is a
 * dead store before operator delete there). The destructor is the class's key
 * function, so this file emits the vtable. Slot 3 (FUN_003e3d70) draws the
 * name's string as debug text at the two floats from +0x18, in the colour
 * the two words at +0xc and +0x10 make together. */
/* derived names: the colour FUN_00205cc0 takes by address: a 32-bit value
 * and a float (1.0 here) */
struct TextColour00205cc0 /* derived name */
{
    u32 value;   /* +0x0 */
    float scale; /* +0x4 */
};

/* derived name: draws debug text at a position: the colour, an int (0
 * here), a printf format and the two coordinates, then the format's
 * arguments (variadic: `mov al, 2` at its callers); 12 callers. */
void FUN_00205cc0(const TextColour00205cc0 *colour, int, const char *format, float x, float y, ...);

class Object0134f430 /* derived name */
{
  public:
    virtual ~Object0134f430();
    virtual void slot2();        /* derived name: 0x69a0; not traced */
    virtual void FUN_003e3d70(); /* derived name: slot 3 */

  private:
    u8 unknown8[4];
    u32 unknownC;    /* +0xc */
    u32 unknown10;   /* +0x10 */
    Name unknown14;  /* +0x14 */
    float unknown18; /* +0x18 */
    float unknown1C; /* +0x1c */
};

Object0134f430::~Object0134f430() {}

// NONMATCHING: instruction order (list-ilp): the base loads the two floats
// between the two words of the colour (0x3e3d93), the build after the
// colour's stores.
void Object0134f430::FUN_003e3d70() /* derived name */
{
    TextColour00205cc0 colour = {unknownC | unknown10, 1.0f};
    FUN_00205cc0(&colour, 0, D_17ac870[unknown14.index].string0, unknown18, unknown1C);
}
