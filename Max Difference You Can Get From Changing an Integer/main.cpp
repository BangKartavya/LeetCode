class Solution {
public:
    int maxDiff(int num) {
        string number = to_string(num);

        int freq[10] = {0};

        for(char& ch: number) freq[ch-'0']++;

        for(int i = 0;i<10;i++) {
            if(freq[i] == number.size()) {
                string result;
                for(int j = 0;j<freq[i];j++) {
                    result += '8';
                }

                return stoi(result);
            }
        }

        char maxi = 0;
        char mini = 0;
        bool pushOne = false;

        for(int i = 0;i<number.size();i++) {
            char ch = number[i];

            if(ch != '9' && maxi == 0) {
                maxi = ch;
                break;
            }
        }

        int i = 0;
        while(i < number.size() && (number[i] == '1' || number[i] == '0')) i++;

        if(i != 0) {
            mini = number[i];
            pushOne = false; 
        }
        else {
            mini = number[i];
            pushOne = true;
        }

        string a;
        string b;

        for(int i = 0;i<number.size();i++) {
            char ch = number[i];

            if(ch == maxi) {
                a.push_back('9');
            }
            else a.push_back(ch);

            if(ch == mini) {
                b.push_back(pushOne ? '1' : '0');
            }
            else {
                b.push_back(ch);
            }

        }
        
        return stoi(a) - stoi(b);
    }
};