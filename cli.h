
#ifndef CLI_H
#define CLI_H

#define CLI_SIZE 1000

typedef struct cli s_cli;
typedef struct cli_function s_cli_function;
typedef int (* f_cli) (int argc, const char *argv[]);

struct cli
{
  const char *prompt;
  const s_cli_function *functions;
  char line[CLI_SIZE];
  char arg[CLI_SIZE];
  int argc;
  const char *argv[500];
  f_cli f;
};

void cli_init (s_cli *cli);
void cli_prompt (s_cli *cli, const char *prompt);

struct cli_function {
  const char *name;
  int arity;           /* negative arity means variable arity */
  f_cli f;
};

void cli_functions (s_cli *cli, const s_cli_function *functions);
f_cli cli_find_function (s_cli *cli, const char *name, int arity);

int cli_scan (s_cli *cli);
int cli_read (s_cli *cli);
int cli_eval (s_cli *cli);

#endif /* CLI_H */

