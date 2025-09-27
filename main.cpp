/*
 This program dsiplays a way that linked lists can be used and implemented.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
/**
 * @brief Searches for a given string value in a list of strings.
 *
 * This is a helper function that searches for a given string value
 * in a list of strings using the standard library find function.
 *
 * Interestingly, the standard list class does not have a find method.
 *
 * @param myList The list to search in.
 * @param value The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool find(const std::list<std::string> &myList, const std::string &value)
{
    bool found = (std::find(myList.begin(),
                            myList.end(),
                            value) != myList.end());
    return found;
}

/**
 * @brief Reads, updates, and writes a list of movies.
 *
 * This function reads in a list of movies from a file,
 * adds new movies to the list, removes movies from the list,
 * and outputs the updated list to a file.
 *
 * @return int The exit status of the program.
 */
int main()
{
    // Follow instructions in project assignment
    std::list<std::string> movies;
    std::ifstream infile;
    std::ofstream outfile;
    std::string temp, filename;

    std::cout << "Reading in BearFlix movie list..." << std::endl;

    // Attempt to read the file for mymovies.txt and return a failure if it fails.
    filename = "mymovies.txt";
    infile.open(filename);
    if (!infile) {
        std::cout << "File " << filename << " cannot be opened." << std::endl;
        return (EXIT_FAILURE);
    }

    std::cout << "Adding new movies..." << std::endl;

    // add movies to the list movies
    while (std::getline(infile, temp)) {
        // check if a movie is already in the list to stop from adding duplicates
        if (!find(movies, temp)) {
            movies.push_back(temp);
        }
        else {
            std::cout << "Movie " << temp << " cannot be added to the list." << std::endl;
        }
    }

    infile.close();
    
    // Attempt to read the file add_movies.txt and return a failure if it fails.
    filename = "add_movies.txt";
    infile.open(filename);
    if (!infile) {
        std::cout << "File " << filename << " cannot be opened." << std::endl;
        return (EXIT_FAILURE);
    }

    // add movies to the list
    while (std::getline(infile, temp)) {
        // check if a movie is already in the list to stop from adding duplicates
        if (!find(movies, temp)) {
            movies.push_back(temp);
        }
        else {
            std::cout << "Movie " << temp << " cannot be added to the list." << std::endl;
        }
    }
    
    infile.close();

    // Attempt to read the file del_movies.txt and return a failure if it fails.
    std::cout << "Removing movies..." << std::endl;
    filename = "del_movies.txt";
    infile.open(filename);
    if (!infile) {
        std::cout << "File " << filename << "cannot be opened." << std::endl;
        return (EXIT_FAILURE);
    }

    // remove movies from the list
    while (std::getline(infile, temp)) {
        // create a variable of the iterator to be used
        auto index = std::find(movies.begin(), movies.end(), temp);
        // if the iterator is not at the end it means that it found the value and can erase it
        if (index != movies.end()) {
            movies.erase(index);
        }
        else {
            // otherwise the iterator is at the end and it did not find the item that was trying to be removed.
            std::cout << "Movie " << temp << " cannot be removed from the list." << std::endl;
        }
    }

    infile.close();

    outfile.open("mymovies_updated.txt", std::ios::out);

    // iterate through movies adding a movie to the file and popping it off of the front of the list after it is added.
    while (!movies.empty()) {
        outfile << movies.front() << std::endl;
        movies.pop_front();
    }

    outfile.close();

    std::cout << "New movie list is ready!";

    return EXIT_SUCCESS;
}
