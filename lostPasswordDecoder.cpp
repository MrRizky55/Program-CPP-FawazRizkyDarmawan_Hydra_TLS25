/*
Welcome to lostPasswordDecoder.cpp!
Pemorgraman ini berfungsi untuk mencari kemungkinan kata sandi yang didapatkan dari lostPasswordEncoder.cpp
Pemrograman ini dibuat berdasarkan soal “The Lost Password” untuk menjawab soal "Lost and Found", TLS 2025.

made by Fawaz Rizky Darmawan (Hydra)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<char> reverseVector(vector<char> input){
    vector<char> newVector;
    for (int i=input.size()-1; i >= 0; i--){
        newVector.push_back(input[i]);
    }
    return newVector;
}

int main(){
    string sandiAwal;
    char asciiDecode;
    int asciiCode=0;
    vector<char> hasil;

    cout << "Masukkan sandi: ";
    cin >> sandiAwal; //Inputting the code
    vector<char> sandi(sandiAwal.begin(), sandiAwal.end());
    vector<char> numbers;
    int x=0,y=0,z;
    bool assignedX = false; //to mark wether x has been assigned or not
    //Checking and getting the ASCII code number
    for (int i=0; i < sandi.size(); i++) {
        if (sandi[i] == '1' ||sandi[i] ==  '2' ||sandi[i] == '3' ||sandi[i] == '4' ||sandi[i] == '5' ||sandi[i] == '6' ||sandi[i] == '7' ||sandi[i] == '8' ||sandi[i] == '9' ||sandi[i] == '0'){
            numbers.push_back(sandi[i]);
            if (assignedX == false){
                x = i;
                assignedX = true;
            }
            y = i+1;
        }
    }

    if (y >= 1){ //Only run if there was any ASCII in the code. Adding the filter just in case
        //Converting mulptiple char to int
        for (int i=0; i < numbers.size(); i++){
            z = numbers[i] - '0';
            asciiCode += z*pow(10,(numbers.size()-i-1));
        } 

        asciiDecode = static_cast<char>(asciiCode); //Converting int to char
        //Checking wether the last letter matches the ASCII character or not 
        if (sandi[sandi.size()-1] != asciiDecode) {
            sandi.push_back(asciiDecode);
        }
        
        sandi.erase(sandi.begin() + x, sandi.begin() + y); //Removing ASCII code from the code
    } 
    hasil = reverseVector(sandi); //Reversing the vector
    for (int i=0; i < hasil.size(); i++) {
        cout << hasil[i];
    }

    return 0;

}
