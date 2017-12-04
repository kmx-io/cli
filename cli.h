
#ifndef CLI_H
#define CLI_H

typedef struct cli
{
  char *prompt;
  char line[1000];
  char arg[1000];
  int argc;
  char *argv[500];
} s_cli;

int cli_read ();

#endif /* CLI_H */

