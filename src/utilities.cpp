#include <termios.h>
#include <stdio.h>
#include<iostream>
#include <fcntl.h>
#include "utilities.h"

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios()
{
  fcntl(0, F_SETFL, O_NONBLOCK); // makes the getchar non-blocking
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  current.c_lflag &= ~ECHO; /* set no echo mode */
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios()
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character without echo */
char get_input()
{
  char ch = getchar();
  return ch;
}
