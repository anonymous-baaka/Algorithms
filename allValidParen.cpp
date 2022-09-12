#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<string>doit(int n)
{
	map<string, int>mp;
	if (n == 0)
	{
		vector<string>vec;
		vec.push_back(string(""));
		mp[string("")]++;
		return vec;
	}
	if (n == 1)
	{
		vector<string>vec;
		vec.push_back(string("()"));
		mp[string("()")]++;
		return vec;
	}
	vector<string>op;
	vector<string> curr = doit(n - 1);
	for (int i = 0; i < curr.size(); i++)
	{
		for (int j = 0; j < curr[i].size(); j++)
		{
			if (curr[i][j] == '(')
			{
				string temp = curr[i].substr(0,j+1)+"()"+ curr[i].substr(j+1);
				if (!mp[temp])
				{
					op.push_back(temp);
					mp[temp]++;
				}
			}
		}
		if (!mp[curr[i] + "()"])
		{
			op.push_back(curr[i] + "()");
			mp[curr[i] + "()"]++;
		}
		if(!mp["()"+curr[i]])
		{
			op.push_back("()" + curr[i]);
			mp["()" + curr[i]]++;
		}
	}
	return op;
}

int main()
{
	int n;
	n = 3;
	vector<string>op = doit(n);
	return 0;
}
