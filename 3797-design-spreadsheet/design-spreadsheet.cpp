class Spreadsheet {
public:
    Spreadsheet(int rows) {
        // No need to store rows since we use sparse representation
    }

    void setCell(string cell, int value) {
        sheet[cell] = value;
    }

    void resetCell(string cell) {
        sheet[cell] = 0;
    }

    int getValue(string formula) {
        int plusPos = formula.find('+');
        string left = formula.substr(1, plusPos - 1);
        string right = formula.substr(plusPos + 1);

        return getToken(left) + getToken(right);
    }

private:
    unordered_map<string, int> sheet;

    int getToken(const string& token) {
        if (isdigit(token[0])) return stoi(token);
        return sheet.count(token) ? sheet[token] : 0;
    }
};
