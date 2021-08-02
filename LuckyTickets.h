#ifndef _LT_
#define _LT_

#include "ITask.h"
#include <iostream>

class LuckyTickets : public ITask
{
    long long int n;
    long long int q;

public:
    std::string Run(std::vector<std::string> &data)
    {
	n = std::stoll(data[0]);
	q = 0;

	Calculate(n);
	return std::to_string(q);
    }

private:
    void Calculate(int n)
    {
	std::vector<long long int> arr(10);
	for (auto i = 0; i < arr.size(); i++)
	    arr[i] = 1;

	for (auto i = 1; i < n; i++)
	    arr = get_next_arr(arr);

	for (auto i = 0; i < arr.size(); i++)
	    q += arr[i] * arr[i];
    }

    std::vector<long long int> get_next_arr(std::vector<long long int> &prev_arr)
    {
	auto new_size = prev_arr.size() + 9;
	std::vector<long long int> new_arr(new_size);

	for (auto i = 0; i < new_size; i++)
	{
	    int k = 0;
	    for (auto j = 0; j < 10; j++)
		if ((i - j >= 0) && (i - j <= (prev_arr.size() - 1)))
		    k += prev_arr[i - j];
	    
	    new_arr[i] = k;
	}

	return new_arr;
    }
};

#endif