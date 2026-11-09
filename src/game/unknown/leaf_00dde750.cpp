/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: returns the int 1 (`mov eax, 1`, a 32-bit result).
 * FUN_00c83870 stores its address at +0x178 of the record it fills (lea at
 * 0xc83dab); FUN_00c83870 also pushes the script function FUN_00c871d0 under
 * "GaPrint". The caller through +0x178 is not traced, so no parameters are
 * known: int with none. Owner and meaning unknown. */
int FUN_00dde750() /* derived name */
{
    return 1;
}
