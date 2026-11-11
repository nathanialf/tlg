/* The Sony 3D audio library functions the executable imports. Each name is the
 * import's verified NID name (tools/nid_names.py), reached through its PLT
 * stub; the parameter types are read from the calls in the base. */
#ifndef TLG_SCE_AUDIO3D_H
#define TLG_SCE_AUDIO3D_H

extern "C" {
/* Pushes a port's queued audio; FUN_00ecc810 passes 1 as the blocking mode. */
int sceAudio3dPortPush(unsigned int port, int blocking);
}

#endif
