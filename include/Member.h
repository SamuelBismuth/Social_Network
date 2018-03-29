#ifndef MEMBER_H
#define MEMBER_H

/** All the includes needed. */
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

/**
 * \brief  Creation of the \class Member.
 * A Member is able to follow and unfollow another member.
 * \author Johann and Samuel.
 */
class Member {

    /** All the public prototypes. */
    public:
        Member(); //Constructor.
        virtual ~Member(); //Destructor.
        void follow(Member &member);
        void unfollow(Member &member);
        int numFollowers();
        int numFollowing();
        static int count();

    protected:

    /** All the private prototypes. */
    private:
        //From here, the variable belongs to the object member.
        int id; //Variable.
        /**
         * About the map in c++ : The second insert with the same key is a no-op. It simply returns an iterator pointing to the existing element.
         * source : https://stackoverflow.com/questions/10732074/stl-map-allows-duplicate-pairs
         * So a map act like a set, and then, we don't need to worried about duplicate follow.
         */
        map<int, Member*> mapFollowers;  //Map.
        map<int, Member*> mapFollowings;  //Map.
        //To here.
};

#endif // MEMBER_H
