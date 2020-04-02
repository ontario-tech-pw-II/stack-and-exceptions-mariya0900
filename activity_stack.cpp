// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 
using namespace std;

//template<class T>
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")

class NotEnoughOperands{};
class UnexpectedInput{};
class MoreThanOneOnTheStack{};
int main() 
{
	int numOfOperands=0;
    string in;
    stack<string> st;   // stack definition

    cin >> in;
	try{

		while(in != "q")
		{
			if(is_str_digit(in)){
				st.push(in);
				numOfOperands++;
			
			}
			else if(is_str_operator(in))
			{
				if (numOfOperands<2)
					throw NotEnoughOperands( );
				int value1=stoi(st.top());
				st.pop();
				int value2=stoi(st.top());
				double value3;
			
				st.pop();

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
				
				if (st.size()>1)
					throw MoreThanOneOnTheStack();
				else
					st.push(to_string(value3));
				

			}
			else //if input is not an integer nor a sign
				throw UnexpectedInput();
			cin >> in;
		
		}
		
	
		cout << "The answer is : " << st.top() << endl;
		
	}//try
	
	catch (NotEnoughOperands){
		cout<<"There are less than two operands on the stack!"<<endl;
	}
	catch (UnexpectedInput){
		cout<<"The input(s) should be either an operator (* / + -) or an integer"<<endl;
	}
	catch (MoreThanOneOnTheStack){
		cout<<"There are more than one item on the stack. We can't print the result"<<endl;
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
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}