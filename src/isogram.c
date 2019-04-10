#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "isogram.h"

static const int LOWEST_ASCII_CODE = (int) 'A';
static const int HIGHEST_ASCII_CODE = (int) 'Z';

int asciiCodeFor(const char character)
{
  return (int) toupper(character);
}

bool is_in_alphabet(const char character)
{
  int characterAsciiCode = asciiCodeFor(character);

  return (characterAsciiCode < LOWEST_ASCII_CODE) || (characterAsciiCode > HIGHEST_ASCII_CODE);
}

int index_of_ascii_code(int ascii_code)
{
  return ascii_code - LOWEST_ASCII_CODE;
}

bool has_been_seen_before(int ascii_code, bool ascii_codes_seen_before[])
{
  return ascii_codes_seen_before[index_of_ascii_code(ascii_code)];
}

bool is_isogram(const char phrase[]) 
{
  const int NUMBER_OF_LETTERS_IN_ALPHABET = HIGHEST_ASCII_CODE - LOWEST_ASCII_CODE + 1;
  bool ascii_codes_seen_before[NUMBER_OF_LETTERS_IN_ALPHABET];
  memset(ascii_codes_seen_before, false, NUMBER_OF_LETTERS_IN_ALPHABET);

  if (!phrase) {
    return false;
  };

  int characterAsciiCode;

  for (size_t i = 0; i < strlen(phrase); i++)
  {
    characterAsciiCode = asciiCodeFor(phrase[i]);

    if (is_in_alphabet(characterAsciiCode))
    {
      continue;
    }

    if (has_been_seen_before(characterAsciiCode, ascii_codes_seen_before))
    {
      return false;
    }
    else
    {
      ascii_codes_seen_before[index_of_ascii_code(characterAsciiCode)] = true;
    }
  }
  
  return true;
}
