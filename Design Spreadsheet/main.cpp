class Spreadsheet {
private:   
    unordered_map<char,vector<int>> rows;
public:
    Spreadsheet(int r) {
        for(char i = 'A'; i <= 'Z';i++) {
            rows[i].resize(r+1,0);
        }
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        int row = stoi(cell.substr(1,cell.size()-1));

        rows[col][row] = value;

    }
    
    void resetCell(string cell) {
        char col = cell[0];
        int row = stoi(cell.substr(1,cell.size()-1));

        rows[col][row] = 0;

    }
    
    int getValue(string formula) {
        string f = formula.substr(1,formula.size()-1);

        string a;
        string b;

        int i = 0;
        
        for(;i<f.size();i++) {
            if(f[i] == '+') break;
            a.push_back(f[i]);
        }
        
        i++;

        for(;i<f.size();i++) {
            b.push_back(f[i]);
        }

        int valA = 0;
        int valB = 0;

        if(a[0] >= 'A' && a[0] <= 'Z') {
            char col = a[0];
            int row = stoi(a.substr(1,a.size()-1));

            valA = rows[col][row];
        }

        else {
            valA = stoi(a);
        }

        if(b[0] >= 'A' && b[0] <= 'Z') {
            char col = b[0];
            int row = stoi(b.substr(1,b.size()-1));

            valB = rows[col][row];
        }

        else {
            valB = stoi(b);
        }

        return valA + valB;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */