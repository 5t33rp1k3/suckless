# suckless

My personal dwm, st, dmenu and slock files. Please be aware that most of them have been heavily patched; adding further patches from the suckless site will likely fail due to line number differences. You'll also need a compositor running (e.g.: compton, xcompmgr) for transparency in dwm and st. Lastly, if you want status bar info as shown in the screenshot, please see statusbar.sh (which can be found in my dots folder). The main differences between my files and stock are summarised below (all credit to the suckless team and patch authors; https://suckless.org/).

dwm: bar and border transparency; media keys can be used in config.h (e.g.: xf86xk_monbrightnessup/down for backlight control); customisable bar height in config.h; three tiling modes: vertical, horizontal, and grid; Xmonad-like tiling behaviour (thanks to the attachaside patch); no border when there's only one, fullscreen window (e.g.: when you're watching a movie; thanks to the noborder patch); floating windows can be configured to open in the centre of the screen; (some) EWMH compatibility for wmctrl -l/-a etc; altered status bar layout (single, centered active window name, etc.).

st: transparency; scrollback with both the mouse and keyboard.

dmenu: centered; bordered; fuzzy matching; width can be set in config.h; fonts and colours are defined in dmenu's config.h instead of dwm's config.h (functionally identical, but allows you to use a different colour scheme between dwm and dmenu if you want to). The scripts folder contains: a web/bookmark searcher, power menu, keyboard layout selector, screen recorder, and a rofi-like window searcher/focuser. Please note that some of these scripts need EWMH compatibility to work properly, as they involve wmctrl.

slock: stock.

The colour scheme applied throughout is a higher contrast tweak of Nord (https://www.nordtheme.com/). The wallpaper is from Edmund Leighton's 1900 painting God Speed.
