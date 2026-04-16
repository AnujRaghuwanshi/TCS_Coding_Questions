// String with a Twist
// Questions
// The program will recieve 3 English words inputs from STDIN

// These three words will be read one at a time, in three separate line
// The first word should be changed like all vowels should be replaced by %
// The second word should be changed like all consonants should be replaced by #
// The third word should be changed like all char should be converted to upper case
// Then concatenate the three words and print them
// Other than these concatenated word, no other characters/string should or message should be written to STDOUT

// For example if you print "how are you" then output should be h%wa#eYOU.

// You can assume that input of each word will not exceed more than 5 chars 

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1, str2, str3;
    cin>>str1>>str2>>str3;

    int n1 = str1.length();
    int n2 = str2.length();
    int n3 = str3.length();

    for(int i = 0; i < n1; i++){
        if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u'){
            str1[i] = '%';
        }
    }

    for(int i = 0; i < n2; i++){
        if(str2[i] != 'a' && str2[i] != 'e' && str2[i] != 'i' && str2[i] != 'o' && str2[i] != 'u'){
            str2[i] = '#';
        }
    }

    for(char &ch : str3){
        ch = toupper(ch);
    }

    cout<<str1+str2+str3;

    return 0;
}
