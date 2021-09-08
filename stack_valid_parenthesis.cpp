#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
int main(){
	string s;
	cin >> s;
	stack<char>st;
	int n = s.length();
	map<char,char> mp;
	mp['{'] = '}'; mp['('] = ')'; mp['[']=']';
	bool success = true;
	for(int i=0;i<n;i++){
		if(s[i] == '{' || s[i] == '[' || s[i] == '('){
			st.push(i);
		}else if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
			if(!st.empty() and mp[s[st.top()]] == s[i]){
				st.pop();
			}else{
				success = false;
				cout << i+1 << endl;
				break;
			}
		}
		else
			continue;
	}
	if(success){
		cout << "Success" << endl;
	}
	return 0;
}
