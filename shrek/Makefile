
CC=gcc

shrek.c: template.c
	python init.py

shrek.s: shrek.c
	$(CC) -m32 -masm=intel -S $^

shrek.bin: shrek.s
	$(CC) -m32 -o $@ $^
	strip -w -N sig* -N key* -N start* $@

shrek: shrek.bin shrek.c
	python protect.py $^
	cp $< $@

clean: 
	rm -f shrek shrek.bin shrek.s shrek.c
