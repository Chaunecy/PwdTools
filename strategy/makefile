CXXFLAGS = -std=c++11 -O3 -Wall
LDFLAGS = -std=c++11 -O3 -no-pie

TARGET = random_sample k_folder
all: $(TARGET)

random_sample: strategy/random_sample.cpp strategy/random_sample.h
	g++ strategy/random_sample.cpp $(CXXFLAGS) -o $@ -no-pie

k_folder: strategy/k_folder.cpp strategy/k_folder.h
	g++ strategy/k_folder.cpp $(CXXFLAGS) -o $@ -no-pie

# .PHONY: clean clean-o
# clean:
# 	rm -f random_sample k_folder
#
# clean-o:
# 	rm -f *.o
