#ifndef TABLE_HPP
#define TABLE_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//template <class T>
//static void stream(std::string in, T *out)
//{
//    std::stringstream val(in);
//    val >> *out;
//}

class table
{
private:
    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> data;
    /* data */
    void parseTable(std::fstream &infile)
    {
        std::string line;             // holder for each line
        getline(infile, line);        // grab first line from file
        while (getline(infile, line)) // while there are still lines to grab
        {
            std::string word;      // word holder
            std::stringstream LS(line); // put each line in a stream to getline again
            std::vector<std::string> linVec = std::vector<std::string>();
            while (getline(LS, word, ',')) // for each item in a line
                linVec.push_back(word);
            this->data.push_back(linVec);
        }
    }

    void parseHeaders(std::string head_line)
    {
        std::stringstream LS(head_line); // put each line in a stream to getline again
        std::string header = "";          // word holder
        while (getline(LS, header, ','))  // for each item in a line
        {
            header = header.substr(1, header.length() - 2);
            this->headers.push_back(header);
        }
    }

public:
    table(/* args */)
    {
        this->headers = std::vector<std::string>();
        this->data = std::vector<std::vector<std::string>>();
    }

    table(std::fstream &infile, bool headers = false)
    {
        if (headers)
        {
            std::string head_line;
            getline(infile, head_line);
            this->parseHeaders(head_line);
        }
        this->parseTable(infile);
    }
    ~table() {}

    std::vector<std::string> getRow(int rowNum) { return this->data.at(rowNum); }

    std::vector<std::string> *getCol(int colNum)
    {
        std::vector<std::string> *ret = new std::vector<std::string>();
        for (int i = 0; i < this->data.size(); i++)
            ret->push_back(this->data.at(i).at(colNum));
        return ret;
    }

    std::vector<std::string> *getCol(std::string colHeader)
    {
        std::vector<std::string> ret = std::vector<std::string>();
        for (int i = 0; i < this->headers.size(); i++)
            if (this->headers.at(i) == colHeader)
                return getCol(i);
        return NULL;
    }
};
#endif // !TABLE_HPP