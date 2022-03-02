#!/bin/sh
vol=$(amixer sget Master | sed -ne "6{s/.*Front Left: Playback \([^ ]*\).*/\1/;p}")
if [ $vol -le 2042 ]; then
	amixer sset Master 0
else
	amixer sset Master $(echo "0.833 * $vol / 1" | bc)
fi

sleep 0.1
killall slstatus; slstatus
