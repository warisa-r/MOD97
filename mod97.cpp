#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool check_length(string x){
    bool stat = false;
    if (x[0]== 'D' && x[1] == 'E'){ //Only check for IBAN in DE
        if(x.length()== 22)
        {
            stat = true;
        }
    }
    else if (x[0]== 'B' && x[1] == 'E'){ //Only check for IBAN in DE
        if(x.length()== 16)
        {
            stat = true;
        }
    }
    else if (x[0]== 'A' && x[1] == 'T'){ //Only check for IBAN in DE
        if(x.length()== 20)
        {
            stat = true;
        }
    }
    return stat;
}

string move (int g, string y){
    
    int n = y.length();
    char temp[n];
    for (int i = 0; i < n; i++){
        temp[i]=y[i];
    }
    for (int j = g; j < n; j++){
        y[j-g] = temp[j];
    }
    for (int a = n-g; a < n; a++){
        y[a] = temp[a-n+g];
    }

    return y;
    cout << y << endl;
}

string replace (string c){
    int l = c.length();
    for (int z = 0; z < l; z++){
        if(int(c[z]-48 > 9)){ //check if it's a letter or not
            int rep = int(c[z]) - 55;
            stringstream strs;
            strs << rep;
            string temp_str = strs.str();
            char* rep_char = (char*) temp_str.c_str(); //thx stackoverflow
            c.erase(c.begin() + z);
            c.insert(z,rep_char);
        }
    }

    return c;
}

bool mod97 (string m){
    bool check = false;
    long long remainder = 0; 
    for (int i = 0; m[i] != '\0'; ++i){ //thank god modulo is distributive
    remainder = (remainder * 10 + m[i] - '0') % 97; //im crying it works
    }
    if(remainder == 1){
        check = true;
    }
    return check;
}

int main(){
    string IBAN;
    cin >> IBAN;
    if (check_length(IBAN)== true){
        cout << "The length is correct" << endl;
        IBAN = move(4, IBAN);
        IBAN = replace (IBAN);
        cout << "IBAN after replace:" << IBAN << endl;
        if (mod97(IBAN) == true){
            cout << "The IBAN you input is valid";
        }
        else{
            cout << "Input the correct IBAN";
        }
    }
    else{
        cout << "Input the correct IBAN";
    }
    return 0;
}