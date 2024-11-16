#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct digit{
    int val;
};

class myInt{

    private:
        vector<digit> vec;
        bool positive;
        bool neutr;
    public:
        myInt(){
            struct digit temp; temp.val = 0;
            vec.push_back(temp);
            neutr = true;
        }
        myInt(int number){
            int temp;
            struct digit a;
            while(number >= 10){
                temp = number % 10;
                a.val = temp;
                vec.push_back(a);
                number -= temp;
                number /= 10;
                cout << "damn" << endl;
            }
            a.val = number;
            vec.push_back(a);
            for(int i = vec.size() - 1; i >= 0;i--){
                cout << vec[i].val;
            }
            cout << endl;
        }
        myInt& operator+(myInt& obj){
            int result;
            bool carry_out;
            struct digit temp;
            for(int i = 0; i < vec.size(); i++){

                result = vec[i].val + obj.vec[i].val;
                if(carry_out) result++;
                carry_out = false;
                cout << result << endl;
                if(result >= 10){
                    carry_out = true;
                    result -= 10;
                }
                cout << result << endl;
                temp.val = result;
                vec[i] = temp;
            }
            if(carry_out){
                struct digit a;
                a.val = 1;
                vec.push_back(a);
                
            }
            for(int i = vec.size() - 1; i >= 0;i--){
                cout << vec[i].val;
            }
            return *this;
        }
        int getInt(){
            int number = 0;
            cout << endl;
            for(int i = 0; i < vec.size(); i++){
                number += vec[i].val * pow(10,i);
                cout << number<< endl;
            }
            cout << number;
        }





};

int main(){

    myInt a(669);
    myInt b;
    myInt c(755);
    b = a + c;
    b.getInt();
    return 0;
}