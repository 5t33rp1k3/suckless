# suckless

My personal dwm, st, dmenu and slock files. Please be aware that most of them have been heavily patched; adding further patches from the suckless site will likely fail due to line number differences. You'll also need a compositor running (e.g.: compton, xcompmgr) for transparency in dwm and st. Lastly, if you want status bar info as shown in the screenshots, then copy the simple status bar loop from my ~/.xinitrc (which can be found in my dots folder). The main differences between my files and stock are summarised below (all credit to the suckless team and patch authors; https://suckless.org/).

dwm: bar and border transparency; media keys can be used in config.h (e.g.: xf86xk_monbrightnessup/down for backlight control); customisable bar height in config.h; three tiling modes: vertical, horizontal, and grid; Xmonad-like tiling behaviour (thanks to the attachaside patch); no border when there's only one, fullscreen window (e.g.: when you're watching a movie; thanks to the noborder patch); floating windows can be configured to open in the centre of the screen.

st: transparency; scrollback with the mouse and keyboard.

dmenu: fonts and colours are defined in dmenu's config.h instead of dwm's config.h (functionally identical, but allows you to use a different colour scheme between dwm and dmenu if you want to).

slock: stock.

The colour scheme applied throughout is a higher contrast tweak of Nord (https://www.nordtheme.com/).
