/*
 * vim:ts=4:sw=4:expandtab
 *
 * i3bar - an xcb-based status- and ws-bar for i3
 * © 2010 Axel Wagner and contributors (see also: LICENSE)
 *
 * mode.c: Handle "mode" event and show current binding mode in the bar
 *
 */
#pragma once

#include <config.hpp>

#include <xcb/xproto.h>

#include "common.hpp"

/* Name of current binding mode and its render width */
struct mode {
    i3String *name;
    int name_width;
};

typedef struct mode mode;

/*
 * Start parsing the received JSON string
 *
 */
void parse_mode_json(char *json);
