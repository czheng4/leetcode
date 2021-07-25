SRC = $(wildcard c++/*)
BIN = $(patsubst c++/%.cpp, bin/%, $(SRC))
BIN_NUM = $(patsubst c++/%.cpp, %, $(SRC))
all: $(BIN)

$(BIN_NUM): %: c++/%.cpp
	g++ -o bin/$@ $<

$(BIN): bin/%: c++/%.cpp
	g++ -o $@ $<

clean:
	rm -rf bin/*