all: pair dselect

pair: pair.cpp sort.cpp
	clang++ -ggdb3 -O0 -std=c++11 -Wall -Wextra -o pair pair.cpp sort.cpp -lcrypt -lcs50 -lm

dselect:dselect.cpp sortutil.cpp
	clang++ -ggdb3 -O0 -std=c++11 -Wall -Wextra -o dselect dselect.cpp sortutil.cpp -lcrypt -lcs50 -lm

clean:
	rm -f *.o a.out	pair dselect