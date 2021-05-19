//Kaushal Prajapat 19.05.2021
//This challenge works with a custom-designed markup language HRML. In HRML, each element consists of a
//starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes.
//We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may
//also be nested.

//The opening tags follow the format:
//<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

//The closing tags follow the format:
//</tag-name>

//The attributes are referenced as:
//tag1~value
//tag1.tag2~name

//Given the source code in HRML format consisting of  lines, answer  queries. For each query, print the
//value of the attribute specified. Print "Not Found!" if the attribute does not exist.
//Example

//HRML listing
//<tag1 value = "value">
//<tag2 name = "name">
//<tag3 another="another" final="final">
//</tag3>
//</tag2>
//</tag1>

//Queries
//tag1~value
//tag1.tag2.tag3~name
//tag1.tag2~value

//Here, tag2 is nested within tag1, so attributes of tag2 are accessed as tag1.tag2~<attribute>. Results of the queries are:

//Query                 Value
//tag1~value            "value"
//tag1.tag2.tag3~name   "Not Found!"
//tag1.tag2.tag3~final  "final"

// The first line consists of two space separated integers, N 
// and Q. N specifies the number of lines in the HRML source 
// program. Q specifies the number of queries.

// // The following N lines consist of either an opening tag 
// with zero or more attributes or a closing tag. There is a 
// space after the tag-name, attribute-name, '=' and value.There 
// is no space after the last value. If there are no attributes 
// there is no space after tag name.

// Q queries follow. Each query consists of string that 
// references an attribute in the source program.More formally, 
// each query is of the form (tag)i1.(tag)i2.(tag)i3.(tag)im 
// ~attr-name where m>=1 and (tag)i1.(tag)i2.(tag)i3.(tag)im are 
// valid tags in the input.

// Print the value of the attribute for each query. Print "Not 
// Found!" without quotes if the attribute does not exist.



#include <iostream>
#include <map>
using namespace std;

map <string, string> tagMap;

void createMap(int &n, string pretag) {
    if(!n) return;

    string line, tag, attr, value;
    getline(cin, line);

    int i=1;
    if(line[i]=='/') {           // found closing tag
        while(line[i]!='>') i++;
        if(pretag.size()>(i-2))        // update tag
            tag = pretag.substr(0,pretag.size()-i+1);
        else
            tag = "";
    }
    else {                       // found opening tag
        while(line[i]!=' ' && line[i]!='>') i++;
        tag = line.substr(1,i-1);    // update tag
        if(pretag!="") tag = pretag + "." + tag;

        int j;
        while(line[i]!='>') { // go through attributes
            j = ++i;
            while(line[i]!=' ') i++;
            attr = line.substr(j,i-j);    // attribute name

            while(line[i]!='\"') i++;
            j = ++i;
            while(line[i]!='\"') i++;
            value = line.substr(j,i-j);    // attribute value
            i+= 1;

            tagMap[tag + "~" + attr] = value;
        }
    }
    createMap(--n, tag);
}

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();
    createMap(n,"");

    string attr, value;
    while(q--) {
        getline(cin,attr);
        value = tagMap[attr];
        if(value=="") value = "Not Found!";
        cout << value << endl;
    }
    return 0;
}
