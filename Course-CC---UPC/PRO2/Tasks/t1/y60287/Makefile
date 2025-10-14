CXX := g++
CXXFLAGS := -std=c++17 -g3 -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-ignored-reference-qualifiers

program: main.o vstack.o html_elem.o
	$(CXX) $(CXXFLAGS) -o program $^

main.o: main.cc vstack.hh html_elem.hh
%.o: %.cc %.hh

clean:
	rm -f program *.o

.PHONY: clean   