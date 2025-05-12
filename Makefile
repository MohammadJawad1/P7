# Include directories
WORKING_DIR = ./

# Add each subfolder as include directories (prevents nasty relative imports!)
CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -O2 \

PROG ?= main

# Main program objects
MAIN_OBJS = main.o

# Submitted objects
SUBMITTED_OBJS = \
	$(WORKING_DIR)/PlayerBST.o

OBJS = $(MAIN_OBJS) $(SUBMITTED_OBJS)

mainprog: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(PROG) *.o *.out \
		$(WORKING_DIR)/*.o \

rebuild: clean mainprog