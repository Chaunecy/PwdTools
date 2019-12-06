CXXFLAGS = -std=c++11 -O3 -Wall
LDFLAGS = -no-pie

TARGET = pwd_tool clean-o
all: $(TARGET)

%.o: tools/%.cpp
	g++ -Wall $(CXXFLAGS) -c $< -o $@

pwd_tool: ./main.cpp ./main.h LenCount.o
	g++ ./main.cpp -o $@ LenCount.o -O2 -no-pie

# -std=c++11 -I/usr/include/python2.7 -lpython2.7
.PHONY: clean clean-o
clean:
	rm -f pwd_tool

clean-o:
	rm -f *.o

