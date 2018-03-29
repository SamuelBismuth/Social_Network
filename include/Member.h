#ifndef MEMBER_H
#define MEMBER_H

/** All the includes needed. */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <algorithm>

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
        int followers, //Variable.
            followings, //Variable.
            id; //Variable
        vector<int> listFollowers;  //List.
        vector<int> listFollowings;  //List.
        //To here.

        static vector<Member*> listUsers; //Static list.

        //Help function.
        friend bool operator== (const Member &first, const Member &second);
        inline bool containsUser(Member *user);
        inline bool containsFollowing(int id);
};

#endif // MEMBER_H
