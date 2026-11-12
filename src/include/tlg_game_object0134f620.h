/* src/include/tlg_game_object0134f620.h: the record that FUN_0134f620 tears
 * down, a member of many game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT0134F620_H
#define TLG_GAME_OBJECT0134F620_H

#include "tlg_types.h"

/* derived names: the record; the classes that hold it call FUN_0134f620 on
 * it from their destructors (`lea rdi, [rbx+X]; call FUN_0134f620`), in the
 * place its own destructor would run. Its fields are not traced beyond the
 * first two. */
struct Object0134f620 /* derived name */
{
    void **unknown0; /* +0x0 */
    int unknown8;    /* +0x8 */
};

void FUN_0134f620(Object0134f620 *self); /* derived name */

#endif
