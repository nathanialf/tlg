/* src/include/tlg_game_object016c7880.h: the class whose vtable is at
 * 0x16c7880 and the classes over it (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016C7880_H
#define TLG_GAME_OBJECT016C7880_H

#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the node at +0xb0 of the classes below: two counted
 * references another thread may replace, at +0x68 and +0x70; emptying one
 * sets bit 3 of the root class's flags (`or byte [r15+0x20], 8` after each,
 * through the node read before the exchange) */
class Node016c7880 : public Node00503fb0 /* derived name */
{
  public:
    void clearUnknown68() /* derived name */
    {
        unknown68.clear();
        flags |= 8;
    }

    void clearUnknown70() /* derived name */
    {
        unknown70.clear();
        flags |= 8;
    }

  private:
    u8 unknown64[0x4];
    AtomicRef0045c470<Object016b9108> unknown68; /* +0x68 */
    AtomicRef0045c470<Object016b9108> unknown70; /* +0x70 */
};

/* derived names: the class whose vtable is at 0x16c7880
 * (config/vtables.derived.base.txt, stored by FUN_007a7110): the node at
 * +0xb0. Its destructor 0x7a7960 (not written) and the destructors of the
 * classes over it each begin by letting the node go: its two references
 * emptied, then the node handed to FUN_00c5a160 when its pointer at +0x28 is
 * set (`cmp qword [rdi+0x28], 0` before the call at 0x7a9ba9), the node
 * read again from +0xb0 after each reference is emptied. */
class Object016c7880 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c7880();

  private:
    u8 unknown24[0x8c];

  protected:
    Node016c7880 *unknownb0; /* +0xb0 */
};

#endif
