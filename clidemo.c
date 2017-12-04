
#include <stdio.h>
#include "cli.h"

void print_argv (int argc, char **argv)
{
  if (argc < 1)
    return;
  printf("%s(", *argv);
  argv++;
  argc--;
  while (1) {
    if (argc < 1) {
      printf(");\n");
      return;
    }
    printf("%s", *argv);
    if (argc > 1)
      printf(", ");
    argv++;
    argc--;
  }
}

int repl ()
{
  s_cli cli;
  cli_init(&cli);
  cli_prompt(&cli, "clidemo> ");
  while (1) {
    cli_read(&cli);
    print_argv(cli.argc, cli.argv);
    if (cli.argc < 0)
      return 0;
  }
  return 0;
}

int main (int argc, char *argv[])
{
  (void) argc;
  (void) argv;
  return repl();
}
