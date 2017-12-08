
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

char * readline (const char *prompt);

#include "cli.h"

void cli_init (s_cli *cli)
{
  if (isatty(0)) {
    cli->prompt = "> ";
    using_history();
  }
  else
    cli->prompt = 0;
  cli->functions = 0;
}

void cli_prompt (s_cli *cli, const char *prompt)
{
  if (isatty(0))
    cli->prompt = prompt;
  else
    cli->prompt = 0;
}

void cli_functions (s_cli *cli, const s_cli_function *functions)
{
  cli->functions = functions;
}

int cli_scan (s_cli *cli)
{
  unsigned i = 0;
  char *line = cli->line;
  char *arg = cli->arg;
  const char **argv = cli->argv;
  cli->argc = 0;
  *argv = arg;
  while (1) {
    *arg = ((++i == CLI_SIZE) ? 0 : *line);
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

int cli_readline (s_cli *cli)
{
  if (cli->prompt) {
    char *line = readline(cli->prompt);
    if (line == 0)
      return -1;
    strncpy(cli->line, line, CLI_SIZE - 1);
    cli->line[CLI_SIZE - 1] = 0;
    free(line);
    add_history(cli->line);
    return 0;
  }
  if (fgets(cli->line, CLI_SIZE, stdin))
    return 0;
  return -1;
}

int cli_read (s_cli *cli)
{
  cli->argc = -1;
  cli->f = 0;
  if (cli_readline(cli))
    return -1;
  cli_scan(cli);
  if (0 < cli->argc)
    cli->f = cli_find_function(cli, cli->argv[0], cli->argc - 1);
  return cli->argc;
}

f_cli cli_find_function (s_cli *cli, const char *name, int arity)
{
  const s_cli_function *function = cli->functions;
  if (function == 0)
    return 0;
  while (1) {
    if (function->name == 0)
      return 0;
    if (strcmp(function->name, name) == 0 &&
        (function->arity < 0 || arity < 0 || function->arity == arity))
      return function->f;
    function++;
  }
}

int cli_eval (s_cli *cli)
{
  if (0 < cli->argc && cli->f)
    return cli->f(cli->argc - 1, cli->argv);
  return -1;
}
