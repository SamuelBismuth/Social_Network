#include "Member.h"

//add constructor and destructor.

void Member::follow(Member member) {
    if(!isFollowing(member)) {
        followings++;
        listFollowings.insert(member);
        member.increaseNumFollowers();
        member.listFollowers.insert(*this);
    }
}

void Member::unfollow(Member member) {
    if(isFollowing(member)) {
        followings--;
        listFollowings.erase(member);
        member.decreaseNumFollowers();
        member.listFollowers.erase(member);
    }
}

void Member::count() {
    //Don't know what this function is doing.
}

int Member::numFollowers() {
    return followers;
}

int Member::numFollowing() {
    return followings;
}

void Member::decreaseNumFollowers() {
    member.followers--;
}

void Member::increaseNumFollowers(){
    member.followers++;
}

bool Member::isFollowing(Member member) {
    if (listFollowings.count(member))
            return true;
    else
        return false;
}

bool operator< (const Member &first, const Member &second) {
    return first.followers < second.followers;
}
