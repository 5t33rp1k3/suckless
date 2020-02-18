# suckless

My personal dwm, st, dmenu and slock files. Please be aware that most of them have been heavily patched; adding further patches from the suckless site will likely fail due to line number differences. You'll also need a compositor running (e.g.: compton, xcompmgr) for transparency in dwm and st. Lastly, if you want status bar info as shown in the screenshots, then copy the simple status bar loop from my ~/.xinitrc (which can be found in my dots folder). The main differences between my files and stock are summarised below (all credit to the suckless team and patch authors; https://suckless.org/).

dwm
Bar and border transparency
Media keys can be used in config.h (e.g.: xf86xk_monbrightnessup/down for backlight control)
Customisable bar height in config.h
Three tiling modes: vertical, horizontal, and grid
Xmonad-like tiling behaviour (thanks to the attachaside patch)
No border when there's only one, fullscreen window (e.g.: when you're watching a movie; thanks to the noborder patch)
Floating windows can be configured to open in the centre of the screen

st
Transparency
Scrollback with the mouse and keyboard

dmenu
Fonts and colours are defined in dmenu's config.h instead of dwm's config.h (functionally identical, but allows you to use a different colour scheme between dwm and dmenu if you want to)

slock
Stock. Maybe one day I'll work out how to get a lock screen with transparency, blur, and text on it

The colour scheme applied throughout is a higher contrast tweak of sourcerer by Xero Harrison (https://sourcerer.xero.nu/)
