# FISH CONFIGURATION

function fish_prompt
	if test $status = 0
		set_color white -b normal
	else
		set_color red -b normal
	end
	echo -n ""
	set_color brwhite -b normal
	echo -n " $USER "
	set_color black -b white
	echo -n "" (dirs) ""
	set_color white -b normal
	echo -n " "
	set_color normal -b normal
end

function fish_right_prompt
	date "+%I:%M"
end
function fish_greeting
end

# ENVIRONMENT VARIABLES

set -x EDITOR /bin/vim
set -x _JAVA_AWT_WM_NONREPARENTING 1
fish_add_path /home/tk/.local/share/gem/ruby/3.0.0/bin
fish_add_path /home/tk/.local/bin

# COMMAND ADJUSTMENTS

function pacman
	command pacman --color=auto $argv
end
function yay
	command yay --color=auto $argv
end
function ls
	command ls --color=auto $argv
end
function rm
	command rm -i $argv
end
function mv
	command mv -n $argv
end
function cp
	command cp -n $argv
end

function maxima
	rlwrap maxima
end

# ABBREVIATED COMMANDS

function la
	ls -a $argv
end

function x
	startx -- -ardelay 200 -arinterval 20
end
function off
	poweroff
end

function mutts
	mutt -f =INBOX/Sent
end

function zopen
	zathura $argv & disown
	exit
end

function listen
	mpv --no-video *
end
function shuffle
	mpv --no-video (ls | shuf)
end

function vds
	vdirsyncer sync
end

function web
	lftp -e "set ssl:verify-certificate false" upload@thomaskaldahl.com@ftp.thomaskaldahl.com:21
end

function srec
	ffmpeg  -video_size 1366x768 -r 30 -f x11grab -i :0.0  -f pulse -ac 2 -i alsa_output.pci-0000_00_1b.0.analog-stereo.monitor  -vcodec libx264 -preset fast  ~/ss/(date +%s).mkv
end
function arec
	ffmpeg  -f pulse -ac 2 -i alsa_output.pci-0000_00_1b.0.analog-stereo.monitor  ~/ss/(date +%s).ogg
end

# SYSTEM SETTINGS

function conserve
	sudo tlp auto
end
function perform
	sudo tlp ac
end

function hires
	xrandr -s 1366x768
end
function lores
	xrandr -s 800x450
end
function vlores
	xrandr -s 320x240
end

function woff
	sudo netctl stop-all
end
function wslow
	sudo netctl stop-all
	sudo netctl start wlp2s0-slowxfinity
end
function wslower
	sudo netctl stop-all
	sudo netctl start wlp2s0-slowerxfinity
end

# MISC COMMANDS

function shrec
	ffmpeg  -video_size 640x480 -r 30 -f x11grab -i :0.0  -f pulse -ac 2 -i alsa_output.pci-0000_00_1b.0.analog-stereo.monitor  -vcodec libx264 -preset ultrafast  ~/ss/sexyhiking/(date +%s).mkv
end
function sexyhiking
	fluidsynth -l -s -i -aalsa -o audio.alsa.device=default /usr/share/soundfonts/freepats-general-midi.sf2 & wine ~/.wine/drive_c/Program\ Files\ \(x86\)/sexyhiking.exe
end
