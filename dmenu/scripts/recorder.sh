#!/bin/bash

# screen recording dialog for dmenu

ffmpeg="ffmpeg -video_size 1920x1080 -framerate 25 -f x11grab -draw_mouse 0 -i :0.0 -c:v libx264rgb -crf 0 -preset ultrafast /home/paul/recording.mkv"
search="ffmpeg\s-video_size\s1920x1080\s-framerate\s25\s-f\sx11grab\s-draw_mouse\s0\s-i\s:0\.0\s-c:v\slibx264rgb\s-crf\s0\s-preset\sultrafast\s/home/paul/recording\.mkv"
IFS=$'\n' read -r -d '' -a pids < <( (ps aux | grep -- $search ) | awk '{print $2;}' && printf '\0' )
pid="${pids[0]}"

if [ ! -z "$pid" ]; then
  menu=$(printf "Stop recording" | dmenu -i)
  if [ ! -z "$menu" ] && [[ $menu = "Stop recording" ]]; then
    eval kill $pid
  fi
else
  menu=$(printf "Start recording" | dmenu -i)
  if [ ! -z "$menu" ] && [[ $menu = "Start recording" ]]; then
    eval $ffmpeg
  fi
fi
