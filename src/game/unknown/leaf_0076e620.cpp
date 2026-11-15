/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016accb0.h"

/* derived names: a name every object of the class starts with (defined in
 * func_00773e90.cpp, "jt_ProxySamplingA"), and a value of four ints the
 * executable only reads (0x58178b0, zero: no store anywhere) */
extern Name D_58178ac;
extern Value004af700 D_58178b0;

/* derived name: the constructor (tlg_game_object016accb0.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the names
 * and the references start empty; then the body: the base's float at +0x7c,
 * the fields from +0xf0 in order, the Name at +0x100 a copy of D_58178ac,
 * the value at +0x120 copied member by member from D_58178b0 (`mov dword;
 * shr rax, 0x20; mov dword`). */
Object016accb0::Object016accb0(const Name &name) : Object00774560(name)
{
    unknown7c = 0.2f;
    unknownf0 = 0.25f;
    unknownfc = 0.1f;
    name100 = D_58178ac;
    unknown104 = 0.5f;
    unknown108 = 0.5f;
    unknown10c = -1;
    unknown110 = -1;
    unknown114 = 0;
    unknown120.set(D_58178b0);
    unknown130 = -1;
    unknown134[0] = 0.0f;
    unknown134[1] = 0.0f;
    unknown134[2] = 3.40282347e+38f;
    unknown134[3] = 3.40282347e+38f;
    unknown144 = 0;
    unknown150 = 1;
    unknown154[0] = -3.40282347e+38f;
    unknown154[1] = -3.40282347e+38f;
    unknown154[2] = -3.40282347e+38f;
    unknown154[3] = 3.40282347e+38f;
    unknown164[0] = 0;
    unknown164[1] = 0x72000;
    unknown164[2] = -1;
    unknown164[3] = -1;
    unknown174 = -1;
    unknown178 = 1;
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0076e800, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016accb0::~Object016accb0() {}
