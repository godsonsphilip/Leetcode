class Solution {
public:
    string bin(int n) {
        string s;
        while (n)
            s = char('0' + (n & 1)) + s, n >>= 1;
        return s.empty() ? "0" : s;
    }

    string convertDateToBinary(string date) {
        int n = date.length();
        string result = "", year = "", month = "", day = "";
        int count = 0;
        string temp = "";

        // Correct parsing logic
        for (int i = 0; i < n; i++) {
            if (date[i] == '-') {
                if (count == 0) year = temp;
                else if (count == 1) month = temp;
                temp = "";
                count++;
            } else {
                temp += date[i];
            }
        }
        day = temp; // Assign last part to day

        if (year.empty() || month.empty() || day.empty()) return "Invalid date";

        // Convert strings to integers
        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        // Convert to binary
        result = bin(y) + '-' + bin(m) + '-' + bin(d);
        return result;
    }
};
