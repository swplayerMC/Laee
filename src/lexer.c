#include <stdio.h>
#include <string.h>
#include "lae.h"
#include "utils.h"

typedef enum {
    file_end,
    number,
    operator
} token;

token tokens[] = {0};

/* Function 'get_char_type'
 * Param: '_char' gets the decimal ASCII code of the given
 * char type variable.
 * Return: a different number based on that keycode */
int get_char_type(int ch) {
  // Digits, from 48 to 58
  if (ch >= 48 && ch <= 57) {
    return 1;
  }
  // Uppercase letter (from 65 to 90)
  // or
  // lowercase letter (from 97 to 122)
  else if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122) {
    return 2;
  }
  // Space character
  else if (ch == 32)
    return 3;
  // else:
  return 0;
}

void add_token(token _token, token *token_array, int index) {
  token_array[index] = _token;
}

void lexer_lex(lae_file_t *lae_file) {
  for (int i; i < sizeof(lae_file->content); i++) {
    char _char = lae_file->content[i];
    char prev_char;
    if (i > 0) prev_char = lae_file->content[i-1];
    char *temp;
    printf("%c", _char);
    switch (get_char_type(_char)) {
      case 1: // Digit
	if (get_char_type(prev_char)==1) {
	  concat(temp, &_char);
	}
	else {
	  temp = "";
	  concat(temp, &_char);
	}
	add_token(temp, tokens, i);
	break;
      case 3: // Space character
	break; // Just skip it
    }
  }
}

