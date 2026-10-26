/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the Graphviz fill colour of a node in one of three states,
 * for the graph dumps from 0x486f0 (which ask for state 2), 0x48840 and
 * 0x489f0; nothing for any other state. */
const char *FUN_00091b30(int state) /* derived name */
{
    switch (state) {
    case 0:
        return "fillcolor=\"#e0ffe0\"";
    case 1:
        return "fillcolor=lightyellow";
    case 2:
        return "fillcolor=\"#ff8080\"";
    default:
        return "";
    }
}
