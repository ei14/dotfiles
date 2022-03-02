#!/bin/sh
vol=$(amixer sget Master | sed -ne "6{s/.*Front Left: Playback \([^ ]*\).*/\1/;p}")
if [ $vol == 0 ]; then
	amixer sset Master 2042
elif [ $vol -ge 54355 ]; then
	amixer sset Master 65536
else
	amixer sset Master $(echo "1.2001 * $vol / 1" | bc)
fi

sleep 0.1
killall slstatus; slstatus
