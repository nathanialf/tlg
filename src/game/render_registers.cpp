/* src/game/render_registers.cpp: the hardware words' init, out of line. They
 * have no address of their own in the base: the link inlines them at each
 * caller (CreateRasterizerState, 0x131f450), where their stores stay under
 * the stores that follow (tlg_game_jsrasterizerstate.h). */
#include "tlg_types.h"

#include "tlg_game_jsrasterizerstate.h"

void PrimitiveSetup0131f450::init()
{
    m_reg = kPolygonModeFill << 5 | kPolygonModeFill << 8;
}

void ClipControl0131f450::init()
{
    m_reg = 0x80000;
}
