#include <vector>

void merge_sort(std::vector<int>& vec);

void quick_sort(std::vector<int>& vec);

bool binary_search(std::vector<int>& vec, int k, bool is_inc = true);

std::pair<long long int, std::pair<int, int>> largest_sum_contiguous_subarray(std::vector<int>& vec);