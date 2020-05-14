#!/bin/bash

# bookmark searching dialogue for dmenu

bookmark_list=$(tr '\t\n' ' ' < ~/.bookmarks)
IFS=' ' read -r -a bookmarks <<< "$bookmark_list"

declare -a bookmark_names=()
for (( x=0; x<${#bookmarks[@]}; x+=2 )); do
  bookmark_names+=("${bookmarks[x]}")
done

declare -a bookmark_urls=()
for (( y=1; y<${#bookmarks[@]}; y+=2 )); do
  bookmark_urls+=("${bookmarks[y]}")
done

menu=$(printf "%s\n" "${bookmark_names[@]}" | dmenu -p bookmarks:)

for i in "${!bookmark_names[@]}"; do
  if [ ! -z "$menu" ] && [[ "${bookmark_names[$i]}" = $menu ]]; then
    firefox "${bookmark_urls[i]}";
  fi
done
