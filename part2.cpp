// Author: Andrew Jensen
// Assignment: Homework 1, Part 2
// 
#include <iostream>        // basic IO
#include <fstream>         // file IO
#include <sstream>         // Data Stream IO
#include <vector>          // vectors
#include "./MathStats.hpp" // HOMEWORK FUNCTIONS

// tire kicker
static void printStats(std::vector<float> *rm, std::vector<float> *medv)
{
    std::vector<float> range = std::vector<float>();
    // Test ROOM vector with all single vector input Statistic methods
    // SUM, MEAN, MEDIAN, RANGE
    std::cout << "RM vector " << std::endl;
    std::cout << "Sum: " << MathStats::Sum(*rm) << std::endl;
    std::cout << "Mean: " << MathStats::Mean(*rm) << std::endl;
    std::cout << "Median: " << MathStats::Median(*rm) << std::endl;
    range = MathStats::Range(*rm);
    std::cout << "Range:\n\rMax: " << range[0] << "\tMin: " << range[1] << std::endl;
    std::cout << "Difference: " << MathStats::Diff(*rm) << std::endl;
    std::cout << std::endl;

    // Test Median dwelling value vector with all single vector input Statistic methods
    // SUM, MEAN, MEDIAN, RANGE
    std::cout << "MEDV vector " << std::endl;
    std::cout << "Sum: " << MathStats::Sum(*medv) << std::endl;
    std::cout << "Mean: " << MathStats::Mean(*medv) << std::endl;
    std::cout << "Median: " << MathStats::Median(*medv) << std::endl;
    range = MathStats::Range(*medv);
    std::cout << "Range:\n\rMax: " << range[0] << "\tMin: " << range[1] << std::endl;
    std::cout << "Difference: " << MathStats::Diff(*medv) << std::endl;
    std::cout << std::endl;

    // Test covariance and correlation functions with both vectors
    std::cout << "Covariance: " << MathStats::Cov(*rm, *medv) << std::endl;
    std::cout << "Correlation: " << MathStats::Corr(*rm, *medv) << std::endl;
}

static void processCSV(std::fstream &infile, std::vector<float> *rm, std::vector<float> *medv)
{
    std::string line = "";        // holder for each line
    getline(infile, line);        // grab first line from file
    while (getline(infile, line)) // while there are still lines to grab
    {
        float f1, f2;                  // define a couple float variables
        int inputCounter = 0;          // set an input counter to count items in each row
        std::stringstream LS(line);    // put each line in a stream to getline again
        std::string word = "";         // word holder
        while (getline(LS, word, ',')) // for each item in a line
        {
            std::stringstream in(word); // turn said word into a stream for easy type conversion
            switch (inputCounter)       // depending on where the word is positioned. . .
            {
            case 1: // dump value in ROOM vector or . . .
            {
                in >> f1;
                rm->push_back(f1);
                break;
            }
            case 2: // dump value in MEDIAN VALUE vector
            {
                in >> f2;
                medv->push_back(f2);
                break;
            }
            default:
            {
                break;
            }
            }
            inputCounter++; // post-increment word counter
        }
    }
}

int main(int argc, const char **argv)
{
    std::fstream infile(argv[1], std::ios::in); // Open file, SEE MAKEFILE FOR USAGE

    std::vector<float> rm = std::vector<float>();   // Setup vector for room statistics
    std::vector<float> medv = std::vector<float>(); // Setup vector for room statistics

    processCSV(infile, &rm, &medv); // PART 1 load values into previously instantiated vectors
    printStats(&rm, &medv);         // PART 2+3 Print results, Kicks the wheels of the math functions in MathStats

    return 0; // we are done here
}