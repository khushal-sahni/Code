#include <iostream>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int _stack :: getMin()
{
   //Your code here
   if(s.empty()) return -1;
   else return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty()) return -1;
   else{
     int value = s.top();
     if(value < minEle){
       value = minEle;
       minEle = 2*minEle - s.top();
       s.pop();
       return value;
     }
     else{
       s.pop();
       return value;
     }
   }
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
     s.push(x);
     minEle = x;
   }
   else{
     if(x >= minEle) s.push(x);
     else{
       s.push(2*x - minEle);
       minEle = x;
     }
   }
}
