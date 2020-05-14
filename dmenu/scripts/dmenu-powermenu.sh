#!/bin/bash

# power menu dialogue for dmenu

options=(lock suspend shutdown reboot) # power menu options
confirmation=(no yes) # confirmation options

menu=$(printf '%s\n' "${options[@]}" | dmenu -p Power:)

if [ ! -z "$menu" ]; then
  if [ $menu = "lock" ]; then
    lkmn=$( ( printf '%s\n' "${confirmation[@]}" && echo ) | dmenu -p Lock? )
    if [ ! -z "$lkmn" ] && [ $lkmn = "yes" ]; then
      $(eval slock)
    else
      exit
    fi
  elif [ $menu = "suspend" ]; then
    ssmn=$( ( printf '%s\n' "${confirmation[@]}" && echo ) | dmenu -p Suspend? )
    if [ ! -z "$ssmn" ] && [ $ssmn = "yes" ]; then
      $(eval systemctl suspend)
    else
      exit
    fi
  elif [ $menu = "shutdown" ]; then
    sdmn=$( ( printf '%s\n' "${confirmation[@]}" && echo ) | dmenu -p Shutdown? )
    if [ ! -z "$sdmn" ] && [ $sdmn = "yes" ]; then
      $(eval systemctl poweroff)
    else
      exit
    fi
  elif [ $menu = "reboot" ]; then
    rbmn=$( ( printf '%s\n' "${confirmation[@]}" && echo ) | dmenu -p Reboot? )
    if [ ! -z "$rbmn" ] && [ $rbmn = "yes" ]; then
      $(eval reboot)
    else
      exit
    fi
  else
    exit
  fi
else
  exit
fi
