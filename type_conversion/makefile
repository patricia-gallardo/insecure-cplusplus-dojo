CXXFLAGS += -I.
CXXFLAGS += -std=c++17
CXXFLAGS += -Wall -Wextra

CFLAGS += -I.
CFLAGS += -std=c11
CFLAGS += -Wall -Wextra -Werror

# Turn off warning (which really should be on)
CFLAGS += -Wno-int-to-pointer-cast

HPP_FILES = $(wildcard *.hpp)
COMPILED_HPP_FILES = $(patsubst %.hpp,%.compiled_hpp,$(HPP_FILES))
CPP_FILES = $(wildcard *.cpp)
COMPILED_CPP_FILES = $(patsubst %.cpp,%.o,$(CPP_FILES)) /usr/lib/catch_main.o

H_FILES = $(wildcard *.h)
COMPILED_H_FILES = $(patsubst %.h,%.compiled_h,$(H_FILES))
C_FILES = $(wildcard *.c)
COMPILED_C_FILES = $(patsubst %.c,%.o,$(C_FILES))

.PHONY: test.output
test.output: test makefile
	@./$<

test: makefile $(COMPILED_CPP_FILES) $(COMPILED_C_FILES) $(COMPILED_HPP_FILES)
	@$(CXX) $(CXXFLAGS) -O $(COMPILED_CPP_FILES) $(COMPILED_C_FILES) -o $@

%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) -O $< -o $@

%.o: %.c
	@$(CC) -c $(CFLAGS) -O $< -o $@

# This rule ensures header files build in their own right.
# The quality of header files is important because header files
# are #included from other files and thus have a large span
# of influence (unlike .cpp files which are not #included)

%.compiled_hpp: %.hpp
	@$(CXX) -x c++ $(CXXFLAGS) -c -o $@ $<

%.compiled_h: %.h
	@$(C) -x c $(CFLAGS) -c -o $@ $<
