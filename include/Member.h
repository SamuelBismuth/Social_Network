#ifndef MEMBER_H
#define MEMBER_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Member {

    public:
        Member();
        virtual ~Member();
        void follow(Member member);
        void unfollow(Member member);
        int numFollowers();
        int numFollowing();
        static int count();

    protected:

    private:
        int followers  = 0,
            followings = 0;
        set<Member> listFollowers;
        set<Member> listFollowings;
        friend bool operator< (const Member &first, const Member &second);
        static std::vector<Member*> listOfUsers;
};

#endif // MEMBER_H
