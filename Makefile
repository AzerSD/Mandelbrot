CFLAGS = -lm `sdl2-config --cflags --libs`

mandel: mandel.c
	$(CC) -o mandel mandel.c $(CFLAGS)
