/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The base system's start (derived name; hkBaseSystem::init by its place
 * before the thread setup 0x9a60 and the quit 0x9ad0): once, the calling
 * thread set up with the router, the reference lock made, the Fios file
 * system and the default error over the report function installed as the
 * singletons (each previous instance's reference released), the
 * singletons' list created, the dummy singleton's slot called and the
 * game's hook run. Always a success. */
hkResult FUN_000098d0(hkMemoryRouter *router, ReportFunction0000b330 reportFunction,
                      void *reportObject) /* derived name */
{
    if (!D_57b80c0) {
        FUN_00009a60(router);
        FUN_00006800();

        hkFileSystem *fileSystem = new FiosFileSystem();
        if (D_57b9b70) {
            D_57b9b70->removeReference();
        }
        D_57b9b70 = fileSystem;

        hkError *error = new Object0000b330(reportFunction, reportObject);
        if (D_57af768) {
            D_57af768->removeReference();
        }
        D_57af768 = error;

        FUN_00009550();
        D_57b80c8->FUN_00008d60();
        FUN_00e98be0();
        D_57b80c0 = true;
    }
    return HK_SUCCESS;
}

/* derived name: a thread's setup with a memory router (called at 0x8f5cc
 * after the floating-point control word is set): the router becomes the
 * thread's, then the thread's block is made; always a success. */
hkResult FUN_00009a60(hkMemoryRouter *router) /* derived name */
{
    FUN_0000bb40(router);
    FUN_014aff00();
    return HK_SUCCESS;
}
