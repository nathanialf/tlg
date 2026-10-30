/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The XML reader's white space: a space, a tab, a line feed or a carriage
 * return (the bit test of 0x800013 from 9, 0x19ddda). derived name. */
static inline bool isXmlSpace(char c) /* derived name */
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

/* A start tag's attributes, from the white space after its name: each a
 * name, '=' and a quoted value, the parse ending at the tag's end or at the
 * first malformed one. derived name. */
static inline void parseAttributes(const char *p, hkArray<XmlAttribute> &attributes)
{
    for (;;) {
        while (isXmlSpace(*p)) {
            p++;
        }
        if (*p == '\0') {
            return;
        }
        XmlAttribute attribute;
        const char *nameStart = p;
        while (!isXmlSpace(*p) && *p != '=' && *p != '\0') {
            p++;
        }
        if (*p == '\0') {
            return;
        }
        FUN_0000eab0(&attribute.name, nameStart, int(p - nameStart));
        while (isXmlSpace(*p)) {
            p++;
        }
        if (*p != '=') {
            return;
        }
        p++;
        while (isXmlSpace(*p)) {
            p++;
        }
        if (*p != '"') {
            return;
        }
        const char *valueStart = ++p;
        while (*p != '"' && *p != '\0') {
            p++;
        }
        if (*p == '\0') {
            return;
        }
        FUN_0000eab0(&attribute.value, valueStart, int(p - valueStart));
        attributes.pushBack(attribute);
        p++;
    }
}

// NONMATCHING: classified (docs/NOTES.md, Round 58): the base leaves every
// scan loop whose increment LoopRotate folds into its last exiting block
// unrotated (the bounded scans, the attribute pointer scans), as LLVM did
// before upstream r181230; 3.3 rotates them after the fold. With the scans
// spelled so that the fold is not needed (a scratch lens, not this source)
// the rest is register allocation and the block order those loops give.
// Here also for the node classes it builds, whose vtables and inline
// destructors it emits (XmlStartElement's D1 and D0, 0x19d450, 0x19d500).
/* derived name: slot 5 of hkXmlParser: the next node of the stream. A node
 * handed back comes first; otherwise the stream is read 32 bytes ahead at a
 * time: processing instructions and comments are skipped, text up to the
 * next tag becomes character data (none when it is only white space), and a
 * tag becomes an end element or a start element with its attributes, a
 * start element closed in its own tag handing back its end element. */
hkResult hkXmlParser::FUN_0019da90(Node **nodeOut, StreamReader *stream)
{
    Object00185000 input(stream);
    if (pendingNodes.getSize()) {
        *nodeOut = pendingNodes[pendingNodes.getSize() - 1];
        pendingNodes.popBack();
        return HK_SUCCESS;
    }
    *nodeOut = 0;
    if (!input.FUN_00185230()) {
        lastError = "End of stream";
        return HK_FAILURE;
    }
    StreamReader *reader = input.reader;
    hkArray<char> text; /* derived name */
    char buffer[32];
    int numRead;
    while ((numRead = reader->peek(buffer, sizeof(buffer))) != 0) {
        if (buffer[0] == '<' && numRead < 2) {
            break;
        }
        if (buffer[0] != '<') {
            /* Text, up to the next tag. */
            for (;;) {
                int i = 0;
                while (i < numRead && buffer[i] != '<') {
                    i++;
                }
                text.insertAt(text.getSize(), buffer, i);
                if (i != numRead) {
                    reader->skip(i);
                    break;
                }
                reader->skip(numRead);
                numRead = reader->peek(buffer, sizeof(buffer));
                if (numRead == 0) {
                    break;
                }
            }
        } else if (buffer[1] == '?') {
            /* A processing instruction, up to its '>'. */
            for (;;) {
                int i = 0;
                while (i < numRead && buffer[i] != '>') {
                    i++;
                }
                if (i != numRead) {
                    reader->skip(i + 1);
                    break;
                }
                reader->skip(numRead);
                numRead = reader->peek(buffer, sizeof(buffer));
                if (numRead == 0) {
                    break;
                }
            }
        } else if (numRead >= 4 && FUN_00017f50("!--", buffer + 1, 3) == 0) {
            /* A comment, up to its "-->". */
            const char *const end = "-->";
            int matched = 0;
            for (;;) {
                int i = 0;
                for (; i < numRead; i++) {
                    if (buffer[i] == end[matched]) {
                        if (++matched == 3) {
                            break;
                        }
                    } else if (buffer[i] != '-') {
                        matched = 0;
                    }
                }
                if (i != numRead) {
                    reader->skip(i + 1);
                    break;
                }
                reader->skip(numRead);
                numRead = reader->peek(buffer, sizeof(buffer));
                if (numRead == 0) {
                    break;
                }
            }
        } else if (text.getSize()) {
            /* The text before the tag: dropped when it is only white space,
             * else the character data. */
            int i = 0;
            while (i < text.getSize() && isXmlSpace(text[i])) {
                i++;
            }
            if (i == text.getSize()) {
                text.clear();
                continue;
            }
            text.pushBack('\0');
            char *const characters = text.data; /* derived name */
            const int length = FUN_0019d710(characters, characters);
            if (length == 1 && characters[0] == '\0') {
                *nodeOut = new XmlCharacters(0);
            } else {
                *nodeOut = new XmlCharacters(characters, length);
            }
            return HK_SUCCESS;
        } else {
            /* A tag, up to its '>'. */
            hkArray<char> tag; /* derived name */
            for (;;) {
                int i = 0;
                while (i < numRead && buffer[i] != '>') {
                    i++;
                }
                tag.insertAt(tag.getSize(), buffer, i);
                if (i != numRead) {
                    reader->skip(i + 1);
                    break;
                }
                reader->skip(numRead);
                numRead = reader->peek(buffer, sizeof(buffer));
                if (numRead == 0) {
                    break;
                }
            }
            if (tag.getSize() == 0) {
                FUN_0000e790(&lastError, "Empty tag");
                return HK_FAILURE;
            }
            tag.pushBack('\0');
            const int length = FUN_0019d710(tag.data, tag.data);
            if (length == -1) {
                FUN_0000e790(&lastError, "Bad tag");
                return HK_FAILURE;
            }
            tag.setSizeUnchecked(length);
            if (tag[1] == '/') {
                hkStringBuf name(tag.data + 2);
                *nodeOut = new XmlEndElement(name.string.data);
                return HK_SUCCESS;
            }
            /* A start element: "<name attribute="value" ...>", or "/>" when
             * it closes itself. */
            const char last = tag[length - 1];
            if (last == '/') {
                tag[length - 1] = '\0';
                tag.setSizeUnchecked(tag.getSize() - 1);
            }
            int nameEnd = 0;
            while (nameEnd < tag.getSize() && tag[nameEnd] != ' ') {
                nameEnd++;
            }
            hkArray<XmlAttribute> attributes; /* derived name */
            if (nameEnd != tag.getSize()) {
                parseAttributes(tag.data + nameEnd, attributes);
                tag[nameEnd] = '\0';
                tag.setSizeUnchecked(nameEnd);
            }
            const char *const elementName = tag.data + 1; /* derived name */
            XmlStartElement *start = new XmlStartElement(elementName);
            start->attributes.swap(attributes);
            if (last == '/') {
                FUN_0019e6b0(new XmlEndElement(elementName));
            }
            *nodeOut = start;
            return HK_SUCCESS;
        }
    }
    FUN_0000e790(&lastError, "premature end of stream");
    return HK_FAILURE;
}
