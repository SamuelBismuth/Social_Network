#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <set>
#include <iterator>
#include <string>

using namespace std;

class Member {

    public:
        void follow(Member member);
        void unfollow(Member member);
        void count();
        int numFollowers();
        int numFollowing();
        void decreaseNumFollowers();
        void increaseNumFollowers();

    protected:

    private:
        bool isFollowing(Member member);
        int followers  = 0,
            followings = 0;
        set<Member> listFollowers;
        set<Member> listFollowings;
        friend bool operator< (const Member &first, const Member &second);
};

#endif // MEMBER_H
