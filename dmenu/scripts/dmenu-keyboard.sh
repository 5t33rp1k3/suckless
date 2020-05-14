#!/bin/bash

# keyboard layout selection dialogue for dmenu

options=(gb us) # layout options
layouts=("setxkbmap -layout gb" "setxkbmap -layout us") # layout commands

menu=$(printf '%s\n' "${options[@]}" | dmenu -p Layout:)

if [ ! -z "$menu" ]; then
    for i in "${!options[@]}"; do
      if [[ "${options[$i]}" = "${menu}" ]]; then
        $(eval "${layouts[i]}");
      fi
    done
else
  exit
fi
