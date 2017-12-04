
#include <stdio.h>
#include "cli.h"

void print_argv (int argc, char **argv)
{
  if (argc < 1)
    return;
  putchar('(');
  while (1) {
    if (argc < 1) {
      putchar(')');
      putchar('\n');
      return;
    }
    char *a = *argv;
    while (*a != 0) {
      putchar(*a);
      a++;
    }
    if (argc > 1) {
      putchar(',');
      putchar(' ');
    }
    argv++;
    argc--;
  }
}

int repl ()
{
  s_cli cli;
  cli.prompt = "clidemo> ";
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
