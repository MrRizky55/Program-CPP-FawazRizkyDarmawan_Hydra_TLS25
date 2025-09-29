/*
Welcome to trafficLight.cpp!
Pemorgraman ini berfungsi untuk mencari warna lampu merah saat detik ke n, dengan n adaalah nilai yang dimasukkan. 
Pemrograman ini dibuat berdasarkan soal “Obey Traffic Lights” untuk menjawab soal "Strange Traffic Light", TLS 2025.

made by Fawaz Rizky Darmawan (Hydra)
*/
#include <iostream>

using namespace std;

int main(){
    int hijau, kuning, merah, total, current, checker;
    hijau = 20;
    kuning = 3;
    merah = 80;
    total = hijau + kuning + merah;
    cout << "Masukkan detik ke n: ";
    cin >> current;
    current -= 44;
    checker = current % total;
    if (checker > 1 && checker <= kuning) cout << "Lampu berwarna kuning";
    else if (checker > kuning && checker <=(kuning + merah) ) cout << "Lampu berwarna merah";
    else cout << "Lampu berwarna hijau";

}