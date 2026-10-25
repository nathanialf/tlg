/* The Sony Fios file functions the executable imports, declared here because
 * the build is freestanding (-nostdinc). Each name is the import's verified
 * NID name (tools/nid_names.py), reached through its PLT stub; the parameter
 * types are read from the calls in the base. */
#ifndef TLG_SCE_FIOS_H
#define TLG_SCE_FIOS_H

typedef int SceFiosFH;      /* derived name: a 32-bit file handle */
typedef long SceFiosOffset; /* derived name: a 64-bit file offset */

extern "C" {
SceFiosOffset sceFiosFHTell(SceFiosFH fh);
}

#endif
