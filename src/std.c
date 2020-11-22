#include"teal.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int is_space(char c) {
  return c == ' '  || c == '\t' ||
         c == '\n' || c == '\v' ||
         c == '\f' || c == '\r';
}

int is_digit(char c) {
  return c == '0' || c == '1' ||
         c == '2' || c == '3' ||
         c == '4' || c == '5' ||
         c == '6' || c == '7' ||
         c == '8' || c == '9';
}

int digit2num(char c) {
  if(c == '0') {
    return 0;
  } else if(c == '1') {
    return 1;
  } else if(c == '2') {
    return 2;
  } else if(c == '3') {
    return 3;
  } else if(c == '4') {
    return 4;
  } else if(c == '5') {
    return 5;
  } else if(c == '6') {
    return 6;
  } else if(c == '7') {
    return 7;
  } else if(c == '8') {
    return 8;
  } else if(c == '9') {
    return 9;
  } else {
    return -1;
  }
}

int strtoi(char* buf, char** ret) {
  int i = 0;
  while(is_digit(*buf)) {
    i*=10;
    i+=digit2num(*buf);
    buf++;
  }

  *ret = buf;
  return i;
}

int length(char* buf) {
  int len = 0;
  while(*(buf++)) {
    len++;
  }

  return len;
}

void sys_exit(int code) {
  syscall(60, code);
}

int read(void *buf, int count) {
  return syscall(0, STDIN, buf, count);
}

int ended() {
  return read(NULL, 1) == 0;
}

int write(void *buf, int count) {
  return syscall(1, STDOUT, buf, count);
}

int ewrite(void *buf, int count) {
  return syscall(1, STDERR, buf, count);
}

int putc(char c) {
  char buf[] = {c};
  return write(buf, 1);
}

int eputc(char c) {
  char buf[] = {c};
  return ewrite(buf, 1);
}