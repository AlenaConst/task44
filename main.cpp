#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1, '\n');
	s2 = s1;
	cout << "Result method A: ";
	int buf = s1.find("  ");
	while (buf != -1)
	{
		s1.erase(buf, 1);
		buf = s1.find("  ");
	}
	cout << s1 << '\n';

	string::iterator it1 = s2.begin() + 1;
	string::iterator it2 = s2.begin() + 1;
	while(it1 != s2.end())
	{
		if (*(it2 - 1) == ' ' && (*it1) == ' ')
		{
			it1++;
		}
		else
		{
			(*it2) = (*it1);
			it1++;
			it2++;
		}
	}
	s2.erase(it2, it1);
	cout << "Result method B: " << s2 << "\n\n";

	//string s3 = "    df     dfgdfg      df    asd    df     .";
	string s3 = "as   asd  as asdas  as assa as     aaabb  as   .      ";
	cout << '"' << s3 << '"';
	while (s3.find('.') != -1) { s3.erase(s3.find('.'), 1); }
	while (*(s3.end() - 1) == ' ') { s3.erase(s3.length() - 1, 1); }
	s3.insert(0, " ");
	int pos = s3.rfind(" ");
	string s4 = s3.substr(pos) + " ";
	s3 += " ";
	buf = s3.find(s4);
	while (buf != -1)
	{
		s3.erase(buf + 1, s4.length() - 1);
		buf = s3.find(s4);
	}
	buf = s3.find("  ");
	while (buf != -1)
	{
		s3.erase(buf, 1);
		buf = s3.find("  ");
	}
	cout << "\nResult: "<< '"' << s3 << '"' << "\n\n";

	string s5, s6;
	int max_l = 0;
	getline(cin, s5, '\n');
	while (s5.find("  ") != -1) { s5.erase(s5.find("  "), 1); }
	if (*(s5.begin()) != ' ') { s5.insert(0, " "); }
	while (s5.rfind(" ") != -1 && s5.length() != 0)
	{
		while (s5.find("  ") != -1) { s5.erase(s5.find("  "), 1); }
		if (*(s5.end() - 1) == ' ') { s5.erase(s5.length() - 1, 1); }
		string bufs = s5.substr(s5.rfind(" "));
		s5.erase(s5.rfind(bufs), bufs.length());
		if (bufs.find(" ") != -1) { bufs.erase(bufs.find(" "), 1);  }
		if (bufs.length() > max_l)
		{
			max_l = bufs.length();
			s6 = bufs;
		}
		else if (bufs.length() == max_l)
		{
			s6 = s6 + " " + bufs;
		}
	}
	cout << "Max length = " << max_l << "\nWords with max length: " << s6;
	return 0;
}
