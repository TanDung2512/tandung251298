#include<iostream>
#include<map>
using namespace std;
map<string,string>username;
map<string,string>login;
void registeruser(pair<string,string> user){
  if(username.find(user.first)==username.end()){
    username.insert(user);
    printf("success: new user added\n");
  }
  else{
    printf("fail: user already exists\n");
  }
}
void loginuser(pair<string,string> user){
  map<string,string>::iterator it;
  it=username.find(user.first);
  if(it!=username.end()){
    if((*it).second.compare(user.second)==0){
      if(login.find((*it).first)==login.end()){
        printf("success: user logged in\n");
        login.insert(user);
      }
      else{
        printf("fail: already logged in\n");
      }
    }
    else printf("fail: incorrect password\n");
  }
  else{
    printf("fail: no such user\n");
  }
}
void logoutusert(string user){
  map<string,string>::iterator it;
  it=username.find(user);
  if(it!=username.end()){
    if(login.find(user)!=login.end()){
      printf("success: user logged out\n");
      login.erase(user);
    }
    else{
      printf("fail: already logged out\n");
    }
  }
  else{
    printf("fail: no such user\n");
  }
}
int main(){
  int n;
  scanf("%d",&n);
  string a,b,c;
  while(n--){
    cin>>a>>b;
    if(a=="register"){
      cin>>c;
      registeruser(make_pair(b,c));
    }
    else if(a=="login"){
      cin>>c;
      loginuser(make_pair(b,c));
    }
    else if(a=="logout"){
      logoutusert(b);
    }
  }
  return 0;
}
