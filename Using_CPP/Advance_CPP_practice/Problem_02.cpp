//1. Count number of apperance of words in a string
//2. Reading word by word a file
//3. Reading char by char a file
#include<iostream>
#include<map>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    map<string,int> m;
    string filename = "Problem_02.txt";
    fstream file;
    string word;
    file.open(filename.c_str());
    while(file >> word)
    {
        // cout<<word<<endl;
        m[word]++;
    }

    for(auto it = m.begin(); it!= m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }



// Read Whole file as one
    // file.open(filename,ios::in);
    // if (!file) {
	// 	cout << "No such file";
	// }
	// else {
	// 	char ch;

	// 	while (1) {
	// 		file >> ch;
	// 		if (file.eof())
	// 			break;

	// 		cout << ch;
	// 	}

	// }
	file.close();
}
