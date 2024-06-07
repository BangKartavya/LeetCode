const int N=26;
struct Trie {
    Trie* next[N];
    bool isEnd=0;

    Trie() {
        fill(next, next+N, (Trie*)NULL);
    }

    ~Trie() {
    //    cout<<"Destructor\n";
        for (int i=0; i<N; ++i) {
            if (next[i] !=NULL) {
                delete next[i];
            }
        }
    }

    void insert(string& word) {
        Trie* Node=this;
        for(char c: word){
            int i=c-'a';
            if(Node->next[i]==NULL)
                Node->next[i]=new Trie();
            Node=Node->next[i];
        }
        Node->isEnd=1;
    }

    string findPrefix(string& word) {
        Trie* Node = this;
        string prefix;
        for (char c : word) {
            int i=c-'a';
            if (Node->next[i]==NULL) return word;  
            Node=Node->next[i];
            prefix+=c;
            if (Node->isEnd) return prefix;
        }
        return word;//Return the original word if no prefix is found
    }
};

class Solution {
public:
    static string replaceWords(vector<string>& dictionary, string& sentence) {
        Trie trie;
        for (string& word : dictionary) 
            trie.insert(word);

        // split the sentence & find ans
        string ans, word;
        for (char c : sentence){
            if (c!=' ') word+=c;
            else{
                ans+=trie.findPrefix(word);
                ans+=' ';
                word="";
            }
        }
        ans+=trie.findPrefix(word);

        return ans;
    }
};