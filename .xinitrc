export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
fcitx &

export QT_QPA_PLATFORMTHEME=qt5ct

feh --bg-scale /home/tk/.bg.gif
exec dwm
