/*
 * vim:ts=4:sw=4:expandtab
 *
 * i3 - an improved dynamic tiling window manager
 * © 2009 Michael Stapelberg and contributors (see also: LICENSE)
 *
 * commands.c: all command functions (see commands_parser.c)
 *
 */
#pragma once

#include <config.hpp>

#include "data.hpp"
#include "commands_parser.hpp"

/**
 * Initializes the specified 'Match' data structure and the initial state of
 * commands.c for matching target windows of a command.
 *
 */
void cmd_criteria_init(Match *current_match, CommandResultIR *cmd_output);

/**
 * A match specification just finished (the closing square bracket was found),
 * so we filter the list of owindows.
 *
 */
void cmd_criteria_match_windows(Match *current_match, CommandResultIR *cmd_output);

/**
 * Interprets a ctype=cvalue pair and adds it to the current match
 * specification.
 *
 */
void cmd_criteria_add(Match *current_match, CommandResultIR *cmd_output, const char *ctype, const char *cvalue);

/**
 * Implementation of 'move [window|container] [to] workspace
 * next|prev|next_on_output|prev_on_output'.
 *
 */
void cmd_move_con_to_workspace(Match *current_match, CommandResultIR *cmd_output, const char *which);

/**
 * Implementation of 'move [window|container] [to] workspace back_and_forth'.
 *
 */
void cmd_move_con_to_workspace_back_and_forth(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'move [--no-auto-back-and-forth] [window|container] [to] workspace <name>'.
 *
 */
void cmd_move_con_to_workspace_name(Match *current_match, CommandResultIR *cmd_output, const char *name, const char *no_auto_back_and_forth);

/**
 * Implementation of 'move [--no-auto-back-and-forth] [window|container] [to] workspace number <number>'.
 *
 */
void cmd_move_con_to_workspace_number(Match *current_match, CommandResultIR *cmd_output, const char *which, const char *no_auto_back_and_forth);

/**
 * Implementation of 'resize set <width> [px | ppt] <height> [px | ppt]'.
 *
 */
void cmd_resize_set(Match *current_match, CommandResultIR *cmd_output, long cwidth, const char *mode_width, long cheight, const char *mode_height);

/**
 * Implementation of 'resize grow|shrink <direction> [<px> px] [or <ppt> ppt]'.
 *
 */
void cmd_resize(Match *current_match, CommandResultIR *cmd_output, const char *way, const char *direction, long resize_px, long resize_ppt);

/**
 * Implementation of 'border normal|pixel [<n>]', 'border none|1pixel|toggle'.
 *
 */
void cmd_border(Match *current_match, CommandResultIR *cmd_output, const char *border_style_str, long border_width);

/**
 * Implementation of 'nop <comment>'.
 *
 */
void cmd_nop(Match *current_match, CommandResultIR *cmd_output, const char *comment);

/**
 * Implementation of 'append_layout <path>'.
 *
 */
void cmd_append_layout(Match *current_match, CommandResultIR *cmd_output, const char *path);

/**
 * Implementation of 'workspace next|prev|next_on_output|prev_on_output'.
 *
 */
void cmd_workspace(Match *current_match, CommandResultIR *cmd_output, const char *which);

/**
 * Implementation of 'workspace [--no-auto-back-and-forth] number <number>'
 *
 */
void cmd_workspace_number(Match *current_match, CommandResultIR *cmd_output, const char *which, const char *no_auto_back_and_forth);

/**
 * Implementation of 'workspace back_and_forth'.
 *
 */
void cmd_workspace_back_and_forth(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'workspace [--no-auto-back-and-forth] <name>'
 *
 */
void cmd_workspace_name(Match *current_match, CommandResultIR *cmd_output, const char *name, const char *no_auto_back_and_forth);

/**
 * Implementation of 'mark [--add|--replace] [--toggle] <mark>'
 *
 */
void cmd_mark(Match *current_match, CommandResultIR *cmd_output, const char *mark, const char *mode, const char *toggle);

/**
 * Implementation of 'unmark [mark]'
 *
 */
void cmd_unmark(Match *current_match, CommandResultIR *cmd_output, const char *mark);

/**
 * Implementation of 'mode <string>'.
 *
 */
void cmd_mode(Match *current_match, CommandResultIR *cmd_output, const char *mode);

/**
 * Implementation of 'move [window|container] [to] output <str>'.
 *
 */
void cmd_move_con_to_output(Match *current_match, CommandResultIR *cmd_output, const char *name, bool move_workspace);

/**
 * Implementation of 'move [window|container] [to] mark <str>'.
 *
 */
void cmd_move_con_to_mark(Match *current_match, CommandResultIR *cmd_output, const char *mark);

/**
 * Implementation of 'floating enable|disable|toggle'
 *
 */
void cmd_floating(Match *current_match, CommandResultIR *cmd_output, const char *floating_mode);

/**
 * Implementation of 'split v|h|t|vertical|horizontal|toggle'.
 *
 */
void cmd_split(Match *current_match, CommandResultIR *cmd_output, const char *direction);

/**
 * Implementation of 'kill [window|client]'.
 *
 */
void cmd_kill(Match *current_match, CommandResultIR *cmd_output, const char *kill_mode_str);

/**
 * Implementation of 'exec [--no-startup-id] <command>'.
 *
 */
void cmd_exec(Match *current_match, CommandResultIR *cmd_output, const char *nosn, const char *command);

/**
 * Implementation of 'focus left|right|up|down'.
 *
 */
void cmd_focus_direction(Match *current_match, CommandResultIR *cmd_output, const char *direction);

/**
 * Implementation of 'focus next|prev sibling'
 *
 */
void cmd_focus_sibling(Match *current_match, CommandResultIR *cmd_output, const char *direction);

/**
 * Implementation of 'focus tiling|floating|mode_toggle'.
 *
 */
void cmd_focus_window_mode(Match *current_match, CommandResultIR *cmd_output, const char *window_mode);

/**
 * Implementation of 'focus parent|child'.
 *
 */
void cmd_focus_level(Match *current_match, CommandResultIR *cmd_output, const char *level);

/**
 * Implementation of 'focus'.
 *
 */
void cmd_focus(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'fullscreen [enable|disable|toggle] [global]'.
 *
 */
void cmd_fullscreen(Match *current_match, CommandResultIR *cmd_output, const char *action, const char *fullscreen_mode);

/**
 * Implementation of 'sticky enable|disable|toggle'.
 *
 */
void cmd_sticky(Match *current_match, CommandResultIR *cmd_output, const char *action);

/**
 * Implementation of 'move <direction> [<amount> [px|ppt]]'.
 *
 */
void cmd_move_direction(Match *current_match, CommandResultIR *cmd_output, const char *direction_str, long amount, const char *mode);

/**
 * Implementation of 'layout default|stacked|stacking|tabbed|splitv|splith'.
 *
 */
void cmd_layout(Match *current_match, CommandResultIR *cmd_output, const char *layout_str);

/**
 * Implementation of 'layout toggle [all|split]'.
 *
 */
void cmd_layout_toggle(Match *current_match, CommandResultIR *cmd_output, const char *toggle_mode);

/**
 * Implementation of 'exit'.
 *
 */
void cmd_exit(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'reload'.
 *
 */
void cmd_reload(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'restart'.
 *
 */
void cmd_restart(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'open'.
 *
 */
void cmd_open(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'focus output <output>'.
 *
 */
void cmd_focus_output(Match *current_match, CommandResultIR *cmd_output, const char *name);

/**
 * Implementation of 'move [window|container] [to] [absolute] position [<pos_x> [px|ppt] <pos_y> [px|ppt]]
 *
 */
void cmd_move_window_to_position(Match *current_match, CommandResultIR *cmd_output, long x, const char *mode_x, long y, const char *mode_y);

/**
 * Implementation of 'move [window|container] [to] [absolute] position center
 *
 */
void cmd_move_window_to_center(Match *current_match, CommandResultIR *cmd_output, const char *method);

/**
 * Implementation of 'move [window|container] [to] position mouse'
 *
 */
void cmd_move_window_to_mouse(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'move scratchpad'.
 *
 */
void cmd_move_scratchpad(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'scratchpad show'.
 *
 */
void cmd_scratchpad_show(Match *current_match, CommandResultIR *cmd_output);

/**
 * Implementation of 'swap [container] [with] id|con_id|mark <arg>'.
 *
 */
void cmd_swap(Match *current_match, CommandResultIR *cmd_output, const char *mode, const char *arg);

/**
 * Implementation of 'title_format <format>'
 *
 */
void cmd_title_format(Match *current_match, CommandResultIR *cmd_output, const char *format);

/**
 * Implementation of 'rename workspace <name> to <name>'
 *
 */
void cmd_rename_workspace(Match *current_match, CommandResultIR *cmd_output, const char *old_name, const char *new_name);

/**
 * Implementation of 'bar mode dock|hide|invisible|toggle [<bar_id>]'
 *
 */
void cmd_bar_mode(Match *current_match, CommandResultIR *cmd_output, const char *bar_mode, const char *bar_id);

/**
 * Implementation of 'bar hidden_state hide|show|toggle [<bar_id>]'
 *
 */
void cmd_bar_hidden_state(Match *current_match, CommandResultIR *cmd_output, const char *bar_hidden_state, const char *bar_id);

/**
 * Implementation of 'shmlog <size>|toggle|on|off'
 *
 */
void cmd_shmlog(Match *current_match, CommandResultIR *cmd_output, const char *argument);

/**
 * Implementation of 'debuglog toggle|on|off'
 *
 */
void cmd_debuglog(Match *current_match, CommandResultIR *cmd_output, const char *argument);

/**
 * Implementation of 'title_window_icon <yes|no>' and 'title_window_icon padding <px>'
 *
 */
void cmd_title_window_icon(Match *current_match, CommandResultIR *cmd_output, const char *enable, int padding);
