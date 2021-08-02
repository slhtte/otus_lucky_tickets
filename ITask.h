#ifndef _ITASK_
#define _ITASK_

#include <string>
#include <vector>

class ITask
{
public:
    virtual std::string Run(std::vector<std::string> &data) = 0;
};

#endif