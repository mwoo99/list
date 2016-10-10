xd: list.c
	gcc list.c -o xd

run: xd
	./xd

clean: 
	rm *~
