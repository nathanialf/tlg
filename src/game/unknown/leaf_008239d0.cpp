/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_string01331840.h"
#include "tlg_game_counted00351760.h"

/* FUN_008239d0: an edge added to the graph: named "<graph's name>_Edge_<the
 * edge count>" (FUN_00cbc2d0, the name of the formatted text), handed to
 * FUN_00c55dd0 with the graph's object at +0x38 and a reference to it
 * appended to the edges at +0x270 (FUN_00351760, an empty reference for
 * null). Answers the edge's name's text. Its callers are not traced. */
// NONMATCHING: instruction order only (116 of 118): the base forms the edges' address
// (`add r12, 0x270` at 0x823ac8) after the call of FUN_00c55dd0, the build before it.
const char *FUN_008239d0(Graph008239d0 *graph, Counted00351760 *edge) /* derived name */
{
    String01331840 text;
    FUN_01331840(&text, "%s_Edge_%d", D_17ac870[graph->name.index].string0, graph->edges270.size());
    FUN_00cbc2d0(D_5945a38, edge, Name(text));
    FUN_00c55dd0(edge, graph->unknown38, 0);
    graph->edges270.push(Ref00503fb0<Counted00351760>(edge));
    return D_17ac870[edge->name.index].string0;
}
