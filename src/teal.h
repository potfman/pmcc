#ifndef _TEAL_H_
#define _TEAL_H_

#include <stddef.h>

// util.c
void read_stdin(char *buf, size_t count);

// lex.c
#define LEX_EOF 0
#define LEX_NUM 1
#define LEX_ADD 2
#define LEX_SUB 3

void init_lexer(char *buf);
int token(int c);
char *value(int c);

#endif
