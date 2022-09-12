#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<int>>doit(vector<int>ip,int n)
{
	if (n >= ip.size())
	{
		vector<vector<int>>vec;
		vec.push_back(vector<int>{});
		return vec;
	}
	vector<vector<int>>rec = doit(ip, n + 1);
	vector<vector<int>>op;
	vector<vector<int>>yes;
	for (int i = 0; i < rec.size(); i++)
	{
		vector<int>t = rec[i];
		t.push_back(ip[n]);
		yes.push_back(t);
	}
	for (int i = 0; i < yes.size(); i++)
	{
		op.push_back(yes[i]);
		op.push_back(rec[i]);
	}
	return op;
}

int main()
{
	vector<int>ip = { 1,2,3};
	vector<vector<int>>op = doit(ip,0);
	for (int i = 0; i < op.size(); i++)
	{
		for (int j = 0; j < op[i].size(); j++)
			cout << op[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
