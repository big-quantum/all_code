#include <iostream>
using namespace std;
int main() {
int arr[5];
int temp;
for(int i=0;i<5;i++){
cin >> arr[i];
}
temp = arr[1];
arr[1] = arr[3];
arr[3] = temp;
for (int i= 4; i>= 0; i--) {
cout<< arr[i];
}
}
