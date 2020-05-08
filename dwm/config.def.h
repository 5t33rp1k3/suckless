/* dwm config header file */
/* See LICENSE file for copyright and license details. */

/* fonts */
static const char *fonts[] = {
	"dejavu sans mono:size=12:antialias=true"
};

/* general */
static const float mfact           = 0.5;  /* factor of master area size [0.05..0.95] */
static const int barpadding        = 9;    /* status bar vertical padding, in pixels */
static const int nmaster           = 1;    /* number of clients in the master area */
static const int resizehints       = 0;    /* 1 means respect size hints in tiled resizals */
static const int showbar           = 1;    /* 0 means no bar, by default */
static const int topbar            = 1;    /* 0 means bar at the bottom of the screen */
static const unsigned int borderpx = 1;    /* window border width, in pixels */
static const unsigned int snap     = 16;   /* snap pixel, measured from screen edge */
static const unsigned int baralpha = 0xff; /* ff, 100%; f2, 95%; e6, 90%; d9, 85%; cc, 80% */
static const unsigned int borderalpha = OPAQUE;

/* colors */
static const char col_black[]  = "#20242c";
static const char col_gray[]   = "#3b4252";
static const char col_white[]  = "#dfe4ed";
static const char col_cyan[]   = "#88c0d0";
static const char *colors[][3] = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_white, col_black, col_gray },
	[SchemeSel]  = { col_cyan,  col_gray,  col_cyan  },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8" };

/* window rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered     isfloating   monitor */
	{ "st",       NULL,       NULL,       0,            1,             0,           -1 },
};

/* layouts */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },        /* first entry is default */
	{ "[B]",      bstack },      /* horizontal tiling */
	{ "[G]",      gaplessgrid }, /* grid layout */
	{ "[N]",      NULL },        /* no layout function means floating behavior */
	{ "[M]",      monocle },     /* full-screen layout */
};

/* key definitions */
#define MODKEY Mod4Mask /* Mod1Mask for Alt key, Mod4Mask for Win (Super) key */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* dmenu */
static char dmenumon[2]       = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };

/* commands */
static const char *backlightdec[] = { "xbacklight", "-dec", "5", NULL };
static const char *backlightinc[] = { "xbacklight", "-inc", "5", NULL };
static const char *filemanager[]  = { "thunar", NULL };
static const char *keyboarduk[]   = { "setxkbmap", "-layout", "gb", NULL };
static const char *keyboardus[]   = { "setxkbmap", "-layout", "us", NULL };
static const char *printscreen[]  = { "scrot", NULL };
static const char *screenlock[]   = { "slock", NULL };
static const char *shutdown[]     = { "systemctl", "poweroff", NULL };
static const char *terminal[]     = { "st", NULL };
static const char *texstudio[]    = { "texstudio", NULL };
static const char *volumedec[]    = { "amixer", "set", "Master", "5%-", NULL };
static const char *volumeinc[]    = { "amixer", "set", "Master", "5%+", NULL };
static const char *volumetog[]    = { "amixer", "set", "Master", "toggle", NULL };
static const char *webbrowser[]   = { "firefox", NULL };

/* key bindings */
static Key keys[] = {
	/* modifier                     key                       function    argument */
	{ 0,                            XF86XK_MonBrightnessDown, spawn,      {.v = backlightdec } },
	{ 0,                            XF86XK_MonBrightnessUp,   spawn,      {.v = backlightinc } },
	{ MODKEY,                       XK_d,                     spawn,      {.v = dmenucmd } },
	{ 0,                            XF86XK_Search,            spawn,      {.v = dmenucmd } },
	{ MODKEY,                       XK_f,                     spawn,      {.v = filemanager } },
	{ 0,                            XF86XK_Explorer,          spawn,      {.v = filemanager } },
	{ MODKEY,                       XK_bracketleft,           spawn,      {.v = keyboarduk } },
	{ MODKEY,                       XK_bracketright,          spawn,      {.v = keyboardus } },
	{ 0,                            XK_Print,                 spawn,      {.v = printscreen } },
	{ MODKEY,                       XK_p,                     spawn,      {.v = printscreen } },
	{ MODKEY,                       XK_q,                     spawn,      {.v = screenlock } },
	{ MODKEY|ControlMask|ShiftMask, XK_s,                     spawn,      {.v = shutdown } },
	{ MODKEY,                       XK_Return,                spawn,      {.v = terminal } },
	{ 0,                            XF86XK_LaunchA,           spawn,      {.v = terminal } },
	{ MODKEY,                       XK_t,                     spawn,      {.v = texstudio } },
	{ 0,                            XF86XK_AudioLowerVolume,  spawn,      {.v = volumedec } },
	{ MODKEY,                       XK_minus,                 spawn,      {.v = volumedec } },
	{ 0,                            XF86XK_AudioRaiseVolume,  spawn,      {.v = volumeinc } },
	{ MODKEY,                       XK_equal,                 spawn,      {.v = volumeinc } },
	{ 0,                            XF86XK_AudioMute,         spawn,      {.v = volumetog } },
	{ MODKEY|ShiftMask,             XK_minus,                 spawn,      {.v = volumetog } },
	{ MODKEY,                       XK_w,                     spawn,      {.v = webbrowser } },
	{ MODKEY,                       XK_b,                     togglebar,  {0} },
	{ MODKEY,                       XK_l,                     focusstack, {.i = +1 } },
	{ MODKEY,                       XK_h,                     focusstack, {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_l,                     movestack,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_h,                     movestack,  {.i = -1 } },
	{ MODKEY,                       XK_k,                     setmfact,   {.f = +0.025} },
	{ MODKEY,                       XK_j,                     setmfact,   {.f = -0.025} },
	{ MODKEY|ShiftMask,             XK_k,                     incnmaster, {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,                     incnmaster, {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return,                zoom,       {0} },
	{ MODKEY,                       XK_Tab,                   view,       {0} },
	{ MODKEY|ShiftMask,             XK_c,                     killclient, {0} },
	{ MODKEY,                       XK_y,                     setlayout,  {.v = &layouts[0]} },
	{ MODKEY,                       XK_u,                     setlayout,  {.v = &layouts[1]} },
	{ MODKEY,                       XK_i,                     setlayout,  {.v = &layouts[2]} },
	{ MODKEY,                       XK_n,                     setlayout,  {.v = &layouts[3]} },
	{ MODKEY,                       XK_m,                     setlayout,  {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,                 setlayout,  {0} },
	{ MODKEY,                       XK_0,                     view,       {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                     tag,        {.ui = ~0 } },
	{ MODKEY,                       XK_period,                focusmon,   {.i = +1 } },
	{ MODKEY,                       XK_comma,                 focusmon,   {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                tagmon,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                 tagmon,     {.i = -1 } },
	TAGKEYS(                        XK_1,                                 0)
	TAGKEYS(                        XK_2,                                 1)
	TAGKEYS(                        XK_3,                                 2)
	TAGKEYS(                        XK_4,                                 3)
	TAGKEYS(                        XK_5,                                 4)
	TAGKEYS(                        XK_6,                                 5)
	TAGKEYS(                        XK_7,                                 6)
	TAGKEYS(                        XK_8,                                 7)
	{ MODKEY|ControlMask|ShiftMask, XK_q,                     quit,       {0} },
};

/* mouse bindings */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
