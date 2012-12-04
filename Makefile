CPP = g++
CFLAGS = -Wall -Werror -Wextra

make: clean list words

list: List.cpp
	$(CPP) $(CFLAGS) -o list List.cpp

words: Words.cpp
	$(CPP) $(CFLAGS) -o words Words.cpp

clean:
	rm -f *~;
	rm -f list;
	rm -f words;
	rm -f test;
