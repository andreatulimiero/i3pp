/*
 * vim:ts=4:sw=4:expandtab
 *
 * i3 - an improved dynamic tiling window manager
 * © 2009 Michael Stapelberg and contributors (see also: LICENSE)
 *
 * This header file includes all relevant files of i3 and the most often used
 * system header files. This reduces boilerplate (the amount of code duplicated
 * at the beginning of each source file) and is not significantly slower at
 * compile-time.
 *
 */
#pragma once

#include <config.hpp>

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <xcb/xcb.h>
#include <xcb/xcb_aux.h>
#include <xcb/xcb_icccm.h>
#include <xcb/xcb_keysyms.h>

#include "libi3.hpp"
#include "data.hpp"
#include "util.hpp"
#include "ipc.hpp"
#include "tree.hpp"
#include "log.hpp"
#include "xcb.hpp"
#include "manage.hpp"
#include "workspace.hpp"
#include "i3.hpp"
#include "x.hpp"
#include "click.hpp"
#include "key_press.hpp"
#include "floating.hpp"
#include "drag.hpp"
#include "configuration.hpp"
#include "handlers.hpp"
#include "randr.hpp"
#include "xinerama.hpp"
#include "con.hpp"
#include "load_layout.hpp"
#include "render.hpp"
#include "window.hpp"
#include "match.hpp"
#include "xcursor.hpp"
#include "resize.hpp"
#include "sighandler.hpp"
#include "move.hpp"
#include "output.hpp"
#include "ewmh.hpp"
#include "assignments.hpp"
#include "regex.hpp"
#include "startup.hpp"
#include "scratchpad.hpp"
#include "commands.hpp"
#include "commands_parser.hpp"
#include "bindings.hpp"
#include "config_directives.hpp"
#include "config_parser.hpp"
#include "fake_outputs.hpp"
#include "display_version.hpp"
#include "restore_layout.hpp"
#include "sync.hpp"
#include "main.hpp"
