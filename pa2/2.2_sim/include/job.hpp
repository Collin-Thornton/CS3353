#ifndef JOB_HPP
#define JOB_HPP

#include <string>
#include <sstream>

class Job {
    private:
        std::string id;
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
        friend std::ostringstream& operator << (std::ostringstream &ss, const Job &job);

        Job(std::string id, int priority, long arrival_time, int length);
        
        int work(int times = 1);

        int getLength();
        int getPriority();
        long getArrival();
        std::string getId();
        bool isFinished();

        std::string toString();
};


#endif