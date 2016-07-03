CC	= /opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j

all:	razorx.gb

%.o:	%.c
	$(CC) -c -o $@ $<

%.s:	%.c
	$(CC) -S -o $@ $<

%.o:	%.s
	$(CC) -c -o $@ $<

razorx.gb:	razorx.o 			game/gameplay.o game/map.o game/brush.o game/painter.o game/filter.o game/screen.o
	$(CC) -o razorx.gb razorx.o game/gameplay.o game/map.o game/brush.o game/painter.o game/filter.o game/screen.o  $<

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm
	rm -f game/*.o game/*.lst game/*.map *.gb *~ game/*.rel game/*.cdb game/*.ihx game/*.lnk game/*.sym game/*.asm

