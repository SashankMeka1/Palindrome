#include <iostream>
#include <cstring>
using namespace std;
bool issame(char input[], int length, int left_index, int right_index){
    if (left_index < length){
        int front = isalnum(input[left_index])/8;//we dont actually remove the punctuation, we just skip the punctuation because it is not alphanumeric and check the next item in the cstring
        int back = isalnum(input[right_index])/8;//check if alphanumeric and divide by eight to normalize
        if(front + back == 2 and input[left_index] != input[right_index]){
            	return false;//if unequal return false
        }
	else{//close in on both sides checking if equal
		return issame(input, length, left_index + back, right_index - front);
	}
    }
    return true; 
}
int main(){
    char input[80];//grab input
    cin.get(input,80);
    bool palindrome = issame(input, strlen(input), 0, strlen(input)-1);
    if (palindrome){//use palindrome function to check
	cout << "It is a palindrome"<<endl;
    }
    else{
	cout << "It is not a palindrome"<<endl;
    }
    return 0;
}
