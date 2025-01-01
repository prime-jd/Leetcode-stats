class Interviewer{
    int id;
    int start;
    public:
    Interviewer(int id, int start){
        this.id = id;
        this.start = start;
    }
};

class Attendee{
    int id;
    public:
    Attendee(int id){
        this.id = id;
    }
};

class Room{
    int id;
    public:
    Room(){
        this.id = id;
    }
};

class Interview{
    Attendee attendee;
    Interviewer interviewer;
    Room room;
    int startTime;
    int endTime;
    public:
    Interview(Attendee &attendee, Interviewer &interviewer, Room &room, int startTime, int endTime): attendee(attendee),interviewer(interviewer),room(room), startTime(startTime), endTime(endTime) {}
};

class ScheduleInterview{
    int start = 9;
    int end = 18;
    int breakStart =14;
    int breakEnd = 15;
    int limitTime = 2;
    vector<Interviewer>interviewer;
    vector<Room>rooms;
    vector<int>attendees;

    public:
    void availablEInterviewer(){

    }
    void schedule(){
       int time = start;
       int i = 0;
       INT J= 0
       while(attendees.size()>0 && time+2<=end){
            if()
            q.push(attendees[i]);
            if(J==interviewer.size() || k==room.size()){
                rooms.pop();
                interviewer.pop();
            }else{
                time += 2;

            }
       }
    }
    
};