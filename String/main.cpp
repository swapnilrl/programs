#include <iostream>
using namespace std;
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

int main(void)
{
    
    string s="abcd";
    string t="abcde";
    int i=0, j=0;
    string res;
    
    int len1 = s.length() ;
    int len2 = t.length() ;

    if(0<=len1<=1000 && len2 == len1+1){
        for(int i=0; i<len2; i++){
            for(int j=i; j<len1; j++){
                cout<<"i= "<<i<<"   "<<"j= "<<j<<"      "<<"s[i]= "<<s[i]<<"   "<<"s[j]= "<<s[j]<<endl;
                res+= t[i];
                res+= s[j];
                cout<<res<<endl;
                if( t[i] == s[j]){
                    cout<<"Matched"<<endl;
                    break;
                }else{
                    cout<<"Mismatch"<<endl;
                }
            }
        }
    }
    /*while ( i<= len1-1 || j<= len2-1)
    {
        if(i==len1){
            res += s2[j];
            j+=1;
        }
        else if(j==len2){
            res += s1[i];
            i+=1;
        }else{
            res += s1[i];
            res += s2[j];
            i+=1;
            j+=1;
        }
    }*/
    res.append("\0");
    
    cout<<"res:"<<res<<endl;  
    return 0;
}