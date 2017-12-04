
#ifndef CLI_H
#define CLI_H

typedef struct cli
{
  const char *prompt;
  char line[1000];
  char arg[1000];
  int argc;
  char *argv[500];
} s_cli;

void cli_init (s_cli *cli);
void cli_prompt (s_cli *cli, const char *prompt);
int cli_scan (s_cli *cli, const char *line);
int cli_read (s_cli *cli);

#endif /* CLI_H */

