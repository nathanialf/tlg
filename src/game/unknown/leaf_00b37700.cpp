/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: formats a message into a 512-byte buffer (vsnprintf) when
 * the bool at +0x8 is set and hands it, its length (511 and the last byte
 * cleared when it did not fit) and the first argument to the object's slot 3
 * (`call [r8+0x18]`); called directly by FUN_0090d360 and
 * FUN_00b2e380 among others. The class, its other slots and the first
 * argument's meaning are not traced. */
class Log00b37700 /* derived name */
{
  public:
    void print(int channel, const char *format, ...); /* derived name */

    virtual void slot0();                                          /* derived name; not traced */
    virtual void slot1();                                          /* derived name; not traced */
    virtual void slot2();                                          /* derived name; not traced */
    virtual void write(int channel, const char *text, int length); /* derived name */

  private:
    bool enabled; /* +0x8 */
};

void Log00b37700::print(int channel, const char *format, ...)
{
    if (!enabled)
        return;
    char text[0x200];
    va_list args;
    va_start(args, format);
    int length = vsnprintf(text, sizeof text, format, args);
    va_end(args);
    if (length >= (int)sizeof text) {
        length = sizeof text - 1;
        text[sizeof text - 1] = '\0';
    }
    write(channel, text, length);
}
