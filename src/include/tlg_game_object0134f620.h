/* src/include/tlg_game_object0134f620.h: the record that 0x134f620 tears
 * down, a member of many game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT0134F620_H
#define TLG_GAME_OBJECT0134F620_H

#include "tlg_types.h"

/* derived names: the record, an array of reference-counted objects. Its
 * destructor is 0x134f620 (D15: the classes that hold it call it where a
 * member's destructor runs, `lea rdi, [rbx+X]; call 0x134f620`, 683 call
 * sites): it drops each pointer of the array at +0x0 counted by the int at
 * +0x8 (a release through the object's slot 2 at the last reference), then
 * frees the array's block. Not written: it reads the thread-local flag
 * D_16dc088 (held). Its fields are not traced beyond the first two. */
struct Object0134f620 /* derived name */
{
    ~Object0134f620();
    /* derived name: 0x138c8d0 drops every pointer of the array (the same
     * release), then resizes the array's block to its int argument where
     * the capacity at +0xc differs (not written: it reads the thread-local
     * flag too). A holder's destructor passes 0 (`xor esi, esi`). */
    void FUN_0138c8d0(int capacity);

    void **unknown0; /* +0x0 */
    int unknown8;    /* +0x8 */
};

#endif
