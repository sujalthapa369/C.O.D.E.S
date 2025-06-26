class Meeting {
  public:
    int start, finish;

    Meeting(int start, int finish) {
        this->start = start;
        this->finish = finish;
    }
};

// Custom comparator function
bool compareMeetings(const Meeting& m1, const Meeting& m2) {
    return m1.finish < m2.finish;
}

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Meeting> meetings;

        // Pushing the pair of starting and finish time in a list.
        for (int i = 0; i < n; i++) {
            meetings.push_back(Meeting(start[i], end[i]));
        }

        // Sorting the list of meetings by finish time using a custom comparator
        sort(meetings.begin(), meetings.end(), compareMeetings);

        int lastFinishTime = -1;
        int res = 0;

        for (int i = 0; i < n; i++) {
            // If the start time of this meeting is greater than or equal
            // to the finish time of the previously selected meeting,
            // increment the counter and update last.
            if (meetings[i].start > lastFinishTime) {
                res++;
                lastFinishTime = meetings[i].finish;
            }
        }

        // Returning the counter.
        return res;
    }
};