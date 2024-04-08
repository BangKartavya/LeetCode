class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;
        int n = students.size();
        for(int i =0;i<n;i++) {
            q.push(students[i]);
            s.push(sandwiches[n-i-1]);
        }

        for(int i =0;i<n;i++) {
            int sz = q.size();
            bool keep_going = true;

            for(int j =0;j<sz && keep_going;j++) {
                int stu = q.front();
                q.pop();

                if(stu==s.top()) {
                    keep_going= false;
                    s.pop();
                    break;
                }
                else {
                    q.push(stu);
                }
            }
            if(q.size()==sz) return sz;
        }
        return 0;

    }
};