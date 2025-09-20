class Spreadsheet {
public:
    int getCell(string cell, int start, int end) {
        bool mode = true;
        int col = 0;
        if (cell[start] >= '0' && cell[start] <= '9') {
            mode = false;
        }
        if (mode) col = cell[start] - 'A';
        int row = 0;
        int i = mode ? start + 1: start;
        for(; i <= end; i++) {
            row = row*10 + (cell[i] - '0');
        }
        return mode ? sheet[row - 1][col] : row;
    }

    int sheet[1000]['Z' - 'A' + 1] = {0};

    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = 0;
        for(int i = 1; i < cell.length(); i++) {
            row = row*10 + (cell[i] - '0');
        }
        sheet[row - 1][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        int length = formula.length();
        int start = 1, end = 1;
        int val1, val2;
        for(int i = 1; i < length; i++)
        {
            if(formula[i] == '+') {
                val1 = getCell(formula, start, end);
                start = i + 1, end = i + 1;
            }
            end = i;
        }
        val2 = getCell(formula, start, end);
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */