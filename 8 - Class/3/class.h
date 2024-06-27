#ifndef CLASS_H
#define CLASS_H

class Clock
{
    //TODO
private:
    int timestamp;
public:
    void SetTime(int hh, int mm, int ss);
    void DisplayTime();
    int getTimestamp() const;
    Clock();
    Clock(int hh, int mm, int ss);
    Clock(int timestamp); 
    ~Clock();
};


#endif /* CLASS_H */