#include <iostream>

#include <cctype>

#include <fstream>
#include <string>

using namespace std;

int main(){
    
    //filename
    string filename;
    
    //the current line from the file
    string line;
    
    //the current and/or first node found
    string node;
    
    //the data contained within a node
    string data;
    
    //did we find a node?
    bool isNode;
    
    //checks if we've reached the end of our node/line
    char check;
    
    cout << "Please enter the file name: " << endl;
    
    cin >> filename;
    
    ifstream xmlFile;
    xmlFile.open(filename.c_str());
    
    if(xmlFile.is_open())
    {
        while(xmlFile.good())
        {
            getline(xmlFile, line);
            if(line[0] == '<' && line[1] != '/' )
            {
               isNode = true;
               for(int i = 0; i < line.length()-1; i++)
               {
                   if(line[i] == '>' || line[i] == '/')
                      break;
                   if(isalpha(line[i]))
                      node += line[i];
               }
            }
            else isNode = false;
            
            cout << line << endl;
            if(isNode)
            {           
               cout << "\nNode is: " << node << "\n" << endl;
               for(int i = 0; i < line.length()-1; i++)
               {
                   if(line[i] == '<' && line[i+1] == '/')
                   {
                       break;
                   }
                   if(line[i-1] == '>')
                   {
                      check = 'n';
                   }
                   if(line[i] == '<' || check == 'c')
                   {
                       check = 'c';
                       continue;
                   }
                   else if(check == 'n')
                      data += line[i];
                   
                }
                cout << "\nData is: " << data << "\n" << endl;
             }
               
            node = "";
            data = "";
        }
        xmlFile.close();
    }
    else
    {
        cout << "Could not find the Save File!";
    }
    
    system("PAUSE");
    cin.ignore(100, '\n');
    return 0;
}
