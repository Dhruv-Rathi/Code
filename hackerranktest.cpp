#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'getPhoneNumber' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string getPhoneNumber(string s) {
    string ans;
    for(int i=0;i<s.length();i++){
        switch(s[i]){
            case 'z': ans+='0'; i+=3; break;
            case 'o': ans+='1'; i+=2; break;
            case 'e': ans+='8'; i+=4; break;
            case 'n': ans+='9'; i+=3; break;
            case 't': i++;
                        if(s[i] == 'w'){
                            ans+='2'; i++; 
                        }
                        else if(s[i] == 'h'){
                            ans+='3'; i+=3;
                        }
                        else{
                            i+=6;
                            switch(s[i]){
                                case 'z': ans+="000"; i+=3; break;
                                case 'o': ans+="111"; i+=2; break;
                                case 'e': ans+="888"; i+=4; break;
                                case 't': i++;
                                        if(s[i] == 'w'){
                                            ans+="222"; i++; 
                                        }
                                        else if(s[i] == 'h'){
                                            ans+="333"; i+=3;
                                        }
                                        break;
                                case 'f': i++;
                                        if(s[i] == 'o'){
                                            ans+="444"; i+=2; 
                                        }
                                        else if(s[i] == 'i'){
                                            ans+="555"; i+=2;
                                        }
                                        break;
                                case 's': i++;
                                        if(s[i] == 'i'){
                                            ans+="666"; i++; 
                                        }
                                        else if(s[i] == 'e'){
                                            ans+="777"; i+=3;
                                        }
                                        break;
                            }
                        }
                        break;
            case 'd': i+=7;
                        switch(s[i]){
                                case 'z': ans+="00"; i+=3; break;
                                case 'o': ans+="11"; i+=2; break;
                                case 'e': ans+="88"; i+=4; break;
                                case 't': i++;
                                        if(s[i] == 'w'){
                                            ans+="22"; i++; 
                                        }
                                        else if(s[i] == 'h'){
                                            ans+="33"; i+=3;
                                        }
                                        break;
                                case 'f': i++;
                                        if(s[i] == 'o'){
                                            ans+="44"; i+=2; 
                                        }
                                        else if(s[i] == 'i'){
                                            ans+="55"; i+=2;
                                        }
                                        break;
                                case 's': i++;
                                        if(s[i] == 'i'){
                                            ans+="66"; i++; 
                                        }
                                        else if(s[i] == 'e'){
                                            ans+="77"; i+=3;
                                        }
                                        break;
                            }
                            break;
            case 's': i++;
                    if(s[i] == 'i'){
                        ans+="6"; i++; 
                    }
                    else if(s[i] == 'e'){
                        ans+="7"; i+=3;
                    }
                    break;
            case 'f': i++;
                    if(s[i] == 'o'){
                        ans+="4"; i+=2; 
                    }
                    else if(s[i] == 'i'){
                        ans+="5"; i+=2;
                    }
                    break;
        }
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = getPhoneNumber(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
