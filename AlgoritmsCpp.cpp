#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct Point {
    int x;
    int y;
};
int main()
{
    vector<Point> punkty;
    ifstream plik("points.txt");
    string line;
    while (getline(plik, line)) {
        istringstream iss(line);
        Point punkt;
        if (iss >> punkt.x >> punkt.y) {
            punkty.push_back(punkt);
        }
    }
    plik.close();
    const int widthx = 20;
    const int heighty = 10;
    vector<vector<char>>  siatka(heighty, vector<char>(widthx, '.'));
    for (const Point& punkt : punkty) {
        int x = punkt.x;
        int y = punkt.y;
        if (x >= 0 && x < widthx && y >= 0 && y < heighty) {
            siatka[y][x] = 'x';
        }
    }
    ofstream wyjscie("kart.txt");
    for (int i = 0; i < heighty; i++) {
        for (int j = 0; j < widthx; j++) {
            wyjscie << siatka[i][j];
        }
        wyjscie << endl;
    }
    wyjscie.close();
    return 0;
}

