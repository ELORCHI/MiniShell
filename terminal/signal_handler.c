#include "terminal.h"

void signal_handler(void)
{
	if (signal(SIGINT, ctrl_c_handler) == SIG_ERR)
		exit(1);
	if (signal(SIGQUIT, ctrl_bs_handler) == SIG_ERR)
		exit(1);
}

void ctrl_c_handler(int sig)
{
	sig = 0;
	free(g_data.command_line);
	g_data.command_line = ft_strdup("");
	g_data.hists = last_hist(g_data.hists);
	g_data.nb_line = 0;
	write(1, "\nMiniShell $> ", 14);
	return;
}

void ctrl_bs_handler(int sig)
{
	sig = 0;
	return;
}
