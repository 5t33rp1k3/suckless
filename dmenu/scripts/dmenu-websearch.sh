#!/bin/bash

# web search dialogue for dmenu

search=(duckduckgo bookmarks google youtube)
menu=$(printf '%s\n' "${search[@]}" | dmenu -p Search: )

if [ ! -z "$menu" ]; then
  if [ $menu = "duckduckgo" ]; then
    a=$( echo | dmenu -p $menu: )
    if [ ! -z "$a" ]; then
      firefox "https://duckduckgo.com/?q=${a}"
    else
      exit
    fi
  elif [ $menu = "bookmarks" ]; then
    ~/.dmenu/scripts/dmenu-bookmarks.sh
  else
    exit
  fi
  elif [ $menu = "google" ]; then
    b=$( echo | dmenu -p $menu: )
    if [ ! -z "$b" ]; then
      firefox "https://www.google.com/search?q=${b}"
    else
      exit
    fi
  elif [ $menu = "youtube" ]; then
    c=$( echo | dmenu -p $menu: )
    if [ ! -z "$c" ]; then
      firefox "https://www.youtube.com/results?search_menu=${c}"
    else
      exit
    fi
else
  exit
fi
