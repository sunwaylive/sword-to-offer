#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char sentence[50000];
    while(cin.getline(sentence, 50000)){
        int len = strlen(sentence);
        reverse(sentence, sentence + len);

        int start = 0, end = 0;
        for(; end < len; end++){
            if(sentence[end] == ' '){
                reverse(sentence + start, sentence + end);
                start = end+1;
            }
        }
        //the last word in case
        reverse(sentence + start, sentence + end);
        printf("%s\n", sentence);
    }
    return 0;
}

// reduce mutiple space to one space
// #include <iostream>
// #include <fstream>
// #include <cstring>
// #include <sstream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     //ifstream in;
//     //in.open("input.txt");
//     //cin.rdbuf(in.rdbuf());
//     stringstream ss;
//     string sentence;
//     string word;
//     vector<string> words;
//     while(getline(cin, sentence)){
//         words.clear();
//         ss.clear();

//         ss<<sentence;
//         while(ss>>word)
//             words.push_back(word);
//         reverse(words.begin(), words.end());
//         int i;
//         for(i = 0; i < words.size(); ++i)
//             cout<<words[i]<<" ";
//         //cout<<words[i]<<endl;
//     }
//     //in.close();
//     return 0;
// }
