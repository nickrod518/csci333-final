CPP = g++
CFLAGS = -Wall -Werror -Wextra

list: List.cpp
	$(CPP) $(CFLAGS) -o list List.cpp

clean:
	rm -f *~;
	rm -f list;
