// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")


int main() 
{
    string in;
    stack<string> st;

    cin >> in;

    try 
    {
        while(in != "q")
        {
            if(is_str_digit(in))
            {
                st.push(in);
            }
            else if(is_str_operator(in))
            {   
                
                if (st.size() < 2)
                    throw 2;

                int value1 = stoi(st.top());
                st.pop();

                int value2 = stoi(st.top());
                st.pop();

                int value3 ;

                switch(in[0])
                {
                    case '+':
                        value3 = value2 + value1;
                        break;

                    case '-':
                        value3 = value2 - value1;
                        break;

                    case '*':
                        value3 = value2 * value1;
                        break;

                    case '/':
                        value3 = value2 / value1;
                        break;

                }
                st.push(to_string(value3));       
            }
            else
                throw 3;

            cin >> in;
        }
        if (st.size() != 1)
            throw 3;
        cout << "The answer is : " << st.top() << endl;

    }
    catch(int e)
    {
        switch(e){
            case 1: 
                cout << "The token is not operator nor integer !" << endl;
                break;
            case 2: 
                cout << "There are not enough operand!" << endl;
                break;
            case 3:
                cout << "The are extra operand in the stack! " << endl;
                break;

        }
    }
    
    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'));
}
