#include "game.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <ctime>

Game::Game(int w, int h)
    : board(w, h),
      snake(h / 2, w / 2, Direction::RIGHT),
      score("highscore.txt"),
      apple(nullptr), gold(nullptr),
      turn(0), eaten(0), goal(60), stop(false), pause(false), win(false), quit(false),
      rng((unsigned)std::time(nullptr)){
    newApple(AppleType::NORMAL);
}

Game::~Game(){
  delete apple;
 delete gold;
}

void Game::run(){
    draw();
    while (!stop){
        Key k = input.getKeyPress();
        if (k == Key::QUIT){
            quit = true;
            stop = true;
            break;
        }
        if (k == Key::PAUSE){
            pause = !pause;
            draw();
            std::this_thread::sleep_for(std::chrono::milliseconds(160));
            continue;
        }
        if (!pause){
            keyWork(k);
            step();
            draw();
        }
        else{
            std::this_thread::sleep_for(std::chrono::milliseconds(80));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(delay()));
    }
    endText();
}

void Game::keyWork(Key k){
    if (k == Key::UP) snake.changeDirection(Direction::UP);
    else if (k == Key::DOWN) snake.changeDirection(Direction::DOWN);
    else if (k == Key::LEFT) snake.changeDirection(Direction::LEFT);
    else if (k == Key::RIGHT) snake.changeDirection(Direction::RIGHT);
}

void Game::step(){
    snake.move();
    turn++;

    auto head = snake.getHeadPosition();
    int r = head.first;
    int c = head.second;

    if (!board.isInside(r, c) || snake.collidesWithSelf()){
        stop = true;
        win = false;
        return;
    }

    if (same(r, c, apple)){
        score.add(apple->getPoints(turn));
        snake.grow();
        delete apple;
        apple = nullptr;
        eaten++;
        newApple(AppleType::NORMAL);
        if (eaten % 4 == 0 && gold == nullptr) newApple(AppleType::GOLDEN);
    }

    if (same(r, c, gold)){
        score.add(gold->getPoints(turn));
        //snake.grow();
        delete gold;
        gold = nullptr;
    }

    if (gold != nullptr && gold->isExpired(turn)){
        delete gold;
        gold = nullptr;
    }
/*
    if (gold == nullptr && turn % 35 == 0){
        std::uniform_int_distribution<int> dis(0, 99);
        if (dis(rng) < 35) newApple(AppleType::GOLDEN);
    }
*/
    if (score.get() >= goal || snake.getLength() >= board.getWidth() * board.getHeight()){
        stop = true;
        win = true;
    }
}

void Game::draw() const{
    board.render(snake, apple, gold);
    std::cout << "Score: " << score.get()
              << "   Best: " << score.getBest()
              << "   Length: " << snake.getLength()
              << "   Turn: " << turn << "\n";
    std::cout << "Goal: " << goal << "   Move: arrow keys   Pause: P   Quit: Q\n";
    if (gold != nullptr){
        std::cout << "Golden apple value now: " << gold->getPoints(turn)
                  << "   disappear after: " << 30 - (turn - gold->getSpawnTurn()) << " turns\n";
    }
    if (pause) std::cout << "PAUSED\n";
}

void Game::newApple(AppleType type){
    std::vector<std::pair<int, int>> cells;
    for (int r = 0; r < board.getHeight(); r++){
        for (int c = 0; c < board.getWidth(); c++){
            if (freeCell(r, c)) cells.push_back({r, c});
        }
    }
    if (cells.empty()) return;

    std::uniform_int_distribution<int> dis(0, (int)cells.size() - 1);
    auto p = cells[dis(rng)];
    Apple* a = new Apple(p.first, p.second, type);
    a->setSpawnTurn(turn);

    if (type == AppleType::NORMAL){
        delete apple;
        apple = a;
    }
    else{
        delete gold;
        gold = a;
    }
}

bool Game::same(int r, int c, const Apple* a) const{
    return a != nullptr && a->getRow() == r && a->getCol() == c;
}

bool Game::freeCell(int r, int c) const{
    if (snake.containsPosition(r, c)) return false;
    if (same(r, c, apple)) return false;
    if (same(r, c, gold)) return false;
    return true;
}

int Game::delay() const{
    int d = 180; //- score.get() / 8 * 15;
    //if (d < 70) d = 70;
    return d;
}

void Game::endText(){
    bool newBest = score.saveBest();
    std::cout << "\n";
    if (quit) std::cout << "Quit game.\n";
    else if (win) std::cout << "You win.\n";
    else std::cout << "Game over.\n";
    std::cout << "Final score: " << score.get() << "\n";
    if (newBest) std::cout << "New best score saved.\n";
    else std::cout << "Best score: " << score.getBest() << "\n";
}
