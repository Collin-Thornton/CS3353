#ifndef JOB_HPP
#define JOB_HPP

#include <string>

class Job {
    private:
        int id;
        int priority = 0;
        long arrival_time;
        int length;

    public:
        bool operator == (Job const &obj) {
            return (priority == obj.priority);
        }
        bool operator >= (Job const &obj) {
            return (priority >= obj.priority);
        }
        bool operator <= (Job const &obj) {
            return (priority <= obj.priority);
        }
        bool operator < (Job const &obj) {
            return (priority < obj.priority);
        }
        bool operator > (Job const &obj) {
            return (priority > obj.priority);
        }


        Job(int id, int priority, long arrival_time, int length);
        
        int work(int times = 1);

        int getLength();
        int getPriority();
        long getArrival();
        int getId();

        std::string toString();
};


#endif