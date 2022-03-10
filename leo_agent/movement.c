#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/agent.h"
#include "beenet.h"

dir_t	get_player_dir(agent_info_t *info, int hasflower)
{
	dir_t dir;
	int bee_pos_is_midmap = (info->col > 1 && info->col < 28);
	int go_way = rand() % 8;
	if (go_way == W)
		go_way = E;
	if (hasflower)
	{
		if (info->row > game.hivecords.row && bee_pos_is_midmap)
			dir = NW + (flag_dir[dir] * (info->player == 1));
		if (info->row < game.hivecords.row && bee_pos_is_midmap)
			dir = SW + (flag_dir[dir] * (info->player == 1));
		if (info->col == game.hivecords.col && info->row > 12)
			dir = N;
		if (info->col == game.hivecords.col && info->row < 12)
			dir = S;
		if (info->col > game.hivecords.col && info->player == 0)
			dir = W;
		if (info->col < game.hivecords.col && info->player == 1)
			dir = E;
	}
	else
		dir = go_way + (flag_dir[dir] * (info->player == 1));
	return (dir);
}