/* dmenu config header file */
/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

/* fonts */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"dejavu sans mono:size=12:antialias=true"
};

/* prompt */
static const char *prompt = ""; /* -p option; prompt to the left of input field */

/* general */
static int fuzzy               = 1;  /* -F option; if 0, dmenu doesn't use fuzzy matching */
static int topbar              = 1;  /* -b option; if 0, dmenu appears at bottom */
static unsigned int lineheight = 30; /* -h option; minimum height of a menu line */
static unsigned int lines      = 5;  /* -l option; if nonzero, dmenu uses vertical list with given number of lines */

/* colors */
static const char *colors[SchemeLast][2] = {
	               /* fground    bground */
	[SchemeNorm] = { "#dfe4ed", "#1b1f26" },
	[SchemeSel]  = { "#88c0d0", "#1b1f26" },
	[SchemeOut]  = { "#dfe4ed", "#1b1f26" },
};

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static const unsigned int border_width = 1;

static int min_width = 400;
