#include<stdio.h>
#include<iostream >
#include<conio.h>
#include<bits/stdc++.h>
struct trie {
    struct trie *edges[26];
}

// Initailizes memory for trie t
trie *initializeTrie(struct trie *t) {
    t=(trie *)malloc(sizeof(trie));
    for(int index=0;index<;26;index++)   {
        t->edges[index]=NULL;
    }
    return t;
}


// Adds a word to the existing trie
trie *addWord(struct trie *t,char *word)    {

    if(word[0]=='/0')   {

    }
    else    {
        int index=t[0]-'a';
        if(t->edges[index]==NULL)   {
            t->edges[index]=initializeTrie(t->edges[index]);
        }

        t->edges[index]=addWord(t->edges[index],++str);
    }
    return t;


}

// Checks whether the word's spelling is correct or not

bool spellChecker(trie *t,char *word)   {
    if(word[0]=='/0')
        return true;
    else    {
        int index=word[0]-'a';
        if(t->edges[index]!=NULL)   {
            spellChecker(t->edges[index],++word);
        }
        else
            return false;
    }
}

// Driver function to implement Spell Checker
int main()  {

    Trie *t=(trie *)malloc(sizeof(trie));
    // Suppose the dictionary consists of four words
    t=addWord(t,"Sibendu");
    t=addWord(t,"Hello");
    t=addWord(t,"Bhubaneswar");
    t=addWord(t,"India");
    bool check1=spellChecker(t,"Sibendu");  // Returns true
    bool check2=spellChecker(t,"Subendu");  // Returns false

}
