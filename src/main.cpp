#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
    string word;
    string meaning;
    Node* left;
    Node* right;

    Node(string word, string meaning){
        this->word = word;
        this->meaning = meaning;
        left = NULL;
        right = NULL;
    }
};

class Dictionary{
    public:
    Node* root;

    Dictionary(){
        root = NULL;
    }

    bool isEmpty(){
        return root == NULL;
    }

    Node* insertW(Node* start, string word, string meaning){
        if(start != NULL){
            if(word < start->word){
                start->left = insertW(start->left, word, meaning);
            }
            else{
                start->right = insertW(start->right, word, meaning);
            }
        }
        else{
            start = new Node(word, meaning);
        }
        return start;
    }

    void insertW(string word, string meaning){
        root = insertW(root, word, meaning);
        cout << "->Word added into dictionary." << endl;
    }

    void inOrder(Node* root){
        if(root != NULL){
            inOrder(root->left);
            cout << root->word << " = " << root->meaning << endl;
            inOrder(root->right);
        }
    }

    Node* search1(Node* root, string word){
        if(root != NULL){
            if(root->word == word){
                cout << "means = " << root->meaning << endl;
                return root;
            }
            else if(word < root->word)
            search1(root->left, word);
            else
            search1(root->right, word);
        }
        else
            cout << "There is no word such that." << endl;
            return NULL;
    }

    Node* update(Node* root, string word, string newMeaning){
        if(root != NULL){
            if(root->word == word){
                root->meaning = newMeaning;
                cout << "->Word updated.." << endl;
                return root;
            }
            else if(word < root->word)
            update(root->left, word, newMeaning);
            else
            update(root->right, word, newMeaning);
        }
        else
            cout << "There is no word to be updated." << endl;
            return NULL;
    }

    int size1(Node* root){
        if(root == NULL){
            return 0;
        }
        else
            return size1(root->left) + 1 + size1(root->right);
    }

};

int main()
{
    Dictionary dic;
    while(1){
        int choice;
        cout << "\n MENU\n";
        cout << "1- Insert a word and it's meaning." << endl;
        cout << "2- Search for a word." << endl;
        cout << "3- List whole words." << endl;
        cout << "4- Update the meaning of a word." << endl;
        cout << "5- List how many words in the dictionary." << endl;
        cout << "0- EXIT" << endl;
        cout << "Choice: "; cin>>choice;
        cout << endl;

        switch(choice){
            case 0: return 0; break;
            case 1:{
                string word, meaning;
                cout << "Enter the word: "; cin>>word; cout << "Enter the meaning: "; cin>>meaning;
                dic.insertW(word, meaning); break;
            }
            case 3:{
                cout << "\n**Dictionary**\n";
                dic.inOrder(dic.root); break;
            }
            case 2:{
                string word;
                cout << "Type the word for searching: "; cin>>word;
                dic.search1(dic.root, word);
                break;
            }
            case 4:{
                string word, newMeaning;
                cout << "Enter the word to be updated: "; cin>>word; cout << "New meaning: "; cin>>newMeaning;
                dic.update(dic.root, word, newMeaning); break;
            }
            case 5:{
                cout << dic.size1(dic.root) << " words" << endl; break;
            }

        }
    }

    return 0;
}
