#include <iostream>
using namespace std;

struct Film {
    char title[100];
    char director[100]; 
    char genre[100]; 
    double popularityRating;
};

void displayFilm(const Film& film) {
    cout << "Title: " << film.title << "\n";
    cout << "Director: " << film.director << "\n";
    cout << "Genre: " << film.genre << "\n";
    cout << "Popularity Rating: " << film.popularityRating << "\n\n";
}

bool searchByTitle(Film films[], int size, const char* title, Film& foundFilm) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(films[i].title, title) == 0) {
            foundFilm = films[i];
            return true;
        }
    }
    return false;
}

bool searchByDirector(Film films[], int size, const char* director, Film& foundFilm) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(films[i].director, director) == 0) {
            foundFilm = films[i];
            return true;
        }
    }
    return false;
}

bool mostPopularInGenre(Film films[], int size, const char* genre, Film& mostPopularFilm) {
    double maxRating = films[0].popularityRating;
    mostPopularFilm = films[0];

    for (int i = 1; i < size; ++i) {
        if (strcmp(films[i].genre, genre) == 0 && films[i].popularityRating > maxRating) {
            mostPopularFilm = films[i];
            maxRating = films[i].popularityRating;
        }
    }

    return maxRating > films[0].popularityRating;
}

int main() {
    const int size = 5;
    Film films[size] = {
        {"The Shawshank Redemption", "Frank Darabont", "Drama", 9.3},
        {"The Godfather", "Francis Ford Coppola", "Crime", 9.2},
        {"The Dark Knight", "Christopher Nolan", "Action", 9.0},
        {"Pulp Fiction", "Quentin Tarantino", "Crime", 8.9},
        {"Forrest Gump", "Robert Zemeckis", "Drama", 8.8}
    };

    char searchTitle[100];
    char searchDirector[100];
    char searchGenre[100];

    cout << "Enter the title of the film you want to search: ";
    gets_s(searchTitle, sizeof(searchTitle));

    cout << "Enter the director you want to search: ";
    gets_s(searchDirector, sizeof(searchDirector));

    cout << "Enter the genre you want to search: ";
    gets_s(searchGenre, sizeof(searchGenre));

    Film foundByTitle;
    if (searchByTitle(films, size, searchTitle, foundByTitle)) {
        cout << "Film found by title:\n";
        displayFilm(foundByTitle);
    }
    else {
        cout << "Film not found by title.\n";
    }

    Film foundByDirector;
    if (searchByDirector(films, size, searchDirector, foundByDirector)) {
        cout << "Film found by director:\n";
        displayFilm(foundByDirector);
    }
    else {
        cout << "Film not found by director.\n";
    }

    Film popularInGenre;
    if (mostPopularInGenre(films, size, searchGenre, popularInGenre)) {
        cout << "The most popular film in the genre " << searchGenre << ":\n";
        displayFilm(popularInGenre);
    }
    else {
        cout << "No films found in the genre " << searchGenre << ".\n";
    }

    return 0;
}
