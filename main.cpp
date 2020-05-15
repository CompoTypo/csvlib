// Author: Andrew Jensen
// Assignment: Homework 1, Part 2
//
#include <iostream>        // basic IO
#include <fstream>         // file IO
#include <sstream>         // Data Stream IO
#include <vector>          // vectors
#include "./MathStats.hpp" // HOMEWORK FUNCTIONS
#include "./table.hpp"     // CSV PARSE TO TABLE


// tire kicker
static void printStats(table t)
{
    // Test ROOM vector with all single vector input Statistic methods
    // SUM, MEAN, MEDIAN, RANGE
    std::vector<std::string> *rm = t.getCol("rm");
    std::cout << "RM vector " << std::endl;
    std::cout << "Sum: " << Sum(rm) << std::endl;
    std::cout << "Mean: " << Mean(rm) << std::endl;
    std::cout << "Median: " << Median(rm) << std::endl;
    std::vector<double> range = Range(rm);
    std::cout << "Range:\n\rMin: " << range[0] << "\tMax: " << range[1] << std::endl;
    std::cout << "Difference: " << Diff(rm) << std::endl;
    std::cout << std::endl;

    // Test Median dwelling value vector with all single vector input Statistic methods
    // SUM, MEAN, MEDIAN, RANGE
    std::vector<std::string> *medv = t.getCol("medv");
    std::cout << "MEDV vector " << std::endl;
    std::cout << "Sum: " << Sum(medv) << std::endl;
    std::cout << "Mean: " << Mean(medv) << std::endl;
    std::cout << "Median: " << Median(medv) << std::endl;
    range = Range(medv);
    std::cout << "Range:\n\rMin: " << range[0] << "\tMax: " << range[1] << std::endl;
    std::cout << "Difference: " << Diff(medv) << std::endl;
    std::cout << std::endl;

    // Test covariance and correlation functions with both vectors
    std::cout << "Covariance: " << Cov(rm, medv) << std::endl;
    std::cout << "Correlation: " << Corr(rm, medv) << std::endl;
}

int main(int argc, const char **argv)
{
    std::fstream infile(argv[1], std::ios::in); // Open file, SEE MAKEFILE FOR USAGE
    // Setup vector for room statistics

    table t = table(infile, true); // PART 1 load values into previously instantiated vectors
    printStats(t);                                                                                      // PART 2+3 Print results, Kicks the wheels of the math functions in MathStats

    return 0; // we are done here
}