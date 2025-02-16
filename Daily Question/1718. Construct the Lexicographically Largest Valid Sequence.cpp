class Solution {
public:
    vector<int> constructDistancedSequence(int targetNumber) {
        vector<int> resultSequence(targetNumber * 2 - 1, 0);
        vector<bool> isNumberUsed(targetNumber + 1, false);
        findLexicographicallyLargestSequence(0, resultSequence, isNumberUsed, targetNumber);
        return resultSequence;
    }

private:
    bool findLexicographicallyLargestSequence(int currentIndex,
                                              vector<int>& resultSequence,
                                              vector<bool>& isNumberUsed,
                                              int targetNumber) {
        if (currentIndex == resultSequence.size()) {
            return true;
        }

        if (resultSequence[currentIndex] != 0) {
            return findLexicographicallyLargestSequence(
                currentIndex + 1, resultSequence, isNumberUsed, targetNumber);
        }

        for (int numberToPlace = targetNumber; numberToPlace >= 1; numberToPlace--) {
            if (isNumberUsed[numberToPlace]) continue;

            isNumberUsed[numberToPlace] = true;
            resultSequence[currentIndex] = numberToPlace;

            if (numberToPlace == 1) {
                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }
            }
            else if (currentIndex + numberToPlace < resultSequence.size() &&
                     resultSequence[currentIndex + numberToPlace] == 0) {
                resultSequence[currentIndex + numberToPlace] = numberToPlace;

                if (findLexicographicallyLargestSequence(
                        currentIndex + 1, resultSequence, isNumberUsed,
                        targetNumber)) {
                    return true;
                }

                resultSequence[currentIndex + numberToPlace] = 0;
            }

            resultSequence[currentIndex] = 0;
            isNumberUsed[numberToPlace] = false;
        }

        return false;
    }
};
