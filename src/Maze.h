#ifndef MAZE_H
#define MAZE_H
#include <iostream>
class Maze{
public:
void solve(){
}
//Recursive method to solve the maze
bool solve(int currR, int currC){
return false;
}
// print the current state of the maze
void printMaze()
{
}
//Determines if a location in the maze is empty
bool isEmpty(int r, int c){
return true;
}
private:
int startRow = 2;
int startCol = 0;
int endRow = 4;
int endCol = 12;
const char W = '#';
const char S = ' ';
static const int WIDTH = 13;
static const int HEIGHT = 14;
//Maze: char(219) is a wall, space is empty, . is the path
char maze[ HEIGHT ][ WIDTH ] =
{ {W, W, W, W, W, W, W, W, W, W, W, W},
{ W, S, S, S, W, S, S, S, S, S, S, W},
{ S, S, W, S, W, S, W, W, W, W, S, W},
{ W, W, W, S, W, S, S, S, S, W, S, W},
{ W, S, S, S, S, W, W, W, S, W, S, S},
{ W, W, W, W, S, W, S, W, S, W, S, W},
{ W, S, S, W, S, W, S, W, S, W, S, W},
{ W, W, S, W, S, W, S, W, S, W, S, W},
{ W, S, S, S, S, S, S, S, S, W, S, W},
{ W, W, W, W, W, W, S, W, W, W, S, W},
{ W, S, S, S, S, S, S, W, S, S, S, W},
{ W, W, W, W, W, W, W, W, W, W, W, W} };
};
#endif // MAZE_H
