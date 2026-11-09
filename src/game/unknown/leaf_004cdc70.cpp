/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: raises the C++ library's length error with "string too long"
 * (the import _ZSt14_Xlength_errorPKc, its NID verified by
 * tools/nid_names.py; it does not return, so ud2 follows the call); called by
 * FUN_004cda20 and FUN_00a282d0 when a string would outgrow its maximum size.
 * Owner unknown. */
namespace std
{
[[noreturn]] void _Xlength_error(const char *message);
}

void FUN_004cdc70() /* derived name */
{
    std::_Xlength_error("string too long");
}
