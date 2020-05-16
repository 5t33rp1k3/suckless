#!/bin/bash

# power menu dialog for dmenu

options=(Lock Suspend Shutdown Reboot)
commands=("slock" "systemctl suspend" "systemctl poweroff" "reboot")
confirmation=(No Yes)

menu=$(printf '%s\n' "${options[@]}" | dmenu -i -p "Power menu >")

for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "$menu" = "Lock" ]]; then
    $(eval slock) && exit
  elif [ ! -z "$menu" ] && [[ "${options[$i]}" = $menu ]]; then
    submenu=$(printf '%s\n' "${confirmation[@]}" | dmenu -i -p "$menu system?");
    if [ ! -z "$menu" ] && [[ "${submenu}" = "Yes" ]]; then
      $(eval "${commands[i]}")
    fi
  fi
done
