#!/bin/sh

img=~/ss/$(date +%s).png 
maim $img
xclip -sel c -t image/png -i $img

brightness=$(printf %.0f $(light))
if [[ $brightness -ge 10 ]]; then
	sudo light -U 10
	sleep 0.1
	sudo light -A 10
else
	sudo light -A 5
	sleep 0.1
	sudo light -U 5
fi
