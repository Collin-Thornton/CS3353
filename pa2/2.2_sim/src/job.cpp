#include "../include/job.hpp"

std::ostringstream& operator << (std::ostringstream &ss, const Job &job){
    ss << job.id << ' ' << job.priority << ' ' << job.length;    
    return ss;
}

Job::Job(std::string id, int priority, long arrival_time, int length, bool compareArrivalTime) {
    this->id = id;

    this->priority = priority;
    this->arrival_time = arrival_time;
    this->length = length;
    this->compareArrivalTime = compareArrivalTime;
}
int Job::work(int times) {
    length -= times;
    return length;
}
int Job::getLength() { return length; }
int Job::getPriority() { return priority; }
std::string Job::getId() { return id; }
long Job::getArrival() { return arrival_time; }
bool Job::isFinished() { return (length == 0); }

std::string Job::toString() {
    std::ostringstream ss;

    ss << id << ' ' << priority << ' ' << length << std::endl;
    return ss.str();
}