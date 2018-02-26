#include<iostream>
using namespace std;
struct Pharma{
  string name;
  int quantity;
  int price;
  Pharma*link;
};
struct Stock{
  Pharma*head;

  bool sell(string med,int nb){
    if(head->name==med){
      if(head->quantity==nb){
        head=NULL;
        return true;
      }
    }
    Pharma*temp=head;
    Pharma*Pre=NULL;
    while(temp!=NULL){
      Pre=temp;
      if(temp->name==med && temp->quantity>=nb){
        if(temp->quantity==nb){
          Pre->link=temp->link;
        }
        else if(temp->quantity>nb){
          temp->quantity-=nb;
        }
        return true;
      }
      temp=temp->link;
    }
    return false;
  }
  bool buy(string med,int nb,int price){
    Pharma*newPhar=new Pharma();
    if(newPhar==NULL){
      throw "stack over flow";
    }
    newPhar->link=NULL;
    newPhar->name=med;
    newPhar->quantity=nb;
    newPhar->price=price;
    Pharma*temp=head;
    Pharma*pre=NULL;
    while(temp!=NULL){
      cout<<1<<endl;
      pre=temp;
      if(temp->name==med){
        temp->quantity+=nb;
        temp->price=price;
        return true;
      }
      temp=temp->link;
    }
    if(pre==NULL){
      head=newPhar;
    }
    else{
      pre->link=newPhar;
    }
    return true;
  }
};
int main(){
  Stock storage;
  storage.head=NULL;

  if(storage.buy("thuocngu",123,12000)){
    cout<<"YES"<<endl;
  }
  return 0;
}
