/*
    Author @ Pradeep Kumar
    Objective : To Convert Infix Expression To Postfix Expression  
    Function :- 
	1) getWeight(char)
                -> Return a precedence of a operator and default means it may be a oprend
                Input Parameter -> None
    2) infixToPostfix(char,char,int)            
                 -> Function that Actual convert infix to postfix expression
                 passing parameter ->
                        infix -> character type variable that store infix expression enter by user
                        postfix ->character type variable that store postfix expression after computation
                        size -> integer type variable store the size of expression
                  Other parameter ->
				         i and k -> use for index purposing
						 ch -> charecter that store a operend and operator of the expression      
                  Return ->None
    Result: a postfix expression      
*/
// Approach : Itrative
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int getWeight(char ch)   //Checking precedence of operator
 {
   switch (ch)
    {
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;   // means it may be a operator
   }
}

void infixToPostfix(char infix[], char postfix[], int size)    // convert infix expression to postfix using a stack
{
   stack<char> s;
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   // iterate over the infix expression   
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         // simply push the opening parenthesis
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') {
         // if we see a closing parenthesis,
         // pop of all the elements and append it to
         // the postfix expression till we encounter
         // a opening parenthesis
         while (!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();

         }
         // pop off the opening parenthesis also
         if (!s.empty()) {
            s.pop();
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         // we saw an operand
         // simply append it to postfix expression
         postfix[k++] = ch;

      }
      else {
         // we saw an operator
         if (s.empty()) {
           
            s.push(ch);        // simply push the operator onto stack if stack is empty
         }
         else {
            // pop of all the operators from the stack and append it to the postfix expression till we        
            // see an operator with a lower precedence that the current operator 
            while (!s.empty() && s.top() != '(' &&
                  weight <= getWeight(s.top())) {
               postfix[k++] = s.top();
               s.pop();

            }
            // push the current operator onto stack
            s.push(ch);
         }
      }
      i++;
   }
                            
   while (!s.empty()) 
   {
      postfix[k++] = s.top();          // pop of the remaining operators present in the stack and append it to postfix expression
      s.pop();
   }
   postfix[k] = 0; // null terminate the postfix expression 
}

// main
int main() {
   char infix[50] ;
   cout<<"enter the infix expression"<<endl;
   cin>>infix;
   int size = strlen(infix);
   char postfix[size];
   infixToPostfix(infix,postfix,size);
   cout<<"\nInfix Expression :: "<<infix;
   cout<<"\nPostfix Expression :: "<<postfix;
   cout<<endl;
   return 0;
}
