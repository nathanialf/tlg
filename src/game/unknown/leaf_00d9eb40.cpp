/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_hks.h"

/* derived names: the code a message is reported with (0x400024 for the
 * line count's), 16 bytes on the frame (`sub rsp, 0x20` with the size's
 * word); the rest is not written here */
struct ReportCode00d9eb40 { /* derived name */

    explicit ReportCode00d9eb40(int code_) : code(code_) {}

    int code;
    int unknown4;   /* not written here */
    void *unknown8; /* not written here */
};

/* derived names: the reporter the script lexer holds at +0x88; slot 2
 * takes a message and its code */
class Reporter00d9eb40 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(const char *message, const ReportCode00d9eb40 &code); /* derived name */
};

/* derived names: the script lexer's state as Lua's LexState and its input
 * stream read here (FUN_00d9d470 and FUN_00d9e620): the reader called with
 * its state and data for the next block when the bytes left run out, the
 * end of the input, the current and the previous character, the line
 * number and the reporter */
struct LexState00d9eb40 { /* derived name */
    u8 unknown0[0x28];
    lua_State *state;                                                /* +0x28 */
    const u8 *(*reader)(lua_State *state, void *data, size_t *size); /* +0x30 */
    void *data;                                                      /* +0x38 */
    size_t left;                                                     /* +0x40 */
    const u8 *next;                                                  /* +0x48 */
    int ended;                                                       /* +0x50 */
    u8 current;                                                      /* +0x54 */
    u8 previous;                                                     /* +0x55 */
    u8 unknown56[0x2];
    unsigned lineNumber; /* +0x58 */
    u8 unknown5c[0x2c];
    Reporter00d9eb40 *reporter; /* +0x88 */
};

/* derived name: Lua's inclinenumber over the stream: past the end nothing;
 * a '\n' or '\r' after the other one (`old`, the character that ended the
 * line) is skipped, then the line counted, "chunk has too many lines"
 * reported from 0x7fffffff */
void FUN_00d9eb40(LexState00d9eb40 *lex, u8 old) /* derived name */
{
    size_t size;
    if (lex->ended)
        return;
    const u8 c = *lex->next;
    const bool newline = c == '\r' || c == '\n';
    if (c != old && newline) {
        ++lex->next;
        if (--lex->left == 0) {
            const u8 *block = lex->reader(lex->state, lex->data, &size);
            if (block && size) {
                lex->left = size;
                lex->next = block;
            } else {
                lex->ended = 1;
                lex->left = 0;
                lex->previous = lex->current;
                lex->current = 0;
                goto counted;
            }
        }
        lex->previous = lex->current;
        lex->current = *lex->next;
    }
counted:
    if (lex->lineNumber >= 0x7fffffff)
        lex->reporter->slot2("chunk has too many lines", ReportCode00d9eb40(0x400024));
    ++lex->lineNumber;
}
