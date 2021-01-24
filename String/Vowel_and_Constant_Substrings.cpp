#include<iostream>
using namespace std;

// Vowel and Constant Substring // 

bool isVowel(char ch){

	return (ch=='a' || ch=='e' || ch=='i'
	          || ch=='o'|| ch=='u'
		   );
}

bool isCont(char ch){

	return (ch!='a' and ch!='e' and ch!='i'
	        and ch!='o' and ch!='u'
		   );
}

int count(string s){
	int len = s.length();
	int co[len+1] ={0};
	int vo[len+1] = {0};

	if(isCont(s[len-1])== true){
		co[len-1] = 1;
	}
	else{
		vo[len-1] = 1;
	}

	for(int i = len-2; i>=0; i--){
		if(isCont(s[i])){
			co[i] = co[i+1]+1;
			vo[i] = vo[i+1];
		}
		else{
			vo[i] = vo[i+1]+1;
			co[i] = co[i+1];
		}
	}

	long long ans = 0;

	for(int i=0; i<len; i++){

		if(isVowel(s[i])){
			ans = ans+co[i+1];
		}
		else{
			ans = ans+vo[i+1];
		}
	}

	return ans;
}

 
int main() 
{
	string s;
	cin>>s;

	cout<<count(s);
	
	return 0;
}