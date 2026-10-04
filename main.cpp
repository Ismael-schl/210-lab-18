//Lab 18 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <string>

using namespace std;

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

    }
    void output(Node *head) {
        
    }
    
};