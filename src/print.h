#ifndef __JSONPRINT_H__
#define __JSONPRINT_H__

#include "buffer.h"

#define PRINT_BUFFER_1(buffer) {			\
    PRINT_BUFFER(buffer.getData(), buffer.getLength())	\
}

#define PRINT_BUFFER(data, len) {		\
    int buflen = len;				\
    if (buflen < 0) buflen = 0;			\
    char* buffer = (char*) malloc(buflen + 1);	\
    buffer[buflen] = '\0';			\
    strncpy(buffer, data, buflen);		\
    printf("%s", buffer);			\
    free(buffer);				\
}

void printIndent(int indent);
void printIndented(int indent, const char* str, int len);
void printIndented(int indent, const Buffer& buffer);

#ifdef ENABLE_JSON

#include <json-glib/json-glib.h>

void printJson(JsonObject* obj);

#endif /* ENABLE_JSON */

#endif /* __JSONPRINT_H__ */

