/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtables at 0x16cafb0, 0x16cafe0, 0x16cb010 and
 * 0x16cb6a0: calls the stored function object whose implementation is at +0x40
 * with the pointer at +0x10, as a tail call; an empty one raises the C++
 * library's bad_function_call (_Xbad_function_call, its NID verified; the
 * implementation's slot 2 is the library's call slot). Class and method
 * unknown. */
namespace std
{
[[noreturn]] void _Xbad_function_call();
}

class Target013580d0 /* derived name */
{
  public:
    virtual void slot0();               /* derived name; not traced */
    virtual void slot1();               /* derived name; not traced */
    virtual void slot2(void *argument); /* derived name */
};

struct Object013580d0 { /* derived name */
    u8 unknown0[0x10];
    void *unknown10;
    u8 unknown18[0x28];
    Target013580d0 *unknown40;
};

void FUN_013580d0(Object013580d0 *self) /* derived name */
{
    if (!self->unknown40) {
        std::_Xbad_function_call();
    }
    void *argument = self->unknown10;
    self->unknown40->slot2(argument);
}
