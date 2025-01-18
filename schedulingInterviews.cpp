#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// class Schedule{
//     public:
//     int candidates;
//     string interviewer;
//     string rooms;
//     string TimeSlot;
// };
// class InterviewSchedule{
//     public:
//     vector<Schedule>schedule;
//     queue<int>candidates;
//     vector<string>rooms;
//     vector<string>interviewers;
//     vector<string>timeSlots = {"9-11","11-1","3-5"};
    
//     InterviewSchedule(vector<string>interviewers, int roomsNo, int candidatesNo){
//         this->interviewers = interviewers;
//         for(int i = 1; i<=candidatesNo; i++){
//             candidates.push(i);
//         }

//         for(int i = 1; i<=roomsNo; i++){
//             rooms.push_back("R"+ to_string(i));
//         }
//     }


//     int currentInterviewer = 0;
//     int currentRoom = 0;
//     int currentSlot = 0;
//     int x = min(interviewers.size(), rooms.size());
//     void interviewScheule(){
//         while(!candidates.empty() && currentSlot<=timeSlots.size()){
//             int candidate = candidates.front();
//             candidates.pop();

//             schedule.push_back({candidate, interviewers[currentInterviewer], rooms[currentRoom], timeSlots[currentSlot]});
//             currentInterviewer = (currentInterviewer + 1)%x;
//             currentRoom = (currentRoom+1)%x;

//             if(currentInterviewer==0 || currentRoom ==0){
//                 currentSlot++;
//             }
//         }
//         if(!candidates.empty()){
//             cout<<"Some Interviewers not got chance to interview" <<candidates.size()<<endl;
//         }
//     }
//     void displaySchedule() {
//         cout << "Attendee\tInterviewer\tRoom\tSlot" << endl;
//         for (const auto &slot : schedule) {
//             cout << slot.candidates << "\t\t" << slot.interviewer << "\t\t" << slot.rooms << "\t" << slot.TimeSlot << endl;
//         }
//     }

// };

// int main(){
//     int rooms = 3;
//     int candidates = 5;
//     vector<string>interviewers = {"A", "B"};
    
//     InterviewSchedule* schedule = new InterviewSchedule(interviewers, rooms, candidates);
//     schedule->interviewScheule();
//     schedule->displaySchedule();

//     return 0;
// }




class InterviewSchedule {
private:
    int attendees;
    vector<string> interviewers;
    int rooms;
    
    struct Slot {
        int attendee;
        string interviewer;
        string room;
        string timeSlot;
    };

    vector<Slot> schedule;

public:
    InterviewSchedule(int n, vector<string> m, int r) : attendees(n), interviewers(m), rooms(r) {}

    void generateSchedule() {
        queue<int> attendeeQueue;
        for (int i = 1; i <= attendees; i++) {
            attendeeQueue.push(i);
        }

        vector<string> roomNames;
        for (int i = 1; i <= rooms; i++) {
            roomNames.push_back("R" + to_string(i));
        }

        vector<string> timeSlots = {"9-11", "11-1", "3-5"};

        size_t currentInterviewer = 0;
        size_t currentRoom = 0;
        size_t currentTimeSlot = 0;
        int x= min(interviewers.size(), roomNames.size());

        while (!attendeeQueue.empty() && currentTimeSlot < timeSlots.size()) {
            int attendee = attendeeQueue.front();
            attendeeQueue.pop();

            schedule.push_back({attendee, interviewers[currentInterviewer], roomNames[currentRoom], timeSlots[currentTimeSlot]});

            currentInterviewer = (currentInterviewer + 1) % x;
            currentRoom = (currentRoom + 1) % x;

            if (currentInterviewer == 0 || currentRoom == 0) {
                currentTimeSlot++;
            }
        }

        if (!attendeeQueue.empty()) {
            cout << "Some interviews could not be scheduled due to time constraints." << endl;
        }
    }

    void displaySchedule() {
        cout << "Attendee\tInterviewer\tRoom\tSlot" << endl;
        for (const auto &slot : schedule) {
            cout << slot.attendee << "\t\t" << slot.interviewer << "\t\t" << slot.room << "\t" << slot.timeSlot << endl;
        }
    }
};

int main() {
    int attendees = 5;
    vector<string> interviewers = {"A", "B"};
    int rooms = 3;

    InterviewSchedule scheduler(attendees, interviewers, rooms);
    scheduler.generateSchedule();
    scheduler.displaySchedule();
    
    return 0;
}



