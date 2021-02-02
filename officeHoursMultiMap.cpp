#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cstdlib>
#include <queue>
using namespace std;


int main(){
  cout<<endl;
  srand(time(NULL));
  int maxStudents = 10; //The maximum amount of students per office hours sessions
  int count = 0; //set count at 0

  multimap<int,string> report; //mulimap for student number and reason's
  vector<string> lines; //used to read in the lines from reason file

  ifstream myfile("reasons.txt");// reads in file
  string reason;
  int total_lines=0;
  while(getline(myfile,reason)){// places all the lines into vector

    total_lines++;
    lines.push_back(reason);
  }


  while(count!=100){// 100 trials

    int totalStudents = rand() %maxStudents+1; // get a random amount of students each time
    for(int i =0; i<totalStudents;i++){
        int random_num= rand()%total_lines;
        report.insert(make_pair(i,lines[random_num]));// inserts student number and random reason
    }
    count++;
  }
  ofstream newfile0("student1.txt");
  ofstream newfile1("student2.txt");
  ofstream newfile2("student3.txt");
  ofstream newfile3("student4.txt");
  ofstream newfile4("student5.txt");
  ofstream newfile5("student6.txt");
  ofstream newfile6("student7.txt");
  ofstream newfile7("student8.txt");
  ofstream newfile8("student9.txt");
  ofstream newfile9("student10.txt");
  for(map<int, string>::const_iterator it = report.begin(); it != report.end(); ++it){
      if(it->first==0){
        newfile0<<it->second;
        newfile0<<endl;
      }
      if(it->first==1){
        newfile1<<it->second;
        newfile1<<endl;
      }
      if(it->first==2){
        newfile2<<it->second;
        newfile2<<endl;
      }
      if(it->first==3){
        newfile3<<it->second;
        newfile3<<endl;
      }
      if(it->first==4){
        newfile4<<it->second;
        newfile4<<endl;
      }
      if(it->first==5){
        newfile5<<it->second;
        newfile5<<endl;
      }
      if(it->first==6){
        newfile6<<it->second;
        newfile6<<endl;
      }
      if(it->first==7){
        newfile7<<it->second;
        newfile7<<endl;
      }
      if(it->first==8){
        newfile8<<it->second;
        newfile8<<endl;
      }
      if(it->first==9){
        newfile9<<it->second;
        newfile9<<endl;
      }
}
   myfile.close();

   int maxServiceTime = 15; //The maximum amount of time spent on one student
   count =0;
   double totalTime = 0;
   double Time1=0;
   double Waiting1=0;
   double firststudent=0;
   double averageTimeOver=0;
   double averageStudentTime = 0;
   double averageStudentWait =0;
   queue<double> waitingRoom;
   queue<double> waitingTime;

   //100 trials
   while(count!=100){
   double Time = 0;
   //get a random amount of students bounded by the max of 20
   double totalStudents = rand() %maxStudents+1;
   //this for loop assigns a time for each student and adds up the times
   //if the time is added up to 60 before we get to the end of the total
   //amount of students then we take in one last one and break.
   for(double i = 0; i<totalStudents; i++){
     if(Time<=60){
       double student = rand() %maxServiceTime +1;
       waitingRoom.push(student);
       Time+=student;
     }
     if(Time > 60){
       totalStudents= i;
       double student = rand() %maxServiceTime +1;
       waitingRoom.push(student);
       Time+=student;
       break;
       }
     }
     if(Time>60){
     double timeOver= Time-60;
     totalTime+=timeOver;
     }

     //this process is to determine the waiting time of each student
     firststudent=waitingRoom.front();
     waitingTime.push(firststudent);
     waitingRoom.pop();
     while(!waitingRoom.empty()){
       double perwait= firststudent;
       double student=waitingRoom.front();
       perwait+=student;
       waitingTime.push(perwait);
       waitingRoom.pop();
     }
     double waiting =0;
     while(!waitingTime.empty()){
       double student =waitingTime.front();
       waiting+=student;
       waitingTime.pop();
     }


     //average waiting time of 1 trial
     double Waiting2=(waiting/totalStudents);
     Waiting1+=Waiting2;

     //average time of each appointment
     double Time2=(Time/totalStudents);
     Time1+=Time2;
     count++;
   }




   averageStudentWait = (Waiting1/100);
   cout<<"After 100 trials the average time a student spends waiting during an office hour visit:"<<endl;
   cout<<averageStudentWait<<" mins"<<endl;
   averageStudentTime= (Time1/100);
   cout<<"After 100 trials the average time a student spends with the professor during an office hour visit:"<<endl;
   cout<<averageStudentTime<<" mins"<<endl;
   averageTimeOver= (totalTime/100);
   cout<<"After 100 trials the average time a Professor spends at an office hour beyond the 1 hour he intended too:"<<endl;
   cout<<averageTimeOver<<" mins"<<endl;
 }
