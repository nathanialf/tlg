/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

class Object016b9720;

/* derived names: the object the holder's pointer at +0x38 names; its
 * pointer at +0x18 names the holder back. Only that field is traced
 * (the holder's destructor clears both ends). */
struct Peer016b9720 /* derived name */
{
    inline void detach(); /* derived name */

    u8 unknown0[0x18];
    Object016b9720 *holder18; /* +0x18 */
};

/* derived names: the class whose vtable is at 0x16b9720
 * (config/vtables.derived.base.txt, stored by FUN_00ced790 FUN_00cee190 FUN_00cee240),
 * derived from Object016b9108: its slots 2 to 4 are the base's. Its
 * own fields from +0x24 are traced only where its destructor FUN_00cee190
 * reads them (the linked object at +0x38); the rest are not traced. */
class Object016b9720 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b9720();

  private:
    friend struct Peer016b9720;

    u8 unknown24[0x14];
    Peer016b9720 *peer38; /* +0x38: detached by the destructor */
};

/* derived name: cuts the link from both ends where a holder is attached
 * (`mov rcx, [rax+0x18]; test rcx, rcx; je; mov qword [rcx+0x38], 0;
 * mov qword [rax+0x18], 0`). */
inline void Peer016b9720::detach()
{
    if (holder18 != 0) {
        holder18->peer38 = 0;
        holder18 = 0;
    }
}

/* derived name: the complete destructor: the body detaches the linked
 * object where there is one; no member has a destructor; then the base's
 * destructor is inlined (its vptr store, then the two names).
 * FUN_00cee240, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016b9720::~Object016b9720()
{
    if (peer38 != 0)
        peer38->detach();
}
