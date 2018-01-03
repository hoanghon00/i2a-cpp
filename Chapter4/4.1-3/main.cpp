#include <iostream>
#include <vector>

using namespace std;

int find_max_subarray_brute_force(vector<int> a, int low, int high, int &max_left, int &max_right) {
	bool is_max_sum_valid = false;
	int max_sum;

	for (int i = low; i <= high; ++i) {
		int cur_sum = 0;
		for (int j = i; j <= high; ++j) {
			cur_sum += a[j];
			if ((is_max_sum_valid && cur_sum > max_sum) || (!is_max_sum_valid)) {
				is_max_sum_valid = true;
				max_left = i;
				max_right = j;
				max_sum = cur_sum;
				cout << "left: " << max_left << ", right: " << max_right << endl;
			}
		}
	}
	return max_sum;
}

int main(int argc, char const *argv[])
{
	std::vector<int>  v1{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	vector<int> a{1};
	int max_left, max_right, max_sum;
	max_sum = find_max_subarray_brute_force(v1, 0, v1.size() -1, max_left, max_right);

	cout << "Max sub array is " << max_sum << " with left idx: " << max_left << " and right idx: "
		<< max_right << endl;
	return 0;
}
