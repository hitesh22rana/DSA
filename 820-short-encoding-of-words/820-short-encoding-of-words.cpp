class Node {
    public:
        Node* links[26];

        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }


        Node* get(char ch){
            return links[ch-'a'];
        }

        void put(char ch, Node* node){
            links[ch-'a']=node;
        }    
    
};


class Trie{
    private:
        Node* root; 
        bool newNodeAdded=false;
    public: 

        Trie(){
            root=new Node();
        }

        void insert(string word){
            Node* node=root;
            for(int i=word.size()-1;i>=0;i--){  // insert in backward direction
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
        }
     
        bool isPresent(string word){
            Node* node=root;
            for(int i=word.size()-1;i>=0;i--){
                if(!node->containsKey(word[i])) return false;
                else node=node->get(word[i]);
            }
            return true;
        }            
};


class Solution {
    private:
        static bool cmp(string &a,string &b){ 
            return a.size()>b.size();
        }
    public:
        int minimumLengthEncoding(vector <string>& words) {
            Trie trie;
            int cnt=0;

            sort(words.begin(),words.end(),cmp); // arrange in decreasing order of length

            for(auto x:words){
                if(trie.isPresent(x)==false){
                    trie.insert(x);
                    cnt+=x.size()+1;
                }

            }
           return cnt;
        }
};