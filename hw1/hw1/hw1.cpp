// Hendrik Brutsaert
// cs110c hw1

#include <iostream>
#include <string>
using namespace std;

void writeIntegerBackwards(int i) {
	if (i == 0)
		return;
	cout << i % 10;
	writeIntegerBackwards(i / 10);
}

void writeBackward(string s) {
	cout << "Enter writeBackward with string: " << s << endl;
	if (s == "")
		return;
	else
	{
		cout << "About to write last character of string: "
			<< s << endl;
		cout <<s.back()<<endl;
		string st = s.substr(0, s.size() - 1);
		writeBackward(st); // Point A
	}
	cout << "Leave writeBackward with string: " << s << endl;
}

void writeBackward2(string s){
cout << "Enter writeBackward2 with string: "
<< s << endl;
if (s == "")
return;
else
{
	string st = s.substr(1, s.size());
	writeBackward2(st); // Point A
		cout << "About to write first character of string: "
		<< s << endl;
		cout << s[0]<<endl;
}
cout << "Leave writeBackward2 with string: " << s << endl;
}

int sum(int start, int end) {
	if (start == end)
		return start;
	return start+sum(start + 1, end);
}

int main()
{
	writeIntegerBackwards(423523);
	writeBackward("abcdefg");
	writeBackward2("abcdefg");
	cout<<"sum of 1 through 10: "<<sum(1, 10);
}
