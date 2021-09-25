#include<bits/stdc++.h>
using namespace std;
string positive(int n){
	if (n>0)
	{
		/* code */
		return "positive";
	}
	else 
		return "negative";
}
string divisible(int n){
	if (n%5==0)
	{
		return "divisible";
	}
	else
		return "not-divisible";
}
string evenodd(int n){
	if(n&2)
		return "odd";
	else 
		return "even";
}
int main(int argc, char const *argv[])
{
	int n; cin>>n;
	cout<<evenodd(n);
	return 0;
}