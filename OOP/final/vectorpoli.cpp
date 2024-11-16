#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Poli{
    
    private:
        vector<int> coef;
        vector<int> power;
    public:
        Poli(){
            int Degree;
            int Coef;
            cout << "Please Enter Polynomials (Degree Coef): -1 to exit" << endl;
            while(Coef != -1){
                cout << "Please Enter Polynomials (Degree Coef): -1 to exit" << endl;
                cin >> Degree;
                if(Degree == -1) break;
                cin >> Coef;
                coef.push_back(Coef);
                power.push_back(Degree);
            }
            cout << "End" << endl;
        }
        int Evaluate(int x){
            int result = 0;
            for(int i = 0; i < coef.size(); i++){
                result +=  pow(x,power[i]) * coef[i];
            }
            cout << "Result is: " << result << endl;
        }
        Poli& operator+(Poli& other){
            bool flag = true;
            for(int i = 0; i < other.power.size(); i++){
                flag = true;
                for(int j = 0; j < this->power.size(); j++){
                    if(power[j] == other.power[i]){
                        coef[j] += other.coef[i];
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    this->coef.push_back(other.coef[i]);
                    this->power.push_back(other.power[i]);
                }
           }
           return *this;
        }


};

int main(){

    Poli pol;
    pol.Evaluate(5);
    Poli pol2;
    pol2.Evaluate(5);
    pol = pol + pol2;
    pol.Evaluate(5);



    return 0;
}
