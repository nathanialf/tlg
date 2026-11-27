/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

int FUN_00d95b60(char *buffer, size_t size, const char *format, ...); /* derived name */

/* derived name: the import q0F6yS-rCms (PLT 0x14b1c68), no candidate name
 * hits it (strcspn's NID is Q0F6yS-rCms): the length of the source before
 * any of the set's characters, as it is used here */
size_t FUN_014b1c68(const char *string, const char *set); /* derived name */

extern const char D_15bad89[6];  /* "%s?%s" */
extern const char D_15bad8f[10]; /* "[string \"" */
extern const char D_15bad99[3];  /* "\"]" */
extern const char D_15bad9c[3];  /* "\n\r" */

/* derived name: the size of a chunk's printed name (the buffer
 * FUN_00dd2f70 hands it) */
static const size_t CHUNK_ID_SIZE = 512;

/* derived name: a string and its end copied, at most `size` bytes */
static inline void copyBounded(char *out, const char *string, size_t size)
{
    const size_t length = strlen(string) + 1;
    memcpy(out, string, length > size ? size : length);
}

/* derived names: as Lua 5.1's luaO_chunkid over a buffer of 512: a source
 * from "=" printed as it is, one from "@" (a file) cut to its last part
 * behind "...", any other as [string "..."] up to its first line break;
 * without a source "[string \"?\"]" through FUN_00d95b60 */
// NONMATCHING: first draft, 11/125 (470 bytes against 492); defined, its buffer is nocapture in
// the link (FUN_00dd2f70's note: the tail call needs it in that unit's own pipeline)
void FUN_00db3a90(char *out, const char *source) /* derived name */
{
    if (!source) {
        FUN_00d95b60(out, CHUNK_ID_SIZE, D_15bad89, D_15bad8f, D_15bad99);
        return;
    }
    if (*source == '=') {
        const size_t length = strlen(source);
        const size_t size = length > CHUNK_ID_SIZE ? CHUNK_ID_SIZE : length;
        copyBounded(out, source + 1, size);
        out[size - 1] = '\0';
    } else if (*source == '@') {
        const size_t length = strlen(source);
        if (length >= CHUNK_ID_SIZE - 6) {
            strcpy(out, "...");
            copyBounded(out + 3, source + length - (CHUNK_ID_SIZE - 8), CHUNK_ID_SIZE - 3);
        } else {
            copyBounded(out, source + 1, CHUNK_ID_SIZE);
        }
        out[CHUNK_ID_SIZE - 1] = '\0';
    } else {
        strcpy(out, "[string \"");
        char *text = out + 9;
        const size_t line = FUN_014b1c68(source, D_15bad9c);
        const size_t length = strlen(source);
        size_t end;
        if (line >= CHUNK_ID_SIZE - 16) {
            copyBounded(text, source, CHUNK_ID_SIZE - 13);
            strcpy(out + CHUNK_ID_SIZE - 8, "...");
            end = CHUNK_ID_SIZE - 14;
        } else {
            copyBounded(text, source, line + 1);
            text[line] = '\0';
            end = line;
            if (line < length) {
                strcpy(text + end, "...");
                end += 3;
            }
        }
        strcpy(text + end, "\"]");
    }
}
