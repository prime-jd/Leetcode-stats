#include<bits/stdc++.h>

class TimeScheduler{
    private :
    int startTime = 9;
    int endTime = 6;
    int limit = 9;
    int attendees;
    int interviewer;
    int rooms;

    TimeScheduler(int attendees,int interviewer, int rooms){
        this.attendees = attendees;
        this.interviewer = interviewee;
        this.rooms = rooms;
    }
    public:
    vector<int>attendee;
    queue<char>interviewers;
    queue<int>room;
    for(int i=0; i<attendees; i++){
        attendee.push_back(i);
    }
    for(int i=0; i<interviewer; i++){
        interviewers.push(static_cast<char>('A' + i));
    }
    for(int i=0; i<rooms;i++){
        room.push(i);
    }
    vector<slot>schedule;
    void scheduler(){
        int time = 0;
        while(!attendee.empty() || time<=limit){
            if(room.empty)
            time+=2;

        }
    }

};

class Time{
    private:
    
    

    public :
    int periods = this.limit/2;
    int maxInterview = min(interviewees, rooms)*periods;
    int remainInterview = maxInterview>=attendees? 0: attendees-maxInterview; 
    void scheduler(){
        int scheduleAttendees = remainInterview==0?attendees: maxInterview;
        for(int i=1; i<limit; i=i+2){
            for()
            mp.push({att, {}})
        }
    }

};