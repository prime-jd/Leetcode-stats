class ScheduleInterview{

};

class Interviewer{
    int id;
    public:
    Interviewer(int id){
        this.id = id;
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
