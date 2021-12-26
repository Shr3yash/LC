//WRONG ans

class Solution {
public:
    int calculate(string s) {
        int calculated=0, num=0;
        char oper='+';
        stack<int> stack;
        for(int i=0;i<s.size();i++)
        {
            if (isdigit(s[i]))
                num=10*num+s[i]-'0';
            else if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1)
            {               
               
               if(oper=='+')
                   stack.push(num);
                else if(oper=='-')
                    stack.push(-num);
                else if(oper=='*')
                {
                    int prev=0;
                    prev=stack.top()*num;
                    stack.pop();
                    stack.push(prev);
                }
                else if(oper=='/')
                {
                    int prev=0;
                    prev=stack.top()/num;
                    stack.pop();
                    stack.push(prev); 
                }
                num=0;
                oper=s[i];

            }

        }
        while(!stack.empty())
        {
            calculated+=stack.top();
            stack.pop();            
        }
        return calculated;

    }

};
