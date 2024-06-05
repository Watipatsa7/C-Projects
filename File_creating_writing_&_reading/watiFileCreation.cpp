#include <iostream>
#include <fstream>

using namespace std;

void create_file(string filename)
{
    //creating and opening a file
    fstream myFile;
    myFile.open(filename+".txt", ios::out);
    if (myFile.is_open())
    {
        cout<<"File is created"<<endl;
    }
    else 
    { 
        cout<<"Unable to create file"<< endl;
    }

    myFile.close();
}

void write_file (string filename)
{
    fstream myFile;
    myFile.open(filename + ".txt", ios::out | ios::app);
    if (myFile.is_open())
    {
    myFile << "Hello world"<<endl;
    myFile.close();
    }
    else 
    { 
        cout<<"Unable to open file"<< endl;
    }
}

void read_file(string filename)
{
    fstream myFile;
    
    myFile.open(filename+".txt", ios::in);

    string message = "Hello world";
    
    while(getline(myFile, message))
    {
    cout << message << endl;
    }
    
    myFile.close();
}

int main ()
{
    string filename;
    int task;
    int ans;
    do
        {
        cout<<"Enter the name of the file"<<endl;
        cin>>filename;

        string tasks[3] =
        {
            "Select 1 to Create a file",
            "Select 2 to Write to a file",
            "Select 3 to Read from a file",
        };
        for(int index = 0; index<3; index++)
        {
            cout<<index+1<<"."<<tasks[index]<<endl;
        }
        cin>>task;

        if (task==1)
        {
            create_file(filename);
        } 
        else if (task==2)
        {
            write_file(filename);
        }
        else if (task==3)
        {
            read_file(filename);
        }
        else { cout<<"Invalid Option"<<endl;}

        cout<<"\nSelect 1 to continue"<<endl;
        cout<<"Select any number apart from 1 to quit"<<endl;
        cin>>ans;
    }
    while(ans==1);
}
