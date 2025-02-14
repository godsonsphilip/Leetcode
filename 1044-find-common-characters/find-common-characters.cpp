
class Solution {
public:
    vector<int> findCommonMinimumFrequency(vector<vector<int>>& frequencyVectors) {
        if (frequencyVectors.empty()) {
            return {}; // Return an empty vector if there are no frequency vectors
        }

        vector<int> commonMinFrequency(26, 0); // Initialize with zeros

        // Iterate through each character (a-z)
        for (int i = 0; i < 26; ++i) {
            if (frequencyVectors[0][i] == 0) {
                continue; // Skip if the key has a value of 0 in the first frequency vector
            }

            int minFreq = frequencyVectors[0][i]; // Start with the frequency from the first vector
            bool isCommon = true;

            // Compare with other frequency vectors
            for (size_t j = 1; j < frequencyVectors.size(); ++j) {
                if (frequencyVectors[j][i] == 0) {
                    isCommon = false; // If any vector doesn't have this character, it's not common
                    break;
                }
                minFreq = min(minFreq, frequencyVectors[j][i]); // Update minFreq to the minimum value
            }

            if (isCommon) {
                commonMinFrequency[i] = minFreq; // Store the minimum frequency for this character
            }

            // Set the value of the current key to zero in the first frequency vector
            frequencyVectors[0][i] = 0;
        }

        return commonMinFrequency;
    }

    vector<string> commonChars(vector<string>& words) {
        vector<string> result;

        // Create frequency vectors for all words
        vector<vector<int>> frequencyVectors;
        for (const auto& str : words) {
            vector<int> freqArray(26, 0); // Initialize a frequency array of size 26 with zeros
            for (char ch : str) {
                if (ch >= 'a' && ch <= 'z') { // Ensure the character is a lowercase letter
                    freqArray[ch - 'a']++; // Increment the corresponding index in the frequency array
                }
            }
            frequencyVectors.push_back(freqArray);
        }

        // Find the common minimum frequency vector
        vector<int> commonMinFrequency = findCommonMinimumFrequency(frequencyVectors);

        // Add characters to the result vector based on their minimum frequency
        for (int i = 0; i < 26; ++i) {
            if (commonMinFrequency[i] > 0) {
                char ch = 'a' + i; // Convert index to corresponding character
                string s(1, ch);   // Create a string from the character
                for (int j = 0; j < commonMinFrequency[i]; ++j) {
                    result.push_back(s); // Add the character to the result vector
                }
            }
        }

        return result;
    }
};

