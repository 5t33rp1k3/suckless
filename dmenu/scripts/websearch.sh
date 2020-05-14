#!/bin/bash

# web search dialog for dmenu, with different search engines

engines=(duckduckgo arch_wiki google youtube wikipedia)
urls=(https://duckduckgo.com/?q= https://wiki.archlinux.org/index.php?search= https://www.google.com/search?q= https://www.youtube.com/results?search_menu= https://en.wikipedia.org/wiki/)

menu=$(printf '%s\n' "${engines[@]}" | dmenu -p search:)

for i in "${!engines[@]}"; do
  if [ ! -z "$menu" ] && [[ "${engines[$i]}" = $menu ]]; then
    submenu=$(echo | dmenu -p $menu);
    if [ ! -z "$submenu" ]; then
      firefox "${urls[i]}$submenu"
    fi
  fi
done
