/*
Welcome to lostPasswordEncoder.cpp!
Pemorgraman ini berfungsi untuk mengubah suatu kata menjadi sebuah kode.
Pemrograman ini dibuat berdasarkan soal “The Lost Password” untuk menjawab soal "Lost and Found", TLS 2025.

made by Fawaz Rizky Darmawan (Hydra)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string input){
    string newString;
    for(int i=input.length()-1; i >= 0;i--) newString.push_back(input[i]);
    return newString;
}

int main(){
    string word;
    char toAscii;
    int asciiNum, middlePoint;
    string asciiToString;

    cout << "Masukkan kata: ";
    cin >> word;
    toAscii = word[0];
    asciiNum = toAscii;
    asciiToString = to_string(asciiNum);
    int i=0;
    // Removing vocal characters
    while (i < word.length()){
        if (word[i] == 'a' || word[i] == 'i' || word[i] == 'u' || word[i] == 'e' || word[i] == 'o' || word[i] == 'A' || word[i] == 'I' || word[i] == 'U' || word[i] == 'E' || word[i] == 'O'){
            word.erase(i,1);
            continue;
        }
        i++;
    }
    string code = reverse(word); //Reversing the word to make the code
    middlePoint = code.length()/2;
    code.insert(middlePoint, asciiToString); //Inserting the ASCII code in the middle of the code 
    cout << code;

    return 0;

}
