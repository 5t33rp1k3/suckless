/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#000000",   /* after initialization */
	[INPUT] =  "#222222",   /* during input */
	[FAILED] = "#aa4450",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;
