#include "Member.h"

static int numberOfUsers = 0;
std::vector<Member*> Member::listOfUsers;

Member::Member() {
    if(std::find(listOfUsers.begin(), listOfUsers.end(), this) == listOfUsers.end()) {
        listOfUsers.push_back(this);
        numberOfUsers++;
    }
}

Member::~Member() {
    if(std::find(listOfUsers.begin(), listOfUsers.end(), this) != listOfUsers.end())
        numberOfUsers--;
}

void Member::follow(Member member) {
    if(listFollowings.count(member) == 0) {
        followings++;
        listFollowings.insert(member);
        //
        //
    }
}

void Member::unfollow(Member member) {
    if(listFollowings.count(member) == 1) {
        followings--;
        listFollowings.erase(member);
        //member.decreaseNumFollowers();
        //member.listFollowers.erase(member);
    }
}

int Member::count() {
    return numberOfUsers;
}

int Member::numFollowers() {
    return followers;
}

int Member::numFollowing() {
    return followings;
}

bool operator< (const Member &first, const Member &second) {
    return first.followers < second.followers;
}
