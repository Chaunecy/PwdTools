CXXFLAGS = -std=c++11 -O3 -Wall
LDFLAGS = -std=c++11 -O3 -no-pie

TARGET = random_sample k_folder clean-o
all: $(TARGET)

random_sample: ./random_sample.cpp ./random_sample.h
	g++ ./random_sample.cpp $(CXXFLAGS) -o $@ -no-pie

k_folder: ./k_folder.cpp ./k_folder.h
	g++ ./k_folder.cpp $(CXXFLAGS) -o $@ -no-pie

# -std=c++11 -I/usr/include/python2.7 -lpython2.7
.PHONY: clean clean-o
clean:
	rm -f strategy

clean-o:
	rm -f *.o
