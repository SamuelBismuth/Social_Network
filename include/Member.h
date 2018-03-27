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
        void follow(Member member);
        void unfollow(Member member);
        int numFollowers();
        int numFollowing();
        static int count();

    protected:

    /** All the private prototypes. */
    private:
        int followers  = 0, //Variable.
            followings = 0; //Variable.
        vector<Member> listFollowers;  //List.
        vector<Member> listFollowings;  //List.
        static vector<Member*> listUsers; //List.
        friend bool operator== (const Member &first, const Member &second);
        inline bool containsUser(Member *user);
        inline bool containsFollowing(Member following);
};

#endif // MEMBER_H
