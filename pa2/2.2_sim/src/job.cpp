#include "../include/job.hpp"

#include <sstream>

Job::Job(int id, int priority, long arrival_time, int length) {
    this->id = id;

    this->priority = priority;
    this->arrival_time = arrival_time;
    this->length = length;
}
int Job::work(int times) {
    length -= times;
    return length;
}
int Job::getLength() { return length; }
int Job::getPriority() { return priority; }
int Job::getId() { return id; }
long Job::getArrival() { return arrival_time; }

std::string Job::toString() {
    std::ostringstream ss;

    ss << "ID:\t\t" << id << std::endl;
    ss << "Priority:\t" << priority << std::endl;
    ss << "Arrival Time:\t" << arrival_time << std::endl;
    ss << "Length:\t\t" << length << std::endl;

    return ss.str();
}