CXXFLAGS += -I.
CXXFLAGS += -std=c++1z
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wshadow
CXXFLAGS += -Wfloat-equal
CXXFLAGS += -O
CXXFLAGS += -Wsequence-point
CXXFLAGS += -Wmissing-noreturn
CXXFLAGS += -Wunreachable-code

# CXXFLAGS += -fprofile-arcs -ftest-coverage

CXXFLAGS += -fsanitize=leak,undefined
CXXFLAGS += -fno-sanitize-recover=all
CXXFLAGS += -fno-omit-frame-pointer

CXXFLAGS += -Wno-implicit-fallthrough

HPP_FILES = $(wildcard *.hpp)
COMPILED_HPP_FILES = $(patsubst %.hpp,%.compiled_hpp,$(HPP_FILES))
CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(patsubst %.cpp,%.o,$(CPP_FILES)) /usr/lib/catch_main.o

%.o: %.cpp
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: test.output
test.output: test makefile
	@./$<

test: makefile $(OBJ_FILES) $(COMPILED_HPP_FILES)
	@$(CXX) $(CXXFLAGS) -O $(OBJ_FILES) -o $@

# This rule ensures header files build in their own right.
# The quality of header files is important because header files
# are #included from other files and thus have a large span
# of influence (unlike .cpp files which are not #included)

%.compiled_hpp: %.hpp
	@$(CXX) -x c++ $(CXXFLAGS) -c -o $@ $<
