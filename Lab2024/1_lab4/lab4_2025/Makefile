DEPS= $(wildcard include/*.h)
SRC = $(wildcard src/*.cpp)

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

obj/%.o: src/%.cpp $(DEPS)
	@mkdir -p obj
	g++ -Wall -g -c $< -o $@

main: $(OBJ)
	g++ -Wall -g -o $@ $^

clean:
	rm -f *:Zone.Identifier include/*:Zone.Identifier src/*:Zone.Identifier obj/*.o *~ core

e: main
	valgrind --leak-check=full --show-leak-kinds=all ./main

.PHONY: clean