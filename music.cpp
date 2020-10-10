#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
class music
{ 
  int play=0;
  int counts=0;
  string song[100];
  string artist[100];
  void read();
  
  void setsong();
  void delsong();
  friend void add();
  public: void display();
};
void music::read()
{
  cout<<"enter the song name: ";
  cin>>song[counts];
  cout<<"enter the artist name: ";
  cin>>artist[counts];
}
void music::display()
{ 
  int i=1;
  string line;
  ifstream file("track.txt",ios::in);
  if(file.is_open())
  {
   while(file>>line)
   {
     cout<<i<<". "<<line<<"\n";
     i++;
   }
  }
}
void music::setsong()
{
  cout<<"enter the song name: ";
  cin>>song[counts];
  cout<<"enter the artist name: ";
  cin>>artist[counts];
  ofstream file1;
  file1.open ("track.txt",ios::app);
  if(file1.is_open()) 
  {
   file1<<song[counts]<<"_"<<artist[counts]<<"\n";
   counts++; 
  }
  else cout<<"UNABLE TO OPEN FILE."<<endl;
}
void music::delsong()
{
  string tsong,tartist,lines;
  cout<<"Enter the song name you want to delete: ";
  cin>>tsong;
  cout<<"Enter the artist name: ";
  cin>>tartist;
  //ifstream file1 open("track.txt");
  //if(file1.is_open())
  //{
    //while(getline(file1,lines))
    //{
      
    //}
  //}
  cout<<"Song delted successfully.\n";
  counts--;
}
void add()
{
  music m1;
  m1.setsong();
}
int main()
{
  int choice;
  while(1)
  {
  system("cls");
  cout<<"Enter your choice: \n";
  cout<<"1.list of playlists\t 2.create a new playlist\t 3.add music to the track\n ENTER 0 TO QUIT\n";
  cin>>choice;
  switch(choice)
  {
    case 0:
        exit(0);
    case 1:
        system("cls");
        cout<<"\nLIST OF PLAYLISTS"<<endl;
        system("pause");
        break;
    case 2:
        system("cls");
        cout<<"\nCREATE A NEW PLAYLIST\n";
        system("pause");
        break;
    case 3:
        system("cls");
        cout<<"\nADD MUSIC TO THE TRACK\n";
        add();
        system("pause");
        cout<<"\nsong added successfully.\n";
        music m1;
        m1.display();
        system("pause");
        break;    
  }
 }
  return 0;
}
