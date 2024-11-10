class Solution {
public:
    bool primeSubOperation(vector<int>& numbers) {
        int largestNumber = *max_element(numbers.begin(), numbers.end());

        vector<bool> primeSieve(largestNumber + 1, false);
        primeSieve[0] = primeSieve[1] = true;

        for (int i = 2; i * i <= largestNumber; ++i) {
            if (!primeSieve[i]) {
                for (int j = 2 * i; j <= largestNumber; j += i) {
                    primeSieve[j] = true;
                }
            }
        }

        vector<int> primeNumbers;
        for (int i = 2; i < primeSieve.size(); ++i) {
            if (!primeSieve[i]) {
                primeNumbers.push_back(i);
            }
        }

        int index = findMaxSubtraction(primeNumbers, 0, numbers[0]);
        if (index != -1) {
            numbers[0] -= primeNumbers[index];
        }

        for (int i = 1; i < numbers.size(); ++i) {
            index = findMaxSubtraction(primeNumbers, numbers[i - 1], numbers[i]);

            if (index == -1 && numbers[i] <= numbers[i - 1]) {
                return false;
            } else if (index != -1) {
                numbers[i] -= primeNumbers[index];
            }
        }

        return true;
    }

private:
    int findMaxSubtraction(const vector<int>& primes, int previousValue, int currentValue) {
        if (primes.empty()) {
            return -1;
        }

        int leftIndex = 0;
        int rightIndex = primes.size() - 1;

        while (leftIndex <= rightIndex) {
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

            if (currentValue - primes[midIndex] <= previousValue) {
                rightIndex = midIndex - 1;
            } else {
                if (midIndex == primes.size() - 1 || currentValue - primes[midIndex + 1] <= previousValue) {
                    return midIndex;
                } else {
                    leftIndex = midIndex + 1;
                }
            }
        }

        int midIndex = rightIndex;
        return (midIndex >= 0 && currentValue - primes[midIndex] <= previousValue) ? -1 : midIndex;
    }
};
