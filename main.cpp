//Lab 18 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 4;

//This code outlines what every node in the list will hold and point to.
struct Node {
    double rating;
    string comment;
    Node *next = nullptr;
};

class Movie {
    private: 
    string title;
    Node *head = nullptr;
    public:
    void addReview(Node *head) {
        ifstream fin("input.txt");
        if (!fin) {
            cerr << "Error: cannot open input file." << endl;
        }
        for (int i = 0; i < SIZE; i++) {
            int whole = rand() % 5+ 1;
            int tenths = rand() % 10;
            if (whole == 5) {
                tenths = 0;
            }
            double tempRating = whole + tenths / 10.0
            
        }
    }
    void output(Node *head) {

    }
    
};

int main() {
    srand(time(0);)
    vector<Movie> movies;


}
