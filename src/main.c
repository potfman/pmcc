#include "teal.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 50000

int main() {
  // Read STDIN.
  char buf2[MAX_INPUT + 1] = "";
  read_stdin(buf2, MAX_INPUT);

  // debug: Print the buffer.
  // fprintf(stderr, "%s", buf);

  // Convert char[] to char*
  char *buf = buf2;

  // Read a number.
  long n = strtol(buf, &buf, 10);

  // debug: Print a receved number.
  // fprintf(stderr, "%d\n", n);

  // Write assembly.
  puts(".intel_syntax noprefix");
  puts(".globl main");
  puts("main:");
  printf("  mov rax, %ld\n", n);
  puts("  ret");

  return 0;
}
