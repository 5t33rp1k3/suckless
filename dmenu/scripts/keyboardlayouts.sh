#!/bin/bash

# keyboard layout dialog for dmenu

options=(gb us)

menu=$(printf '%s\n' "${options[@]}" | dmenu -p Layout:)

for i in "${!options[@]}"; do
  if [ ! -z "$menu" ] && [[ "${options[$i]}" = "${menu}" ]]; then
    setxkbmap -layout "${options[i]}" 
  fi
done
