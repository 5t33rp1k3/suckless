#!/bin/bash

# web and bookmark search dialog for dmenu, including different search engines

# bookmarks are read from a file ~/.bookmarks, and must be of the format:
# bookmark1_name bookmark1_url
# bookmark2_name bookmark2_url
# ...etc. Spaces/tabs can be used between names and urls

search=(Bookmarks DuckDuckGo Google YouTube Wikipedia)
urls=("" "https://duckduckgo.com/?q=" "https://www.google.com/search?q=" "https://www.youtube.com/results?search_query=" "https://en.wikipedia.org/wiki/")
homepages=("" "https://duckduckgo.com" "https://www.google.com" "https://www.youtube.co.uk" "https://en.wikipedia.org/wiki/Main_Page")

menu=$(printf '%s\n' "${search[@]}" | dmenu -i -p "Search >")

for i in "${!search[@]}"; do
  if [ ! -z "$menu" ] && [[ $menu = "Bookmarks" ]]; then

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
   
    menu=$(printf "%s\n" "${bookmark_names[@]}" | dmenu -i -p "Bookmarks >")
   
    for i in "${!bookmark_names[@]}"; do
      if [ ! -z "$menu" ] && [[ "${bookmark_names[$i]}" = $menu ]]; then
        firefox "${bookmark_urls[i]}";
      fi
    done

  elif [ ! -z "$menu" ] && [[ "${search[$i]}" = $menu ]]; then
    submenu=$(echo Homepage | dmenu -p "$menu >");

    if [ ! -z "$submenu" ] && [[ $submenu = "Homepage" ]]; then
      firefox "${homepages[i]}"
    elif [ ! -z "$submenu" ]; then
      firefox "${urls[i]}$submenu"
    fi

  fi
done
