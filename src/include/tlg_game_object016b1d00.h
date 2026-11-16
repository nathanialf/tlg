/* src/include/tlg_game_object016b1d00.h: the class whose vtable is at
 * 0x16b1d00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1D00_H
#define TLG_GAME_OBJECT016B1D00_H

#include "tlg_game_object016c7c78.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b1d00
 * (config/vtables.derived.base.txt, stored by FUN_00a29f30 FUN_00a2b360 FUN_00a2b430), derived from Object016c7c78 (tlg_game_object016c7c78.h; itself derived from
 * Object016b9108): slot 5 is its own (declared; their bodies are not written here), the others the base's. Its own fields
 * from +0x50 are traced where its destructor FUN_00a2b360 tears them down
 * (the record at +0x50) and where the creator FUN_00a29f30 inlines its
 * constructor; their meaning is not traced. 0x70 bytes (the creator's
 * `mov edi, 0x70`). */
class Object016b1d00 : public Object016c7c78 /* derived name */
{
  public:
    /* inlined in the creator FUN_00a29f30: the array empty, its lock made
     * free, the int at +0x68 zero */
    Object016b1d00(const Name &name) : Object016c7c78(name), unknown68(0) {}

    virtual ~Object016b1d00();
    virtual void slot5(); /* derived name; FUN_00a2b500, not traced */

  private:
    /* +0x50: an array of counted references with its lock at +0x64 (the
     * creator's `mov dword [r15+0x64], 0` after the owner's index), torn
     * down by the destructor (`lea rdi, [rbx+0x50]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> record50;
    int unknown68; /* +0x68: zero from the constructor; not traced */
    u8 unknown6c[0x4];
};

#endif
