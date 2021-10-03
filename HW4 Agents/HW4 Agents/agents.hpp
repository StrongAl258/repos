#include <sstream>
using namespace std;

#define RECOVERY_PERIOD 14

class Agent {
public:
    virtual bool isInfected() = 0;
    virtual bool isCured(int) = 0;
    virtual bool isDead() = 0;
    virtual string info() const = 0;
};

ostream& operator<<(ostream& o, const Agent& a)
{
    o << a.info();
    return o;
}

class Healthy : public Agent{
public:
   inline bool isInfected() { return false; }
   inline bool isCured(int s){ return false; }
   inline bool isDead(){ return false; }
   inline string info() const{
        ostringstream s; 
        s << "H";
        return s.str();
    }
};

class Infected : public Agent{
protected:
    int infDate;
public:
    Infected() : infDate{ 0 } { }
    Infected(int a) :infDate{ a } {}
    inline bool isInfected() { return true; }
    bool isCured(int s) {
        if (s - infDate > RECOVERY_PERIOD)
            return true;
        return false; }
    inline bool isDead() { return false; }
    inline string info() const{
        ostringstream s;
        s << "I[" << infDate << "]";
        return s.str();
    }
    int getDate() {
        return infDate;
    }
};

class Dead : public Infected{
protected:
    int date;
    string idate;
public: 
    Dead(Infected* a, int b) {
        date = b;
        idate = a->info();
    }
    inline bool isInfected() { return false; }
    inline bool isCured(int s) { return false; }
    inline bool isDead() { return true; }
    inline string info() const{
        ostringstream s;
        s << "D[" << idate << ", " << date << "]";
        return s.str();
    }
};

class Cured : public Infected{
protected:
    int date;
    string idate;
public:
    Cured(Infected* a, int b) {
        date = b;
        idate = a->info();
    }
    inline bool isInfected() { return false; }
    inline bool isCured(int s) { return true; }
    inline bool isDead() { return false; }
    inline string info() const{
        ostringstream s;
        s << "C[" << idate << ", " << date << "]";
        return s.str();
    }
};
