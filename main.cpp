//Lab 18 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

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
            float tempRating = 
        }
    }
    void output(Node *head) {

    }
    
};

int main() {
    vector<Movie> movies;


}
