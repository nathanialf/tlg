/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c7c78.h"

/* derived names: the class whose vtable is at 0x16b1cc0
 * (config/vtables.derived.base.txt, stored by FUN_00a29d80 FUN_00a2a670), derived from Object016c7c78 (tlg_game_object016c7c78.h; itself derived from
 * Object016b9108): slot 5 is its own (declared; their bodies are not written here), the others the base's. Its own fields
 * from +0x28 are traced only where its destructor FUN_00a2a670 tears them down
 * (the Names at +0x68, +0x64, +0x58, +0x50); the rest are not traced. */
class Object016b1cc0 : public Object016c7c78 /* derived name */
{
  public:
    virtual ~Object016b1cc0();
    virtual void slot5(); /* derived name; FUN_00a2a820, not traced */

  private:
    u8 unknown28[0x28];
    Name name50; /* +0x50: released by the destructor (`mov eax, [rbx+0x50]; shl 5`) */
    u8 unknown54[0x4];
    Name name58; /* +0x58: released by the destructor (`mov eax, [rbx+0x58]; shl 5`) */
    u8 unknown5c[0x8];
    Name name64; /* +0x64: released by the destructor (`mov eax, [rbx+0x64]; shl 5`) */
    Name name68; /* +0x68: released by the destructor (`mov eax, [rbx+0x68]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * (FUN_00a2a290, tlg_game_object016c7c78.h) is inlined, and Object016b9108's in it.
 * FUN_00a2a800, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b1cc0::~Object016b1cc0() {}
