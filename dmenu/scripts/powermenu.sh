#!/bin/bash

# power menu dialog for dmenu

options=(lock suspend shutdown reboot)
commands=("slock" "systemctl suspend" "systemctl poweroff" "reboot")
confirmation=(no yes)

menu=$(printf '%s\n' "${options[@]}" | dmenu -p Power:)

for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "${options[$i]}" = $menu ]]; then
    submenu=$(printf '%s\n' "${confirmation[@]}" | dmenu -p $menu);
    if [ ! -z "$menu" ] && [[ "${submenu}" = "yes" ]]; then
      $(eval "${commands[i]}")
    fi
  fi
done
