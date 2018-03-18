#include <string.h>
#include "str_util.h"

/* 
 * Convert C Character Literal in (str..end] (excluding surrounding quotes)
 * to character, returning converted char or -1 if string is invalid.
 */

/*
 * Convert character to digit in given base,
 * returning -1 for invalid bases and characters.
 */
int basedigit(char c, int base) {
    int i;

#if (('z' - 'a') != 25 || ('Z' - 'A') != 25)
#error Faulty Assumption
    This code assumes the code set is ASCII, ISO 646, ISO 8859, or something similar.
    #endif /* Alphabet test */
        if (base < 2 || base > 36)
            i = -1;
        else if (c >= '0' && c <= '9')
            i = c - '0';
        else if (c >= 'A' && c <= 'Z')
            i = c - 'A' + 10;
        else if (c >= 'a' && c <= 'z')
            i = c - 'a' + 10;
        else
            i = -1;
    return((i < base) ? i : -1);
}

/* 
 * Convert string containing C character literal to character value
 * Returns -1 if character literal is invalid, otherwise 0x00..0xFF
 * Does not support extension \E for ESC \033.
 * Does not support any extension for DEL \177.
 * Does not support control-char notation ^A for CTRL-A \001.
 * Accepts \z as valid z when z is not otherwise special.
 * Accepts \038 as valid CTRL-C \003; next character starts with the 8.
 * Accepts \x3Z as valid CTRL-C \003; next character starts with the Z.
 * Treats invalid octal escape \8 or \9 as 8 or 9
 */
int cstrlit_chr(const char *str) {
    ++str;
    const char *end = str + strlen(str) - 1;
    unsigned char u;
    int rv;

    if (str >= end)
        rv = -1;    /* String contains no data */
    else if ((u = *str++) != '\\')
        rv = u;
    else if (str == end)
        rv = -1;    /* Just a backslash - invalid */
    else if ((u = *str++) == 'x') {
       /*
        * Hex character constant - \xHH or \xH, where H is a hex digit.
        * Technically, can be \xHHH too, if CHAR_BIT > 8; this nicety
        * is being studiously ignored.
        */
        int x1;
        int x2;
        if (str == end)
            rv = -1;
        else if ((x1 = basedigit(*str++, 16)) < 0) {
            rv = -1;        /* Invalid hex constant */
            str--;
        }
        else if (str == end)
            rv = x1;        /* Single digit hex constant */
        else if ((x2 = basedigit(*str++, 16)) < 0) {
            rv = x1;        /* Single-digit hex constant */
            str--;
        }
        else
            rv = (x1 << 4) | x2;    /* Double-digit hex constant */
    }
    else if ('0' <= u && u <= '9') {
       /*
        * Octal character constant - \O or \OO or \OOO, where O is an
        * octal digit.  Technically, the constant extends for an
        * indefinite number of octal digits; this nicety is being
        * studiously ignored.  Treat \8 as 8 and \9 as 9.
        */
        int o1;
        int o2;
        int o3;
        if ((o1 = basedigit(u, 8)) < 0)
            rv = u; /* Invalid octal constant (\8 or \9) */
        else if (str == end)
            rv = o1;    /* Single-digit octal constant */
        else if ((o2 = basedigit(*str++, 8)) < 0) {
            rv = o1;    /* Single-digit octal constant */
            str--;
        }
        else if (str == end)
            rv = (o1 << 3) | o2;    /* Double-digit octal constant */
        else if ((o3 = basedigit(*str++, 8)) < 0) {
            rv = (o1 << 3) | o2;    /* Double-digit octal constant */
            str--;
        }
        else if (o1 >= 4)
            rv = -1;                /* Out of range 0x00..0xFF (\000..\377) */
        else
            rv = (((o1 << 3) | o2) << 3) | o3;
    }
    else {
        /* Presumably \a, \b, \f, \n, \r, \t, \v, \', \", \? or \\ - or an error */
        switch (u) {
        case 'a':
            rv = '\a';
            break;
        case 'b':
            rv = '\b';
            break;
        case 'f':
            rv = '\f';
            break;
        case 'n':
            rv = '\n';
            break;
        case 'r':
            rv = '\r';
            break;
        case 't':
            rv = '\t';
            break;
        case 'v':
            rv = '\v';
            break;
        case '\"':
            rv = '\"';
            break;
        case '\'':
            rv = '\'';
            break;
        case '\?':
            rv = '\?';
            break;
        case '\\':
            rv = '\\';
            break;
        case '\0':  /* Malformed: solitary backslash followed by NUL */
            rv = -1;
            break;
        default:
            rv = u; /* Nominally invalid: \X but X not special; return X. */
            break;
        }
    }
    return rv;
}
