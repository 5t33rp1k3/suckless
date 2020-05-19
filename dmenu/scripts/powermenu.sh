#!/bin/bash

# power menu dialog for dmenu

options=(Lock Suspend Shutdown Reboot)
commands=("slock" "systemctl suspend" "systemctl poweroff" "reboot")


menu=$(printf '%s\n' "${options[@]}" | dmenu -i)

for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "$menu" = "Lock" ]]; then
    $(eval slock) && exit
  elif [ ! -z "$menu" ] && [[ "${options[$i]}" = $menu ]]; then
    confirmation=(Cancel "$menu")
    submenu=$(printf '%s\n' "${confirmation[@]}" | dmenu -i );
    if [ ! -z "$menu" ] && [[ "${submenu}" = "$menu" ]]; then
      $(eval "${commands[i]}")
    fi
  fi
done
