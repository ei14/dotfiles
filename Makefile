main:
	cp -r \
	~/.bg.gif \
	~/.cmd \
	~/.dwm \
	~/.suckless \
	~/.gtkrc-2.0 \
	~/.xinitrc \
	~/.vimrc \
	.
	cp -r \
	~/.vim/after \
	~/.vim/pack \
	./.vim
	cp -r \
	~/.config/chromium-flags.conf \
	~/.config/fish \
	~/.config/gtk-2.0 \
	~/.config/gtk-3.0 \
	~/.config/GIMP \
	./.config
	rm -rf ./usr/share/applications/*
	cp -r \
	/usr/share/applications/* \
	./usr/share/applications
	cp -r \
	/etc/X11/xorg.conf.d/* \
	./etc/X11/xorg.conf.d
	yay -Q > ./packages

# Also manually upload:
# .muttrc
# .mutt
