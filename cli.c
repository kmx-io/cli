
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char * readline (const char *prompt);

#include "cli.h"

void cli_init (s_cli *cli)
{
  using_history();
  cli_prompt(cli, "> ");
}

void cli_prompt (s_cli *cli, const char *prompt)
{
  cli->prompt = prompt;
}

int cli_scan (s_cli *cli, const char *line)
{
  unsigned i = 0;
  char *arg = cli->arg;
  char **argv = cli->argv;
  cli->argc = 0;
  *argv = arg;
  while (1) {
    *arg = ((++i == 1000) ? 0 : *line);
    if (*arg == 0) {
      if (*argv != arg) {
        argv++;
        cli->argc++;
      }
      *argv = 0;
      return cli->argc;
    }
    else if (*arg == ' ') {
      *arg = 0;
      if (*argv != arg) {
        argv++;
        cli->argc++;
      }
      *argv = arg + 1;
    }
    arg++;
    line++;
  }
}

int cli_read (s_cli *cli)
{
  char * line = readline(cli->prompt);
  if (line) {
    add_history(line);
    return cli_scan(cli, line);
  }
  return (cli->argc = -1);
}
