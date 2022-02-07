BIN:=prgrm
SRC := $(wildcard *.c)


.PHONY: all clean

all: $(BIN)

$(BIN): $(SRC)
	 $(CC) $^ -o $@

clean:
	$(RM) $(BIN)