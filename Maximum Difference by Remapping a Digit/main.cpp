class Solution {
public:
    int minMaxDifference(int num) {
        string n = to_string(num);

        char toSwitchMaxi = 0;
        char toSwitchMini = 0;

        for(char& ch: n) {
            if(ch != '9' && toSwitchMaxi == 0) {
                toSwitchMaxi = ch;
                
            }
            if(ch != '0' && toSwitchMini == 0) {
                toSwitchMini = ch;
            }
        }

        if(toSwitchMaxi == 0) {
            return num;
        }

        string maxi;
        string mini;

        for(char& ch: n) {
            if(ch == toSwitchMaxi) {
                maxi.push_back('9');
            }
            else maxi.push_back(ch);

            if(ch == toSwitchMini) {
                mini.push_back('0');
            }
            else mini.push_back(ch);
        }
/*
        cout << "maxi : " << maxi << endl;
        cout << "mini : " << mini << endl;
*/
        return stoi(maxi) - stoi(mini);
    }

};