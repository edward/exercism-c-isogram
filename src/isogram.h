#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>

int asciiCodeFor(const char character);

bool is_in_alphabet(const char character);

int index_of_ascii_code(int ascii_code);

bool has_been_seen_before(int ascii_code, bool ascii_codes_seen_before[]);

bool is_isogram(const char phrase[]);

#endif
