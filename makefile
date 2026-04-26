CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
OBJ = main.o game.o score.o apple.o board.o input.o snake.o

snake_game: $(OBJ)
	$(CXX) $(CXXFLAGS) -o snake_game $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o snake_game highscore.txt
