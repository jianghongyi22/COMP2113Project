CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OBJ = main.o game.o score.o apple.o board.o input.o snake.o file_output.o

snake_game: $(OBJ)
	$(CXX) $(CXXFLAGS) -o snake_game $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o snake_game highscore.txt

run: snake_game
	./snake_game

.PHONY: clean run