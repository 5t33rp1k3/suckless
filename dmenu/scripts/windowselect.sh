#!/bin/bash

# window listing and focusing dialog for dmenu

IFS=$'\n' read -r -d '' -a windowlist < <( (wmctrl -l | awk '{ for(i=4; i<=NF; i++) printf "%s",$i (i==NF?ORS:OFS) }' ) | cut -c -38 && printf '\0' )

if [ ${#windowlist[@]} -eq 0 ]; then
  menu=$(echo "No windows open" | dmenu -i )
else
  menu=$(printf '%s\n' "${windowlist[@]}" | dmenu -i )
  for i in "${!windowlist[@]}"; do
    if [ ! -z "$menu" ] && [[ "${windowlist[$i]}" = $menu ]]; then
      wmctrl -a "$menu"
    fi
  done
fi
