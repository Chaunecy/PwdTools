CXXFLAGS = -std=c++11 -O3 -Wall -no-pie

TARGET = len_count
all: $(TARGET)

len_count: tools_cpp/LenCount.cpp tools_cpp/LenCount.h
	g++ tools_cpp/LenCount.cpp -o $@ $(CXXFLAGS)

# .PHONY: clean clean-o
# clean:
# 	rm -f len_count
#
# clean-o:
# 	rm -f *.o

