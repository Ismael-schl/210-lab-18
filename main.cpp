//Lab 18 | COMSC 210 | Ismael Hadi
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;

//This code outlines what every node in the list will hold and point to.
struct Node {
    double rating;
    string comment;
    Node *next = nullptr;
};

//Describes a class Movie that each have a title, and a linked list of ratings and comments on the movies.
class Movie {
    private: 
    string title;
    Node *head = nullptr;
    public:
    //constructor
    Movie(string t) {
        title = t;
    }
    //destructor
    ~Movie() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    //Copy constructor
    Movie(const Movie& source) {
        title = source.title;
        head = nullptr;
        Node* tail = nullptr;
        Node* cur = source.head;
        while(cur != nullptr) {
            Node* n = new Node;
            n->rating = cur->rating;
            n->comment = cur->comment;
            n->next = nullptr;
            if (head == nullptr) {
                head = n;
            }
            else {
                tail->next = n;
            }
            tail = n;
            cur = cur->next;
        }
    }
    //Copy assignment operator
    Movie& operator=(const Movie& source) {
        if (this == &source) {
            return *this;
        }

        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        
        title = source.title;

        Node *tail = nullptr;
        Node* cur = source.head;
        while (cur != nullptr) {
            Node* n = new Node;
            n->rating = cur->rating;
            n->comment = cur->comment;
            n->next = nullptr;
            if (head == nullptr) {
                head = n;
            }
            else {
                tail->next = n;
            }
            tail = n;
            cur = cur->next;
        }
        return *this;
    }
    //This function reads an input file and assigns a random rating to every inputted line of review. It places these values in a linked list.
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
    //This function outputs and averages every movie rating for each respective movie via a forloop and some output formatting.
    void output() {
        cout << "Movie Title: " << title << endl;
        double sum = 0.0;
        Node* current = head;
        for (int i = 0; i < SIZE; i++) {
            cout << "    > Review #" << (i+1) << ": " << current->rating  << ": " << current->comment << endl;
            sum += current->rating;
            current = current->next;
        }
        cout << "    > Average: " <<  sum/SIZE << endl << endl;
    }
};

//The main functiion initializes a container vector to hold movies, then accepts names for 4 movies.
//It uses the classes member functions to populate our information on the movies and output the ratings to 1 decimal place.
int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cerr << "Error: cannot open input file." << endl;
        return 1;
    }
    srand(time(0));
    cout << fixed << setprecision(1);
    vector<Movie> movies;
    Movie a("Interstellar");
    a.addReview(fin);
    movies.push_back(a);
    Movie b("Dune");
    b.addReview(fin);
     movies.push_back(b);
    Movie c("Jungle Book");
    c.addReview(fin);
     movies.push_back(c);
    Movie d("The Dark Knight");
    d.addReview(fin);
     movies.push_back(d);
    for (int i = 0; i < movies.size(); i++) {
        movies[i].output();
    }
    return 0;
}
