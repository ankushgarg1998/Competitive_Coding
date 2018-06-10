#include<iostream>
#include<unordered_map>
using namespace std;

#define hashmap unordered_map<char, node*>

class node
    {
    public:
        char data;
        hashmap h;
        bool isTerminal;

        node(char d)
            {
            data = d;
            isTerminal = false;
            }
    };

class Trie
    {
    node* root;
    
    public:
        Trie()
            {
            root = new node('\0');
            }
        // Insertion
        void addWord(char* word)
            {
            node* temp = root;
            for(int i=0; word[i] != '\0'; i++)
                {
                char ch = word[i];
                if((temp->h).count(ch) == 0)
                    {
                    node* child = new node(ch);
                    temp->h[ch] = child;
                    temp = child;
                    }
                else
                    temp = temp->h[ch];
                }
            temp->isTerminal = true;
            }
        // Lookup
        bool search(char *word)
            {
            node* temp = root;
            for(int i=0; word[i] != '\0'; i++)
                {
                char ch = word[i];
                if((temp->h).count(ch))
                    temp = temp->h[ch];
                else
                    return false;
                }
            return temp->isTerminal;
            }
    };

int main()
    {
    char words[10][100] = {"apple", "ape", "code", "coding", "no"};

    Trie t;
    for(int i=0; i<5; i++)
        t.addWord(words[i]);

    char searchWord[100];
    cin.getline(searchWord, 100);

    if(t.search(searchWord))
        cout<<"Found";
    else
        cout<<"Not Found";
    return 0;
    }