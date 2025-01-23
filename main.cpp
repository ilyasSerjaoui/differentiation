#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class F{
    public:
        string fd;
        int flen;
        string arrf[1000];
        string x;
        string nx;
    public:
        friend void F_(F& f_);
};

string cpo(string arrf){
    int cpoint;
    string cpor;
    stringstream cpostream;
    cpostream << arrf;
    cpostream >> cpoint;
    arrf = to_string(cpoint - 1);

    return arrf;
}

string xkF1(int xkf_, string kf, int fac, string po, string ren, string mren){
    for(char ch : ren){
        if(isalpha(ch)){
            if(kf == "^"){
                if(fac){
                    
                }else{
                    ren = po+ren;
                }
                
            }
            kf = " ";
        }
    }
    return ren;
}

void F_(F& f_){
    f_.fd = "1+2x-6x^3+4x-x^2"; // WRITE HERE YOUR FORMULA
    f_.flen = f_.fd.length()-1;
    cout<<endl;
    cout<<"ƒ(x) = ";
    for(int j=0; j<=f_.flen; ++j){
        f_.arrf[j] = f_.fd[j];
        cout<<f_.arrf[j]<<" ";;
    }
    cout<<endl<<endl;
    for(int i=0; i<=f_.flen; ++i){

        if(f_.arrf[i-1]=="^"){
            if(cpo(f_.arrf[i])=="1" || cpo(f_.arrf[i])=="0"){
                f_.arrf[i] = "";
                f_.arrf[i-1] = f_.arrf[i];
            }else{
                f_.arrf[i] = cpo(f_.arrf[i]);
            }
        }else if(isdigit(f_.arrf[i][0]) && f_.arrf[i-1]!="^"){
            for(char ch : f_.arrf[i+1]){
                if(isalpha(ch) && !isdigit(f_.arrf[i-1][0])){
                    if(f_.arrf[i+2]=="^"){
                        int cpoint; int cpoint1;
                        string cpor; string cpor1; string s;
                        stringstream cpostream; stringstream cpostream1;
                        cpostream << f_.arrf[i+3];
                        cpostream >> cpoint;
                        cpostream1 << f_.arrf[i];
                        cpostream1 >> cpoint1;

                        f_.arrf[i] = to_string(cpoint * cpoint1);

                        f_.arrf[i+1] = f_.arrf[i+1];
                    }else{
                        f_.arrf[i+1] = "";
                        f_.arrf[i] = f_.arrf[i];
                    }
                }else{
                    f_.arrf[i] = "0";
                }
            }
        }
        f_.arrf[i] = xkF1(isdigit(f_.arrf[i][0]), f_.arrf[i+1], isdigit(f_.arrf[i-1][0]), f_.arrf[i+2], f_.arrf[i], f_.arrf[i-1]);

        
    }
    cout<<"==> ƒ'(x) = ";
    for(int i=0; i<=f_.flen; ++i){
        cout<<f_.arrf[i]<<" ";
    }
    cout<<endl;
}

int main(){
    F erb;
    F_(erb);
    
    return 0;
}
