# compiler = clang++ # Use this on Mac
# debugger = lldb 	 # Use this on Mac
compiler = g++ # Use this on Linux
debugger = gdb # Use this on Linux
compiler-flags = -std=c++17 -g -Og -Wall -Wextra -pedantic
compiler-flags-sanitizer = $(compiler-flags) -fsanitize=address
output-file = main
output-file-sanitizer = $(output-file)-sanitizer
input-file = $(output-file).cpp
input-headers = binary_tree.hpp binary_tree.cc

all: $(output-file)

$(output-file): $(input-file) $(input-headers)
	$(compiler) $(compiler-flags) $(input-file) -o $(output-file)

clean:
	rm -f $(output-file)

run: $(output-file)
	./$(output-file)

$(debugger): $(output-file)
	$(debugger) $(output-file)

valgrind: $(output-file)
	valgrind ./$(output-file)

sanitizer: $(input-file) $(input-headers)
	$(compiler) $(compiler-flags-sanitizer) $(input-file) -o $(output-file-sanitizer)
	./$(output-file-sanitizer)
	rm -f $(output-file-sanitizer)

rules:
	@echo "Make Rules:"
	@echo "all		- Makes everything as necessary (default)"
	@echo "$(output-file)		- Makes output file as necessary"
	@echo "clean		- Cleans out files that can be generated"
	@echo "run		- Makes program as necessary, then runs it"
	@echo "$(debugger)		- Makes program as necessary, then runs it through $(debugger)"
	@echo "valgrind	- Makes program as necessary, then runs it through valgrind"
	@echo "sanitizer	- Makes program as necessary, then runs it through Address Sanitizer and cleans it up."