/**
 * Author: Andrew Jensen
 * MATHSTATS CLASS
 */
#ifndef MATHSTATS_HPP
#define MATHSTATS_HPP

#include <algorithm> // sorting alg
#include <cmath>     // sqrt function
#include <iostream>
#include <sstream>
#include <vector> // vector import

// simple sum function
static double Sum(std::vector<std::string> *inVec)
{
    double ret, sum = 0.0;
    for (int i = 0; i < inVec->size(); i++) // for each element in vector
        sum += std::stod(inVec->at(i));
    return sum; // return sum
}

// simple average funtion
static double Mean(std::vector<std::string> *inVec)
{
    return Sum(inVec) / inVec->size(); // average = mean = sum / #elements
}

// find standard deviation of a vector
static double standDev(std::vector<std::string> *inVec)
{
    double temp, sd = 0.0;     // standard deviation store point
    double mean = Mean(inVec); // grab the mean of the vector contents

    for (int i = 0; i < inVec->size(); i++) // for every element in vector
    {
        temp = std::stod(inVec->at(i));
        sd += std::pow(temp - mean, 2); // Delta squared then sum it
    }
    return std::sqrt(sd / inVec->size()); // return sqrt of Delta^2 summed over #Elements
}

// simple median graber
static double Median(std::vector<std::string> *inVec)
{
    double temp;
    std::sort(inVec->begin(), inVec->end()); // sort vectors
    if (inVec->size() % 2 == 0)              // if even number of elements
    {                                        // return miidle value between two middle elements
        temp = std::stod(inVec->at((inVec->size() / 2) + 1) + inVec->at((inVec->size() / 2)));
        return temp / 2;
    }
    temp = std::stod(inVec->at((inVec->size() / 2)));
    return temp; // otherwise return middle element
}

static std::vector<double> Range(std::vector<std::string> *inVec)
{
    double temp;
    std::vector<double> tempVec = std::vector<double>();
    std::vector<double> range = std::vector<double>();
    for (int i = 0; i < inVec->size()-1; i++)
    {
        temp = std::stod(inVec->at(i));
        tempVec.push_back(temp);
    }
    std::sort(tempVec.begin(), tempVec.end());       // sort the vector
    range.push_back(tempVec[0]);                // set min
    range.push_back(tempVec[tempVec.size() - 1]); // set max
    return range;                                // return the range between max and min
}

// Return max - min
static double Diff(std::vector<std::string> *inVec)
{
    std::vector<double> range = Range(inVec);  // grab the range
    return range[range.size() - 1] - range[0]; // Return max - min
}

static double Cov(std::vector<std::string> *inVecX, std::vector<std::string> *inVecY)
{
    double tempX, tempY, sum = 0.0;
    double xMean = Mean(inVecX); // grab mean values for both vectors
    double yMean = Mean(inVecY); // grab mean values for both vectors

    if (inVecX->size() == inVecY->size()) // if vectors are not the same size, exit
    {
        for (int i = 0; i < inVecX->size(); i++) // for each element in both vectors really
        {
            tempX = std::stod(inVecX->at(i));
            tempY = std::stod(inVecX->at(i));
            sum += ((tempX - xMean) * (tempY - yMean)); // multiply deltas between the two vectors
        }
        return sum / (inVecX->size() - 1); // return sum of all multiplied deltas divided by #elements per vector
    }
    else
    {
        std::cout << "ERR: two vectors of varying size entered" << std::endl;
        return -1;
    }
}

static float Corr(std::vector<std::string> *inVecX, std::vector<std::string> *inVecY)
{
    // return covariance over the standard deviations of both vectors multiplied
    return Cov(inVecX, inVecY) / (standDev(inVecX) * standDev(inVecY));
}
#endif // !1NMathStats_HPP
