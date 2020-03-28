/**
 * Author: Andrew Jensen
 * MATHSTATS CLASS
 */
#ifndef MATHSTATS_HPP
#define MATHSTATS_HPP

#include <algorithm> // sorting alg
#include <vector>    // vector import
#include <cmath>     // sqrt function

class MathStats
{
private:
    // find standard deviation of a vector
    static float standDev(std::vector<float> inVec)
    {
        float sd = 0.0;           // standard deviation store point
        float mean = Mean(inVec); // grab the mean of the vector contents

        for (int i = 0; i < inVec.size(); i++)  // for every element in vector
            sd += std::pow(inVec[i] - mean, 2); // Delta squared then sum it
        return std::sqrt(sd / inVec.size());    // return sqrt of Delta^2 summed over #Elements
    }

public:
    // simple sum function
    static float Sum(std::vector<float> inVec)
    {
        double sum = 0.0;
        for (int i = 0; i < inVec.size(); i++) // for each element in vector
            sum += inVec[i];                   // add element value to sum
        return sum;                            // return sum
    }

    // simple average funtion
    static float Mean(std::vector<float> inVec)
    {
        return Sum(inVec) / inVec.size(); // average = mean = sum / #elements
    }

    // simple median graber
    static float Median(std::vector<float> inVec)
    {
        std::sort(inVec.begin(), inVec.end()); // sort vectors
        if (inVec.size() % 2 == 0)             // if even number of elements
            // return miidle value between two middle elements
            return (inVec[(inVec.size() / 2) + 1] + inVec[(inVec.size() / 2)]) / 2;
        return inVec[(inVec.size() / 2)]; // otherwise return middle element
    }

    static std::vector<float> Range(std::vector<float> inVec)
    {
        std::vector<float> range = std::vector<float>();
        std::sort(inVec.begin(), inVec.end()); // sort the vector
        range.push_back(inVec[0]); // set min
        range.push_back(inVec[inVec.size() - 1]); // set max
        return range; // return the range between max and min
    }

    // Return max - min
    static float Diff(std::vector<float> inVec)
    {
        std::vector<float> range = Range(inVec); // grab the range
        return range[range.size() - 1] - range[0]; // Return max - min
    }

    static float Cov(std::vector<float> inVecX, std::vector<float> inVecY)
    {
        float sum = 0.0;
        float xMean = Mean(inVecX); // grab mean values for both vectors
        float yMean = Mean(inVecY); // grab mean values for both vectors

        if (inVecX.size() == inVecY.size()) // if vectors are not the same size, exit
        {
            for (int i = 0; i < inVecX.size(); i++)                 // for each element in both vectors really
                sum += ((inVecX[i] - xMean) * (inVecY[i] - yMean)); // multiply deltas between the two vectors
            return sum / (inVecX.size() - 1);                             // return sum of all multiplied deltas divided by #elements per vector
        }
        else
        {
            std::cout << "ERR: two vectors of varying size entered" << std::endl;
            return -1;
        }
    }

    static float Corr(std::vector<float> inVecX, std::vector<float> inVecY)
    {
        // return covariance over the standard deviations of both vectors multiplied
        return Cov(inVecX, inVecY) / (standDev(inVecX) * standDev(inVecY));
    }
};
#endif // !1NMathStats_HPP
