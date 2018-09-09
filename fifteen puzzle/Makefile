all: find generate fifteen

fifteen: fifteen.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o fifteen fifteen.c -lcs50 -lm

find: find.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o find find.c helpers.c -lcs50 -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core fifteen find generate log.txt
