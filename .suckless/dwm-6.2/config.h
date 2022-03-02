#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 0;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "Terminus:weight=bold:pixelsize=16" };
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#ffffff", "#000000", "#000000" },
	[SchemeSel]  = { "#ffffff", "#555555", "#000000" },
	[SchemeHid]  = { "#aaaaaa", "#555555", "#000000" },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	//{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "W",      monocle },
	{ "E",      tile },    /* first entry is default */
	{ "R",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "/home/tk/.cmd/dmenu.sh", dmenumon, NULL };

static const char *termcmd[]  = { "st", NULL };
static const char *browsercmd[]  = { "chromium", NULL };

static const char *louder[]  = { "/home/tk/.cmd/louder.sh", NULL };
static const char *quieter[]  = { "/home/tk/.cmd/quieter.sh", NULL };
static const char *mute[]  = { "amixer", "sset", "Master", "0%", NULL };

static const char *brighter[]  = { "/home/tk/.cmd/brighter.sh", NULL };
static const char *darker[]  = { "/home/tk/.cmd/darker.sh", NULL };

static const char *warmer[]  = { "/home/tk/.cmd/warmer.sh", NULL };
static const char *colder[]  = { "/home/tk/.cmd/colder.sh", NULL };
static const char *resetColor[]  = { "/home/tk/.cmd/reset_color.sh", NULL };

static const char *screenshot[]  = { "/home/tk/.cmd/screenshot.sh", NULL };
static const char *screenshotRect[]  = { "/home/tk/.cmd/screenshot_rect.sh", NULL };

static const char *suspend[]  = { "systemctl", "suspend", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd} },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd} },
	{ MODKEY,                       XK_c,      spawn,          {.v = browsercmd} },

	{ 0,              XF86XK_AudioLowerVolume, spawn,          {.v = quieter} },
	{ 0,              XF86XK_AudioRaiseVolume, spawn,          {.v = louder} },
	{ 0,                     XF86XK_AudioMute, spawn,          {.v = mute} },

	{ 0,               XF86XK_MonBrightnessUp, spawn,          {.v = brighter} },
	{ 0,             XF86XK_MonBrightnessDown, spawn,          {.v = darker} },
	{ MODKEY,                       XK_Up,     spawn,          {.v = brighter} },
	{ MODKEY,                       XK_Down,   spawn,          {.v = darker} },

	{ MODKEY,                       XK_Left,   spawn,          {.v = warmer} },
	{ MODKEY,                       XK_Right,  spawn,          {.v = colder} },
	{ MODKEY|ShiftMask,             XK_Left,   spawn,          {.v = resetColor} },
	{ MODKEY|ShiftMask,             XK_Right,  spawn,          {.v = resetColor} },

	{ MODKEY,                       XK_s,      spawn,          {.v = screenshot} },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = screenshotRect} },

	{ MODKEY|ShiftMask,             XK_v,      spawn,          {.v = suspend} },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_l,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_h,      focusstackvis,  {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_l,      focusstackhid,  {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_h,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_m,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_j,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_k,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k,      tagmon,         {.i = +1 } },
//	{ MODKEY,                       XK_s,      show,           {0} },
//	{ MODKEY,                       XK_h,      hide,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

