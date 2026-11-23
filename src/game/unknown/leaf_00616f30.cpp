/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: a text split at its blanks in a copy of its own: up to 32
 * words, each ended by a zero written over the blank after it (FUN_00616d40
 * builds one on its stack: the words and their count cleared, the text not) */
struct Words00616d40 /* derived name */
{
    Words00616d40() : words(), count(0) {}

    /* copies the text and finds its words; a 33rd word is cut off where it
     * starts (derived name) */
    void split(const char *source)
    {
        strcpy(text, source);
        char *p = text;
        while (*p) {
            if (*p == ' ') {
                *p++ = 0;
            } else {
                words[count++] = p;
                while (*p && *p != ' ')
                    ++p;
                if (count == 32)
                    break;
            }
        }
        *p = 0;
    }

    /* the number of words (derived name) */
    unsigned size() const
    {
        return count;
    }

    char text[1024]; /* +0x0 */
    char *words[32]; /* +0x400 */
    int count;       /* +0x500 */
};

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16abd90 (stored by FUN_006151c0): slot 0 the complete destructor, slot 1
 * the deleting one (operator delete of the object), slot 2 FUN_00616d40. */
class Object00616f30 /* derived name */
{
  public:
    virtual ~Object00616f30();

    /* whether a text has more than one word (derived name) */
    virtual bool slot2(const char *text);
};

Object00616f30::~Object00616f30() {}

// NONMATCHING: FUN_00616d40 22/74: the word's scan tests the end and the blank as one
// `(c | 0x20) == 0x20`; the base keeps the two exits and carries the character to the loop's
// test (`mov al, 0x20` on a blank), its load at the top replaced by the scan's (if/else, a
// `continue` on the blank and the count test in either place give one IR)
bool Object00616f30::slot2(const char *text)
{
    Words00616d40 words;
    if (!text)
        return false;
    words.split(text);
    return words.size() > 1;
}
