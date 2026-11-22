/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING _ZN14Object016a7f88C1ERK4Name (0x2bbb10): 79/81, the base takes the owner table's address (`lea rax, [0x5943280]`) before the array's (`lea rbx, [r14+0x60]`) for clear(1)'s reallocation; the build the other way. */
#include "tlg_game_object016a7f88.h"

/* derived name: the constructor: the base built from the name, the Name
 * at +0x24 emptied again (Name's assignment of the empty name, inlined:
 * `cmp dword [r14+0x24], 0` after its store), three floats and the two
 * vectors at +0x40 set (one 32-byte store from the constant at 0x14e33a0),
 * and the array of pairs given room for one (clear(1)). The class's
 * destructor is defined in the class, so this unit emits the vtable and
 * both destructors (FUN_002bbc70 and the deleting FUN_002bbda0). */
Object016a7f88::Object016a7f88(const Name &name) : Object016b9108(name)
{
    name24 = Name();
    unknown28 = 0.0f;
    unknown2c = 0.5f;
    unknown30 = 0.5f;
    unknown40 = Float4A(0.5f, 0.5f, 0.5f, 1.0f);
    unknown50 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    unknown60.clear(1);
}
