#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt range_begin, RandomIt range_end,
	const string& prefix) {

	if (prefix.empty() || range_begin == range_end)
	{
		return { range_begin, range_begin };
	}

	auto first = std::lower_bound(range_begin, range_end, prefix);
	
	string prefix2 = prefix;
	prefix2[prefix2.length() - 1] += 1;

	auto last = std::lower_bound(range_begin, range_end, prefix2);

	return std::make_pair(first, last);
}
