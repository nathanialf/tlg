/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: three functions on the file's own flag at 0x583262c (direct
 * RIP-relative accesses: internal linkage, docs/DECISIONS.md D17), which
 * FUN_00b127e0 also clears (0xb1296b). FUN_00b10ec0 stores the addresses of
 * FUN_00b108b0 and FUN_00b108c0 (lea at 0xb11f47 and 0xb11f64) and of
 * FUN_00b108d0 (lea at 0xb12037, stored at 0x5832398) into its records; none
 * of the three reads an argument, and no call shows its parameters. Owner and
 * meaning unknown. */
static bool D_583262c;

void FUN_00b108b0() /* derived name */
{
    D_583262c = true;
}

void FUN_00b108c0() /* derived name */
{
    D_583262c = false;
}

bool FUN_00b108d0() /* derived name */
{
    return D_583262c;
}
