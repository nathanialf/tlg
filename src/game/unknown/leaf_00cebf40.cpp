/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a factory that creates nothing. FUN_00cebf60 passes its
 * address (lea at 13554549) to FUN_00cbb0e0 as the 7th argument, the default
 * when its caller supplies no function, with the int 0xb0 as its 4th argument;
 * FUN_00cbb0e0 stores the 7th argument at +0x8 of the 0xa8-byte type record it
 * allocates. The factories in that place that do create (FUN_00204080) take
 * two pointers, ignore the first, pass the second to the base constructor and
 * return the new object: a null object pointer here, with both parameters
 * unused. Type unknown. */
struct Object00cebf40;

Object00cebf40 *FUN_00cebf40(void *, void *) /* derived name */
{
    return 0;
}
