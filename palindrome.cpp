#include <iostream>
#include <cstring>
using namespace std;
bool issame(char input[], int length, int left_index, int right_index){
    if (left_index < length){
        int front = isalnum(input[left_index])/8;
        int back = isalnum(input[right_index])/8;//check if alphanumeric and divide by eight to normalize
	if (front + back == 2 and input[left_index] == input[right_index]){//if alpha numeric and equal go to next
            return issame(input, length, left_index + 1, right_index - 1);
        }
        else if (front + back == 0){//if not alpha numeric skip
            return issame(input, length, left_index + 1, right_index - 1);
        }
        else if (front + back == 1){//if one not alphanumeric skip that one only
            return issame(input, length, left_index + back, right_index - front);
        }
        else if(front + back == 2 and input[left_index] != input[right_index]){
            return false;//if unequal return false
        }
    }
    return true; 
}
int main(){
    char input[80];//grab input
    cin>>input;
    bool palindrome = issame(input, strlen(input), 0, strlen(input)-1);
    if (palindrome){//use palindrome function to check
	cout << "It is a palindrome"<<endl;
    }
    else{
	cout << "It is not a palindrome"<<endl;
    }
    return 0;
}
