CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJ = HW2main.o approximations.o pi_approx.o

all: HW2main

HW2main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

HW2main.o: HW2main.cpp approximations.h pi_approx.h
	$(CXX) $(CXXFLAGS) -c $<

approximations.o: approximations.cpp approximations.h
	$(CXX) $(CXXFLAGS) -c $<

pi_approx.o: pi_approx.cpp pi_approx.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o HW2main
