class ExamRoom {
public:
    int n;
    set<int> students;
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if(students.empty()){
            students.insert(0);
            return 0;
        }
        int max_dist = *students.begin();
        int best_far =  0;

        auto it = students.begin();
        int s1 = *it;
        ++it;

        while(it != students.end()){
            int s2 = *it;
            int dist = (s2 - s1) / 2;
            if(max_dist < dist){
                max_dist = dist;
                best_far = s1 + dist;
            }
            s1 = s2;
            ++it;
        }
        int right_gap = (n - 1) - *students.rbegin();
        if(right_gap > max_dist){
            max_dist = right_gap;
            best_far = n - 1;
        }
        students.insert(best_far);
        return best_far;
    }
    
    void leave(int p) {
        students.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */