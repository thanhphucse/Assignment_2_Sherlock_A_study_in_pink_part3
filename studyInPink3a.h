/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0);
    string toString() const;
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    int distanceTo(const Point & otherPoint) const;
};
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

string Point::toString() const{
    string s = "<Point[,]>";
    s.insert(7, to_string(this->x));
    int size = s.size();
    s.insert(size - 2, to_string(this->y));
    return s;
}
int Point::distanceTo(const Point& otherPoint) const {
    int d = pow(this->x - otherPoint.x, 2) + pow(this->y - otherPoint.y, 2);
    return ceil((float)sqrt(d));
}

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node * next=NULL);
    string toString() const;
};
Node::Node(const Point& point, Node* next){
    this->point = point;
    this->next = next;
}
string Node::toString() const {
    string s = "<Node[]>";
    s.insert(6, this->point.toString());
    return s;
}

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path();
    ~Path();

    void addPoint(int x, int y);
    string toString() const;
    Point getLastPoint() const;
    bool isNotEmpty();
    int getLength() const;
};
Path::Path() {
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
    this->length = -1;
}
void Path::addPoint(int x, int y) {
    Point newPoint(x, y);
    Node* newNode = new Node(newPoint, NULL);
    if (this->count == 0) {
        this->head = newNode;
        this->tail = newNode;
        this->count++;
        this->length = 0;
    }
    else {
        this->length = 0;
        this->tail->next = newNode;
        this->tail = this->tail->next;
        this->count++;
        
        Node* pretemp = this->head;
        Node* temp = this->head->next;
        while (temp != NULL) {
            int a = pow(temp->point.getX() - pretemp->point.getX(), 2);
            int b = pow(temp->point.getY() - pretemp->point.getY(), 2);
            this->length += ceil((float)sqrt(a + b));
            temp = temp->next;
            pretemp = pretemp->next;
        }
    }
}
string Path::toString() const {
    string s = "<Path[count:,length:,[]]>";
    s.insert(12, to_string(this->count));
    int size = 0;
    int i = 0;
    while (s[i] != '\0') {
        size++;
        i++;
    }
    s.insert(20+(size-25), to_string(this->length));

    int lastsize = 0;
    i = 0;
    while (s[i] != '\0') {
        lastsize++;
        i++;
    }

    if (this->count == 0) return s;
    else {
        if (this->count == 1) {
            string strNode = this->head->toString();
            s.insert((lastsize - 3), strNode);
            return s;
        }
        else {
            Node* temp = this->head;
            string strNode;
            while (temp->next != NULL) {
                strNode += temp->toString() + ",";
                temp = temp->next;
            }
            strNode += temp->toString();
            s.insert((lastsize - 3), strNode);
            return s;
        }
    }
}
Point Path::getLastPoint() const {
    int x = this->tail->point.getX();
    int y = this->tail->point.getY();
    Point p(x, y);
    return p;
}
Path::~Path() {
    if (head != NULL) {
        while (this->head != NULL) {
            Node* temp = this->head->next;
            delete this->head;
            this->head = temp;
        }
    }
}
bool Path::isNotEmpty() {
    if (this->head != NULL) {
        return true;
    }
    else {
        return false;
    }
}
int Path::getLength() const{
    return this->length;
}


class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name="");
    ~Character();

    string getName() const;
    void setName(const string & name);

    void moveToPoint(int x, int y);
    string toString() const;
    int pathLength() const;
    Path* getPath()const;
};
Character::Character(const string& name) {
    this->name = name;
    this->path = new Path();
}
Character::~Character() {
    if (this->path->isNotEmpty()) {
        this->path->~Path();
    }
    delete this->path;
}
string Character::getName() const {
    return this->name;
}
void Character::setName(const string& name) {
    this->name = name;
}
void Character::moveToPoint(int x, int y) {
    this->path->addPoint(x, y);
}
string Character::toString() const {
    string s = "<Character[name:,path:]>";
    int size = s.size();
    s.insert(16, this->name);
    int size2 = s.size();
    s.insert(22 + size2 - size, this->path->toString());
    return s;
}
int Character::pathLength() const {
    return this->path->getLength();
}
Path* Character::getPath()const {
    return this->path;
}

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
    int l1 = chWatson.pathLength();
    int l2 = chMurderer.pathLength();
    if ((l1 - l2) <= maxLength) {
        outDistance = chMurderer.getPath()->getLastPoint().distanceTo(chWatson.getPath()->getLastPoint());
        if (outDistance <= maxDistance) return true;
        else return false;
    }
    else {
        outDistance = -1;
        return false;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */