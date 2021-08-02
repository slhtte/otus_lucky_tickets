#ifndef _TESTER_
#define _TESTER_

#include "LuckyTickets.h"
#include <ctime>
#include <fstream>
#include <iostream>


class Tester
{
private:
    ITask *task;
    std::string path;
    bool RunTest(std::ifstream &inFile, std::ifstream &outFile);

public:
    Tester(ITask *task, std::string path);
    void RunTests();
};

Tester::Tester(ITask *task, std::string path)
{
    this->task = task;
    this->path = path;
}

void Tester::RunTests()
{
    int nr = 0;

    while (true)
    {
        std::string inFile_path = this->path +  "test." + std::to_string(nr) + ".in";
        std::string outFile_path = this->path +  "test." + std::to_string(nr) + ".out";
        std::ifstream inFile(inFile_path);
        std::ifstream outFile(outFile_path);
        
        if (!inFile || !outFile)
        {
            break;
        }

        unsigned int start_time = std::clock();
        bool result = RunTest(inFile, outFile);
        unsigned int end_time = std::clock();
        std::cout << "Test #" + std::to_string(nr) + (result ? " true" : " false") << " " << "run time:" << end_time - start_time <<  std::endl;
        nr++;
    }
}

bool Tester::RunTest(std::ifstream &inFile, std::ifstream &outFile)
{
    try
    {
        std::vector<std::string> data;
        while (!inFile.eof())
        {
            std::string s;
            inFile >> s;
            data.push_back(s);
        }

        std::string expect;
        outFile >> expect;
        std::string actual = task->Run(data);
        return actual == expect;
    }
    catch(...)
    {
        std::cout << "Error!" << std::endl;
        return false;
    }
}

#endif