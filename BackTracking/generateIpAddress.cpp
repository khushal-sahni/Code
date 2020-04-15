#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector <string> v;

void func(int index, string ip, string address, int num){
  if(index == str.length()){
    if(num == 3){
      if(ip == "") return;
      if(stoi(ip) > 255) return;
      v.push_back(address + "." + ip);
      return;
    }
    else return;
  }
  ip += str[index];
  if(stoi(ip) > 255) return;
  if(stoi(ip) == 0){
    if(num == 3){
      if(index == str.length()-1){
        v.push_back(address+".0");
        return;
      }
      else return;
    }
    if(address == "") func(index+1,"",ip, num + 1);
    else func(index+1, "",address + "."+ ip, num + 1);
    return;
  }
  if(num == 3) func(index + 1, ip, address, num);
  else{
    if(address == "") func(index+1,"",ip, num + 1);
    else func(index+1, "",address + "."+ ip, num + 1);
    func(index+1, ip, address,num);
  }

}

vector<string> genIp(string &s) {
    v.clear();
    int l = s.length();
    if(l < 4) return v;
    str = s;
    func(0,"","",0);
    return v;
}

int main(){
  string s = "1111";
  auto v = genIp(s);
  for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
}
//number can not be 0 prefixed unless they are 0
