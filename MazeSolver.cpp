#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Coordinate.h"
#include "MyStack.h"


#define X getX()
#define Y getY()

using namespace std;

void printMap(vector<string> map) {
    for (int i = 0; i != 10; ++ i) {
        cout << map[i] << endl;
    }
    cout << endl;
}

struct Offset {
    int x;
    int y;
};

Offset moves[4];

enum {
    East,
    West,
    North,
    South,
};

bool solve(Coordinate top, vector<string> map) {
    if (map[top.Y][top.X] == 'G') {
        map[top.Y][top.X] = '+';
        printMap(map);
        return true;
    }
    map[top.Y][top.X] = '+';
    for (int i = 0; i != 4; ++ i) {
        Coordinate next(moves[i].x + top.X, moves[i].y + top.Y);
        if (
            0 <= next.X
            and next.X < 10
            and 0 <= next.Y 
            and next.Y < 10
            and map[next.Y][next.X] != '#'
            and map[next.Y][next.X] != '+'
        ) {
            if (solve(next, map)) return true;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i != 4; ++ i) {
        int& target = i / 2 ? moves[i].y : moves[i].x;
        target = i % 2 ? -1: 1;
    }
    ifstream fin("input.txt");
    vector<string> map;
    string tmp;
    for (int i = 0; i != 10; ++ i) {
        fin >> tmp;
        map.push_back(tmp);
    }
    MyStack<Coordinate> stack;
    Coordinate begin(0, 0);
    stack.push(begin);
    solve(begin, map);
}
