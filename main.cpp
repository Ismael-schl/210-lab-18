//Lab 18 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 3;

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
    void addReview(ifstream &fin) {
        for (int i = 0; i < SIZE; i++) {
            string tempString;
            int whole = rand() % 5+ 1;
            int tenths = rand() % 10;
            if (whole == 5) {
                tenths = 0;
            }
            double tempRating = whole + tenths / 10.0;
            getline(fin, tempString);
            Node *newReview = new Node;
            if (!head) {
                head = newReview;
                newReview->next = nullptr;
                newReview->rating = tempRating;
                newReview->comment = tempString;
            }
            else {
                newReview->next = head;
                newReview->comment = tempString;
                newReview->rating = tempRating;
                head = newReview;
            }
        }
    }
    void output(Movie* movie) {
        cout << "Movie Title: " << title << endl;
        for (int i = 0; i < SIZE; i++) {
            Node* current = head;
            cout << "    > Review #" << (i+1) << ": " << current->rating  << ": " << current->comment << endl;
            
        }
    }
    
};

int main() {
    srand(time(0);)
    vector<Movie> movies;


}
