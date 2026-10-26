/* The Sony network library functions the executable imports. Each name is the
 * import's verified NID name (tools/nid_names.py), reached through its PLT
 * stub; the parameter types are read from the calls in the base. */
#ifndef TLG_SCE_NET_H
#define TLG_SCE_NET_H

extern "C" {
int sceNetTerm(void);
}

#endif
