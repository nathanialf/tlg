/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01499f30.h"
#include "tlg_game_object05adaaa8.h"

/* derived name: under the device's mutex, a new Object016c3b40 made from
 * the description and handed out, or, with no description or a kind it
 * does not take, the out pointer cleared, the object released and -2. */
// NONMATCHING: 97/195, 901 bytes against 892: the base passes the device
// pointer the constructor loaded for the count's `lock inc` (rdi, 0x130aaaa)
// to AllocateOnionMemory; the module loads 0x5adaaa8 again in each arm. The
// count is relaxed, so only aliasing keeps the load: the loaded device's
// +0x10090 against the global 0x5adaaa8, MayAlias for BasicAA while the
// global is the base's (extern) and not the module's own; the rest (the
// constructor's stores, the release's direct call of 0x130af40) is the base's
int JsDevice::CreateQuery(const QueryDesc01499f30 *pDesc, Object016c3b40 **ppQuery)
{
    int result;
    m_mutex.Lock();
    Object016c3b40 *query = new Object016c3b40;
    if (pDesc && query->Initialize(*pDesc)) {
        *ppQuery = query;
        result = 0;
    } else {
        *ppQuery = nullptr;
        query->Release();
        result = -2;
    }
    m_mutex.Unlock();
    return result;
}
